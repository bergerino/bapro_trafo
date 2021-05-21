int valArray[500];
int state;

void setup() {
  Serial.begin(115200);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(A0, INPUT);
}

void loop() {
  if (Serial.available()){
    state = Serial.parseInt();
    if (state == 2){z200(); readVoltage();}
    if (state == 4){z400(); readVoltage();}
    if (state == 6){z600(); readVoltage();}
  }
  else {
    if (state == 2){z200(); readVoltage();}
    if (state == 4){z400(); readVoltage();}
    if (state == 6){z600(); readVoltage();}
  }
}

void z200() {
    delay(100);
    digitalWrite(7, HIGH);
    delay(100);
    digitalWrite(8, HIGH);
  }
void z400() {
    delay(100);
    digitalWrite(7, LOW);
    delay(100);
    digitalWrite(8, LOW);
  }
void z600() {
    delay(100);
    digitalWrite(7, HIGH);
    delay(100);
    digitalWrite(8, LOW);
  }
  
void readVoltage() {
    static unsigned long lastChrono;
    unsigned long currentChrono = millis();
    if (currentChrono - lastChrono >= 2) { // ~100Hz
    Serial.println(analogRead(A0));
    lastChrono = currentChrono;
    }
  }
    
