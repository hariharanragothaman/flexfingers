
*/  This is the Arduino Code to control fllex sensors, and map the results on to an embedded device.
* Controlling a servo position using a potentiometer (variable resistor)
* MPC - added serial output 'n stuff With flex sensor
* Tweak Val to Angle Map
*/

/* Hardware Setup,Here is the wiring:
*  Wiring
*  Flex Sensor |------Arduino Gnd
*  Flex Sensor |------Analog 0
*  100K |------Analog 0
*  100K |------Arduino 5V


* | Yellow ------ Digi 9 (PWM)
* Top servo | Red -----------5V
* | Brown -------Gnd
* | Yellow ------ Digi 10 (PWM)
* Bottom servo | Red -----------5V
* | Brown ------

*/

#include<Servo.h>

Servo myservo; // create servo object to control a servo
Servo otherServo ;

int potpin = 0; // analog pin used to connect the potentiometer
int val; // variable to read the value from the analog pin
int valComp;

void setup()
  {
    myservo.attach(9); // attaches the servo on pin 9 to the servo object
    otherServo.attach(10);
    Serial.begin(9600);
  }

void loop()
  {
    val = analogRead(potpin); // reads the value of the potentiometer (value between 0 and 1023)
    Serial.println(val);
    valComp = analogRead(potpin);
    Serial.println(valComp);
    val = map(val, 40, 350, 90, 179); // scale it to use it with the servo (value between 0 and 180)
    valComp = map(valComp, 350, 40, 0, 90); //other servo does oposite
    myservo.write(val); // sets the servo position according to the scaled value
    delay(15);
    otherServo.write(valComp);
    delay(25); // waits for the servo to get there
    
  }
