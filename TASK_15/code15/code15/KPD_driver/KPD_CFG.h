/*
 * KPD_CFG.h
 *
 * Created: 09-Sep-25 9:04:26 PM
 *  Author: Yasser Khidr
 */ 


#ifndef KPD_CFG_H_
#define KPD_CFG_H_

#define KPD_ROW_INIT  0
#define KPD_ROW_END   3

#define KPD_COL_INIT  4
#define KPD_COL_END   7

/* Keypad button layout */
extern const uint8_t KPD_u8Buttons[4][4];


#define KPD_PORT  PORT_C

/* Row pins */
#define KPD_R0    0
#define KPD_R1    1
#define KPD_R2    2
#define KPD_R3    3

/* Column pins */
#define KPD_C0    4
#define KPD_C1    5
#define KPD_C2    6
#define KPD_C3    7

#endif /* KPD_CFG_H_ */
