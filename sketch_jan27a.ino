#include <HCSR04.h>

#include <Servo.h>
#define TRIG_PIN A1
#define ECHO_PIN A0
Servo myservo;
HCSR04 sonar(ECHO_PIN, TRIG_PIN);
int a;
int program()
{
  int maximum = 0;
  int degree = 0;
  int b;
  for(int dec = 0; dec <= 180; dec = dec + 45){
    myservo.write(dec);
    b = distance();
    delay(3000);
    if(b > maximum)
    {
      maximum = b;
      degree = dec;
    }
  }
  myservo.write(degree);
  delay(5000);
}
int distance()
{
   a = sonar.dist();
   Serial.print("\n");
   Serial.print(a,DEC);
   return a;
}

void setup() {
  Serial.begin(9600);
  myservo.attach(3);

}



void loop() {
  program();
}
