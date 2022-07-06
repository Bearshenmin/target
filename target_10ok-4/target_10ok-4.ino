/*
 * Generated using BlocklyDuino:
 *
 * https://github.com/MediaTek-Labs/BlocklyDuino-for-LinkIt
 *
 * Date: Mon, 04 Jul 2022 01:58:35 GMT
 */
#include <IRremote.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd_i2c(0x27);

#include <Servo.h>

IRrecv irrecv(8);
decode_results results;
String myCodeType;
String myIRcode;
String ir_type(int tip)
{
  if (tip == 1){
    return "RC5";
  } else if (tip == 2){
    return "RC6";
  } else if (tip == 3){
    return "NEC";
  } else if (tip == 4){
    return "SONY";
  } else if (tip == 5){
    return "PANASONIC";
  } else if (tip == 6){
    return "JVC";
  } else if (tip == 7){
    return "SAMSUNG";
  } else if (tip == 10){
    return "LG";
  } else if (tip == 14){
    return "SHARP";
  } else if (tip == 17){
    return "LEGO_PF";
  } else {
    return "UNKNOWN";
  }
}

long T1 = 0;
int Angel1 = 90;
int _E5_A2_9E_E9_87_8F1 = 0;
long T2 = 0;
int Angel2 = 90;
int _E5_A2_9E_E9_87_8F2 = 0;
long T3 = 0;
int Angel3 = 90;
int _E5_A2_9E_E9_87_8F3 = 0;
long T4 = 0;
int Angel4 = 90;
int _E5_A2_9E_E9_87_8F4 = 0;
int _E5_AE_9A_E6_99_82_E9_96_93_E9_9A_94 = 20;
int _E6_9C_80_E5_A4_A7_E5_80_BC = 10;
Servo __myservo4;
void func1() {
  if (millis() - T1 > _E5_AE_9A_E6_99_82_E9_96_93_E9_9A_94) {
    if (analogRead(A0) > 350) {
      _E5_A2_9E_E9_87_8F1 = 0;
      Angel1 = 180;
      __myservo4.write(180);
    } else {
      if (Angel1 < 0 || Angel1 > 180) {
        _E5_A2_9E_E9_87_8F1 = 0 - _E5_A2_9E_E9_87_8F1;
      }
      __myservo4.write(Angel1);
      Angel1 = Angel1 + _E5_A2_9E_E9_87_8F1;
    }
    T1 = millis();
  }
}

Servo __myservo5;
void func2() {
  if (millis() - T2 > _E5_AE_9A_E6_99_82_E9_96_93_E9_9A_94) {
    if (analogRead(A1) > 550) {
      _E5_A2_9E_E9_87_8F2 = 0;
      Angel2 = 180;
      __myservo5.write(Angel2);
    } else {
      if (Angel2 < 0 || Angel2 > 180) {
        _E5_A2_9E_E9_87_8F2 = 0 - _E5_A2_9E_E9_87_8F2;
      }
      __myservo5.write(Angel2);
      Angel2 = Angel2 + _E5_A2_9E_E9_87_8F2;
    }
    T2 = millis();
  }
}

Servo __myservo6;
void func3() {
  if (millis() - T3 > _E5_AE_9A_E6_99_82_E9_96_93_E9_9A_94) {
    if (analogRead(A2) > 350) {
      _E5_A2_9E_E9_87_8F3 = 0;
      Angel3 = 180;
      __myservo6.write(Angel3);
    } else {
      if (Angel3 < 0 || Angel3 > 180) {
        _E5_A2_9E_E9_87_8F3 = 0 - _E5_A2_9E_E9_87_8F3;
      }
      __myservo6.write(Angel3);
      Angel3 = Angel3 + _E5_A2_9E_E9_87_8F3;
    }
    T3 = millis();
  }
}

Servo __myservo7;
void func4() {
  if (millis() - T4 > _E5_AE_9A_E6_99_82_E9_96_93_E9_9A_94) {
    if (analogRead(A3) > 350) {
      _E5_A2_9E_E9_87_8F4 = 0;
      Angel4 = 180;
      __myservo7.write(Angel4);
    } else {
      if (Angel4 < 0 || Angel4 > 180) {
        _E5_A2_9E_E9_87_8F4 = 0 - _E5_A2_9E_E9_87_8F4;
      }
      __myservo7.write(Angel4);
      Angel4 = Angel4 + _E5_A2_9E_E9_87_8F4;
    }
    T4 = millis();
  }
}

void setup()
{
  irrecv.enableIRIn();

  lcd_i2c.begin(16, 2);
  lcd_i2c.backlight();
  lcd_i2c.clear();
  for (int count = 0; count < 3; count++) {
    lcd_i2c.clear();
    lcd_i2c.setCursor(0,0);
    lcd_i2c.print("Loading.");
    delay(300);
    lcd_i2c.setCursor(0,0);
    lcd_i2c.print("Loading..");
    delay(300);
    lcd_i2c.setCursor(0,0);
    lcd_i2c.print("Loading...");
    delay(300);
  }
  lcd_i2c.print("Done");
  delay(700);
  lcd_i2c.clear();
  lcd_i2c.setCursor(0,0);
  lcd_i2c.print("OK!GO~");
  __myservo4.attach(4);
  __myservo5.attach(5);
  __myservo6.attach(6);
  __myservo7.attach(7);
}

void loop()
{
  if (irrecv.decode(&results)) {
    if (results.decode_type>0){
      myCodeType=ir_type(results.decode_type);
      myIRcode=String(results.value, HEX);
      if (myIRcode == "101000ff") {
        Angel1 = 90;
        _E5_A2_9E_E9_87_8F1 = 0;
        Angel2 = 90;
        _E5_A2_9E_E9_87_8F2 = 0;
        Angel3 = 90;
        _E5_A2_9E_E9_87_8F3 = 0;
        Angel4 = 90;
        _E5_A2_9E_E9_87_8F4 = 0;
      }
      if (myIRcode == "1010807f") {
        Angel1 = random(20, 160);
        _E5_A2_9E_E9_87_8F1 = 1;
        Angel2 = random(20, 160);
        _E5_A2_9E_E9_87_8F2 = 1;
        Angel3 = random(20, 160);
        _E5_A2_9E_E9_87_8F3 = 1;
        Angel4 = random(20, 160);
        _E5_A2_9E_E9_87_8F4 = 1;
      }
      if (myIRcode == "101040bf") {
        Angel1 = random(20, 160);
        _E5_A2_9E_E9_87_8F1 = 4;
        Angel2 = random(20, 160);
        _E5_A2_9E_E9_87_8F2 = 4;
        Angel3 = random(20, 160);
        _E5_A2_9E_E9_87_8F3 = 4;
        Angel4 = random(20, 160);
        _E5_A2_9E_E9_87_8F4 = 4;
      }
      if (myIRcode == "1010c03f") {
        Angel1 = random(20, 160);
        _E5_A2_9E_E9_87_8F1 = 7;
        Angel2 = random(20, 160);
        _E5_A2_9E_E9_87_8F2 = 7;
        Angel3 = random(20, 160);
        _E5_A2_9E_E9_87_8F3 = 7;
        Angel4 = random(20, 160);
        _E5_A2_9E_E9_87_8F4 = 7;
      }
      if (myIRcode == "101020df") {
        Angel1 = 180;
        _E5_A2_9E_E9_87_8F1 = 0;
        Angel2 = 180;
        _E5_A2_9E_E9_87_8F2 = 0;
        Angel3 = 180;
        _E5_A2_9E_E9_87_8F3 = 0;
        Angel4 = 180;
        _E5_A2_9E_E9_87_8F4 = 0;
      }
    }
    irrecv.resume();
  }
  func1();
  func2();
  func3();
  func4();
}
