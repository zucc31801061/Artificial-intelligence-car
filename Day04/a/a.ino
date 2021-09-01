int pin1 = 8;
int pin2 = 7;
int pwm1 = 6;
int pin3 = 2;
int pin4 = 4;
int pwm2 = 5;
int key =A0;

int Sensorl_1 = A3;//红外
int Sensorr_1 = A1;

void setup() {
  // put your setup code here, to run once:
   pinMode(pin1,OUTPUT);
  pinMode(pin2,OUTPUT);
  pinMode(pwm1,OUTPUT);
  pinMode(pin3,OUTPUT);
  pinMode(pin4,OUTPUT);
  pinMode(pwm2,OUTPUT);
  pinMode(key,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  pinMode(A4,INPUT);
  pinMode(Sensorl_1,INPUT);
  pinMode(Sensorr_1,INPUT);
  digitalWrite(key, HIGH);
  Serial.begin(9600);
}
void key_scan()
{
  while (digitalRead(key));       //当按键没有被按下一直循环
  while (!digitalRead(key))       //当按键被按下时
  {
    delay(10);                    //延时10ms
    if (digitalRead(key)  ==  LOW)//第二次判断按键是否被按下
    {
      delay(100);
      while (!digitalRead(key));  //判断按键是否被松开
    }
  }
}
void stop(){
  digitalWrite(pin1,LOW);
  digitalWrite(pin2,LOW);
  digitalWrite(pin3,LOW);
  digitalWrite(pin4,LOW);
  analogWrite(pwm1,0);
  analogWrite(pwm2,0);
  //delay(time*100);
}
void go_ahead(int speed=50){
  digitalWrite(pin1,HIGH);
  digitalWrite(pin2,LOW);
  digitalWrite(pin3,HIGH);
  digitalWrite(pin4,LOW);
  analogWrite(pwm1,speed);
  analogWrite(pwm2,speed);
  //delay(time*100);
}
void back(int speed=50){
  digitalWrite(pin1,LOW);
  digitalWrite(pin2,HIGH);
  digitalWrite(pin3,LOW);
  digitalWrite(pin4,HIGH);
  analogWrite(pwm1,speed);
  analogWrite(pwm2,speed);
  //delay(time*100);
 }
void turnl(int speed=50){
  digitalWrite(pin1,LOW);
  digitalWrite(pin2,LOW);
  digitalWrite(pin3,HIGH);
  digitalWrite(pin4,LOW);
  analogWrite(pwm1,speed);
  //analogWrite(pwm2,0);
  //delay(time*100);
}
void turnr(int speed=50){
  digitalWrite(pin1,HIGH);
  digitalWrite(pin2,LOW);
  digitalWrite(pin3,LOW);
  digitalWrite(pin4,LOW);
  //analogWrite(pwm1,0);
  analogWrite(pwm2,speed);
  //delay(time*100);
}

void ydturnl(int speed=50){
  digitalWrite(pin1,LOW);
  digitalWrite(pin2,HIGH);
  digitalWrite(pin3,HIGH);
  digitalWrite(pin4,LOW);
  analogWrite(pwm1,speed);
  analogWrite(pwm2,speed);
  //delay(time*100);
}
void ydturnr(int speed=50){
  digitalWrite(pin1,HIGH);
  digitalWrite(pin2,LOW);
  digitalWrite(pin3,LOW);
  digitalWrite(pin4,HIGH);
  analogWrite(pwm1,speed);
  analogWrite(pwm2,speed);
  //delay(time*100);
}
void bizhang(){
  int SM_1 = digitalRead(A3);
  int SM_2 = digitalRead(A1);
       if (SM_1 == LOW && SM_2==LOW ){
        delay(1);
        ydturnr();  
       }
       else {
        if (SM_1==HIGH &&SM_2==HIGH)
       {
        delay(1);
        go_ahead();
        
       } 
         else if ( (SM_1 == HIGH) && SM_2 == LOW)
        {
          delay(1);
          ydturnl();
        }
         else if ((SM_1 == LOW) && SM_2 == HIGH) 
        {
          delay(1);
          ydturnr();
        }
         else
        {    
          stop();
        }}}

void loop() {
  // put your main code here, to run repeatedly:
      key_scan();
      while(1){
        bizhang();
      }
}
