int Left_f = 8;
int Left_s = 7;
int Right_f = 2;
int Right_s = 4;
int Left_go = 6;
int Right_go = 5;
int key=A0;

void setup() {
  // put your setup code here, to run once:
  pinMode(Left_f, OUTPUT);
  pinMode(Left_s, OUTPUT);
  pinMode(Right_f, OUTPUT);
  pinMode(Right_s, OUTPUT);
  pinMode(Left_go, OUTPUT);
  pinMode(Right_go, OUTPUT);
  pinMode(A0, INPUT);
  digitalWrite(key, HIGH);

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
void go () {
  digitalWrite(Left_f, HIGH);
  digitalWrite(Left_s, LOW);
  digitalWrite(Right_f, HIGH);
  digitalWrite(Right_s, LOW);
  analogWrite(Left_go, 50);
  analogWrite(Right_go, 50);
}
void loop() {
  // put your main code here, to run repeatedly:
  key_scan();
  while(1){
    go();
  }
}
