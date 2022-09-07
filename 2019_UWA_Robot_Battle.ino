/*int pwm11 = 5;
  int pwm21 = 3;
  int pwm12 = 9;
  int pwm22 = 7;
  int en11 = 4;
  int en21 = 2;
  int en12 = 8;
  int en22 = 6;*/

#define PWM0A   9
#define PWM1A   7
#define PWM0B   5
#define PWM1B   3
#define DIR0A   8
#define DIR1A   6
#define DIR0B   4
#define DIR1B   2

int chPin[6] = {A1, A2, A3, A4, A5, A6};
int chMax[6] = {1848, 1800, 0, 0, 0, 0};
int chMid[6] = {1497, 1502, 0, 0, 0, 0};
int chMin[6] = {1105, 1180, 2500, 2500, 2500, 2500};
int chRow[6];
int ch[6];
int right , left;
int rPower, lPower = 0;
int maxSpeed = 255;
int throtalError = 10;
float kp = 1.5;
bool battleStart = false;

void setup() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  pinMode(PWM0A, OUTPUT);
  pinMode(PWM1A, OUTPUT);
  pinMode(PWM0B, OUTPUT);
  pinMode(PWM1B, OUTPUT);
  pinMode(DIR0A, OUTPUT);
  pinMode(DIR1A, OUTPUT);
  pinMode(DIR0B, OUTPUT);
  pinMode(DIR1B, OUTPUT);
  pinMode(13, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  sRead();
  int go  = ch[1];
  int turn = ch[0];

  rPower = go - turn * kp;
  lPower = go + turn * kp;

  rPower = constrain(rPower, -255, 255);
  lPower = constrain(lPower, -255, 255);

  if (chRow[4] < 1200) {
    rPower = rPower * 55 / 100;
    lPower = lPower * 55 / 100;
  }

  //    Serial.print(lPower);
  //    Serial.print("\t");
  //    Serial.println(rPower);
  
  if ((chRow[5] > 1200) && battleStart)
    drive(lPower, rPower);
  else
    drive(0, 0);

//    Serial.print(rPower);
//    Serial.print("\t");
//    Serial.println(lPower);
  //  if ((chRow[5] > 1485) && (chRow[5] < 1515)) /*digitalWrite(13, HIGH*/drive(50,50); else /*digitalWrite(13, LOW)*/drive(0,0);
  //  if ((chRow[5] > 1485) && (chRow[5] < 1515))
  //    //drive(rPower, lPower);
  //    digitalWrite(13, HIGH);
  //  else
  //    digitalWrite(13, LOW);
  //  drive(0, 0);
}
