const byte INT_PIN = 2;
const byte LED_PIN = 13;
volatile byte state = LOW, oldState = LOW;
unsigned long time, lastTime, delta;
unsigned long timeHigh, timeLow;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(INT_PIN), process, CHANGE);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("tH=");
  Serial.print(timeHigh, DEC);
  Serial.print(" | ");
  Serial.print("T=");
  Serial.print(timeHigh+timeLow, DEC);
  Serial.print(" | ");
  Serial.print("DC=");
  Serial.println(timeHigh*100/(timeHigh+timeLow), DEC);
}

void process() {
  oldState = state;
  state = !state;
  time = millis();
  delta = time - lastTime;
  lastTime = time;
  // H->L transition
  if (oldState && !state) {
    timeHigh = delta;
  } else {
    timeLow = delta;
  }
  digitalWrite(LED_PIN, state);
}


