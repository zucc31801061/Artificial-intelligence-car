int inpin=A0;//按键引脚
int k;
void setup()
{
  pinMode(LED_BUILTIN,OUTPUT);
  pinMode(inpin,INPUT);
}
int key=A0;
void key_scan()
{
  while(digitalRead(key));//当按键没有被按下时
  while(!digitalRead(key));//当按键被按下时
  {
   delay(10);
   if (digitalRead(key)==LOW)//第二次判断按键是否被按下
   {
     delay(100);
     while(!digitalRead(key));//判断按键是否被松开
   }
  }
}

void blink()
{
  digitalWrite(LED_BUILTIN, HIGH); 
  delay(1000);                     
  digitalWrite(LED_BUILTIN, LOW); 
  delay(1000);                   
}
void loop()
{
  key_scan();
  blink();
} 
