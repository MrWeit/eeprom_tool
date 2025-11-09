#ifndef EEPROM_OPS_H
#define EEPROM_OPS_H

#include <stdint.h>
#include <stddef.h>
#include "eeprom_defs.h"

// ═══════════════════════════════════════════════════════════════
// Return Codes
// ═══════════════════════════════════════════════════════════════
#define EEPROM_SUCCESS             0
#define EEPROM_ERROR_UNKNOWN      -1
#define EEPROM_ERROR_CRC          -2
#define EEPROM_ERROR_VERSION      -3
#define EEPROM_ERROR_TEST_FAIL    -4


int eeprom_decode(uint8_t *data, size_t size, EEPROMVersion version);
int eeprom_encode(uint8_t *data, size_t size, EEPROMVersion version);
int eeprom_edit_interactive(void *eeprom_struct, EEPROMVersion version);

#endif // EEPROM_OPS_H
