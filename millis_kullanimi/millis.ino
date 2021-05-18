String okunanKarakter;
int led = 13;
int led1 = 4;
int led2 = 5;
int b = 0;
bool durum = false;
bool gate = false;
bool gate1 = false;
int LEDdurumu = 0;
int LEDdurumu1 = 0;

unsigned long eskiZaman = 0;
unsigned long eskiZaman1 = 0;
unsigned long yeniZaman;



void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}


void serialEvent() {
  /******************************Usb_port_data_okuma******************************/
  if (Serial.available() > 0) {
    okunanKarakter = Serial.read();
    b = okunanKarakter.toInt();
  }
}
void loop() {

  yeniZaman = millis();


/******************************************zaman millis***********************/

  if (durum == true) {
    
    if (yeniZaman - eskiZaman > 3000) {
      if (LEDdurumu == 1) {
        digitalWrite(led2, LOW);
        LEDdurumu = 0;
        eskiZaman = 0;
        gate = false;
      }
    }

    if (yeniZaman - eskiZaman1 > 3000) {
      if (LEDdurumu1 == 1) {
        digitalWrite(led1, LOW);
        LEDdurumu1 = 0;
        eskiZaman1 = 0;
        gate1 = false;
      }
    }

    if ((gate == false) && (gate1 == false)) {
      durum = false;
      yeniZaman = 0;
    }
  }
  /******************************Komut****************************************/
  switch (b) {


    case '1': {
        digitalWrite(led1, HIGH);
        LEDdurumu1 = 1;
        durum = true;
        gate1 = true;
        eskiZaman1 = millis();
        break;
      }

    case '2': {
        digitalWrite(led2, HIGH);
        LEDdurumu = 1;
        durum = true;
        gate = true;
        eskiZaman = millis();
        break;
      }
  }


  /*************************************************************************/
}
