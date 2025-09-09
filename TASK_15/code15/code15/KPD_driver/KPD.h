

#ifndef KPD_H_
#define KPD_H_

#include "../utilities/types.h"

#define NOTPRESSED 0xff

void KPD_Init(void);
uint8_t  KPD_u8GetPressed( void );

#endif /* KPD_H_ */
