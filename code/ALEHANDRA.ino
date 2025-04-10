#define BLYNK_TEMPLATE_ID "TMPL2APmbSldI"
#define BLYNK_TEMPLATE_NAME "AleHANDra"
#define BLYNK_AUTH_TOKEN "9k5JiPhQKm--B35W8TbDUBMGI4TEniTc"

#define BLYNK_PRINT Serial
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

Adafruit_PWMServoDriver pca = Adafruit_PWMServoDriver(0x40);

#define servoMIN 125
#define servoMAX 600

char auth[] = "9k5JiPhQKm--B35W8TbDUBMGI4TEniTc";
char ssid[] = "Redmi Note 12";
char pass[] = "Hillary01";

void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22);
  pca.begin();
  pca.setPWMFreq(60);
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  Serial.println("Blynk conectado, listo para recibir comandos.");
}

void moverServo(int numServo, int valor, int minGrados, int maxGrados) {
  int posPWM = map(valor, minGrados, maxGrados, servoMIN, servoMAX);
  Serial.print("Servo "); Serial.print(numServo);
  Serial.print(" -> Grado: "); Serial.print(valor);
  Serial.print(" -> PWM: "); Serial.println(posPWM);
  pca.setPWM(numServo, 0, posPWM);
}

// Servos de 0 a 20 grados (V0-V3)
BLYNK_WRITE(V0) { moverServo(0, param.asInt(), 0, 20); }
BLYNK_WRITE(V1) { moverServo(1, param.asInt(), 0, 20); }
BLYNK_WRITE(V2) { moverServo(2, param.asInt(), 0, 20); }
BLYNK_WRITE(V3) { moverServo(3, param.asInt(), 0, 20); }

// Servo de 0 a 90 grados (V4)
BLYNK_WRITE(V4) { moverServo(4, param.asInt(), 0, 90); }

// Servos de 0 a 180 grados (V5-V10)
BLYNK_WRITE(V5) { moverServo(5, param.asInt(), 0, 180); }
BLYNK_WRITE(V6) { moverServo(6, param.asInt(), 0, 180); }
BLYNK_WRITE(V7) { moverServo(7, param.asInt(), 0, 180); }
BLYNK_WRITE(V8) { moverServo(8, param.asInt(), 0, 180); }
BLYNK_WRITE(V9) { moverServo(9, param.asInt(), 0, 180); }
BLYNK_WRITE(V10) { moverServo(10, param.asInt(), 0, 180); }

void loop() {
  Blynk.run();
}
