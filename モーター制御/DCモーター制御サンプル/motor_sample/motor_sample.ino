/* ----------------------------
 *  モーター制御サンプル
 *  正転・逆転繰り返し
 *----------------------------*/
 
#include "motDrv.h"

enum{
  MOT_OFF = 0
, MOT_CW
, MOT_CCW
, MOT_BRAKE
};

UCHAR motStg;

void setup(){
  // モーター制御初期化
  mot_init();
  motStg = MOT_OFF;
}

void loop(){

  switch(motStg){
    case MOT_CW:
      motStg = MOT_BRAKE;
      // CW/CCW
      MOT_DC_ON_CW;
      mot_pwm_control(255);
      break;
    case MOT_CCW:
      // CCW/CW
      MOT_DC_ON_CCW;
      mot_pwm_control(255);
      motStg = MOT_OFF;
      break;
    case MOT_BRAKE:
      // ブレーキ
      MOT_DC_BRAKE;
      mot_pwm_control(0);
      motStg = MOT_CCW;
      break;
//  case MOT_OFF:
    default:
      // 停止
      MOT_DC_STOP;
      mot_pwm_control(0);
      motStg = MOT_CW;
      break;
  }

  delay(3000);
}
