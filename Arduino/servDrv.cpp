#include "arduino.h"
#include "Servo.h"
#include "servDrv.h"
#include "PinIO.h"
#include "LogUtil.h"

Servo servo;

//---------------------------
// サーボモーター制御初期化
//---------------------------
void serv_init(void){
	servo.attach(SERV_PORT_PWM);
}
//---------------------------
// サーボモーターPWM制御
// pwm:0～100
//---------------------------
void serv_pwm_control(int pwm){
  // 上限下限値判定
  if(( SERV_CNT_INPUT_LOW > pwm ) ||
     ( SERV_CNT_INPUT_HI < pwm) ){
      Serial.print("SRVPWM");timeStamp();Serial.print("Range Error");ln();
      return;
  }
	// 入力変換
  pwm = map(pwm, SERV_CNT_INPUT_LOW, SERV_CNT_INPUT_HI, SERV_CNT_OUTPUT_LOW, SERV_CNT_OUTPUT_HI);

  // パルス幅設定
//  servo.writeMicroseconds(pwm);
  servo.write(pwm);
  Serial.print("SRVPWM");timeStamp();Serial.print(pwm,DEC);ln();
  
}

//--------------
// 右旋回
//--------------
void hdrTurnRight(int level){
  Serial.print("Turn Right");timeStamp();Serial.print(level,DEC);ln();
  switch(level){
    case '1':serv_pwm_control(100);break;
//    case '2':serv_pwm_control(100);break;
//    case '3':serv_pwm_control(100);break;
//    case '4':serv_pwm_control(100);break;
//    case '5':serv_pwm_control(100);break;
    default:break;
  }
}
//--------------
// 左旋回
//--------------
void hdrTurnLeft(int level){
  Serial.print("Turn Left");timeStamp();Serial.print(level,DEC);ln(); 
  switch(level){
    case '1':serv_pwm_control(0);break;
//    case '2':serv_pwm_control(0);break;
//    case '3':serv_pwm_control(0);break;
//    case '4':serv_pwm_control(0);break;
//    case '5':serv_pwm_control(0);break;
    default:break;
  }
}

