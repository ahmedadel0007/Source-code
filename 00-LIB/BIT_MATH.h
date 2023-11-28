#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(REG,BIT)      (REG |= (1<<BIT))
#define CLR_BIT(REG,BIT)      (REG &= ~(1<<BIT))
#define GET_BIT(REG,BIT)      ((REG >> BIT) & 0x01)
#define TOG_BIT(REG,BIT)      (REG ^= (1<<BIT))

#define SET_PORT(REG)         (REG |= 0xFF)
#define CLR_PORT(REG)         (REG &= 0x00)
#define TOG_PORT(REG)         (REG ^= 0xFF)

#endif