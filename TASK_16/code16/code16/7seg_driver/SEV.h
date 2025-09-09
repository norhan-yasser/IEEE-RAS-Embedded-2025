#ifndef SEV_H_
#define SEV_H_

#include "../utilities/types.h"

/* initialize 7-seg (segments mapped to a port/pins in config below) */
void Sev_Init(void);

/* display 0..9 on the single 7-seg */
void Sev_DisplayNumber(uint8_t num);

#endif /* SEV_H_ */
