#ifndef servDrv_H_
#define servDrv_H_

// 構成(モーター、ポート、入力値など)に合わせて変更

// サーボモータ制御入力値　0～100、50センター値
#define SERV_CNT_INPUT_LOW    0         // サーボモーター制御 入力下限
#define SERV_CNT_INPUT_HI     100       // サーボモーター制御 入力上限

// サーボモータ制御出力角度(サーボモーターの性能によって変える)
#define SERV_CNT_OUTPUT_LOW   0         // サーボモーター制御 出力下限
#define SERV_CNT_OUTPUT_HI    170       // サーボモーター制御 出力上限

extern void serv_init(void);
extern void serv_pwm_control(int pwm);
extern void hdrTurnRight(int level);
extern void hdrTurnLeft(int level);
#endif
