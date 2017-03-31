#include "arduino.h"
#include "Servo.h"
#include "servDrv.h"

Servo servo;

//---------------------------
// サーボモーター制御初期化
//---------------------------
void serv_init(void){
	servo.attach(SERV_PORT_PWM);
}

//---------------------------
// サーボモーターPWM制御
// pwm:0～1023(仮)
//---------------------------
void serv_pwm_control(int pwm){
	// 入力変換
	pwm = map(pwm, SERV_CNT_INPUT_LOW, SERV_CNT_INPUT_HI, SERV_CNT_OUTPUT_LOW, SERV_CNT_OUTPUT_HI);
	// パルス幅設定
	servo.writeMicroseconds(pwm);
}
