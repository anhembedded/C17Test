

#ifndef C17TEST_U_STDINT_H
#define C17TEST_U_STDINT_H

#include <stdint.h>

#define pd_BOOL_T uint8_t



/* BASIC BITWISE MACRO */
#define pd_BIT_SET(a, b) ((a) |= (1UL << (b)))
#define pd_BIT_CLEAR(a, b) ((a) &= ~(1UL << (b)))
#define pd_BIT_TOGGLE(a, b) ((a) ^= (1UL << (b)))
#define pd_BIT_READ(a, b) (!!((a) & (1UL << (b)))) // '!!' to make sure this returns 0 or 1
#define pd_SET_BIT(a, b) ((a) |= (1UL << (b)))
#define pd_CLEAR_BIT(a, b) ((a) &= ~(1UL << (b)))
#define pd_TOGGLE_BIT(a, b) ((a) ^= (1UL << (b)))
#define pd_READ_BIT(a, b) (!!((a) & (1UL << (b)))) // '!!' to make sure this returns 0 or 1
#define pd_CLEAR_REG(REG) ((REG) = (0x0))
#define pd_WRITE_REG(REG, VAL) ((REG) = (VAL))
#define pd_READ_REG(REG) ((REG))
#define pd_MODIFY_REG(REG, CLEARMASK, SETMASK) pd_WRITE_REG((REG), (((pd_READ_REG(REG)) & (~(CLEARMASK))) | (SETMASK)))
#define pd_LOWBYTE(w) ((uint8_t) ((w) & 0xff))
#define pd_HIGHBYTE(w) ((uint8_t) ((w) >> 8))
#define pd_CONSTRAIN(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))
#define pd_READ_BIT_MASK(R,P,M) (((R)>>(P))&((M)))
#define pd_WAIT_UNTIL(a) while(!(a))


#define pd__SFI    /*FORCE static inline __STATIC_FORCEINLINE*/
#define pd_UN_WAIT_UNTIL(condition) while (!(condition))
#define pd_waitUntil UN_WAIT_UNTIL
#define pd_MASK(x) (0b01 << (x))

#define pd_UNUSED(X) (void)X



static inline void pd_delayUs(uintmax_t delayUsTime)
{
    //todo: implement that function platform
}
static inline void pd_delayMs(uintmax_t delayMsTime)
{
    //todo: implement that function platform
}
static inline void pd_delayCyc(uintmax_t delayCycTime)
{
    //todo: implement that function platform
}
static inline void pd_NOP()
{
    //todo: implement that function platform
}


#define  pd_disableIqr pd_NOP  //interrupt flags still set but not handled
#define pd_enableIqr pd_NOP





#endif //C17TEST_U_STDINT_H
