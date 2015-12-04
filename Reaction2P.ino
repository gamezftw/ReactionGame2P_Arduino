int buttonLeft1P = 12;
int buttonRight1P = 8;
int buttonLeft2P = 7;
int buttonRight2P = 4;
int LEDLeft = 11;
int LEDRight = 9;
boolean LEDLeftIndicator;
boolean LEDRightIndicator;
boolean buttonPressed1P;
boolean buttonPressed2P;
int LEDDelay;
int chooseLED;
double startTimer;
double endTimer1P;
double endTimer2P;
double singleTimer1P;
double singleTimer2P;
double totalTimer1P;
double totalTimer2P;
double averageTimer1P;
double averageTimer2P;
int score1P;
int score2P;
int counter;

void setup(){
  Serial.begin(9600);
  pinMode(buttonLeft1P, INPUT);
  pinMode(buttonLeft2P, INPUT);
  pinMode(buttonRight1P, INPUT);
  pinMode(buttonRight2P, INPUT);
  pinMode(LEDLeft, OUTPUT);
  pinMode(LEDRight, OUTPUT);
  LEDLeftIndicator = false;
  LEDRightIndicator = false;
  totalTimer1P = 0;
  totalTimer2P = 0;
  singleTimer1P = 0;
  singleTimer2P = 0;
  averageTimer1P = 0;
  averageTimer2P = 0;
  score1P = 0;
  score2P = 0;
  chooseLED = 0;
  counter = 1;
}

void loop(){
  LEDDelay = random(2000, 6000);
  chooseLED = random(1, 3);
  startTimer = 0;
  endTimer1P = 0;
  endTimer2P = 0;
  buttonPressed1P = false;
  buttonPressed2P = false; 
  delay(LEDDelay);
  startTimer = millis();
  if(chooseLED == 1){
    digitalWrite(LEDLeft, HIGH);
    LEDLeftIndicator = true;
    while(buttonPressed1P != true || buttonPressed2P != true){
      if(digitalRead(buttonLeft1P) == LOW && buttonPressed1P == false){
        endTimer1P = millis();
        singleTimer1P = endTimer1P - startTimer;
        totalTimer1P = totalTimer1P + singleTimer1P;
        averageTimer1P = totalTimer1P / counter;
        buttonPressed1P = true;
      }
      if(digitalRead(buttonLeft2P) == LOW && buttonPressed2P == false){
        endTimer2P = millis();
        singleTimer2P = endTimer2P - startTimer;
        totalTimer2P = totalTimer2P + singleTimer2P;
        averageTimer2P = totalTimer2P / counter;
        buttonPressed2P = true;
      }
    }
    digitalWrite(LEDLeft, LOW);
  }
  if(chooseLED == 2){
    digitalWrite(LEDRight, HIGH);
    LEDRightIndicator = true;
    while(buttonPressed1P != true || buttonPressed2P != true){
      if(digitalRead(buttonRight1P) == LOW && buttonPressed1P == false){
        endTimer1P = millis();
        singleTimer1P = endTimer1P - startTimer;
        totalTimer1P = totalTimer1P + singleTimer1P;
        averageTimer1P = totalTimer1P / counter;
        buttonPressed1P = true;
      }
      if(digitalRead(buttonRight2P) == LOW && buttonPressed2P == false){
        endTimer2P = millis();
        singleTimer2P = endTimer2P - startTimer;
        totalTimer2P = totalTimer2P + singleTimer2P;
        averageTimer2P = totalTimer2P / counter;
        buttonPressed2P = true;
      }
    }
    digitalWrite(LEDRight, LOW);
  }
  counter++;
  if(singleTimer1P<singleTimer2P){
    Serial.println("1P Wins");
    Serial.println(singleTimer1P/1000);
    Serial.println("\n");
    score1P++;
  }
  else{
    Serial.println("2P Wins");
    Serial.println(singleTimer2P/1000);
    Serial.println("\n");
    score2P++;
  }
  if(counter%6==0){
    Serial.print("Current score is: ");
    Serial.print(score1P);
    Serial.print(":");
    Serial.print(score2P);
    Serial.print("\n");
    delay(5000);
    Serial.print("Player 1 average time: ");
    Serial.println(averageTimer1P/1000);
    Serial.print("Player 2 average time: ");
    Serial.println(averageTimer2P/1000);
  }
}
