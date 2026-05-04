const int POT_PIN = A0;
const int LED_PIN = 9;

float filteredVal = 0.0;
const float ALPHA = 0.1;

void setup() {
    pinMode(LED_PIN, OUTPUT);
    Serial.begin(115200);
}

void loop() {
    int raw = analogRead(POT_PIN);

    filteredVal = ALPHA * raw + (1 - ALPHA) * filteredVal;

    // 映射到 PWM 范围 0~255
    int brightness = map((int)filteredVal, 0, 1023, 0, 255);
    analogWrite(LED_PIN, brightness);

    // 输出两列数据：原始值, 滤波值（用于串口绘图器）
    Serial.print(raw);
    Serial.print(",");
    Serial.println((int)filteredVal);

    delay(10); // 控制采样率，同时让绘图器刷新可读
}
