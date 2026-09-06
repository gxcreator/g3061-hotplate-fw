#ifndef I2C_H
#define I2C_H

#include <stdint.h>

/* Single board-wired bus; link one software or hardware implementation.
 * Callers supply address and payload bytes, each followed by an ACK clock. */
void i2c_init(void);
void i2c_start(void);
void i2c_stop(void);
void i2c_write_byte(uint8_t dat);
/* Release SDA and clock the ninth bit, without checking ACK/NACK. */
void i2c_clock_ack(void);

#endif
