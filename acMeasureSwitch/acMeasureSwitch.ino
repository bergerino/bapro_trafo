int valArray[500];
int state;

void setup() {
  Serial.begin(115200);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(A0, INPUT);
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
  }
  else {
    if (state == 1){z200Load0(); readVoltage();}
    if (state == 2){z400Load0(); readVoltage();}
    if (state == 3){z600Load0(); readVoltage();}
    if (state == 4){z200Load100(); readVoltage();}
    if (state == 5){z400Load100(); readVoltage();}
    if (state == 6){z600Load100(); readVoltage();}
  }
}

void z200Load0() {
    delay(100);
    digitalWrite(7, HIGH);
    delay(100);
    digitalWrite(8, HIGH);
    delay(100);
    digitalWrite(6, HIGH);
  }
void z400Load0() {
    delay(100);
    digitalWrite(7, LOW);
    delay(100);
    digitalWrite(8, LOW);
    delay(100);
    digitalWrite(6, HIGH);
  }
void z600Load0() {
    delay(100);
    digitalWrite(7, HIGH);
    delay(100);
    digitalWrite(8, LOW);
    delay(100);
    digitalWrite(6, HIGH);
  }
void z200Load100() {
    delay(100);
    digitalWrite(7, HIGH);
    delay(100);
    digitalWrite(8, HIGH);
    delay(100);
    digitalWrite(6, LOW);
  }
void z400Load100() {
    delay(100);
    digitalWrite(7, LOW);
    delay(100);
    digitalWrite(8, LOW);
    delay(100);
    digitalWrite(6, LOW);
  }
void z600Load100() {
    delay(100);
    digitalWrite(7, HIGH);
    delay(100);
    digitalWrite(8, LOW);
    delay(100);
    digitalWrite(6, LOW);
  }
  
void readVoltage() {
    static unsigned long lastChrono;
    unsigned long currentChrono = millis();
    if (currentChrono - lastChrono >= 2) { // ~100Hz
    Serial.println(analogRead(A0));
    lastChrono = currentChrono;
    }
  }
    
