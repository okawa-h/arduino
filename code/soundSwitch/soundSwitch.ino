int b_pin = 7;   // すいっち
int state = 0;

int led = 13; // sund
int melo = 200;
int melo2 = 0;
int meloInt = 0;
int oto = 262;

int touch  = 0;  //センサーのピン番号
int get_a0 = 0;  //センサーデータ取得用

void setup() {
  
  Serial.begin(38400);
  pinMode(led, OUTPUT);
  pinMode(b_pin, INPUT);
  
}

void loop() {
  
  get_a0 = analogRead(touch);
  Serial.println(get_a0);
  state = digitalRead(b_pin);

  if (get_a0 < 666) {
    
    melo2 = melo*2;
    
  } else {
    
    melo2 = melo;
    
  }
  
  if (state == 1) {
    
    Serial.println("on");
    digitalWrite(led,HIGH);

    if (meloInt == 0) {oto = 262;}
    if (meloInt == 1) {oto = 294;}
    if (meloInt == 2) {oto = 330;}
    if (meloInt == 3) {oto = 349;}
    if (meloInt == 4) {oto = 392;}
    if (meloInt == 5) {oto = 440;}
    if (meloInt == 6) {oto = 494;}
    if (meloInt == 7) {oto = 523;}
    
    tone(led,oto,melo2);
    meloInt++;
    if (meloInt == 8) {
      meloInt = 0;
    }
    
  } else {
    
    Serial.println("off");
    digitalWrite(led,LOW);
    
  }
  
  delay(400);
}
