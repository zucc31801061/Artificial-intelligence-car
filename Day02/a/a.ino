int redd=11;//红灯引脚为11
int greend=10;//绿灯引脚为10
int blued=9;//蓝灯引脚为9
void setup() {
  // put your setup code here, to run once:
  pinMode(redd,OUTPUT);
  pinMode(greend,OUTPUT);
  pinMode(blued,OUTPUT);
  //设置彩灯引脚为输出模式
}
void led(unsigned char red,unsigned char green,unsigned char blue)
{
  analogWrite(redd,red);//analogWrite函数通过PWM的方式在引脚上输出一个模拟量，控制LED亮度
  analogWrite(blued,blue);
  analogWrite(greend,green);
}
void loop() {
  // put your main code here, to run repeatedly:
  led(0,255,255);//调用led函数，点亮红灯
  delay(1000);//持续1000ms
  led(255,0,255);//点亮绿灯
  delay(1000);
  led(255,255,0);//点亮蓝灯
  delay(1000);
}
