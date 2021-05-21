const int SampleCount = 300;  // At 8900 samples per second, about 2 cycles of 60 Hz.
int Samples[SampleCount];


void setup()
{
  Serial.begin(115200);
}


void loop() {
  Serial.println(analogRead(A0));
  delay(21);
}
