int state;
int values[4][150];

void setup() {
  Serial.begin(250000);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
}

void loop() {
  if (Serial.available()){
    state = Serial.parseInt();
    if (state == 1){z200Load0(); readVoltage();}
    if (state == 2){z400Load0(); readVoltage();}
    if (state == 3){z600Load0(); readVoltage();}
    if (state == 4){z200Load100(); readVoltage();}
    if (state == 5){z400Load100(); readVoltage();}
    if (state == 6){z600Load100(); readVoltage();}
    if (state == 7){z200Load330(); readVoltage();}
    if (state == 8){z400Load330(); readVoltage();}
    if (state == 9){z600Load330(); readVoltage();}
    if (state == 10){z200LoadAll(); readVoltage();}
    if (state == 11){z400LoadAll(); readVoltage();}
    if (state == 12){z600LoadAll(); readVoltage();}
  }
  /*else {
    if (state == 1){z200Load0(); readVoltage();}
    if (state == 2){z400Load0(); readVoltage();}
    if (state == 3){z600Load0(); readVoltage();}
    if (state == 4){z200Load100(); readVoltage();}
    if (state == 5){z400Load100(); readVoltage();}
    if (state == 6){z600Load100(); readVoltage();}
    if (state == 7){z200Load330(); readVoltage();}
    if (state == 8){z400Load330(); readVoltage();}
    if (state == 9){z600Load330(); readVoltage();}
    if (state == 10){z200LoadAll(); readVoltage();}
    if (state == 11){z400LoadAll(); readVoltage();}
    if (state == 12){z600LoadAll(); readVoltage();}
  }*/
  /*static unsigned long lastChrono;
    unsigned long currentChrono = millis();
    if (currentChrono - lastChrono >= 0.5) { // ~100Hz
    Serial.print(analogRead(A1));
    Serial.print(',');
    Serial.print(analogRead(A2));
    Serial.print('\n');
    lastChrono = currentChrono;
    }*/
}

void z200Load0() {
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(5, HIGH);
  }
void z400Load0() {
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(5, HIGH);
  }
void z600Load0() {
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(5, HIGH);
  }
void z200Load100() {
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(5, HIGH);
  }
void z400Load100() {
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, HIGH);
  }
void z600Load100() {
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(5, HIGH);
  }
void z200Load330() {
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(5, LOW);
  }
void z400Load330() {
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(5, LOW);
  }
void z600Load330() {
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(5, LOW);
  }
void z200LoadAll() {
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
  }
void z400LoadAll() {
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
  }
void z600LoadAll() {
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
  }
  
//void readVoltage() {
 //   static unsigned long lastChrono;
   // unsigned long currentChrono = millis();
    //if (currentChrono - lastChrono >= 2) { // ~100Hz
    //Serial.println(analogRead(A1)/* + ", " + analogRead(A2)*/);
    //lastChrono = currentChrono;
    //}
  //}

void readVoltage() {
    for(int i = 0; i<150; i++){
       values[0][i] = analogRead(A0);
       values[1][i] = analogRead(A1);
       values[2][i] = analogRead(A2);
       values[3][i] = analogRead(A3);
      }
    for(int i = 0; i<150; i++){
       Serial.print(values[0][i]);
       Serial.print(',');
       Serial.print(values[1][i]);
       Serial.print(',');
       Serial.print(values[2][i]);
       Serial.print(',');
       Serial.print(values[3][i]);
       Serial.print('\n');
       delay(5);
      }
  }
