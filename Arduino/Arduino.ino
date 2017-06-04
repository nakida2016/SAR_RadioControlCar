#include <MsTimer2.h>
#include "PinIO.h"
#include "LedBlink.h"
#include "servDrv.h"
#include "motDrv.h"

//-----------------------------------------------------------------
// 初期処理
//-----------------------------------------------------------------
void setup() {
  // put your setup code here, to run once:
  pinModeSetup();
  Serial.begin(9600);
  timerTaskSetup();

  // テスト用初期設定
//  motStg = MOT_OFF;
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

// DCモーターテスト
//  switch(motStg){
//    case MOT_CW:
//      motStg = MOT_BRAKE;
//      // CW/CCW
//      MOT_DC_ON_CW;
//      mot_pwm_control(255);
//      break;
//    case MOT_CCW:
//      // CCW/CW
//      MOT_DC_ON_CCW;
//      mot_pwm_control(255);
//      motStg = MOT_OFF;
//      break;
//    case MOT_BRAKE:
//      // ブレーキ
//      MOT_DC_BRAKE;
//      mot_pwm_control(0);
//      motStg = MOT_CCW;
//      break;
////  case MOT_OFF:
//    default:
//      // 停止
//      MOT_DC_STOP;
//      mot_pwm_control(0);
//      motStg = MOT_CW;
//      break;
//  }
//
//  delay(3000);

}

//-----------------------------------------------------------------
// PinIO初期化関数
//-----------------------------------------------------------------
void pinModeSetup(void){
  pinMode( WORKING_LED , OUTPUT);
  serv_init(); // サーボモーター制御初期化
  mot_init();  // DCモーター制御初期化
}

//-----------------------------------------------------------------
// 定周期タスク登録&開始
//-----------------------------------------------------------------
void timerTaskSetup(){
  MsTimer2::set(BLINK_TIMER,ledBlink);  // LED点滅
  MsTimer2::start();
}

