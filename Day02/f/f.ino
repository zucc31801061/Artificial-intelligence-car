#include<math.h>
//定义引脚
const int DIR1_RIGHT = 2;  //右电机前
const int DIR2_RIGHT = 4;  //右电机后

const int DIR1_LEFT = 8;  //左电机前
const int DIR2_LEFT = 7;  //左电机后

const int PWM_LEFT = 6;  //左电机调速
const int PWM_RIGHT = 5;  //右电机调速

const int LdrSensorLeft=A4;//左边寻光 
const int LdrSensorRight=A2;//右边寻光

int LdrSersorLeftValue ; //光敏电阻采集的数据变量
int LdrSersorRightValue ;

void setup() {
  //设置电机输出
  pinMode(DIR1_RIGHT, OUTPUT);      
  pinMode(DIR2_RIGHT, OUTPUT);  
  pinMode(DIR1_LEFT, OUTPUT);  
  pinMode(DIR2_LEFT, OUTPUT);  
  pinMode(PWM_LEFT, OUTPUT);  
  pinMode(PWM_RIGHT, OUTPUT); 
  //寻光传感器输入
  pinMode(LdrSensorLeft,INPUT);
  pinMode(LdrSensorRight,INPUT);
  //初始设置为高电平
  digitalWrite(LdrSensorLeft,HIGH);
  digitalWrite(LdrSensorRight,HIGH);
}
//电机运动
void motorsWrite(int speedLeft,int speedRight)
{
  digitalWrite(PWM_LEFT,speedLeft);//速度赋值
  digitalWrite(PWM_RIGHT,speedRight);
  if(speedRight>0) 
  {
    digitalWrite(DIR1_RIGHT, 1);
    digitalWrite(DIR2_RIGHT, 0);
  }
  else
  {
    digitalWrite(DIR1_RIGHT, 0);
    digitalWrite(DIR2_RIGHT, 1);
  }
  analogWrite(PWM_RIGHT, abs(speedRight));//光强度改变速度
  if(speedLeft > 0)
  {
    digitalWrite(DIR1_LEFT,1);
    digitalWrite(DIR2_LEFT,0);
  }
  else
  {
    digitalWrite(DIR1_LEFT,0);
    digitalWrite(DIR2_LEFT,1);
  }
  analogWrite(PWM_LEFT, abs(speedLeft));
}
//左转
void motorLeft()
{
   motorsWrite(0,80);  
}
//右转
void motorRight()
{
  motorsWrite(80,0);
}
//停止
void stopMotor()
{
  motorsWrite(0,0);
}
void loop(){
  //遇到光线,寻光模块的指示灯灭,端口电平为HIGH
  //未遇光线,寻光模块的指示灯亮,端口电平为LOW
  LdrSersorRightValue = digitalRead(LdrSensorRight);
  LdrSersorLeftValue  = digitalRead(LdrSensorLeft);
 
  if(LdrSersorLeftValue==HIGH && LdrSersorRightValue==HIGH)
  {
    motorsWrite(80,80);//两侧均有光时信号为HIGH，小车前进
  }
  else if(LdrSersorLeftValue == HIGH && LdrSersorRightValue == LOW)
  {
motorLeft();//左边探测到有光，向左转  
}
  else if(LdrSersorRightValue == HIGH && LdrSersorLeftValue == LOW)
  {
    motorRight();//右边探测到有光，向右转
  }
  else
  {
    stopMotor();//停止
  }
}
