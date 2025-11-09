#ifndef I2C_EEPROM_H
#define I2C_EEPROM_H

#include <stdint.h>

// I2C EEPROM 24C02 interface functions (Linux only)

/**
 * Open I2C device
 * @param path - device path (e.g., "/dev/i2c-0")
 * @param port_settings - unused, for future compatibility
 * @return file descriptor on success, -1 on error
 */
int iic_open(const char* path, const char* port_settings);

/**
 * Close I2C device
 * @param i2c_fd - file descriptor from iic_open()
 */
void iic_close(int i2c_fd);

/**
 * Load EEPROM 24C02 (256 bytes)
 * @param i2c_fd - file descriptor from iic_open()
 * @param dev_addr - I2C device address (0x50 + board_index)
 * @param page - starting page (address = page * 8)
 * @param data - buffer for data (should be at least 256 bytes)
 * @param len - length to read (max 256 bytes)
 * @return >=0 on success, -1 on error
 */
int iic_eeprom_load(int i2c_fd, uint8_t dev_addr, uint8_t page, uint8_t *data, unsigned int len);

#endif // I2C_EEPROM_H
