#include <OLED_I2C.h>
#include <SoftwareSerial.h>
OLED myOLED(SDA, SCL, 8);
SoftwareSerial mySerial(3, 4); // RX, TX
extern uint8_t SmallFont[];    // If you do not use the Cyrillic alphabet, it is
                            // better to include the SmallFont font, it will
                            // take up less space in the memory of programs.
String cash0 = "";
String cash1 = "";
String cash2 = "";
String cash3 = "";
String cash4 = "";
String cash5 = "";
String content = "";
char character;
char Draw_number;
bool Draw_mode_on;
int number_draw[4];
int i1x, i1y, i2x, i2y, ir; // int &1x,int &1y,int &2x,int &2y,int &r;
int inyDraw_number = 0;
void setup() {
  mySerial.begin(9600);
  Serial.begin(9600);
  myOLED.begin(); // Initiate work with the display.
  myOLED.setFont(SmallFont);
}

void loop() {
  if (digitalRead(A2) == 1)
    Draw_Mode(character, Draw_number, Draw_mode_on, content, i1x, i1y, i2x, i2y,
              inyDraw_number);
  else
    Text_output(cash0, cash1, cash2, cash3, cash4, cash5, character, content);
}
void Draw_Mode(char &character, char &Draw_number, bool &Draw_mode_on,
               String &content, int &lx1, int &ly1, int &lx2, int &ly2,
               int &inyDraw_number) {
  while (mySerial.available()) {
    character = mySerial.read();
    if (Draw_mode_on == 1) {

      if (character == '1' || character == '2' || character == '3' ||
          character == '4' || character == '5' || character == '6' ||
          character == '7' || character == '8' || character == '9' ||
          character == '0')
        content.concat(character);

      else {
        // number_draw[inyDraw_number]=atoi(content.c_str());
        if (character == ';') {
          switch (inyDraw_number) {
          case (0):
            lx1 = atoi(content.c_str());
            break;
          case (1):
            ly1 = atoi(content.c_str());
            break;
          case (2):
            lx2 = atoi(content.c_str());
            break;
          case (3):
            ly2 = atoi(content.c_str());
            break;
          case (4):
            inyDraw_number = 0;
            break;
            // break;
          } // switch(inyDraw_number)
          inyDraw_number++;
          Draw_mode_on = 0;
        }
      }
    }

    switch (character) {
    case ('B'):
      myOLED.setBrightness(lx1);
      break;
    case ('u'):
      myOLED.update();
      break;
    case ('x'):
      myOLED.clrScr();
      break;
    case ('f'):
      myOLED.fillScr();
      break;
    case ('i'):
      myOLED.invert(lx1);
      break;
    case ('p'):
      myOLED.setPixel(lx1, ly1);
      break;
    case ('P'):
      myOLED.clrPixel(lx1, ly1);
      break;
    case ('k'):
      myOLED.invPixel(lx1, ly1);
      break;
    case ('l'):
      myOLED.drawLine(lx1, ly1, lx2, ly2);
      break;
    case ('L'):
      myOLED.clrLine(lx1, ly1, lx2, ly2);
      break;
    case ('r'):
      myOLED.drawRect(lx1, ly1, lx2, ly2);
      break;
    case ('R'):
      myOLED.clrRect(lx1, ly1, lx2, ly2);
      break;
    case ('o'):
      myOLED.drawRoundRect(lx1, ly1, lx2, ly2);
      break;
    case ('O'):
      myOLED.clrRoundRect(lx1, ly1, lx2, ly2);
      break;
    case ('c'): // small
      myOLED.drawCircle(lx1, ly1, ly2);
      break;
    case ('C'): // big
      myOLED.clrCircle(lx1, ly1, ly2);
      break;
    case ('z'): // 8d8
      inyDraw_number = 0;
      lx1 = 0;
      ly1 = 100;
      lx2 = 0;
      ly2 = 100;
      break;
    case (':'):
      Draw_mode_on = 1;
      content = "";
      break;
    case (']'): // 8d8
      myOLED.drawCircle(10, 10, 10);
      myOLED.update();
      break;

      // break;
    }

  } // while(mySerial.available()
  // return number_draw;
}

void Text_output(String &cash0, String &cash1, String &cash2, String &cash3,
                 String &cash4, String &cash5, char &character,
                 String &content) {
  while (mySerial.available()) {
    // Serial.print("mySerial.available()");
    // myOLED.clrScr();
    character = mySerial.read();
    if (character == '\n') // TinyBasic Plus v0.151039 //25 in length
    {
      Serial.print(content);
      cash0 = cash1;
      cash1 = cash2;
      cash2 = cash3;
      cash3 = cash4;
      cash4 = cash5;
      cash5 = content;
      myOLED.clrScr();
      myOLED.print(cash0, 0, 0);
      myOLED.print(cash1, 0, 10);
      myOLED.print(cash2, 0, 20);
      myOLED.print(cash3, 0, 30);
      myOLED.print(cash4, 0, 40);
      myOLED.print(cash5, 0, 50);
      myOLED.update();

      content = "";
    } // Wrote string '
    else if (character != '\r')
      content.concat(character);
  }
}
