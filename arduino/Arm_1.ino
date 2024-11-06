#include <Servo.h>

Servo baseServo;    // Servo 1 - Base rotation
Servo arm1Servo;    // Servo 2 - First arm segment
Servo arm2Servo;    // Servo 3 - Second arm segment
Servo clawServo;    // Servo 4 - Claw

// starting positions of servos
int basePos = 90;  
int arm1Pos = 90;    
int arm2Pos = 90;    
int clawPos = 90;    

void setup() {
  baseServo.attach(8);  
  arm1Servo.attach(9);   
  arm2Servo.attach(10);  
  clawServo.attach(11);  
  
  Serial.begin(9600);
  
  baseServo.write(basePos);
  arm1Servo.write(arm1Pos);
  arm2Servo.write(arm2Pos);
  clawServo.write(clawPos);
}

void loop() {
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    
    int commaIndex = command.indexOf(',');
    if (commaIndex != -1) {
      int servoNum = command.substring(0, commaIndex).toInt();
      int angle = command.substring(commaIndex + 1).toInt();
      
      // Constrain (0-180)
      angle = constrain(angle, 0, 180);
      
      switch (servoNum) {
        case 1:
          basePos = angle;
          baseServo.write(basePos);
          break;
        case 2:
          arm1Pos = angle;
          arm1Servo.write(arm1Pos);
          break;
        case 3:
          arm2Pos = angle;
          arm2Servo.write(arm2Pos);
          break;
        case 4:
          clawPos = angle;
          clawServo.write(clawPos);
          break;
      }
      
      // Send confirmation 
      Serial.print("Servo ");
      Serial.print(servoNum);
      Serial.print(" moved to ");
      Serial.println(angle);
    }
  }
}