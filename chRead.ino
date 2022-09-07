//void chRead() {
//  for (int i = 0; i < 6; i++) {
//
//    chRow[i] = pulseIn(chPin[i], HIGH);
//
//    if (chMax[i] < chRow[i])
//      chMax[i] = chRow[i];
//    if (chMin[i] > chRow[i])
//      chMin[i] = chRow[i];
//
//
//    ch[i] = map(chRow[i], chMin[i], chMax[i], 0, 510);
//    ch[i] = ch[i] - 255;
//
//    if ((ch[i] > -20) && (ch[i] < 20)) {
//      ch[i] = 0;
//    }
//    Serial.print(chRow[i]);
//    Serial.print("\t");
//  }
//  Serial.println();
//}

void sRead() {
  for (int i = 0; i < 2; ++i) {              // This should be 1. not the fucking 6.
    chRow[i] = constrain(pulseIn(chPin[i], HIGH), chMin[i], chMax[i]);
    if (chRow[i] > chMid[i])
      ch[i] = map(chRow[i], chMid[i], chMax[i], 0, maxSpeed);
    else
      ch[i] = map(chRow[i], chMid[i], chMin[i], 0, -maxSpeed);

    if ((ch[i] > -10) && (ch[i] < 10))
      ch[i] = 0;
//    Serial.print(ch[i]);
//    Serial.print('\t');
  }

  chRow[4] = pulseIn(chPin[4], HIGH);
  chRow[5] = pulseIn(chPin[5], HIGH);
  
  if ((chRow[0] == 0) || (chRow[1] == 0) || (chRow[4] == 0) || (chRow[5] == 0))
    battleStart = false;
  else
    battleStart = true;
//  Serial.print(chRow[4]);
//  Serial.print('\t');
//  Serial.println(chRow[5]);
  //  Serial.print(ch[0]);
  //  Serial.print("\t");
  //  Serial.println(ch[1]);
}
