#include <Servo.h>
Servo myservo;
int pos = 3;    // 舵机引脚
void setup()
{
  myservo.attach(3);  //定义舵机接口
}  
void loop()
{ 
for(pos = 0; pos < 180; pos += 1)  //从0度到180度
{                                      
  myservo.write(pos);    // 设定舵机旋转角度
  delay(15); //等待15ms舵机到达指定位置
  }
  for(pos = 180; pos>=1; pos-=1)// 从180度到0度
  {                               
    myservo.write(pos);              
    delay(15);
  }
}
