void drive(int m1Speed, int m2Speed) {
  setM1Speed(m1Speed);
  setM2Speed(m2Speed);
}

void setM2Speed(int speed) {
  unsigned char reverse = 0;
  if (speed <= 0) {
    speed = -speed;
    reverse = 1;
  }
  if (speed >= 0xFF)
    speed = 0xFF;
  if (reverse) {
    digitalWrite(DIR0B, HIGH);
    digitalWrite(DIR1B, HIGH);
    analogWrite(PWM0B, 0xFF - speed);
    analogWrite(PWM1B, 0xFF - speed);
  }
  else {
    digitalWrite(DIR0B, LOW);
    digitalWrite(DIR1B, LOW);
    analogWrite(PWM0B, speed);
    analogWrite(PWM1B, speed);
  }
}

void setM1Speed(int speed)
{
  unsigned char reverse = 0;
  if (speed <= 0) {
    speed = -speed;
    reverse = 1;
  }
  if (speed >= 0xFF)
    speed = 0xFF;

  if (reverse) {
    digitalWrite(DIR0A, HIGH);
    digitalWrite(DIR1A, HIGH);
    analogWrite(PWM0A, 0xFF - speed);
    analogWrite(PWM1A, 0xFF - speed);
  }
  else {
    digitalWrite(DIR0A, LOW);
    digitalWrite(DIR1A, LOW);
    analogWrite(PWM0A, speed);
    analogWrite(PWM1A, speed);
  }
}
