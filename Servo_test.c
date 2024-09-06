#include <ESP32Servo.h>


#define servoCapturePin 33 //Capture mechanism servo, servo_3 on PCB

Servo servoCapture;


void setup() {

  //Libaries

  // put your setup code here, to run once:

  // Capture mechanism servo

  servoCapture.attach(servoCapturePin, 500, 2400);

  servoCapture.setPeriodHertz(50);    // standard 50 hz servo

  change_servo_angle(0, 180, 5, 100);
  delay(1000);
  change_servo_angle(180, 0, 5, 100);

}

/*
* takes in a current angle and the new angle that you want to go to, the 
*   step value is the absolute magnitude of the change in angle you want, 
*   with a given settle time which is a delay in milliseconds. 
*
*   don't try to break it too much as I just chucked it together
*/
void change_servo_angle(int current, int new, int step, int settle) {
  if (new < current) {
    for (int newpos = current; newpos < new; newpos -= step) {

      servoCapture.write(newpos);

      delay(settle);

    }
  }
  else {
    for (int newpos = current; newpos < new; newpos += step) {

    servoCapture.write(newpos);

    delay(settle);
    }
  }
}




void loop() {

  // put your main code here, to run repeatedly:
}
