#ifndef UI_H
#define UI_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "eeprom_defs.h"
#include "eeprom_structure.h"

// ═══════════════════════════════════════════════════════════════
// ANSI Color Codes
// ═══════════════════════════════════════════════════════════════

#define TERM_RESET   "\033[0m"
#define TERM_BOLD    "\033[1m"
#define TERM_DIM     "\033[2m"

#define TERM_BLACK   "\033[30m"
#define TERM_RED     "\033[31m"
#define TERM_GREEN   "\033[32m"
#define TERM_YELLOW  "\033[33m"
#define TERM_BLUE    "\033[34m"
#define TERM_MAGENTA "\033[35m"
#define TERM_CYAN    "\033[36m"
#define TERM_WHITE   "\033[37m"

#define TERM_BG_BLACK   "\033[40m"
#define TERM_BG_RED     "\033[41m"
#define TERM_BG_GREEN   "\033[42m"
#define TERM_BG_YELLOW  "\033[43m"
#define TERM_BG_BLUE    "\033[44m"
#define TERM_BG_MAGENTA "\033[45m"
#define TERM_BG_CYAN    "\033[46m"
#define TERM_BG_WHITE   "\033[47m"

// ═══════════════════════════════════════════════════════════════
// UI Helper Functions
// ═══════════════════════════════════════════════════════════════

// Formatted output
void ui_print_success(const char *format, ...);
void ui_print_error(const char *format, ...);
void ui_print_warning(const char *format, ...);
void ui_print_info(const char *format, ...);

// Headers and separators
void ui_print_header(const char *title);
void ui_print_separator(void);

// Input with validation
bool ui_input_uint8(const char *prompt, uint8_t *value, uint8_t min, uint8_t max);
bool ui_input_uint16(const char *prompt, uint16_t *value, uint16_t min, uint16_t max);
bool ui_input_int8(const char *prompt, int8_t *value, int8_t min, int8_t max);
bool ui_input_string(const char *prompt, char *buffer, size_t maxlen);

// ═══════════════════════════════════════════════════════════════
// EEPROM Display Functions
// ═══════════════════════════════════════════════════════════════

// Print EEPROM structure using metadata (tabular format)
void ui_print_eeprom(const void *eeprom_struct, EEPROMVersion version);

// Print single field value
void ui_print_field(const void *base, const FieldMetadata *field);

// Print category header
void ui_print_category_header(const char *category);

#endif // UI_H
