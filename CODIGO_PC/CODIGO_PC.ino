#define CP 23
#define CALL 24
#define RETURN 25
int count = 0;
int temporal_count = -1;
void setup() {
  DDRL = 0xFF;
  DDRJ = 0x00;
  pinMode(CP, INPUT);
  pinMode(CALL,INPUT);
  pinMode(RETURN,INPUT);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(CP)==1){
    count = count + 1;
    delay(3);
  }
  else if (digitalRead(CALL)==1){
    temporal_count = count;
    count = PINJ - 1;
    delay(3);
  }
  else if (digitalRead(RETURN)==1 && temporal_count != -1){
    count = temporal_count;
    temporal_count = -1;
    delay(3);
  }
  PORTL = count;
}
