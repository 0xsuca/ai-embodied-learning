// 定义连接到ULN2003的Arduino引脚，可按你的接线修改
// int apin = 8; // 橙色线
// int bpin = 9; // 粉色线 或 黄色线 (注意线序)
// int cpin = 10; // 黄色线 或 粉色线
// int dpin = 11; // 蓝色线

// int delaytime = 20000; // 每步之间的延时 (微秒)，决定转速

// void setup() {
//   // 初始化所有引脚为输出
//   pinMode(apin, OUTPUT);
//   pinMode(bpin, OUTPUT);
//   pinMode(cpin, OUTPUT);
//   pinMode(dpin, OUTPUT);
// }

// void loop() {
//   // 8拍模式的驱动序列，逐个发送脉冲
//   digitalWrite(apin, HIGH);
//   delayMicroseconds(delaytime);
//   digitalWrite(apin, LOW);

//   digitalWrite(bpin, HIGH);
//   delayMicroseconds(delaytime);
//   digitalWrite(bpin, LOW);

//   digitalWrite(cpin, HIGH);
//   delayMicroseconds(delaytime);
//   digitalWrite(cpin, LOW);

//   digitalWrite(dpin, HIGH);
//   delayMicroseconds(delaytime);
//   digitalWrite(dpin, LOW);
// }

#include <Servo.h>

Servo myservo;
//舵机

const int pot_pin = A0;
const int pwm_pin = 9;



float filter_pot = 0.0;
float ratio = 0.1;
void setup(){
    pinMode(pwm_pin, OUTPUT);
    myservo.attach(pwm_pin);
    Serial.begin(115200);
}

void loop(){
    // 0-1023 map to 0-180,
    int row_pot = analogRead(pot_pin);

    filter_pot = row_pot * ratio + filter_pot * (1 - ratio);

    int filter_angle =  map((int)filter_pot, 0, 1023, 0, 180);

    myservo.write(filter_angle);

}
