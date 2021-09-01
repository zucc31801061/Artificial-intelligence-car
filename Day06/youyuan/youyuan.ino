const int Right_motor_go = 2;  //右电机前
const int Right_motor_back = 4;  //右电机后

const int Left_motor_go = 8;  //左电机前
const int Left_motor_back = 7;  //左电机后

const int Left_motor_pwm = 6;  //左电机调速
const int Right_motor_pwm = 5;  //右电机调速
int red = 11;
int green = 10;
int blue = 9;
int huidu;
int k;

void go_straight() {
  digitalWrite(Left_motor_go, HIGH);
  digitalWrite(Left_motor_back, LOW);
  digitalWrite(Right_motor_go, HIGH);
  digitalWrite(Right_motor_back, LOW);
  
  analogWrite(Left_motor_pwm, 50);
  analogWrite(Right_motor_pwm, 50);
}
void Stop() {
  analogWrite(Left_motor_pwm,0);
  analogWrite(Right_motor_pwm,0);
  
  digitalWrite(Left_motor_go,LOW);
  digitalWrite(Right_motor_go, LOW);
  digitalWrite(Left_motor_back,LOW);
  digitalWrite(Right_motor_back, LOW);
}
void turn_left() {
  analogWrite(Left_motor_pwm,7);
  analogWrite(Right_motor_pwm,50);
  
  digitalWrite(Left_motor_go,LOW);
  digitalWrite(Right_motor_go, HIGH);
  digitalWrite(Left_motor_back,HIGH);
  digitalWrite(Right_motor_back, LOW);
}
void turn_right() {
 analogWrite(Left_motor_pwm,50);
  analogWrite(Right_motor_pwm,7);
  
  digitalWrite(Left_motor_go,HIGH);
  digitalWrite(Right_motor_go, LOW);
  digitalWrite(Left_motor_back,LOW);
  digitalWrite(Right_motor_back, HIGH);
}
void back() {
  digitalWrite(Left_motor_go, LOW);
  digitalWrite(Left_motor_back, HIGH);
  digitalWrite(Right_motor_go, LOW);
  digitalWrite(Right_motor_back, HIGH);
  
  analogWrite(Left_motor_pwm,50);
  analogWrite(Right_motor_pwm,50);
}
void turn_left_stop() {
  digitalWrite(Left_motor_go, LOW);
  digitalWrite(Left_motor_back, HIGH);
  digitalWrite(Right_motor_go, HIGH);
  digitalWrite(Right_motor_back, LOW);
  
  analogWrite(Left_motor_pwm, 50);
  analogWrite(Right_motor_pwm, 50);
}
void turn_right_stop() {
  digitalWrite(Left_motor_go, HIGH);
  digitalWrite(Left_motor_back, LOW);
  digitalWrite(Right_motor_go, LOW);
  digitalWrite(Right_motor_back, HIGH);
  analogWrite(Left_motor_pwm,50);
  analogWrite(Right_motor_pwm,50);
}
void select_light(int k){
  switch(k){
    case 1:analogWrite(red,245);analogWrite(green,20);analogWrite(blue,195);break;
    case 2:analogWrite(red,10);analogWrite(green,21);analogWrite(blue,248);break;
    case 3:analogWrite(red,250);analogWrite(green,0);analogWrite(blue,0);break;
    case 4:analogWrite(red,40);analogWrite(green,200);analogWrite(blue,245);break;
    case 5:analogWrite(red,15);analogWrite(green,248);analogWrite(blue,10);break;
    case 6:analogWrite(red,227);analogWrite(green,246);analogWrite(blue,18);break;
    case 7:analogWrite(red,10);analogWrite(green,21);analogWrite(blue,248);break;
    case 8:analogWrite(red,40);analogWrite(green,200);analogWrite(blue,245);break;
    case 9:analogWrite(red,15);analogWrite(green,248);analogWrite(blue,10);break;
    case 10:analogWrite(red,250);analogWrite(green,0);analogWrite(blue,0);break;
    default:break;
  }
}
/*void color( int i ){
  if(i==1){
    analogWrite(red,255);
    analogWrite(green,0);
    analogWrite(blue,255);
  }else if(i==2||i==7){
    analogWrite(red,0);
    analogWrite(green,0);
    analogWrite(blue,255);
  }else if(i==3||i==10){
    analogWrite(red,255);
    analogWrite(green,0);
    analogWrite(blue,0);
  }else if(i==4||i==8){
    analogWrite(red,0);
    analogWrite(green,255);
    analogWrite(blue,255);
  }else if(i==5||i==9){
    analogWrite(red,0);
    analogWrite(green,255);
    analogWrite(blue,0);
  }else if(i==6){
    analogWrite(red,255);
    analogWrite(green,255);
    analogWrite(blue,0);
  }
} */
void select_way(int choice) {       //小车动作
  switch (choice) {
    case 1: delay(200); turn_left_stop(); delay(800); break;
    case 2:  delay(200); turn_right_stop(); delay(800); break;
    case 3: delay(400);
      Stop();
      k++;
      
      select_light(k);
      delay(300);
      digitalWrite(red,LOW);
      digitalWrite(green,LOW);
      digitalWrite(blue, LOW);
      back();
      delay(20);
      while(digitalRead(A2) || digitalRead(A1) ||digitalRead(A3) || digitalRead(A4)){
        delay(10);
      } 
      turn_left_stop();
      delay(400);
       while((digitalRead(A1) ||digitalRead(A3)));
       delay(50);
      go_straight();
      /*
      turn_left_stop();
      delay(1040);
      while((digitalRead(A1) ||digitalRead(A3)));
       delay(50);
       back();
       delay(300);
       Stop();
      k++;
      //select_light(k);
      color(k);
      delay(300);
      digitalWrite(red,LOW);
      digitalWrite(green,LOW);
      digitalWrite(blue, LOW);
      go_straight();*/
  break;
    case 4: go_straight(); delay(800); break;
  }
}
void Begin() {                   //按钮
  while (digitalRead(A0));
  while (!digitalRead(A0)) {
    delay(10);
    if (digitalRead(A0) == 0) {
      delay(100);
      while (!digitalRead(A0));
      
    }
  }
}
//1;左转   2：右转   3,：转身   4：直走
int a[37] = {2, 1, 2, 3, 2, 4, 3, 2, 2, 2, 3, 4, 4, 3, 2, 1, 1, 3, 1, 3, 1, 1, 1, 2, 3, 2, 2, 3, 2, 2, 3,2, 1, 3, 1, 2};
int i = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(Left_motor_go, OUTPUT);
  pinMode(Left_motor_back, OUTPUT);
  pinMode(Right_motor_go, OUTPUT);
  pinMode(Right_motor_back, OUTPUT);
  pinMode(Left_motor_pwm, OUTPUT);
  pinMode(Right_motor_pwm, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A2, INPUT);
  pinMode(A1, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Begin();
  while (1) {

    if (digitalRead(A2) && !digitalRead(A1) && !digitalRead(A3) && digitalRead(A4) ) {
      go_straight();
    }
    else if (digitalRead(A2) && !digitalRead(A1) &&  digitalRead(A3) && digitalRead(A4)) {
      turn_left();
    }
    else if (digitalRead(A2) && digitalRead(A1) && !digitalRead(A3) && digitalRead(A4)) {
      turn_right();

    }
    else if (digitalRead(A2) && digitalRead(A1) && digitalRead(A3) && !digitalRead(A4)) {
      turn_right();
      delay(30);
    }
    else if (!digitalRead(A2) && digitalRead(A1) && digitalRead(A3) && digitalRead(A4)) {
      turn_left();
      delay(30);
    }
    else if (!digitalRead(A2) && !digitalRead(A1) && digitalRead(A3) && digitalRead(A4)) {
      delay(40);
      turn_left_stop();
    }
    else if (!digitalRead(A2) && digitalRead(A1) && !digitalRead(A3) && digitalRead(A4)) {
      delay(40);
      turn_left_stop();
    }
    else if (digitalRead(A2) && !digitalRead(A1) && digitalRead(A3) && !digitalRead(A4)) {
      delay(40);
      turn_right_stop();
    }
    else  if (digitalRead(A2) && digitalRead(A1) && !digitalRead(A3) && !digitalRead(A4)) {
      delay(40);
      turn_right_stop();
    }
    else if (!digitalRead(A2) && !digitalRead(A1) && !digitalRead(A3) && digitalRead(A4)) {
      select_way(a[i]);
      i++;
    }
    else if (digitalRead(A2) && !digitalRead(A1) && !digitalRead(A3) && !digitalRead(A4)) {
      select_way(a[i]);
      i++;
    }
    else if (!digitalRead(A2) && !digitalRead(A1) && !digitalRead(A3) && !digitalRead(A4)) {
      /*if(a[i-1]==3){
        go_straight();
        continue;
      }*/
      select_way(a[i]);
      i++;
    }
    if (i == 37) {
      go_straight();
      delay(1500);
      Stop();
    }
  }
}
