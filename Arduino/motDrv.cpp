#include "arduino.h"
#include "motDrv.h"
#include "PinIO.h"
#include "LogUtil.h"

//---------------------------
// モーター制御初期化
//---------------------------
void mot_init(void){
	pinMode(MOT_PORT_OUT1, OUTPUT);
	pinMode(MOT_PORT_OUT2, OUTPUT);
	pinMode(MOT_PORT_PWM, OUTPUT);
}

//---------------------------
// DCモーター制御
// port1_out:HIGH/LOW
// port2_out:HIGH/LOW
//---------------------------
void mot_control(boolean port1_out, boolean port2_out){
	digitalWrite(MOT_PORT_OUT1, port1_out);
	digitalWrite(MOT_PORT_OUT2, port2_out);
}

//---------------------------
// DCモーターPWM制御
// pwm:0～255(DCモーターDuty)
//---------------------------
void mot_pwm_control(UCHAR pwm){
	analogWrite(MOT_PORT_PWM, pwm);
}

//----------------------------
// 前進
//----------------------------
void hdrDriveFront(int level){
    Serial.print("Front");timeStamp();Serial.print(level,DEC);ln();
}
//----------------------------
// バック
//----------------------------
void hdrDriveBack(int level){
    Serial.print("Back");timeStamp();Serial.print(level,DEC);ln();
}

