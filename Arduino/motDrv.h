#ifndef motDrv_H_
#define motDrv_H_

typedef unsigned char UCHAR;

// 構成に合わせて変更
//#define MOT_PORT_OUT1 1   // モーター制御 OUT1
//#define MOT_PORT_OUT2 2   // モーター制御 OUT2
//#define MOT_PORT_PWM  3   // モーター制御 PWM
#define MOT_DC_ON_CW   mot_control(LOW, HIGH);   // CW
#define MOT_DC_ON_CCW  mot_control(HIGH, LOW);   // CCW
#define MOT_DC_BRAKE   mot_control(HIGH, HIGH);  // BRAKE
#define MOT_DC_STOP    mot_control(LOW, LOW);    // STOP

extern void mot_init(void);
extern void mot_control(boolean port1_out,boolean port2_out);
extern void mot_pwm_control(UCHAR pwm);
extern void hdrDriveFront(int level);
extern void hdrDriveBack(int level); 
#endif
