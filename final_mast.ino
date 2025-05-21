#define button1 2
#define button2 3
#define button3 4
#define button4 5
#define button5 6
#define button6 9
#define button7 10
#define button8 11

int value = 0;
void setup() {
  
  Serial.begin(38400);
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);
  pinMode(button5, INPUT_PULLUP);
  pinMode(button6, INPUT_PULLUP);
  pinMode(button7, INPUT_PULLUP);
  pinMode(button8, INPUT_PULLUP);
}

void loop() {
  int val1 = digitalRead(button1);
  int val2 = digitalRead(button2);
  int val3 = digitalRead(button3);
  int val4 = digitalRead(button4);
  int val5 = digitalRead(button5);
  int val6 = digitalRead(button6);
  int val7 = digitalRead(button7);
  int val8 = digitalRead(button8);
  if(val1 == 0 ){
    Serial.println("A");
    delay(200);
  }else if(val2 == 0 ){
    Serial.println("B");
    delay(200);
  }else if(val3 == 0 ){
    Serial.println("C");
    delay(200);
  } else if(val4 == 0 ){
    Serial.println("D");
    delay(200);
  } else if(val5 == 0 ){
    Serial.println("E");
    delay(200);
  } else if(val6 == 0 ){
    Serial.println("F");
    delay(200);
  } else if(val7 == 0 ){
    Serial.println("G");
    delay(200);
  } else if(val8 == 0 ){
    Serial.println("H");
    delay(200);
  }
  delay(200);
}
