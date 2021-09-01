int PIN_R = 11;          // 红色LED引脚
int PIN_G = 10;           // 绿色LED引脚
int PIN_B = 9;          // 蓝色LED引脚
int PIN_KEY = A0;         // 按键引脚
int KEY_COUNT = 0;       //选择判断变量
void setup()
{
    pinMode(PIN_R, OUTPUT);
    pinMode(PIN_G, OUTPUT);
    pinMode(PIN_B, OUTPUT); 
    pinMode(PIN_KEY,INPUT); 
}
void loop(){
  ScanKey();
  if(KEY_COUNT==1){
    color(0, 255, 255);   //红色R
    delay(500);
    color(255, 255, 255); //熄灭
    delay(500);
  }
  if(KEY_COUNT==2){
    color(255,0, 255);     //绿色G
    delay(500);
    color(255, 255, 255);  //熄灭
    delay(500);
  }
  if(KEY_COUNT==3){
   color(255, 255, 0);    //蓝色B
   delay(500);
   color(255, 255, 255);  //熄灭
   delay(500);
  }
  if(KEY_COUNT==4){
    color(0,0,255);        // 黄色 RG
    delay(500);
    color(255, 255, 255);  //熄灭
    delay(500);  
  }
  if(KEY_COUNT==5){
    color(0,0,0);     // 白色 RGB
    delay(500);
    color(255, 255, 255);  //熄灭
    delay(500);
  }
  if(KEY_COUNT==6){
    color(0,255,0);       // 紫色 RB
    delay(1000);
    color(255, 255, 255); //熄灭
    delay(500);   
  }
  if(KEY_COUNT==7){
    color(255,0,0);     // 青色 GB
    delay(500);
    color(255, 255, 255);   //熄灭
    delay(500);
  }
  if(KEY_COUNT==8){
    color(255, 255, 255);  // 关闭三基色LED
  }
  if(KEY_COUNT > 7)
  {
   KEY_COUNT = 0;
  }
}
void ScanKey(){ 
  if(digitalRead(PIN_KEY)==LOW){
    delay(20);
    if(digitalRead(PIN_KEY)==LOW){
      KEY_COUNT++;
      while(digitalRead(PIN_KEY)==LOW);
      }
   }
}
void color (unsigned char red, unsigned char green, unsigned char blue){     //颜色控制函数
  analogWrite(PIN_R, 255-red);
  analogWrite(PIN_G, 255-green);
  analogWrite(PIN_B, 255-blue);
} 
