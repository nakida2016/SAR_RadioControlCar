#ifndef servDrv_H_
#define servDrv_H_

// 構成(モーター、ポート、入力値など)に合わせて変更
#define SERV_PORT_PWM          3  // サーボモーター制御 ポート
#define SERV_CNT_INPUT_LOW     0  // サーボモーター制御 入力下限
#define SERV_CNT_INPUT_HI   1023  // サーボモーター制御 入力上限
#define SERV_CNT_OUTPUT_LOW 1000  // サーボモーター制御 出力下限
#define SERV_CNT_OUTPUT_HI  2000  // サーボモーター制御 出力上限

extern void serv_init(void);
extern void serv_pwm_control(int pwm);
#endif
