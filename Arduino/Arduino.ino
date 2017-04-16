#include <MsTimer2.h>
#include "PinIO.h"
#include "LedBlink.h"
#include "servDrv.h"

//-----------------------------------------------------------------
// 初期処理
//-----------------------------------------------------------------
void setup() {
  // put your setup code here, to run once:
  pinModeSetup();
  Serial.begin(9600);
  timerTaskSetup();
}

//-----------------------------------------------------------------
// メインループ
//-----------------------------------------------------------------
void loop() {
  // put your main code here, to run repeatedly:

// サーボテスト
//  serv_pwm_control(0);
//  delay(1000);
//  serv_pwm_control(30);
//  delay(1000);
//  serv_pwm_control(45);
//  delay(1000);
//  serv_pwm_control(90);
//  delay(1000);
//  serv_pwm_control(120);
//  delay(1000);
//  serv_pwm_control(180);
//  delay(1000);
//  serv_pwm_control(600);
//  delay(1000);
//  serv_pwm_control(1024);
//  delay(1000);

}

//-----------------------------------------------------------------
// PinIO初期化関数
//-----------------------------------------------------------------
void pinModeSetup(void){
  pinMode( WORKING_LED , OUTPUT);
  serv_init();
}

//-----------------------------------------------------------------
// 定周期タスク登録&開始
//-----------------------------------------------------------------
void timerTaskSetup(){
  MsTimer2::set(BLINK_TIMER,ledBlink);  // LED点滅
  MsTimer2::start();
}

