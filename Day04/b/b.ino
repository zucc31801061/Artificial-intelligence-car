int Left_f = 8;
int Left_s = 7;
int Right_f = 2;
int Right_s = 4;
int Left_go = 6;
int Right_go = 5;
int key=A0;
void go_straight() {
  digitalWrite(Left_f, HIGH);
  digitalWrite(Left_s, LOW);
  digitalWrite(Right_f, HIGH);
  digitalWrite(Right_s, LOW);
  analogWrite(Left_go, 50);
  analogWrite(Right_go, 50);
}
void Stop() {
  digitalWrite(Left_f, LOW);
  digitalWrite(Left_s, LOW);
  digitalWrite(Right_f, LOW);
  digitalWrite(Right_s, LOW);
  analogWrite(Left_go, 0);
  analogWrite(Right_go, 0);
}
void turn_left() {
  digitalWrite(Left_f, LOW);
  digitalWrite(Left_s, HIGH);
  digitalWrite(Right_f, HIGH);
  digitalWrite(Right_s, LOW);
  analogWrite(Left_go, 0);
  analogWrite(Right_go, 50);
}
void turn_right() {
  digitalWrite(Left_f, HIGH);
  digitalWrite(Left_s, LOW);
  digitalWrite(Right_f, LOW);
  digitalWrite(Right_s, HIGH);
  analogWrite(Left_go, 50);
  analogWrite(Right_go, 0);
}
void back() {
  digitalWrite(Left_f, LOW);
  digitalWrite(Left_s, HIGH);
  digitalWrite(Right_f, LOW);
  digitalWrite(Right_s, HIGH);
  analogWrite(Left_go, 50);
  analogWrite(Right_go, 50);
}
void turn_left_stop() {
  digitalWrite(Left_f, LOW);
  digitalWrite(Left_s, HIGH);
  digitalWrite(Right_f, HIGH);
  digitalWrite(Right_s, LOW);
  analogWrite(Left_go, 50);
  analogWrite(Right_go, 50);
}
void turn_right_stop() {
  digitalWrite(Left_f, HIGH);
  digitalWrite(Left_s, LOW);
  digitalWrite(Right_f, LOW);
  digitalWrite(Right_s, HIGH);
  analogWrite(Left_go, 50);
  analogWrite(Right_go, 50);
}
void key_scan() {
  while (digitalRead(A0));
  while (!digitalRead(A0)) {
    delay(10);
    if (digitalRead(A0) == 0) {
      delay(100);
      while (!digitalRead(A0));
    }
  }
}
void setup() {
  // put your setup code here, to run once:
  pinMode(Left_f, OUTPUT);
  pinMode(Left_s, OUTPUT);
  pinMode(Right_f, OUTPUT);
  pinMode(Right_s, OUTPUT);
  pinMode(Left_go, OUTPUT);
  pinMode(Right_go, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A2, INPUT);
  pinMode(A1, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  digitalWrite(key, HIGH);
}
void xunguang(){
  int SM_1 = digitalRead(A4);
  int SM_2 = digitalRead(A2);
  if (SM_1 == HIGH && SM_2==HIGH ){
        delay(1);
        go_straight();  
       }
  else if(SM_1 ==LOW && SM_2==LOW){
    delay(1);
    Stop();
  }
  else if(SM_1 ==HIGH && SM_2==LOW){
    delay(1);
    turn_left_stop();
  }
  else{
    delay(1);
    turn_right_stop();
  }
}
void loop() {
  // put your main code here, to run repeatedly:
  key_scan();
  while(1){
    xunguang();
  }
}
