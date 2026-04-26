int pin_input = 2;
int pin_output = 13;
//button state enum
enum ButtonState{IDLE, DEBOUNCED, PRESSED, RELEASED};
ButtonState buttonState = IDLE;

//time variable
const unsigned long longest_pressed_time_threshold = 1000;
const unsigned long debounced_time_threshold = 30;
unsigned long last_press_time = 0;
unsigned long last_debouce_time = 0;
//other state
bool led_state = LOW;
bool current_read_signal = HIGH;
bool last_read_signal = LOW;
bool longPressedTrigger = false;


void setup(){
    pinMode(pin_input, INPUT_PULLUP);
    pinMode(pin_output, OUTPUT);
    digitalWrite(pin_output, led_state);
    Serial.begin(115200);

}
void loop() {
    unsigned long current = millis();
    current_read_signal = digitalRead(pin_input);

    switch(buttonState) {
        case IDLE:
            if(current_read_signal == LOW) {
                buttonState = DEBOUNCED;
                last_debouce_time = current;
            }
            break;

        case DEBOUNCED:
            // 修正 √：用 current - last_debouce_time
            if(current - last_debouce_time >= debounced_time_threshold) {
                if(digitalRead(pin_input) == LOW) {
                    buttonState = PRESSED;
                    last_press_time = current;
                    Serial.println("Button Pressed");
                } else {
                    buttonState = IDLE;
                }
            }
            break;

        case PRESSED:
            if(digitalRead(pin_input) == HIGH) {
                buttonState = RELEASED;
                last_debouce_time = current;
            } else {
                // 修正 √：用 current - last_press_time
                if(!longPressedTrigger && (current - last_press_time >= longest_pressed_time_threshold)) {
                    longPressedTrigger = true;
                    led_state = LOW;
                    digitalWrite(pin_output, led_state);
                    Serial.println("Long Press -> LED OFF");
                }
            }
            break;

        case RELEASED:
            // 修正 √：用 current - last_debouce_time
            if(current - last_debouce_time >= debounced_time_threshold) {
                if(digitalRead(pin_input) == HIGH) {
                    if (!longPressedTrigger) {
                        led_state = !led_state;
                        digitalWrite(pin_output, led_state);
                        Serial.println("Short Press -> Toggle LED");
                    }
                    buttonState = IDLE;
                    longPressedTrigger = false; // 每次按键释放后重置长按标记
                } else {
                    buttonState = PRESSED;
                }
            }
            break;
    }

    last_read_signal = current_read_signal;
}
