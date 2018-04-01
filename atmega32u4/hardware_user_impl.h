// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#include <stdint.h>

#define static_delay_us(x) _delay_us(x)
#define static_delay_ms(x) _delay_ms(x)

#define enable_interrupts() do { \
    sei(); \
} while(0);

#define disable_interrupts() do { \
    cli(); \
} while(0);

// define flash pointer sizes
#if MCU_FLASH_SIZE <= 64
typedef uint16_t flash_ptr_t;
typedef uint16_t flash_addr_t;
typedef uint32_t flash_size_t;
#else
typedef uint16_t flash_ptr_t;
typedef uint32_t flash_addr_t;
typedef uint32_t flash_size_t;
#endif

#define MCU_BITNESS 8

typedef uint16_t io_port_t;

// SPM_PAGESIZE is in words (uint16_t), so convert to bytes
#define PAGE_SIZE           (SPM_PAGESIZE * 2)

#if defined (__AVR_ATmega32U4__)
#include "io_map/iom32u4.h"
#else
#error "Found unsupported MCU when trying to choose pin map"
#endif
