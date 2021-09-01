int PIN_TRIG=13;//发送引脚
int PIN_ECHO=12;//接收引脚
void setup() 
{ 
  Serial.begin(9600);
  pinMode(PIN_TRIG,OUTPUT);//发送引脚输出
  pinMode(PIN_ECHO,INPUT);//接受引脚输入
}
void loop() 
{
  float distance = ultrasonic_distance();
  Serial.print(distance);
  Serial.println(" cm");
}
float ultrasonic_distance(void)
{
  float distance; float duration;
  digitalWrite(PIN_TRIG,LOW);//设置发送引脚为低电平
  delayMicroseconds(2);
  digitalWrite(PIN_TRIG,HIGH);//设置发送引脚为高电平
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG,LOW);//设置发送引脚为低电平，准备下一次测距
  duration = float(pulseIn(PIN_ECHO,HIGH));
  //调用pulseIn函数计算时间，并转换成距离
  /*340m/1s 换算成 34000cm / 1000000 us 经过约分之后,则表示成34cm 
   / 1000 us表示 1us 对应的传输的距离(cm) 由于考虑传输包含发送的距离
   ,故要除以2 */
  distance = (duration * 17)/1000;
  return distance;
}
