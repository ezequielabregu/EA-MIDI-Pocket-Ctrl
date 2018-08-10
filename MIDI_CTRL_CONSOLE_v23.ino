/* Configuraci´n de botones notenumber(input))
        65(A3)    63(A1)    64(A2)
  66(A5)                                67 (A4)
        61(12)    60(11)  62(13)
*/
//#include <Scheduler.h>
#include <EEPROM.h>
#include <LiquidCrystal.h>
#include <MIDI.h> //importo la libreria MIDI

//DISPLAY
LiquidCrystal lcd(7, 6, 5, 4, 3, 2); //son las salidas digitales Arduino MEGA

//CUSTOM CHARACTER


//1 off
byte customChar1[8] = {
  0b11110,
  0b11110,
  0b11010,
  0b10010,
  0b11010,
  0b11010,
  0b11010,
  0b11110
};

//2
byte customChar2[8] = {
  0b11110,
  0b11110,
  0b10010,
  0b11010,
  0b11010,
  0b10110,
  0b10010,
  0b11110
};

//3
byte customChar3[8] = {
  0b11110,
  0b11110,
  0b10010,
  0b11010,
  0b10010,
  0b11010,
  0b10010,
  0b11110
};

//4
byte customChar4[8] = {
  0b11110,
  0b11110,
  0b10110,
  0b10010,
  0b10010,
  0b11010,
  0b11010,
  0b11110
};

//5
byte customChar5[8] = {
  0b11110,
  0b11110,
  0b10010,
  0b10110,
  0b10010,
  0b11010,
  0b10010,
  0b11110
};

//6
byte customChar6[8] = {
  0b11110,
  0b11110,
  0b10010,
  0b10110,
  0b10010,
  0b10010,
  0b10010,
  0b11110
};

///7

byte customChar7[8] = {
  0b11110,
  0b11110,
  0b10010,
  0b11010,
  0b10110,
  0b10110,
  0b10110,
  0b11110
};

///8

byte customChar8[8] = {
  0b11110,
  0b11110,
  0b00010,
  0b01010,
  0b10110,
  0b01010,
  0b00010,
  0b11110
};


///////////////////////////////////////////***************************


//*****************************************************************************
int r0 = 0;
int r1 = 0;  // the three digital pins for the bits
int r2 = 0;

int  bin [] = {000, 1, 10, 11, 100, 101, 110, 111};//list of binary values

/////**********////////// parametros librerias midi
//Scene 1
int ctrl0Scene1 = 20; //CC#
int ctrl1Scene1 = 21;
int ctrl2Scene1 = 22;
int ctrl3Scene1 = 23;
int ctrl4Scene1 = 24;
int ctrl5Scene1 = 25;
int ctrl6Scene1 = 26;
int ctrl7Scene1 = 27;

//Scene 2
int ctrl0Scene2 = 30; //CC#
int ctrl1Scene2 = 31;
int ctrl2Scene2 = 32;
int ctrl3Scene2 = 33;
int ctrl4Scene2 = 34;
int ctrl5Scene2 = 35;
int ctrl6Scene2 = 36;
int ctrl7Scene2 = 37;

//Scene 3
int ctrl0Scene3 = 40; //CC#
int ctrl1Scene3 = 41;
int ctrl2Scene3 = 42;
int ctrl3Scene3 = 43;
int ctrl4Scene3 = 44;
int ctrl5Scene3 = 45;
int ctrl6Scene3 = 46;
int ctrl7Scene3 = 47;

//Scene 4
int ctrl0Scene4 = 50; //CC#
int ctrl1Scene4 = 51;
int ctrl2Scene4 = 52;
int ctrl3Scene4 = 53;
int ctrl4Scene4 = 54;
int ctrl5Scene4 = 55;
int ctrl6Scene4 = 56;
int ctrl7Scene4 = 57;

//Scene 5
int ctrl0Scene5 = 60; //CC#
int ctrl1Scene5 = 61;
int ctrl2Scene5 = 62;
int ctrl3Scene5 = 63;
int ctrl4Scene5 = 64;
int ctrl5Scene5 = 65;
int ctrl6Scene5 = 66;
int ctrl7Scene5 = 67;

//Scene 6
int ctrl0Scene6 = 70; //CC#
int ctrl1Scene6 = 71;
int ctrl2Scene6 = 72;
int ctrl3Scene6 = 73;
int ctrl4Scene6 = 74;
int ctrl5Scene6 = 75;
int ctrl6Scene6 = 76;
int ctrl7Scene6 = 77;


//CC# inicio
int ctrl0 = 20; //CC#
int ctrl1 = 21;
int ctrl2 = 22;
int ctrl3 = 23;
int ctrl4 = 24;
int ctrl5 = 25;
int ctrl6 = 26;
int ctrl7 = 27;

//MIDINote number
int buttonNote1 = 60; //C
int buttonNote2 = 61; //C#
int buttonNote3 = 62; //D#
int buttonNote4 = 63; //...
int buttonNote5 = 64;
int buttonNote6 = 65;
int buttonNote7 = 66;
int buttonNote8 = 67;


//Variables potes
int potValue0 = 0;
int lastPotValue0 = 128; //Valor de inicio, se usa para comparar con el valor anterior
int potValue1 = 0;
int lastPotValue2 = 128;
int potValue2 = 0;
int lastPotValue1 = 128;
int potValue3 = 0;
int lastPotValue3 = 128;
int potValue4 = 0;
int lastPotValue4 = 128;
int potValue5 = 0;
int lastPotValue5 = 128;
int potValue6 = 0;
int lastPotValue6 = 128;
int potValue7 = 0;
int lastPotValue7 = 128;


//Variables botones
int buttonState1 = 0;         // current state of the button
int lastButtonState1 = 0;     // previous state of the button
int buttonState2 = 0;
int lastButtonState2 = 0;
int buttonState3 = 0;
int lastButtonState3 = 0;
int buttonState4 = 0;
int lastButtonState4 = 0;
int buttonState5 = 0;         // current state of the button
int lastButtonState5 = 0;     // previous state of the button
int buttonState6 = 0;
int lastButtonState6 = 0;
int buttonState7 = 0;
int lastButtonState7 = 0;
int buttonState8 = 0;
int lastButtonState8 = 0;


//******************
int count1 = 0;
int count2 = 0;
int scene = 0;
int selSceneState = 0;
int configBtnState1 = 0 ;
int configBtnState2 = 0 ;
int pageConf = 0;

//****EEPROM
int index0=0;
int index1=1;
int index2=2;
int index3=3;
int index4=4;
int index5=5;
int index6=6;
int index7=7;

int writeValue0=0;
int writeValue1=1;
int writeValue2=2;
int writeValue3=3;
int writeValue4=4;
int writeValue5=5;
int writeValue6=6;
int writeValue7=7;


//***********STEP SEQ
int stepSeq [9] = {0,0,0,0,0,0,0,0,0}; /// array para las notas
int stepSeqIndex = 0;
int lastStepSeqIndex = 60; //comienza en C3
int lastCount = 0;
int seqCount = -1 ;
int play = 0;
int playState = 0;
int lastPlayState = 0;
int noteSeq0 = 0;
int noteSeq1 = 0;
int noteSeq2 = 0;
int noteSeq3 = 0;

int keyVel=0;

unsigned long stepInit0 = 0;
unsigned long stepInit1 = 0;

unsigned long prevMillis0 = 0;
unsigned long prevMillis1 = 0;

int tempo = 500;
int bpm = 0;
int stepTime1 = 0 ;

int stepState0 = 0;
int stepState1 = 1;

int octava=0;
int lastOctava= 0;
int octavaState= 0;
int octavaRange = 13 ;
int transp = 59;
int lastTranspUp = 0;
int lastTranspDown = 0;
int transpUp = 0;
int transpDown = 0;

int randMode = 0 ;
int randState = 0 ;
int lastRandState = 0;

float midiCLockTime = 0;

int tempoScale = 1;
int subdivState = 0;
int lastSubdiv1 = 0;
int lastSubdiv2 = 0;
int lastSubdiv3 = 0;
int pageSeq = 0;
int lastPageSeq = 0;
int pageState = 0;
int tempoSubdiv1 = 0;
int tempoSubdiv2 = 0;
int tempoSubdiv3 = 0;

int playReverse = 0;
///******************

unsigned long prevMillisButtonA = 0;
int lastButtonA = 0;
int buttonA = 0;

int  Threshlod = 7;

MIDI_CREATE_DEFAULT_INSTANCE ();  //creo la instancia
//////////////////////////////////////////////////////////


void setup() {

  lcd.begin(16, 2);
  MIDI.begin(MIDI_CHANNEL_OMNI);  //comienza MIDI por el canal OMNI en este caso
  Serial.begin (31250); //puerto serial a 31250 baudios


// Scheduler.startLoop(loopSeq);

  //Custom characters

  lcd.createChar(1, customChar1);
  lcd.createChar(2, customChar2);
  lcd.createChar(3, customChar3);
  lcd.createChar(4, customChar4);
  lcd.createChar(5, customChar5);
  lcd.createChar(6, customChar6);
  lcd.createChar(7, customChar7);
  lcd.createChar(8, customChar8);
  //lcd.createChar(10, customCharCC);

  ///pines de Potenciometro////
  pinMode(8, OUTPUT);    // r0
  pinMode(9, OUTPUT);    // r1
  pinMode(10, OUTPUT);    // r2

  ///pines de botones
  pinMode(11, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  pinMode(13, INPUT_PULLUP);
  /// inputs analogicos como digitales
  pinMode(A1, INPUT_PULLUP);
  pinMode(A2, INPUT_PULLUP);
  pinMode(A3, INPUT_PULLUP);
  pinMode(A4, INPUT_PULLUP);
  pinMode(A5, INPUT_PULLUP);

  //*********INTRO Bienvenida***********************

  lcd.setCursor(0, 0);
  lcd.print("ABREGU MIDI CTRL");
  
  lcd.setCursor(0, 1);
  lcd.print("Firmware v160129");

  delay (2000);
  
  for (int countScroll = 0; countScroll < 15; countScroll++) {
      lcd.scrollDisplayRight();
      delay(50);
                 }
   lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("    LOADING    ");
  delay (200);
    lcd.clear();
  delay (100);
  lcd.print("    LOADING    ");
  delay (200);
    lcd.clear();
  delay (100);
   lcd.print("    LOADING    ");
  delay (200);
    lcd.clear();
  delay (100);

  lcd.clear();

  ///////////////*****************************
}

void refreshDisplay(){
        lcd.setCursor(0, 0);
        lcd.write((uint8_t)1);
        lcd.setCursor(1, 0);
        lcd.print(lastPotValue0/8);
        if ((lastPotValue0/8) < 100) lcd.print (" ");

        
        lcd.setCursor(4, 0);
        lcd.write((uint8_t)2);
        lcd.setCursor(5, 0);
        lcd.print(lastPotValue1/8);
        if ((lastPotValue1/8) < 100) lcd.print (" ");
    
        
        lcd.setCursor(8, 0);
        lcd.write((uint8_t)3);
        lcd.setCursor(9, 0);
        lcd.print(lastPotValue2/8);
        if ((lastPotValue2/8) < 100) lcd.print (" ");

        
        lcd.setCursor(12, 0);
        lcd.write((uint8_t)4);
        lcd.setCursor(13, 0);
        lcd.print(lastPotValue3/8);
        if ((lastPotValue3/8) < 100) lcd.print (" ");

        lcd.setCursor(0, 2);
        lcd.write((uint8_t)5);
        lcd.setCursor(1, 2);
        lcd.print(lastPotValue4/8);
        if ((lastPotValue4/8) < 100) lcd.print (" ");

         lcd.setCursor(4, 2);
        lcd.write((uint8_t)6);
        lcd.setCursor(5, 2);
        lcd.print(lastPotValue5/8);
        if ((lastPotValue5/8) < 100) lcd.print (" ");

         lcd.setCursor(8, 2);
        lcd.write((uint8_t)7);
        lcd.setCursor(9, 2);
        lcd.print(lastPotValue6/8);
        if ((lastPotValue6/8) < 100) lcd.print (" ");
  
        lcd.setCursor(12, 2);
        lcd.write((uint8_t)8);
        lcd.setCursor(13, 2);
        lcd.print(lastPotValue7/8);
        if ((lastPotValue7/8) < 100) lcd.print (" ");

}


void loop () {

unsigned long currentMillis = millis();
//unsigned long currentMicros = micros();


if (digitalRead (A4) == HIGH) {
    count1 = ++count1;     
    if (count1 == 4) {
      MIDI.sendNoteOff(buttonNote7, 0, 1);
      scene = 1;
      count1 = 0 ;
     configBtnState1 = 1 - configBtnState1;
    }
    delay (250); 
  }
    
 else {count1= 0; }

  if (digitalRead (A5) == HIGH) {
    count2 = ++count2;
    if (count2 == 4) {
       MIDI.sendNoteOff(buttonNote8, 0, 1);
      scene = 2;
      configBtnState2 = 1 - configBtnState2;
    }
    delay (250);
    if (digitalRead (A5) == LOW) {
      count2 = 0;
    }
  }
  
 else {count2= 0; } 

  if ((configBtnState1 == 0) && (configBtnState2 == 0)) {
    scene = 3;
 }
  switch (scene) {

    ////////////////*********SCENE 1 PRESETS*******************////////////////////////////
    case 1: 

    lcd.setCursor(0, 0);
        lcd.print("Push Btns To Sel  ");
        lcd.setCursor(0, 2);
        lcd.print("a FACTORY SCENE      ");
          
    
        if (digitalRead (A3) == HIGH) {
          ctrl0 = ctrl0Scene1;
          ctrl1 = ctrl1Scene1;
          ctrl2 = ctrl2Scene1;
          ctrl3 = ctrl3Scene1;
          ctrl4 = ctrl4Scene1;
          ctrl5 = ctrl5Scene1;
          ctrl6 = ctrl6Scene1;
          ctrl7 = ctrl7Scene1;
          
        }
        
        else if (digitalRead (A1) == HIGH) {
          ctrl0 = ctrl0Scene2;
          ctrl1 = ctrl1Scene2;
          ctrl2 = ctrl2Scene2;
          ctrl3 = ctrl3Scene2;
          ctrl4 = ctrl4Scene2;
          ctrl5 = ctrl5Scene2;
          ctrl6 = ctrl6Scene2;
          ctrl7 = ctrl7Scene2;
          
        }
       
        else if (digitalRead (A2) == HIGH) {
          ctrl0 = ctrl0Scene3;
          ctrl1 = ctrl1Scene3;
          ctrl2 = ctrl2Scene3;
          ctrl3 = ctrl3Scene3;
          ctrl4 = ctrl4Scene3;
          ctrl5 = ctrl5Scene3;
          ctrl6 = ctrl6Scene3;
          ctrl7 = ctrl7Scene3;

        }

         else if (digitalRead (12) == HIGH) {
          ctrl0 = ctrl0Scene4;
          ctrl1 = ctrl1Scene4;
          ctrl2 = ctrl2Scene4;
          ctrl3 = ctrl3Scene4;
          ctrl4 = ctrl4Scene4;
          ctrl5 = ctrl5Scene4;
          ctrl6 = ctrl6Scene4;
          ctrl7 = ctrl7Scene4;

          
         }

         else if (digitalRead (11) == HIGH) {
          ctrl0 = ctrl0Scene5;
          ctrl1 = ctrl1Scene5;
          ctrl2 = ctrl2Scene5;
          ctrl3 = ctrl3Scene5;
          ctrl4 = ctrl4Scene5;
          ctrl5 = ctrl5Scene5;
          ctrl6 = ctrl6Scene5;
          ctrl7 = ctrl7Scene5;

         }


          else if (digitalRead (13) == HIGH) {
          ctrl0 = ctrl0Scene6;
          ctrl1 = ctrl1Scene6;
          ctrl2 = ctrl2Scene6;
          ctrl3 = ctrl3Scene6;
          ctrl4 = ctrl4Scene6;
          ctrl5 = ctrl5Scene6;
          ctrl6 = ctrl6Scene6;
          ctrl7 = ctrl7Scene6; 

        }

           

        if (digitalRead(A3) == HIGH) {
          lcd.setCursor(0, 0);
          lcd.print("SCENE 1           ");
          lcd.setCursor(0, 2);
          lcd.print("SELECTED          ");
          delay (1000);
          refreshDisplay();
          scene = 3;   
        
        }

        else if (digitalRead(A1) == HIGH) {
          lcd.setCursor(0, 0);
          lcd.print("SCENE 2           ");
          lcd.setCursor(0, 2);
          lcd.print("SELECTED          ");
          delay (1000);
          refreshDisplay();
          scene = 3;

        }

        else if (digitalRead(A2) == HIGH) {
          lcd.setCursor(0, 0);
          lcd.print("SCENE 3           ");
          lcd.setCursor(0, 2);
          lcd.print("SELECTED          ");
          delay (1000);
          refreshDisplay();
         scene = 3;

        }
   

        else if (digitalRead(12) == HIGH) {
          lcd.setCursor(0, 0);
          lcd.print("SCENE 4           ");
          lcd.setCursor(0, 2);
          lcd.print("SELECTED          ");
          delay (1000);
          scene = 3;
        }
  

        else if (digitalRead(11) == HIGH) {
          lcd.setCursor(0, 0);
          lcd.print("SCENE 5           ");
          lcd.setCursor(0, 2);
          lcd.print("SELECTED          ");
          delay (1000);
          refreshDisplay();
          scene = 3;
        }
      

        else if (digitalRead(13) == HIGH) {
          lcd.setCursor(0, 0);
          lcd.print("SCENE 6           ");
          lcd.setCursor(0, 2);
          lcd.print("SELECTED          ");
          delay (1000);
          refreshDisplay();
          scene = 3;
        }

        else if (digitalRead(A5) == HIGH) {
          lcd.setCursor(0, 0);
          lcd.print("Push Btns To Sel");
          lcd.setCursor(0, 2);
          lcd.print("a CUSTOM  SCENE   ");
          delay (2000);
          scene = 6;
        
        }


                
        delay (20);

  
      break;
      

    ////////////////*********SCENE 2  CONFIG*******************////////////////////////////
    case 2: 
        
       //MIDI.sendNoteOff(buttonNote7, 100, 1);

        lcd.setCursor(0, 0);
        lcd.print("RED Btn SET CC#  ");
        lcd.setCursor(0, 2);
        lcd.print("WHT Btn STEP SEQ  ");

        if (digitalRead(A4) == HIGH) {
          scene = 3;
        }

        if ((digitalRead (A3) == HIGH) || (digitalRead (A1) == HIGH) || (digitalRead (A2) == HIGH)) {
          scene = 4;
        lcd.setCursor(0, 0);
        lcd.print("ENTER TO        ");
        lcd.setCursor(0, 2);
        lcd.print("CC# SETUP       ");
        delay (1500);
        
        lcd.setCursor(0, 0);
        lcd.print("Sel CC# w/POT  ");
        lcd.setCursor(0, 2);
        lcd.print("Push Btn To SAVE     ");
        delay (2500);
        }
        
        if ((digitalRead (11) == HIGH) || (digitalRead (12) == HIGH) || (digitalRead (13) == HIGH)) {
        
        lcd.setCursor(0, 0);
        lcd.print("STEP SEQUENCER  ");
        lcd.setCursor(0, 2);
        lcd.print("MODE ACTIVE     ");
        delay (2500);
        lcd.setCursor(0, 2);
        lcd.print("                 ");
          scene = 5;
        }
        delay (20);

       
        break;
        
        
 ////////***********CC setup ////////////////////////////
      
      case 4 :
      

         for (int count = 0; count < 8; count++)
  { //loop through each channel, checking for a signal

    int row = bin[count]; //channel 5 = 5th element in the bin list -> 101 etc.
    ///potenciometros
    r0 = bitRead(row, 0); //bitRead() -> parameter 1 = binary sequence, parameter 2 = which bit to read, starting from the right most bit
    r1 = bitRead(row, 1); //channel 7 = 111, 1 = 2nd bit
    r2 = bitRead(row, 2); // third bit

    digitalWrite(8, r0); // send the bits to the digital pins
    digitalWrite(9, r1);
    digitalWrite(10, r2);

    //***************WRITE CC# into EPPROM ONLY WHEN A BUTTONS IS PRESSED

    int potValue0 = analogRead (0) / 8; //escaleo el rango 0-1023
    if ((potValue0  != lastPotValue0) && (count == 0))  {
      writeValue0= potValue0;
      lastPotValue0 = potValue0; // queda el ultimo valor del pote.
    }
      ctrl0 = EEPROM.read (index0);

     int potValue1 = analogRead (0) / 8; //escaleo el rango 0-1023
    if ((potValue1  != lastPotValue1) && (count == 1))  {
      writeValue1= potValue1;
      lastPotValue1 = potValue1; // queda el ultimo valor del pote.
    }
      ctrl1 = EEPROM.read (index1);

      int potValue2 = analogRead (0) / 8; //escaleo el rango 0-1023
      if ((potValue2  != lastPotValue2) && (count == 2))  {
      writeValue2= potValue2;
      lastPotValue2 = potValue2; // queda el ultimo valor del pote.
    }
      ctrl2 = EEPROM.read (index2);


    int potValue3 = analogRead (0) / 8; //escaleo el rango 0-1023
    if ((potValue3  != lastPotValue3) && (count == 3))  {
      writeValue3= potValue3;
      lastPotValue3 = potValue3; // queda el ultimo valor del pote.
    }
      ctrl3 = EEPROM.read (index3);  

    int potValue4 = analogRead (0) / 8; //escaleo el rango 0-1023
    if ((potValue4  != lastPotValue4) && (count == 4))  {
      writeValue4= potValue4;
      lastPotValue4 = potValue4; // queda el ultimo valor del pote.
    }
      ctrl4 = EEPROM.read (index4);

    int potValue5 = analogRead (0) / 8; //escaleo el rango 0-1023
    if ((potValue5  != lastPotValue5) && (count == 5))  {
      writeValue5= potValue5;
      lastPotValue5 = potValue5; // queda el ultimo valor del pote.
    }
      ctrl5 = EEPROM.read (index5);

     int potValue6 = analogRead (0) / 8; //escaleo el rango 0-1023
    if ((potValue6  != lastPotValue6) && (count == 6))  {
      writeValue6= potValue6;
      lastPotValue6 = potValue6; // queda el ultimo valor del pote.
    }
      ctrl6 = EEPROM.read (index6);


     int potValue7 = analogRead (0) / 8; //escaleo el rango 0-1023
    if ((potValue7  != lastPotValue7) && (count == 7))  {
      writeValue7= potValue7;
      lastPotValue7 = potValue7; // queda el ultimo valor del pote.
    }
      ctrl7 = EEPROM.read (index7);

                    

      if (digitalRead (A3) == HIGH) {
        EEPROM.write(index0, writeValue0 );
        EEPROM.write(index1, writeValue1 );
        EEPROM.write(index2, writeValue2 );
        EEPROM.write(index3, writeValue3 );
        EEPROM.write(index4, writeValue4 );
        EEPROM.write(index5, writeValue5 );
        EEPROM.write(index6, writeValue6 );
        EEPROM.write(index7, writeValue7 );

        lcd.setCursor(0, 0);
        lcd.write("CC# SETUP 1      ");
        lcd.setCursor(0, 2);
        lcd.print("SAVED IN MEMORY      ");
        delay (2000);
        
      }

      if (digitalRead (A1) == HIGH) {
        EEPROM.write(index0 + 8, writeValue0 );
        EEPROM.write(index1 + 8, writeValue1 );
        EEPROM.write(index2 + 8, writeValue2 );
        EEPROM.write(index3 + 8, writeValue3 );
        EEPROM.write(index4 + 8, writeValue4 );
        EEPROM.write(index5 + 8, writeValue5 );
        EEPROM.write(index6 + 8, writeValue6 );
        EEPROM.write(index7 + 8, writeValue7 );

        lcd.setCursor(0, 0);
        lcd.write("CUSTOM CC# SET 2      ");
        lcd.setCursor(0, 2);
        lcd.print("SAVED IN MEMORY      ");
        delay (2000);
        
      }

       if (digitalRead (A2) == HIGH) {
        EEPROM.write(index0 + 16, writeValue0 );
        EEPROM.write(index1 + 16, writeValue1 );
        EEPROM.write(index2 + 16, writeValue2 );
        EEPROM.write(index3 + 16, writeValue3 );
        EEPROM.write(index4 + 16, writeValue4 );
        EEPROM.write(index5 + 16, writeValue5 );
        EEPROM.write(index6 + 16, writeValue6 );
        EEPROM.write(index7 + 16, writeValue7 );

        lcd.setCursor(0, 0);
        lcd.write("CUSTOM CC# SET 3      ");
        lcd.setCursor(0, 2);
        lcd.print("SAVED IN MEMORY      ");
        delay (2000);
        
      }

    if (digitalRead (12) == HIGH) {
        EEPROM.write(index0 + 24, writeValue0 );
        EEPROM.write(index1 + 24, writeValue1 );
        EEPROM.write(index2 + 24, writeValue2 );
        EEPROM.write(index3 + 24, writeValue3 );
        EEPROM.write(index4 + 24, writeValue4 );
        EEPROM.write(index5 + 24, writeValue5 );
        EEPROM.write(index6 + 24, writeValue6 );
        EEPROM.write(index7 + 24, writeValue7 );

        lcd.setCursor(0, 0);
        lcd.write("CUSTOM CC# SET 4      ");
        lcd.setCursor(0, 2);
        lcd.print("SAVED IN MEMORY      ");
        delay (2000);
        
      }
            
      if (digitalRead (11) == HIGH) {
        EEPROM.write(index0 + 32, writeValue0 );
        EEPROM.write(index1 + 32, writeValue1 );
        EEPROM.write(index2 + 32, writeValue2 );
        EEPROM.write(index3 + 32, writeValue3 );
        EEPROM.write(index4 + 32, writeValue4 );
        EEPROM.write(index5 + 32, writeValue5 );
        EEPROM.write(index6 + 32, writeValue6 );
        EEPROM.write(index7 + 32, writeValue7 );

        lcd.setCursor(0, 0);
        lcd.write("CUSTOM CC# SET 5      ");
        lcd.setCursor(0, 2);
        lcd.print("SAVED IN MEMORY      ");
        delay (2000);
        
      }

     if (digitalRead (13) == HIGH) {
        EEPROM.write(index0 + 40, writeValue0 );
        EEPROM.write(index1 + 40, writeValue1 );
        EEPROM.write(index2 + 40, writeValue2 );
        EEPROM.write(index3 + 40, writeValue3 );
        EEPROM.write(index4 + 40, writeValue4 );
        EEPROM.write(index5 + 40, writeValue5 );
        EEPROM.write(index6 + 40, writeValue6 );
        EEPROM.write(index7 + 40, writeValue7 );

        lcd.setCursor(0, 0);
        lcd.write("CUSTOM CC# SET 6      ");
        lcd.setCursor(0, 2);
        lcd.print("SAVED IN MEMORY      ");
        delay (2000);
        
      }                 
     ///display CC setup
     
  int potValue = analogRead ( 0 ) / 8;

    if (count == 0) {
        lcd.setCursor(0, 0);
        lcd.write((uint8_t)1);
        lcd.setCursor(1, 0);
        lcd.print(abs(potValue));
        if ((potValue) < 100) lcd.print (" ");   // para que refresque el display sin parpadear
      }
    
  

    if (count == 1) { 
        lcd.setCursor(4, 0);
        lcd.write((uint8_t)2);
        lcd.setCursor(5, 0);
        lcd.print(abs(potValue));
        if ((potValue) < 100) lcd.print (" ");   // para que refresque el display sin parpadear
      }

    if (count == 2) { 
        lcd.setCursor(8, 0);
        lcd.write((uint8_t)3);
        lcd.setCursor(9, 0);
        lcd.print(abs(potValue));
        if ((potValue) < 100) lcd.print (" ");   // para que refresque el display sin parpadear
      }

    if (count == 3) { 
        lcd.setCursor(12, 0);
        lcd.write((uint8_t)4);
        lcd.setCursor(13, 0);
        lcd.print(abs(potValue));
        if ((potValue) < 100) lcd.print (" ");   // para que refresque el display sin parpadear
      }

       if (count == 4) { 
        lcd.setCursor(0, 2);
        lcd.write((uint8_t)5);
        lcd.setCursor(1, 2);
        lcd.print(abs(potValue));
        if ((potValue) < 100) lcd.print (" ");   // para que refresque el display sin parpadear
      }

    if (count == 5) { 
        lcd.setCursor(4, 2);
        lcd.write((uint8_t)6);
        lcd.setCursor(5, 2);
        lcd.print(abs(potValue));
        if ((potValue) < 100) lcd.print (" ");   // para que refresque el display sin parpadear
      }  

    if (count == 6) { 
        lcd.setCursor(8, 2);
        lcd.write((uint8_t)7);
        lcd.setCursor(9, 2);
        lcd.print(abs(potValue));
        if ((potValue) < 100) lcd.print (" ");   // para que refresque el display sin parpadear
      }  

     if (count == 7) { 
        lcd.setCursor(12, 2);
        lcd.write((uint8_t)8);
        lcd.setCursor(13, 2);
        lcd.print(abs(potValue));
        if ((potValue) < 100) lcd.print (" ");   // para que refresque el display sin parpadear
      } 

      
        }
         if (digitalRead (A4) == HIGH) {
          scene = 3;
        lcd.setCursor(0, 0);
        lcd.write("PERFORMANCE MODE      ");
        lcd.setCursor(0, 2);
        lcd.print("ACTIVE!               ");
        delay (1000);
        refreshDisplay();
          
  }

  delay (20);
  break;
        
 //////////////****Escene 5 SEQUENCER setup *****************//////////////////////
      
      case 5 :

     
         for (int count = 0; count < 8; count++)
  { //loop through each channel, checking for a signal

    int row = bin[count]; //channel 5 = 5th element in the bin list -> 101 etc.
    ///potenciometros
    r0 = bitRead(row, 0); //bitRead() -> parameter 1 = binary sequence, parameter 2 = which bit to read, starting from the right most bit
    r1 = bitRead(row, 1); //channel 7 = 111, 1 = 2nd bit
    r2 = bitRead(row, 2); // third bit

    digitalWrite(8, r0); // send the bits to the digital pins
    digitalWrite(9, r1);
    digitalWrite(10, r2);


        
   if (count == 0){
int potValue0 = analogRead (0); 
    if (abs(potValue0  - lastPotValue0) > Threshlod) {  
      stepSeq [1] = potValue0/8;
      lastPotValue0 = potValue0; 
      }
    }

    if (count == 1){
int potValue1 = analogRead (0); 
    if (abs(potValue1  - lastPotValue1) > Threshlod) {  
      stepSeq [2] = potValue1/8;
      lastPotValue1 = potValue1; 
      }
    }



       if (count == 2){
int potValue2 = analogRead (0); 
    if (abs(potValue2  - lastPotValue2) > Threshlod) {  
      stepSeq [3] = potValue2/8;
      lastPotValue2 = potValue2; 
      }
    }


    if (count == 3){
int potValue3 = analogRead (0); 
    if (abs(potValue3  - lastPotValue3) > Threshlod) {  
      stepSeq [4] = potValue3/8;
      lastPotValue3 = potValue3; 
      }
    }

    if (count == 4){
int potValue4 = analogRead (0); 
    if (abs(potValue4  - lastPotValue4) > Threshlod) {  
      stepSeq [5] = potValue4/8;
      lastPotValue4 = potValue4; 
      }
    }

    if (count == 5){
int potValue5 = analogRead (0); 
    if (abs(potValue5  - lastPotValue5) > Threshlod) {  
      stepSeq [6] = potValue5/8;
      lastPotValue5 = potValue5; 
      }
    }

    if (count == 6){
int potValue6 = analogRead (0); 
    if (abs(potValue6  - lastPotValue6) > Threshlod) {  
      stepSeq [7] = potValue6/8;
      lastPotValue6 = potValue6; 
      }
    }

    if (count == 7){
int potValue7 = analogRead (0); 
    if (abs(potValue7  - lastPotValue7) > Threshlod) {  
      stepSeq [8] = potValue7/8;
      lastPotValue7 = potValue7; 
      }
    }
   
  }




///display datos

        lcd.setCursor(0, 0);
        lcd.print("BPM ");
        lcd.setCursor(0, 2);
        lcd.print(bpm);
        if ((bpm) < 100) lcd.print (" ");
        if ((transp) < 1000) lcd.print (" ");
        
        lcd.setCursor(4, 0);
        lcd.print("KEY ");
        lcd.setCursor(4, 2);
        lcd.print(transp + 1);
        if ((transp) < 100) lcd.print (" ");

        lcd.setCursor(8, 0);
        lcd.print("M "); 
        lcd.setCursor(8, 2);
        if (randState == 0) {        
        lcd.print("f ");}
        else if (randState == 1) {
        lcd.print("r ");}

        lcd.setCursor(10, 0);
        lcd.print("R ");
        lcd.setCursor(10, 2);
        if (octavaState == 0) {  
          lcd.print("12");
        }
        else {lcd.print("24");}
      
//control transposición
transpUp= digitalRead (A2);
transpDown= digitalRead (A1);


if (( transpUp == HIGH) && (lastTranspUp != transpUp)) {
  transp = transp + 1;
}
lastTranspUp = transpUp;
if (( transpDown == HIGH) && (lastTranspDown != transpDown)) {
  transp = transp - 1;
}
lastTranspDown = transpDown;

//***control de tiempo
if ( digitalRead (11) == HIGH) {
  tempo = tempo + 1;
}
else if ( digitalRead (13) == HIGH) {
  tempo = tempo - 1;
        }

bpm = 60000 / tempo ;


 /// Control Straight / Random
      randMode =  digitalRead (A3);
      if (randMode != lastRandState) {
        if (randMode == HIGH){
         randState = 1 - randState;
            }
           }
       lastRandState = randMode;


                     
/// control de rango de 8va del potenciometro        
octava =  digitalRead (12);
if ((octava == HIGH) && (lastOctava == LOW)) {
   octavaState = 1 - octavaState;
      }
 lastOctava = octava;

if (octavaState == 0) {       
  octavaRange = 13;
  }
else {
  octavaRange = 25;
}

      
//*****control PLAY STOP

play =  digitalRead (A5);
if (play != lastPlayState) {
  if (play == HIGH ){
   playState = 1 - playState;
      }
      delay (10);
     } 
 lastPlayState = play;



//// SEQUENCER
      
if (playState == 1) {       

     if (currentMillis - prevMillis0 > (tempo / 2)  ){
              
                    if (randState == 0) {
                    seqCount = seqCount + 1;}
                    else { seqCount = random (8) + 1; }
                    
                    stepSeqIndex = map ((stepSeq [seqCount]), 0 ,127, 0 ,octavaRange)  + transp  ; // 
                    prevMillis0 = currentMillis;                                         
                    MIDI.sendNoteOff (lastStepSeqIndex, 100, 1);

                    if ((stepSeqIndex - transp) == 0 ) {
                        keyVel=0;}                
                    else {keyVel = 100;}
                    
                    MIDI.sendNoteOn (stepSeqIndex, keyVel, 1);
                    lastCount = seqCount;
                    lastStepSeqIndex = stepSeqIndex;
                    

                      }
                  if (seqCount == 8){ 
                    seqCount = 0;}  
                                          
          }
      

  if ((playState == LOW ) && (lastPlayState != playState)) {
    delay (10);
     MIDI.sendControlChange(120, 100, 1);
      MIDI.sendNoteOff (stepSeq [0], 100, 1);
      MIDI.sendNoteOff (stepSeq [1], 100, 1);
      MIDI.sendNoteOff (stepSeq [2], 100, 1);
      MIDI.sendNoteOff (stepSeq [3], 100, 1);
      MIDI.sendNoteOff (stepSeq [4], 100, 1);
      MIDI.sendNoteOff (stepSeq [5], 100, 1);
      MIDI.sendNoteOff (stepSeq [6], 100, 1);
      MIDI.sendNoteOff (stepSeq [7], 100, 1);
      MIDI.sendNoteOff (stepSeqIndex, 100, 1);
  }

///////**********///Display feedback  SEQ
    lcd.setCursor(12, 0);
    if (lastCount == 1) {
         lcd.write((uint8_t)1);
              }   
        else {lcd.write (" ");}
        
    lcd.setCursor(13, 0);
    if (lastCount == 2) {
         lcd.write((uint8_t)2);
              }   
        else {lcd.write (" ");}

    lcd.setCursor(14, 0);
    if (lastCount == 3) {
         lcd.write((uint8_t)3);
              }   
        else {lcd.write (" ");}        

    lcd.setCursor(15, 0);
    if (lastCount == 4) {
         lcd.write((uint8_t)4);
              }   
        else {lcd.write (" ");}

    
    lcd.setCursor(12, 2);
    if (lastCount == 5) {
         lcd.write((uint8_t)5);
              }   
        else {lcd.write (" ");}
        
    lcd.setCursor(13, 2);
    if (lastCount == 6) {
         lcd.write((uint8_t)6);
              }   
        else {lcd.write (" ");}

    lcd.setCursor(14, 2);
    if (lastCount == 7) {
         lcd.write((uint8_t)7);
              }   
        else {lcd.write (" ");}        

    lcd.setCursor(15, 2);
    if (lastCount == 8) {
     lcd.write((uint8_t)8);
              }   
        else {lcd.write (" ");}    



 if (digitalRead (A4) == HIGH) {
        lcd.setCursor(0, 0);
        lcd.write("PERFORMANCE MODE      ");
        lcd.setCursor(0, 2);
        lcd.print("ACTIVE!               ");
        delay (1000);  
        
        MIDI.sendControlChange(120, 100, 1);
        playState= 0;
          
        refreshDisplay();
        scene = 3;
        }        

//SEND MIDI CLOCK (no anda todavía), porque LIVE no sincroniza

//    midiCLockTime = 60000 / (bpm * 24);
//   if (currentMillis - prevMillis1 > midiCLockTime){
//    //Serial.write (248);
//    MIDI.sendRealTime(midi::Clock);
//    prevMillis1 = currentMillis;     
//    
//   }
  

        break;

 //////////****SEL CUSTOM SCENE ///////////*************************
         case 6 :
         
        lcd.setCursor(0, 0);
        lcd.print("Push Btns To Sel ");
        lcd.setCursor(0, 2);
        lcd.print("a CUSTOM  SCENE    ");   

         if (digitalRead (A3) == HIGH) {
          ctrl0 = EEPROM.read (index0);
          ctrl1 = EEPROM.read (index1);
          ctrl2 = EEPROM.read (index2);
          ctrl3 = EEPROM.read (index3);
          ctrl4 = EEPROM.read (index4);
          ctrl5 = EEPROM.read (index5);
          ctrl6 = EEPROM.read (index6);
          ctrl7 = EEPROM.read (index7);
          
        }
        
       else if (digitalRead (A1) == HIGH) {
          ctrl0 = EEPROM.read (index0 + 8);
          ctrl1 = EEPROM.read (index1 + 8);
          ctrl2 = EEPROM.read (index2 + 8);
          ctrl3 = EEPROM.read (index3 + 8);
          ctrl4 = EEPROM.read (index4 + 8);
          ctrl5 = EEPROM.read (index5 + 8);
          ctrl6 = EEPROM.read (index6 + 8);
          ctrl7 = EEPROM.read (index7 + 8);
        }
       
        else if (digitalRead (A2) == HIGH) {
          ctrl0 = EEPROM.read (index0 + 16);
          ctrl1 = EEPROM.read (index1 + 16);
          ctrl2 = EEPROM.read (index2 + 16);
          ctrl3 = EEPROM.read (index3 + 16);
          ctrl4 = EEPROM.read (index4 + 16);
          ctrl5 = EEPROM.read (index5 + 16);
          ctrl6 = EEPROM.read (index6 + 16);
          ctrl7 = EEPROM.read (index7 + 16);

        }

        else if (digitalRead (12) == HIGH) {
          ctrl0 = EEPROM.read (index0 + 24);
          ctrl1 = EEPROM.read (index1 + 24);
          ctrl2 = EEPROM.read (index2 + 24);
          ctrl3 = EEPROM.read (index3 + 24);
          ctrl4 = EEPROM.read (index4 + 24);
          ctrl5 = EEPROM.read (index5 + 24);
          ctrl6 = EEPROM.read (index6 + 24);
          ctrl7 = EEPROM.read (index7 + 24);

          
         }

        else if (digitalRead (11) == HIGH) {
          ctrl0 = EEPROM.read (index0 + 32);
          ctrl1 = EEPROM.read (index1 + 32);
          ctrl2 = EEPROM.read (index2 + 32);
          ctrl3 = EEPROM.read (index3 + 32);
          ctrl4 = EEPROM.read (index4 + 32);
          ctrl5 = EEPROM.read (index5 + 32);
          ctrl6 = EEPROM.read (index6 + 32);
          ctrl7 = EEPROM.read (index7 + 32);

         }


        else  if (digitalRead (13) == HIGH) {
          ctrl0 = EEPROM.read (index0 + 40);
          ctrl1 = EEPROM.read (index1 + 40);
          ctrl2 = EEPROM.read (index2 + 40);
          ctrl3 = EEPROM.read (index3 + 40);
          ctrl4 = EEPROM.read (index4 + 40);
          ctrl5 = EEPROM.read (index5 + 40);
          ctrl6 = EEPROM.read (index6 + 40);
          ctrl7 = EEPROM.read (index7 + 40);

        }


        

        if (digitalRead(A3) == HIGH) {
          lcd.setCursor(0, 0);
          lcd.print("CUSTOM SCENE 1    ");
          lcd.setCursor(0, 2);
          lcd.print("SELECTED          ");
          delay (1000);
          refreshDisplay();
          scene = 3;
         
        }

        else if (digitalRead(A1) == HIGH) {
          lcd.setCursor(0, 0);
          lcd.print("CUSTOM SCENE 2           ");
          lcd.setCursor(0, 2);
          lcd.print("SELECTED          ");
          delay (1000);
          refreshDisplay();
          scene = 3;
        }

        else if (digitalRead(A2) == HIGH) {
          lcd.setCursor(0, 0);
          lcd.print("CUSTOM SCENE 3           ");
          lcd.setCursor(0, 2);
          lcd.print("SELECTED          ");
          delay (1000);
          refreshDisplay();
         scene = 3;
        }
   

        else if (digitalRead(12) == HIGH) {
          lcd.setCursor(0, 0);
          lcd.print("CUSTOM SCENE 4           ");
          lcd.setCursor(0, 2);
          lcd.print("SELECTED          ");
          delay (1000);
          refreshDisplay();
          scene = 3;
        }
  

        else if (digitalRead(11) == HIGH) {
          lcd.setCursor(0, 0);
          lcd.print("SCENE 5           ");
          lcd.setCursor(0, 2);
          lcd.print("SELECTED          ");
          delay (1000);
          refreshDisplay();
          scene = 3;
        }
      

        else if (digitalRead(13) == HIGH) {
          lcd.setCursor(0, 0);
          lcd.print("CUSTOM SCENE 6           ");
          lcd.setCursor(0, 2);
          lcd.print("SELECTED          ");
          delay (1000);
          refreshDisplay();
          scene = 3;
        }
        
        delay (10);

  
      break;
      
////////////////*********SCENE 3 PERFORMANCE*******************////////////////////////////
case 3: 


  for (int count = 0; count < 8; count++)
  { //loop through each channel, checking for a signal

    int row = bin[count]; //channel 5 = 5th element in the bin list -> 101 etc.
    ///potenciometros
    r0 = bitRead(row, 0); //bitRead() -> parameter 1 = binary sequence, parameter 2 = which bit to read, starting from the right most bit
    r1 = bitRead(row, 1); //channel 7 = 111, 1 = 2nd bit
    r2 = bitRead(row, 2); // third bit

    digitalWrite(8, r0); // send the bits to the digital pins
    digitalWrite(9, r1);
    digitalWrite(10, r2);

    //***************MIDI CC KNOBS*************************

    
if (count == 0){
int potValue0 = analogRead (0); //escaleo el rango 0-1023
    if (abs(potValue0  - lastPotValue0) > Threshlod) {  //solo manda valores si es distinto y coincide con el count 0
      MIDI.sendControlChange(ctrl0, potValue0 / 8, 1);
      lastPotValue0 = potValue0;    
      
      if (buttonState1 == HIGH) {
        lcd.setCursor(0, 0);
        lcd.write("o");
      }
      else {
        lcd.setCursor(0, 0);
        lcd.write((uint8_t)1);
        lcd.setCursor(1, 0);
        lcd.print(potValue0 / 8);
        if ((potValue0 / 8) < 100){ lcd.print (" ");}       
      }
      
      }
    }
 
    
if (count == 1){
int potValue1 = analogRead (0); //escaleo el rango 0-1023
    if (abs(potValue1  - lastPotValue1) > Threshlod) {  //solo manda valores si es distinto y coincide con el count 0
      MIDI.sendControlChange(ctrl1, potValue1 / 8, 1);
     lastPotValue1 = potValue1; // queda el ultimo valor del pote.


      if (buttonState2 == HIGH) {
        lcd.setCursor(4, 0);
        lcd.write("o");
      }
      else {
        lcd.setCursor(4, 0);
        lcd.write((uint8_t)2);
        lcd.setCursor(5, 0);
        lcd.print(potValue1/8);
        if ((potValue1/8) < 100) lcd.print (" ");
      }
      }
      
    }
     

if (count == 2){
int potValue2 = analogRead (0); //escaleo el rango 0-1023
    if (abs(potValue2  - lastPotValue2) > Threshlod) {  //solo manda valores si es distinto y coincide con el count 0
      MIDI.sendControlChange(ctrl2, potValue2 / 8, 1);
      lastPotValue2 = potValue2; 

       if (buttonState3 == HIGH) {
        lcd.setCursor(8, 0);
        lcd.write("o");
      }
      else {
        lcd.setCursor(8, 0);
        lcd.write((uint8_t)3);
        lcd.setCursor(9, 0);
        lcd.print(abs(potValue2/8));
        if ((potValue2/8) < 100) lcd.print (" ");
      }
 
      }
        
    }
    

if (count == 3){
int potValue3 = analogRead (0); //escaleo el rango 0-1023
    if (abs(potValue3  - lastPotValue3) > Threshlod) {  //solo manda valores si es distinto y coincide con el count 0
      MIDI.sendControlChange(ctrl3, potValue3 / 8, 1);
       lastPotValue3 = potValue3; 


     if (buttonState8 == HIGH) {
        lcd.setCursor(12, 0);
        lcd.write("o");
      }
      else {
        lcd.setCursor(12, 0);
        lcd.write((uint8_t)4);
        lcd.setCursor(13, 0);
        lcd.print(abs(potValue3/8));
        if ((potValue3/8) < 100) lcd.print (" ");
      }
      }
       
    }
   

if (count == 4){
int potValue4 = analogRead (0); //escaleo el rango 0-1023
    if (abs(potValue4  - lastPotValue4) > Threshlod) {  //solo manda valores si es distinto y coincide con el count 0
      MIDI.sendControlChange(ctrl4, potValue4 / 8, 1);
         lastPotValue4 = potValue4;


     if (buttonState4 == HIGH) {
        lcd.setCursor(0, 2);
        lcd.write("o");
      }
      else {
        lcd.setCursor(0, 2);
        lcd.write((uint8_t)5);
        lcd.setCursor(1, 2);
        lcd.print(abs(potValue4/8));
        if ((potValue4/8) < 100) lcd.print (" ");   // para que refresque el display sin parpadear
      }
      }
       
    }    


if (count == 5){
int potValue5 = analogRead (0); //escaleo el rango 0-1023
    if (abs(potValue5  - lastPotValue5) > Threshlod) {  //solo manda valores si es distinto y coincide con el count 0
      MIDI.sendControlChange(ctrl5, potValue5 / 8, 1);
      lastPotValue5 = potValue5; // queda el ultimo valor del pote.

  if (buttonState5 == HIGH) {
        lcd.setCursor(4, 2);
        lcd.write("o");
      }
      else {
        lcd.setCursor(4, 2);
        lcd.write((uint8_t)6);
        lcd.setCursor(5, 2);
        lcd.print(abs(potValue5/8));
        if ((potValue5/8) < 100) lcd.print (" ");   // para que refresque el display sin parpadear
      }
 
      } 
    }
    

if (count == 6){
int potValue6 = analogRead (0); //escaleo el rango 0-1023
    if (abs(potValue6  - lastPotValue6) > Threshlod) {  //solo manda valores si es distinto y coincide con el count 0
      MIDI.sendControlChange(ctrl6, potValue6 / 8, 1);
       lastPotValue6 = potValue6; // queda el ultimo valor del pote.

       if (buttonState6 == HIGH) {
        lcd.setCursor(8, 2);
        lcd.write("o");
      }
      else {
        lcd.setCursor(8, 2);
        lcd.write((uint8_t)7);
        lcd.setCursor(9, 2);
        lcd.print(abs(potValue6/8));
        if ((potValue6/8) < 100) lcd.print (" ");   // para que refresque el display sin parpadear
      }
      
      }
       
    }
   
if (count == 7){
int potValue7 = analogRead (0); //escaleo el rango 0-1023
    if (abs(potValue7  - lastPotValue7) > Threshlod) {  //solo manda valores si es distinto y coincide con el count 0
      MIDI.sendControlChange(ctrl7, potValue7 / 8, 1);
      
    lastPotValue7 = potValue7;
    if (buttonState7 == HIGH) {
        lcd.setCursor(12, 2);
        lcd.write("o");
      }
      else {
        lcd.setCursor(12, 2);
        lcd.write((uint8_t)8);
        lcd.setCursor(13, 2);
        lcd.print(abs(potValue7/8));
        if ((potValue7/8) < 100) lcd.print (" ");   // para que refresque el display sin parpadear
      }
      }
      
    }
    //****************BUTTONS*********************************

    int buttonState1 = digitalRead(A3);
    if (buttonState1 != lastButtonState1) {
      if (buttonState1 == HIGH) {
        MIDI.sendNoteOn(buttonNote1, 100, 1);
      }
      else {
        MIDI.sendNoteOff(buttonNote1, 0, 1);
      }
    }
    lastButtonState1 = buttonState1;


    int buttonState2 = digitalRead(A1);
    if (buttonState2 != lastButtonState2) {
      if (buttonState2 == HIGH) {
        MIDI.sendNoteOn(buttonNote2, 100, 1);
      }
      else {
        MIDI.sendNoteOff(buttonNote2, 0, 1);
      }
    }
    lastButtonState2 = buttonState2;


    int buttonState3 = digitalRead(A2);
    if (buttonState3 != lastButtonState3) {
      if (buttonState3 == HIGH) {
        MIDI.sendNoteOn(buttonNote3, 100, 1);
      }
      else {
        MIDI.sendNoteOff(buttonNote3, 0, 1);
      }
    }
    lastButtonState3 = buttonState3;


    int buttonState4 = digitalRead(12);
    if (buttonState4 != lastButtonState4) {
      if (buttonState4 == HIGH) {
        MIDI.sendNoteOn(buttonNote4, 100, 1);
      }
      else {
        MIDI.sendNoteOff(buttonNote4, 0, 1);
      }
    }
    lastButtonState4 = buttonState4;


    int buttonState5 = digitalRead(11);
    if (buttonState5 != lastButtonState5) {
      if (buttonState5 == HIGH) {
        MIDI.sendNoteOn(buttonNote5, 100, 1);
      }
      else {
        MIDI.sendNoteOff(buttonNote5, 0, 1);
      }
    }
    lastButtonState5 = buttonState5;


    int buttonState6 = digitalRead(13);
    if (buttonState6 != lastButtonState6) {
      if (buttonState6 == HIGH) {
        MIDI.sendNoteOn(buttonNote6, 100, 1);
      }
      else {
        MIDI.sendNoteOff(buttonNote6, 0, 1);
      }
    }
    lastButtonState6 = buttonState6;


    int buttonState7 = digitalRead(A4);
    if (buttonState7 != lastButtonState7) {
      if (buttonState7 == HIGH) {
        MIDI.sendNoteOn(buttonNote7, 100, 1);
      }
      else {
        MIDI.sendNoteOff(buttonNote7, 0, 1);
      }
    }
    lastButtonState7 = buttonState7;


    int buttonState8 = digitalRead(A5);
    if (buttonState8 != lastButtonState8) {
      if (buttonState8 == HIGH) {
        MIDI.sendNoteOn(buttonNote8, 100, 1);
      }
      else {
        MIDI.sendNoteOff(buttonNote8, 0, 1);
      }
    }
    lastButtonState8 = buttonState8;


     
    ///********************************************************
    delay (10); // time to read the values
  
 
    } ///cierra el for
     break;
  } //cierra switch loop
}

