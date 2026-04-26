unsigned long previous_A = 0;
unsigned long previous_B = 0;
const int led_A = 4;
int state_A = LOW;
const unsigned long delayTime_A_low = 200;
const unsigned long delayTime_A_high = 200;

const int led_B = 8;
int state_B = LOW;
const unsigned long delayTime_B_low = 300;
const unsigned long delayTime_B_high = 700;


void setup(){
    Serial.begin(9600);
    pinMode(led_A, OUTPUT);
    pinMode(led_B, OUTPUT);
}
void loop(){
    unsigned long current = millis();
    if(state_A == LOW){
        if(current - previous_A >= delayTime_A_low ){
            previous_A = current;
            digitalWrite(led_A, HIGH);
        }
    }else{
        if(current - previous_A >= delayTime_A_high ){
            previous_A = current;
            digitalWrite(led_A, LOW);
        }
    }

    if(state_B == LOW){
        if(current - previous_B >= delayTime_B_low ){
            previous_B = current;
            digitalWrite(led_B, HIGH);
        }
    }else{
        if(current - previous_B >= delayTime_B_high ){
            previous_B = current;
            digitalWrite(led_B, LOW);
            Serial.print(state_B);
        }
    }

}
