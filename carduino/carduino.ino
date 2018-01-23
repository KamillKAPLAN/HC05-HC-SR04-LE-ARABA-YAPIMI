int buzzer = 10;
const int sagileri = 2;
const int saggeri = 4;
const int solileri = 5;
const int solgeri = 6;
const int solenable = 11;
const int sagenable = 3;

int geripin1 = 14;
int geripin2 = 15;
int ileripin1 = 16;
int ileripin2 = 17;
int sagpin1 = 21;
int sagpin2 = 22;
int solpin1 = 19;
int solpin2 = 18;

void setup() { 
  pinMode(sagileri, OUTPUT);
  pinMode(saggeri, OUTPUT);
  pinMode(solileri, OUTPUT);
  pinMode(solgeri, OUTPUT);
  pinMode(sagenable, OUTPUT);
  pinMode(solenable, OUTPUT);
  pinMode(buzzer, OUTPUT);
  
  pinMode(geripin1, OUTPUT);
  pinMode(geripin2, OUTPUT);
  pinMode(ileripin1, OUTPUT);
  pinMode(ileripin2, OUTPUT);
  pinMode(sagpin1, OUTPUT);
  pinMode(sagpin2, OUTPUT);
  pinMode(solpin1, OUTPUT);
  pinMode(solpin2, OUTPUT);

  Serial.begin(9600);
}

void siren() {
  digitalWrite(ileripin1, LOW);
  digitalWrite(ileripin2, LOW);
  digitalWrite(geripin1, LOW);
  digitalWrite(geripin2, LOW);
  digitalWrite(sagpin1, LOW);
  digitalWrite(sagpin2, LOW);
  digitalWrite(solpin1, LOW);
  digitalWrite(solpin2, LOW);
  for(int i=0; i<=2; i++){
    digitalWrite(buzzer, HIGH);
    delay(500);
    digitalWrite(buzzer, LOW);
    delay(500);
  }  
}
void ileri() {
  analogWrite(sagenable, 255);
  analogWrite(solenable, 255);
  digitalWrite(sagileri, LOW);
  digitalWrite(saggeri, HIGH);
  digitalWrite(solileri, LOW);
  digitalWrite(solgeri, HIGH);
  // İLERİ PİNLERİ YAKAR
  digitalWrite(geripin1, LOW);
  digitalWrite(geripin2, LOW);
  digitalWrite(sagpin1, LOW);
  digitalWrite(sagpin2, LOW);
  digitalWrite(solpin1, LOW);
  digitalWrite(solpin2, LOW);
  digitalWrite(buzzer, LOW);
  for(int i=0; i<=1; i++){
    digitalWrite(ileripin1, HIGH);
    digitalWrite(ileripin2, HIGH);
    delay(500);
    digitalWrite(ileripin1, LOW);
    digitalWrite(ileripin2, LOW);
    delay(500);
  }
  digitalWrite(ileripin1, HIGH);
  digitalWrite(ileripin2, HIGH);  
}
void geri() {
  analogWrite(sagenable, 200); //220 degeri pwm olarak motor hizini ayarliyor 255 e kadar çikabilir analogWrite komutunu bunun icin kullaniyoruz
  analogWrite(solenable, 200);
  digitalWrite(sagileri, HIGH);
  digitalWrite(saggeri, LOW);
  digitalWrite(solileri, HIGH);
  digitalWrite(solgeri, LOW);
  // GERİ PİNLERİ YAKAR
  digitalWrite(ileripin1, LOW);
  digitalWrite(ileripin2, LOW);
  digitalWrite(sagpin1, LOW);
  digitalWrite(sagpin2, LOW);
  digitalWrite(solpin1, LOW);
  digitalWrite(solpin2, LOW);
  digitalWrite(buzzer, LOW);
  for(int i=0; i<=1; i++){
    digitalWrite(geripin1, HIGH);
    digitalWrite(geripin2, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(500);
    digitalWrite(geripin1, LOW);
    digitalWrite(geripin2, LOW);
    digitalWrite(buzzer, LOW);
    delay(500);
  }
  digitalWrite(geripin1, HIGH);
  digitalWrite(geripin2, HIGH);
}
void sag() {
  analogWrite(solenable, 150);
  analogWrite(sagenable, 255);
  digitalWrite(sagileri, HIGH);
  digitalWrite(saggeri, LOW);
  digitalWrite(solileri, LOW);
  digitalWrite(solgeri, HIGH);
  //SAG PİNLERİ YAKAR
  digitalWrite(ileripin1, LOW);
  digitalWrite(ileripin2, LOW);
  digitalWrite(geripin1, LOW);
  digitalWrite(geripin2, LOW);
  digitalWrite(solpin1, LOW);
  digitalWrite(solpin2, LOW);
  digitalWrite(buzzer, LOW);
  for(int i=0; i<=1; i++){
    digitalWrite(sagpin1, HIGH);
    digitalWrite(sagpin2, HIGH);
    delay(500);
    digitalWrite(sagpin1, LOW);
    digitalWrite(sagpin2, LOW);
    delay(500);
  }
  digitalWrite(sagpin1, HIGH);
  digitalWrite(sagpin2, HIGH);  
}
void sol() {
  analogWrite(solenable, 255);
  analogWrite(sagenable, 150);
  digitalWrite(sagileri, LOW);
  digitalWrite(saggeri, HIGH);
  digitalWrite(solileri, HIGH);
  digitalWrite(solgeri, LOW);
  //SOL PİNLERİ YAKAR
  digitalWrite(ileripin1, LOW);
  digitalWrite(ileripin2, LOW);
  digitalWrite(geripin1, LOW);
  digitalWrite(geripin2, LOW);
  digitalWrite(sagpin1, LOW);
  digitalWrite(sagpin2, LOW);
  digitalWrite(buzzer, LOW);
  for(int i=0; i<=1; i++){
    digitalWrite(solpin1, HIGH);
    digitalWrite(solpin2, HIGH);
    delay(500);
    digitalWrite(solpin1, LOW);
    digitalWrite(solpin2, LOW);
    delay(500);
  }
  digitalWrite(solpin1, HIGH);
  digitalWrite(solpin2, HIGH);
  
}
void dur() {
  digitalWrite(sagileri, LOW);
  digitalWrite(saggeri, LOW);
  digitalWrite(solileri, LOW);
  digitalWrite(solgeri, LOW);
  //DUR PİNLERİ YAKAR
  digitalWrite(geripin1, HIGH);
  digitalWrite(geripin2, HIGH);
  digitalWrite(ileripin1, LOW);
  digitalWrite(ileripin2, LOW);
  for(int i=0; i<=4; i++){
    digitalWrite(sagpin1, HIGH);
    digitalWrite(sagpin2, HIGH);
    digitalWrite(solpin1, HIGH);
    digitalWrite(solpin2, HIGH);
    delay(500);
    digitalWrite(sagpin1, LOW);
    digitalWrite(sagpin2, LOW);
    digitalWrite(solpin1, LOW);
    digitalWrite(solpin2, LOW);
    delay(500);
  } 
  digitalWrite(geripin1, HIGH);
  digitalWrite(geripin2, HIGH);
  digitalWrite(ileripin1, LOW);
  digitalWrite(ileripin2, LOW);
  digitalWrite(buzzer, LOW);
}
// LOOP FONKSIYONU
void loop() {
  // Bluetooth sensörü kodları
  if (Serial.available() > 0)
  {
    char tus = (char)Serial.read();
    Serial.println("KAMIL KAPLAN");
    if ( tus == 'w' ) {
      Serial.println("Araba ileriye hareket etti"); ileri();
    }
    if ( tus == 's' ) {                                             
      Serial.println("Araba geriye hareket etti"); geri();       
    }
    if ( tus == 'a' ) {
      Serial.println("Araba Sola dondu");   sol();
    }
    if ( tus == 'd' ) {
      Serial.println("Araba Saga dondu"); sag();
    }
    if (tus == 'x') {
      Serial.println("Araba DURDU"); dur();
    }
    if (tus == 'e') {
      siren();
    }
  }
}
