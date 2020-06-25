int enAF = 2 ;
int enBF = 3 ;
int enAB = 4 ;
int enBB = 5 ;
int in1B = 22 ;
int in2B = 24 ;

int in3B = 26 ;
int in4B = 28 ;

int in1F = 30 ;
int in2F = 32 ;
int in3F = 34 ;
int in4F = 36 ;

int LS = 8 ;
int RS = 9 ;
int BS1 = 10 ;
int BS2 = 11 ;

int Speed = 180;
int Speed1 = 255;
int Speed2 = 150;

#include <Stepper.h>

const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
// for your motor

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 46, 48, 50, 52);

void setup() {


  pinMode ( enBB , OUTPUT ) ;
  pinMode ( enAB , OUTPUT ) ;
  pinMode ( enBF , OUTPUT ) ;
  pinMode ( enAF , OUTPUT ) ;
  pinMode ( in3B , OUTPUT ) ;
  pinMode ( in4B , OUTPUT ) ;
  pinMode ( in1B , OUTPUT ) ;
  pinMode ( in2B , OUTPUT ) ;
  pinMode ( in3F , OUTPUT ) ;
  pinMode ( in4F , OUTPUT ) ;
  pinMode ( in1F , OUTPUT ) ;
  pinMode ( in2F , OUTPUT ) ;

  pinMode ( LS , INPUT ) ;
  pinMode ( RS , INPUT ) ;
  pinMode ( BS1 , INPUT ) ;
  pinMode ( BS2 , INPUT ) ;

  // set the speed at 60 rpm:
  myStepper.setSpeed(60);
  // initialize the serial port:
  Serial.begin(9600);

}
void loop() {
  delay (5000) ;
  while (1)
  {
    for ( int i = 0 ; i < 10 ; i++ )
    {
      myStepper.step(stepsPerRevolution);
    }
    break ;
  }
  digitalWrite ( in1F , HIGH ) ;
  digitalWrite (in2F , LOW ) ;
  digitalWrite ( in3F , LOW ) ;
  digitalWrite (in4F , HIGH ) ;
  digitalWrite ( in1B , HIGH ) ;
  digitalWrite (in2B , LOW ) ;
  digitalWrite ( in3B , LOW ) ;
  digitalWrite (in4B , HIGH ) ;
  analogWrite ( enBB , Speed1 ) ;
  analogWrite ( enAB , Speed1 ) ;
  analogWrite ( enAF , Speed1 ) ;
  analogWrite ( enBF , Speed1 ) ;
  delay (500) ;
  while (1)
  {
    if (!digitalRead(BS1))
    {
      digitalWrite ( in1F , HIGH ) ;
      digitalWrite (in2F , LOW ) ;
      digitalWrite ( in3F , LOW ) ;
      digitalWrite (in4F , HIGH ) ;
      digitalWrite ( in1B , HIGH ) ;
      digitalWrite (in2B , LOW ) ;
      digitalWrite ( in3B , LOW ) ;
      digitalWrite (in4B , HIGH ) ;
      analogWrite ( enBB , Speed1 ) ;
      analogWrite ( enAB , Speed1 ) ;
      analogWrite ( enAF , Speed1 ) ;
      analogWrite ( enBF , Speed1 ) ;
    }
    else
    {
      digitalWrite ( in1F , LOW ) ;
      digitalWrite (in2F , LOW ) ;
      digitalWrite ( in3F , LOW ) ;
      digitalWrite (in4F , LOW ) ;
      digitalWrite ( in1B , LOW ) ;
      digitalWrite (in2B , LOW ) ;
      digitalWrite ( in3B , LOW ) ;
      digitalWrite (in4B , LOW ) ;
      analogWrite ( enBB , 0 ) ;
      analogWrite ( enAB , 0 ) ;
      analogWrite ( enAF , 0 ) ;
      analogWrite ( enBF , 0 ) ;
      delay (2000) ;
      break ;
    }
  }
  while (1)
  {
    if (!digitalRead(RS) && !digitalRead(LS))
    {
      digitalWrite ( in1F , HIGH ) ;
      digitalWrite (in2F , LOW ) ;
      digitalWrite ( in3F , HIGH ) ;
      digitalWrite (in4F , LOW ) ;
      digitalWrite ( in1B , HIGH ) ;
      digitalWrite (in2B , LOW ) ;
      digitalWrite ( in3B , HIGH ) ;
      digitalWrite (in4B , LOW ) ;
      analogWrite ( enBB , Speed2 ) ;
      analogWrite ( enAB , Speed2 ) ;
      analogWrite ( enAF , Speed2 ) ;
      analogWrite ( enBF , Speed2 ) ;
    }

    if (!digitalRead(RS) && digitalRead(LS))
    {
      digitalWrite ( in1F , HIGH ) ;
      digitalWrite (in2F , LOW ) ;
      digitalWrite ( in3F , LOW ) ;
      digitalWrite (in4F , LOW ) ;
      digitalWrite ( in1B , HIGH ) ;
      digitalWrite (in2B , LOW ) ;
      digitalWrite ( in3B , LOW ) ;
      digitalWrite (in4B , LOW ) ;
      analogWrite ( enBB , Speed ) ;
      analogWrite ( enAB , Speed ) ;
      analogWrite ( enAF , Speed ) ;
      analogWrite ( enBF , Speed ) ;
    }

    if (digitalRead(RS) && !digitalRead(LS))
    {
      digitalWrite ( in1F , LOW ) ;
      digitalWrite (in2F , LOW ) ;
      digitalWrite ( in3F , HIGH ) ;
      digitalWrite (in4F , LOW ) ;
      digitalWrite ( in1B , LOW ) ;
      digitalWrite (in2B , LOW ) ;
      digitalWrite ( in3B , HIGH ) ;
      digitalWrite (in4B , LOW ) ;
      analogWrite ( enBB , Speed ) ;
      analogWrite ( enAB , Speed ) ;
      analogWrite ( enAF , Speed ) ;
      analogWrite ( enBF , Speed ) ;
    }

    if (digitalRead(RS) && digitalRead(LS))
    {
      digitalWrite ( in1F , LOW ) ;
      digitalWrite (in2F , LOW ) ;
      digitalWrite ( in3F , LOW ) ;
      digitalWrite (in4F , LOW ) ;
      digitalWrite ( in1B , LOW ) ;
      digitalWrite (in2B , LOW ) ;
      digitalWrite ( in3B , LOW ) ;
      digitalWrite (in4B , LOW ) ;
      analogWrite ( enBB , 0 ) ;
      analogWrite ( enAB , 0 ) ;
      analogWrite ( enAF , 0 ) ;
      analogWrite ( enBF , 0 ) ;

      delay (3000) ;

      for ( int i = 0 ; i < 10 ; i++ )
      {
        myStepper.step(-stepsPerRevolution);
      }

      break ;
    }
  }

  delay (7000) ;

  digitalWrite ( in2F , HIGH ) ;
  digitalWrite (in1F , LOW ) ;
  digitalWrite ( in4F , HIGH ) ;
  digitalWrite (in3F , LOW ) ;
  digitalWrite ( in2B , HIGH ) ;
  digitalWrite (in1B , LOW ) ;
  digitalWrite ( in4B , HIGH ) ;
  digitalWrite (in3B , LOW ) ;
  analogWrite ( enBB , Speed2 ) ;
  analogWrite ( enAB , Speed2 ) ;
  analogWrite ( enAF , Speed2 ) ;
  analogWrite ( enBF , Speed2 ) ;

  delay (1500) ;

  digitalWrite ( in1F , HIGH ) ;
  digitalWrite (in2F , LOW ) ;
  digitalWrite ( in3F , LOW ) ;
  digitalWrite (in4F , HIGH ) ;
  digitalWrite ( in1B , HIGH ) ;
  digitalWrite (in2B , LOW ) ;
  digitalWrite ( in3B , LOW ) ;
  digitalWrite (in4B , HIGH ) ;
  analogWrite ( enBB , Speed1 ) ;
  analogWrite ( enAB , Speed1 ) ;
  analogWrite ( enAF , Speed1 ) ;
  analogWrite ( enBF , Speed1 ) ;

  delay (1000) ;

  while (1)
  {
    if (!digitalRead(BS1))
    {
      digitalWrite ( in1F , HIGH ) ;
      digitalWrite (in2F , LOW ) ;
      digitalWrite ( in3F , LOW ) ;
      digitalWrite (in4F , HIGH ) ;
      digitalWrite ( in1B , HIGH ) ;
      digitalWrite (in2B , LOW ) ;
      digitalWrite ( in3B , LOW ) ;
      digitalWrite (in4B , HIGH ) ;
      analogWrite ( enBB , Speed1 ) ;
      analogWrite ( enAB , Speed1 ) ;
      analogWrite ( enAF , Speed1 ) ;
      analogWrite ( enBF , Speed1 ) ;
    }
    else
    {
      digitalWrite ( in1F , LOW ) ;
      digitalWrite (in2F , LOW ) ;
      digitalWrite ( in3F , LOW ) ;
      digitalWrite (in4F , LOW ) ;
      digitalWrite ( in1B , LOW ) ;
      digitalWrite (in2B , LOW ) ;
      digitalWrite ( in3B , LOW ) ;
      digitalWrite (in4B , LOW ) ;
      analogWrite ( enBB , 0 ) ;
      analogWrite ( enAB , 0 ) ;
      analogWrite ( enAF , 0 ) ;
      analogWrite ( enBF , 0 ) ;
      delay (2000) ;
      break ;
    }
  }

  while (1)
  {
    if (!digitalRead(RS) && !digitalRead(LS))
    {
      digitalWrite ( in1F , HIGH ) ;
      digitalWrite (in2F , LOW ) ;
      digitalWrite ( in3F , HIGH ) ;
      digitalWrite (in4F , LOW ) ;
      digitalWrite ( in1B , HIGH ) ;
      digitalWrite (in2B , LOW ) ;
      digitalWrite ( in3B , HIGH ) ;
      digitalWrite (in4B , LOW ) ;
      analogWrite ( enBB , Speed2 ) ;
      analogWrite ( enAB , Speed2 ) ;
      analogWrite ( enAF , Speed2 ) ;
      analogWrite ( enBF , Speed2 ) ;
    }

    if (!digitalRead(RS) && digitalRead(LS))
    {
      digitalWrite ( in1F , HIGH ) ;
      digitalWrite (in2F , LOW ) ;
      digitalWrite ( in3F , LOW ) ;
      digitalWrite (in4F , LOW ) ;
      digitalWrite ( in1B , HIGH ) ;
      digitalWrite (in2B , LOW ) ;
      digitalWrite ( in3B , LOW ) ;
      digitalWrite (in4B , LOW ) ;
      analogWrite ( enBB , Speed ) ;
      analogWrite ( enAB , Speed ) ;
      analogWrite ( enAF , Speed ) ;
      analogWrite ( enBF , Speed ) ;
    }

    if (digitalRead(RS) && !digitalRead(LS))
    {
      digitalWrite ( in1F , LOW ) ;
      digitalWrite (in2F , LOW ) ;
      digitalWrite ( in3F , HIGH ) ;
      digitalWrite (in4F , LOW ) ;
      digitalWrite ( in1B , LOW ) ;
      digitalWrite (in2B , LOW ) ;
      digitalWrite ( in3B , HIGH ) ;
      digitalWrite (in4B , LOW ) ;
      analogWrite ( enBB , Speed ) ;
      analogWrite ( enAB , Speed ) ;
      analogWrite ( enAF , Speed ) ;
      analogWrite ( enBF , Speed ) ;
    }

    if (digitalRead(RS) && digitalRead(LS))
    {
      digitalWrite ( in1F , LOW ) ;
      digitalWrite (in2F , LOW ) ;
      digitalWrite ( in3F , LOW ) ;
      digitalWrite (in4F , LOW ) ;
      digitalWrite ( in1B , LOW ) ;
      digitalWrite (in2B , LOW ) ;
      digitalWrite ( in3B , LOW ) ;
      digitalWrite (in4B , LOW ) ;
      analogWrite ( enBB , 0 ) ;
      analogWrite ( enAB , 0 ) ;
      analogWrite ( enAF , 0 ) ;
      analogWrite ( enBF , 0 ) ;

      delay (3000) ;
      break ;
    }
  }

  while (1)
  {
    if (!digitalRead(BS1))
    {
      digitalWrite ( in1F , HIGH ) ;
      digitalWrite (in2F , LOW ) ;
      digitalWrite ( in3F , LOW ) ;
      digitalWrite (in4F , HIGH ) ;
      digitalWrite ( in1B , HIGH ) ;
      digitalWrite (in2B , LOW ) ;
      digitalWrite ( in3B , LOW ) ;
      digitalWrite (in4B , HIGH ) ;
      analogWrite ( enBB , Speed1 ) ;
      analogWrite ( enAB , Speed1 ) ;
      analogWrite ( enAF , Speed1 ) ;
      analogWrite ( enBF , Speed1 ) ;
    }
    else
    {
      digitalWrite ( in1F , LOW ) ;
      digitalWrite (in2F , LOW ) ;
      digitalWrite ( in3F , LOW ) ;
      digitalWrite (in4F , LOW ) ;
      digitalWrite ( in1B , LOW ) ;
      digitalWrite (in2B , LOW ) ;
      digitalWrite ( in3B , LOW ) ;
      digitalWrite (in4B , LOW ) ;
      analogWrite ( enBB , 0 ) ;
      analogWrite ( enAB , 0 ) ;
      analogWrite ( enAF , 0 ) ;
      analogWrite ( enBF , 0 ) ;
      delay (2000) ;
      break ;
    }
  }
  delay (15000) ;
}
