/*
 * Код для бомбы на посвят
 * Дата начала: 05.09
 * Версия: 0.1
 * 
*/

#define numberOfWires 9 // количество проводов, подключенных от 2 пина. Количество от 1 до 9

#define firstWirePin 2 
#define correctWirePin 5

#define buzzerPin 11
#define redLedPin 12
#define greenLedPin 13

int wiresArray [numberOfWires]; //массив для хранения состояния проводов. Выдернут или нет
 
void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  for(int wirePin = firstWirePin; wirePin < firstWirePin+numberOfWires; wirePin++){
    pinMode(wirePin, INPUT);
    wiresArray[wirePin - firstWirePin] = wirePin;
  }
}

void playWinningMusic(){ // победная музыка из суперМарио. Нашел в интернете
  tone(buzzerPin,1318,150);
  delay(150);
  tone(buzzerPin,1318,300);
  delay(300);
  tone(buzzerPin,1318,150);
  delay(300);
  tone(buzzerPin,1046,150);
  delay(150);
  tone(buzzerPin,1318,300);
  delay(300);
  tone(buzzerPin,1568,600);
  delay(600);
  tone(buzzerPin,784,600);
  delay(600);
  tone(buzzerPin,1046,450) ; // 2й такт
  delay(450);
  tone(buzzerPin,784,150);
  delay(450);
  tone(buzzerPin,659,300);
  delay(450);
  tone(buzzerPin,880,300);
  delay(300);
  tone(buzzerPin,987,150);
  delay(300);
  tone(buzzerPin,932,150);
  delay(150);
  tone(buzzerPin,880,300);
  delay(300);
  tone(buzzerPin,784,210); // 3й такт
  delay(210);
  tone(buzzerPin,1318,210);
  delay(210);
  tone(buzzerPin,1568,150);
  delay(150);
  tone(buzzerPin,1750,300);
  delay(300);
  tone(buzzerPin,1396,150);
  delay(150);
  tone(buzzerPin,1568,150);
  delay(300);
  tone(buzzerPin,1318,300);
  delay(300);
  tone(buzzerPin,1046,150);
  delay(150);
  tone(buzzerPin,1174,150);
  delay(150);
  tone(buzzerPin,987,450);
  delay(450);
  tone(buzzerPin,1046,450); // 4й такт
  delay(450);
  tone(buzzerPin,784,150);
  delay(450);
  tone(buzzerPin,659,300);
  delay(450);
  tone(buzzerPin,880,300);
  delay(300);
  tone(buzzerPin,987,150);
  delay(300);
  tone(buzzerPin,932,150);
  delay(150);
  tone(buzzerPin,880,300);
  delay(300);
  tone(buzzerPin,784,210); // 5й такт
  delay(210);
  tone(buzzerPin,1318,210);
  delay(210);
  tone(buzzerPin,1568,150);
  delay(150);
  tone(buzzerPin,1750,300);
  delay(300);
  tone(buzzerPin,1396,150);
  delay(150);
  tone(buzzerPin,1568,150);
  delay(300);
  tone(buzzerPin,1318,300);
  delay(300);
  tone(buzzerPin,1046,150);
  delay(150);
  tone(buzzerPin,1174,150);
  delay(150);
  tone(buzzerPin,987,450);
  delay(600);
  tone(buzzerPin,1568,150); // 6ой Спуск вниз
  delay(150);
  tone(buzzerPin,1480,150);
  delay(150);
  tone(buzzerPin,1396,150);
  delay(150);
  tone(buzzerPin,1244,300);
  delay(300);
  tone(buzzerPin,1318,150);
  delay(300);
  tone(buzzerPin,830,150);
  delay(150);
  tone(buzzerPin,880,150);
  delay(150);
  tone(buzzerPin,1046,150);
  delay(300);
  tone(buzzerPin,880,150);
  delay(150);
  tone(buzzerPin,1046,150);
  delay(150);
  tone(buzzerPin,1174,150);
  delay(150);
}

void playWrongWireSound(){
  tone(buzzerPin, 1000, 1500);
  delay(1500);
}

void loop() {
  for(int wirePin = firstWirePin; wirePin < firstWirePin+numberOfWires; wirePin++){ 
    if(wiresArray[wirePin - firstWirePin] != -1 && !digitalRead(wirePin)){
      wiresArray[wirePin - firstWirePin] = -1;
      if(wirePin == correctWirePin){
        digitalWrite(greenLedPin, HIGH);
        playWinningMusic();
        digitalWrite(greenLedPin, LOW);
      }else{
        digitalWrite(redLedPin, HIGH);
        playWrongWireSound();
        digitalWrite(redLedPin, LOW);
      } 
    }
  }
}
