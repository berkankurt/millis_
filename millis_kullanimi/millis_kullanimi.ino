String okunanKarakter;
int led = 13;
int led1 = 4;
int led2 = 5;
int b = 0;
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

void loop() {

  yeniZaman = millis();

  /******************************Usb_port_data_okuma******************************/
  if (Serial.available() > 0) {
    okunanKarakter = Serial.read();
    b = okunanKarakter.toInt();
  }
  /******************************************zaman millis***********************/
  if (yeniZaman - eskiZaman > 3000) {
    if (LEDdurumu == 1) {
      digitalWrite(led2, LOW);
      LEDdurumu = 0;
    }
    eskiZaman = yeniZaman;
  }


  if (yeniZaman - eskiZaman1 > 3000) {
    if (LEDdurumu1 == 1) {
      digitalWrite(led1, LOW);
      LEDdurumu1 = 0;
    }
    eskiZaman1 = yeniZaman;
  }
  /******************************Komut****************************************/
  switch (b) {


    case '1': {
        digitalWrite(led1, HIGH);
        LEDdurumu1 = 1;
        break;
      }

    case '2': {
        digitalWrite(led2, HIGH);
        LEDdurumu = 1;
        break;
      }
  }

  /*************************************************************************/
}
