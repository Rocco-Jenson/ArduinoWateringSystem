#define LED 13
#define RELAY_1_DIGITAL_PIN 2
#define RELAY_2_DIGITAL_PIN 3
#define MS_1_ANALOG_READ_PIN A0
#define MS_2_ANALOG_READ_PIN A1
#define MS_AIR_VAL 603
#define MS_WATER_VAL 360
#define RELAY_ON LOW    /*(Normally Open Used)*/
#define RELAY_OFF HIGH

void setup() {
  if (Serial) {
    Serial.begin(9600);
  }
  pinMode(RELAY_1_DIGITAL_PIN, OUTPUT);
  pinMode(RELAY_2_DIGITAL_PIN, OUTPUT);
  digitalWrite(RELAY_1_DIGITAL_PIN, RELAY_OFF);
  digitalWrite(RELAY_2_DIGITAL_PIN, RELAY_OFF);
  pinMode(MS_2_ANALOG_READ_PIN, INPUT);
  pinMode(LED, OUTPUT);
  delay(5000);
}

void loop() {
  const char* analog_1 = "A0";
  const char* analog_2 = "A1";
  int soilMoistureVal1 = read_map_print(analog_1);
  int soilMoistureVal2 = read_map_print(analog_2);
  test_sensor(soilMoistureVal1, RELAY_1_DIGITAL_PIN);
  test_sensor(soilMoistureVal2, RELAY_2_DIGITAL_PIN);
}

int read_map_print(const char* pin_value) {
  int soilMoistureVal = analogRead(pin_value);
  int soilMoisturePercent = map(soilMoistureVal, MS_AIR_VAL, MS_WATER_VAL, 0, 100);
  Serial.println(soilMoisturePercent);
  return soilMoisturePercent;
}

void test_sensor(int soilMoisturePercent, int relay_pin) {
  Serial.println(soilMoisturePercent);

  if (soilMoisturePercent >= 75) {              /*if soil >= 75% Flash And Relay Off*/
    digitalWrite(relay_pin, RELAY_OFF);
    flash();
  } else if (soilMoisturePercent <= 50) {       /*if soil <= 50% On And Relay On*/
    digitalWrite(relay_pin, RELAY_ON);
    mask_flash();
  } else {
    digitalWrite(LED, LOW);
  }
}

void flash() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(LED, HIGH);
    delay(250);
    digitalWrite(LED, LOW);
    delay(250);
  }
}

void mask_flash() {
  digitalWrite(LED, HIGH);
  delay(1500);
}