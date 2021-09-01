int FM=A0;
void setup() {
  pinMode(FM, OUTPUT);
}
void loop() {
  digitalWrite(LED_BUILTIN, HIGH); 
  delay(1000);                     
  digitalWrite(LED_BUILTIN, LOW); 
  delay(1000);                   
}
