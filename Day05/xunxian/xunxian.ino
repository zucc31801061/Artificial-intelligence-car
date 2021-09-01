#define Left1 A2   //定义巡线传感器的引脚
#define Left2 A1
#define Right1 A3
#define Right2 A4

#define key A0 //按键的引脚

const int Right_motor_go = 2;  //右电机前
const int Right_motor_back = 4;  //右电机后

const int Left_motor_go = 8;  //左电机前
const int Left_motor_back = 7;  //左电机后

const int Left_motor_pwm = 6;  //左电机调速
const int Right_motor_pwm = 5;  //右电机调速
void setup() {
  // 电机的输出
  pinMode(Left_motor_go, OUTPUT);      
  pinMode(Left_motor_back, OUTPUT);  
  pinMode(Right_motor_back, OUTPUT);  
  pinMode(Right_motor_go, OUTPUT);  
  pinMode(Left_motor_pwm, OUTPUT);  
  pinMode(Right_motor_pwm, OUTPUT); 

  pinMode(key,INPUT);

  pinMode(Left1,INPUT);
  pinMode(Left2,INPUT);
  pinMode(Right1,INPUT);
  pinMode(Right2,INPUT);
}
//控制小车
void Startcar(){
  while(1){
 if((digitalRead(Left1)==HIGH&&digitalRead(Left2)==LOW&&digitalRead(Right1)==LOW&&digitalRead(Right2)==HIGH)||(digitalRead(Left1)==LOW&&digitalRead(Left2)==LOW&&digitalRead(Right1)==LOW&&digitalRead(Right2)==LOW)){
     straight();    //直走
     
   }
   else if(digitalRead(Left1)==HIGH&&digitalRead(Left2)==LOW&&digitalRead(Right1)==HIGH&&digitalRead(Right2)==HIGH){
     turnleft2();
     //左转
   }
   else if(digitalRead(Left1)==HIGH&&digitalRead(Left2)==HIGH&&digitalRead(Right1)==LOW&&digitalRead(Right2)==HIGH){
     turnright2(); //右转  
     
   }
   else if(digitalRead(Left1)==LOW&&digitalRead(Left2)==LOW&&digitalRead(Right1)==LOW&&digitalRead(Right2)==HIGH){
    
     turnleft1();   //左转直角
    
   }
   else if(digitalRead(Left1)==HIGH&&digitalRead(Left2)==LOW&&digitalRead(Right1)==LOW&&digitalRead(Right2)==LOW){
    
    turnright1();   //右转直角
    
   }
   //左转锐角
   else if(digitalRead(Left1)==LOW&&digitalRead(Left2)==LOW&&digitalRead(Right1)==LOW&&digitalRead(Right2)==HIGH){
     turnleft2();
     
   }
   else if(digitalRead(Left1)==LOW&&digitalRead(Left2)==HIGH&&digitalRead(Right1)==LOW&&digitalRead(Right2)==HIGH){
     turnleft2(); 
     
   }
   else if(digitalRead(Left1)==LOW&&digitalRead(Left2)==LOW&&digitalRead(Right1)==HIGH&&digitalRead(Right2)==HIGH){
     turnleft2(); 
     
   }
   //右转锐角
   else if(digitalRead(Left1)==HIGH&&digitalRead(Left2)==LOW&&digitalRead(Right1)==LOW&&digitalRead(Right2)== LOW){
     turnright2();
     
   }
   else if(digitalRead(Left1)==HIGH&&digitalRead(Left2)==HIGH&&digitalRead(Right1)==LOW&&digitalRead(Right2)==LOW){
     turnright2(); 
     
   }
   else if(digitalRead(Left1)==HIGH&&digitalRead(Left2)==LOW&&digitalRead(Right1)==HIGH&&digitalRead(Right2)==LOW){
     turnright2();
     
   }
   else if(digitalRead(Left1)==HIGH&&digitalRead(Left2)==LOW&&digitalRead(Right1)==LOW&&digitalRead(Right2)==LOW){
     turnright2();
     
   }
   
  }
}
//直线行走
void straight(){
  analogWrite(Left_motor_pwm,110);
  analogWrite(Right_motor_pwm,110);
 
  digitalWrite(Left_motor_go,HIGH);
  digitalWrite(Right_motor_go, HIGH);
  digitalWrite(Left_motor_back,LOW);
  digitalWrite(Right_motor_back, LOW);
}
//左转
void turnleft1(){
  analogWrite(Left_motor_pwm,0);
  analogWrite(Right_motor_pwm,100);
  digitalWrite(Left_motor_go,LOW);
  digitalWrite(Right_motor_go, HIGH);
  digitalWrite(Left_motor_back,LOW);
  digitalWrite(Right_motor_back, LOW);
  
}
//原地左转
void turnleft2(){
  analogWrite(Left_motor_pwm,100);
  analogWrite(Right_motor_pwm,100);
  
  digitalWrite(Left_motor_go,LOW);
  digitalWrite(Right_motor_go, HIGH);
  digitalWrite(Left_motor_back,HIGH);
  digitalWrite(Right_motor_back, LOW);
}
//右转
void turnright1(){
  analogWrite(Left_motor_pwm,100);
  analogWrite(Right_motor_pwm,0);
  
  digitalWrite(Left_motor_go,HIGH);
  digitalWrite(Right_motor_go, LOW);
  digitalWrite(Left_motor_back,LOW);
  digitalWrite(Right_motor_back, LOW);
 
}
//原地右转
void turnright2(){
  analogWrite(Left_motor_pwm,100);
  analogWrite(Right_motor_pwm,100);

  digitalWrite(Left_motor_go,HIGH);
  digitalWrite(Right_motor_go, LOW);
  digitalWrite(Left_motor_back,LOW);
  digitalWrite(Right_motor_back, HIGH);
}
//stop
void stopcar(){
  analogWrite(Left_motor_pwm,0);
  analogWrite(Right_motor_pwm,0);
  
  digitalWrite(Left_motor_go,LOW);
  digitalWrite(Right_motor_go, LOW);
  digitalWrite(Left_motor_back,LOW);
  digitalWrite(Right_motor_back, LOW);
}
//按键控制小车
int val;
void loop() {
  // put your main code here, to run repeatedly:
  val = digitalRead(key);
  if(val==LOW){
    delay(80);
    if(val==LOW){    
        Startcar();
     }
   }  
}
