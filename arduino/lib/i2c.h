#ifndef I2C_H
#define I2C_H


void i2c_init(void);
unsigned char i2c_start(unsigned char address);
unsigned char i2c_write(unsigned char data);
unsigned char i2c_read_ack(void);
unsigned char i2c_read_nack(void);
void i2c_stop(void);

#endif // I2C_MASTER_H
