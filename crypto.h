#ifndef CRYPTO_H
#define CRYPTO_H

#include <stdint.h>
#include <stddef.h>
#include "eeprom_defs.h"

void encode_data(uint8_t *data, size_t length, uint8_t algorithm_version,
				 uint8_t key_index, EEPROMVersion eeprom_version);
void decode_data(uint8_t *data, size_t length, uint8_t algorithm_version,
				 uint8_t key_index, EEPROMVersion eeprom_version);

uint8_t calculate_crc(const uint8_t *data, size_t length);

#endif // CRYPTO_H
