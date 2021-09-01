//定义电机引脚
int Left_f = 8;
int Left_s = 7;
int Right_f = 2;
int Right_s = 4;
int Left_go = 6;
int Right_go = 5;
void go_straight() {//直行
  digitalWrite(Left_f, HIGH);
  digitalWrite(Left_s, LOW);
  digitalWrite(Right_f, HIGH);
  digitalWrite(Right_s, LOW);
  analogWrite(Left_go, 50);
  analogWrite(Right_go, 50);
}
void Stop() {//停止
  digitalWrite(Left_f, LOW);
  digitalWrite(Left_s, LOW);
  digitalWrite(Right_f, LOW);
  digitalWrite(Right_s, LOW);
  analogWrite(Left_go, 0);
  analogWrite(Right_go, 0);
}
void turn_left() {//左转小调
  digitalWrite(Left_f, LOW);
  digitalWrite(Left_s, HIGH);
  digitalWrite(Right_f, HIGH);
  digitalWrite(Right_s, LOW);
  analogWrite(Left_go, 30);
  analogWrite(Right_go, 50);
}
void turn_right() {//右转小调
  digitalWrite(Left_f, HIGH);
  digitalWrite(Left_s, LOW);
  digitalWrite(Right_f, LOW);
  digitalWrite(Right_s, HIGH);
  analogWrite(Left_go, 50);
  analogWrite(Right_go, 30);
}
void turn_left_90(){//左转直角
  digitalWrite(Left_f, LOW);
  digitalWrite(Left_s, LOW);
  digitalWrite(Right_f, HIGH);
  digitalWrite(Right_s, LOW);
  analogWrite(Left_go, 0);
  analogWrite(Right_go, 50);
}
void turn_right_90(){//右转直角
  digitalWrite(Left_f, HIGH);
  digitalWrite(Left_s, LOW);
  digitalWrite(Right_f, LOW);
  digitalWrite(Right_s, LOW);
  analogWrite(Left_go, 50);
  analogWrite(Right_go, 0);
}
void turn_left_stop() {//原地左转
  digitalWrite(Left_f, LOW);
  digitalWrite(Left_s, HIGH);
  digitalWrite(Right_f, HIGH);
  digitalWrite(Right_s, LOW);
  analogWrite(Left_go, 50);
  analogWrite(Right_go, 50);
}
void turn_right_stop() {//原地右转
  digitalWrite(Left_f, HIGH);
  digitalWrite(Left_s, LOW);
  digitalWrite(Right_f, LOW);
  digitalWrite(Right_s, HIGH);
  analogWrite(Left_go, 50);
  analogWrite(Right_go, 50);
}
void stop(){//停止
  analogWrite(Left_go,0);
  analogWrite(Right_go,0);
  digitalWrite(Left_f,LOW);
  digitalWrite(Left_s, LOW);
  digitalWrite(Right_f,LOW);
  digitalWrite(Right_s, LOW);
}
void key_scan() {//按键检测
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
  //电机输出
  pinMode(Left_f, OUTPUT);
  pinMode(Left_s, OUTPUT);
  pinMode(Right_f, OUTPUT);
  pinMode(Right_s, OUTPUT);
  pinMode(Left_go, OUTPUT);
  pinMode(Right_go, OUTPUT);
  //按钮和灰度传感器输入
  pinMode(A0, INPUT);
  pinMode(A2, INPUT);
  pinMode(A1, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  //初始设置高电平
  digitalWrite(A0, HIGH);
}
void xunji(){//巡线
  while(1){
    if (digitalRead(A2) && !digitalRead(A1) && !digitalRead(A3) && digitalRead(A4) ) {
      go_straight();//1001直行
    }
    else if (digitalRead(A2) && !digitalRead(A1) &&  digitalRead(A3) && digitalRead(A4)) {
      turn_left();//1011左小调
    }
    else if (digitalRead(A2) && digitalRead(A1) && !digitalRead(A3) && digitalRead(A4)) {
      turn_right();//1101右小调
    }
    else if (digitalRead(A2) && digitalRead(A1) && digitalRead(A3) && !digitalRead(A4)) {
      turn_right();//1110右小调
    }
    else if (!digitalRead(A2) && digitalRead(A1) && digitalRead(A3) && digitalRead(A4)) {
      turn_left();//0111左小调
    }
    else if (!digitalRead(A2) && !digitalRead(A1) && digitalRead(A3) && digitalRead(A4)) {
      turn_left_stop();//0011左转锐角
    }
    else if (!digitalRead(A2) && digitalRead(A1) && !digitalRead(A3) && digitalRead(A4)) {
      turn_left_stop();//0101左转锐角
    }
    else if (digitalRead(A2) && !digitalRead(A1) && digitalRead(A3) && !digitalRead(A4)) {
      turn_right_stop();//1010右转锐角
    }
    else  if (digitalRead(A2) && digitalRead(A1) && !digitalRead(A3) && !digitalRead(A4)) {
      turn_right_stop();//1100右转锐角
    }
    else if (!digitalRead(A2) && !digitalRead(A1) && !digitalRead(A3) && digitalRead(A4)) {
      turn_left_90();//0001左转直角
    }
    else if (digitalRead(A2) && !digitalRead(A1) && !digitalRead(A3) && !digitalRead(A4)) {
      turn_right_90();//1000右转直角
    }
    else if (!digitalRead(A2) && !digitalRead(A1) && !digitalRead(A3) && !digitalRead(A4)) {
      go_straight();//0000十字路口
    }
  }
}
void loop() {
  // put your main code here, to run repeatedly:
  key_scan();
  while (1) {
    xunji();
  }
}
