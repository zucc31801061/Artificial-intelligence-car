int inByte;
void setup()
{
  Serial.begin(9600);
  pinMode(LED_BUILTIN,OUTPUT);
}
void loop()
{
  if(Serial.available()>0)//判断是否有数据
  {
    inByte=Serial.read();
    if(inByte=='K')
    {
      digitalWrite(LED_BUILTIN,HIGH);
    }
    if(inByte=='G')
    {
      digitalWrite(LED_BUILTIN,LOW);
    }
  }
}
