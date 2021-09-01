int inByte;
void setup()
{
  Serial.begin(9600);
}
void loop()
{
  if(Serial.available()>0)//判断是否有数据
  {
    inByte=Serial.read();
    Serial.print("I received: ");
    Serial.println(inByte,DEC);
  }
}
