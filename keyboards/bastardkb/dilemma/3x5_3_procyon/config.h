/**
 * Copyright 2022 Charly Delay <charly@codesink.dev> (@0xcharly)
 * Copyright 2023 casuanoob <casuanoob@hotmail.com> (@casuanoob)
 * Copyright 2025 George Norton (@george-norton)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

/* Handedness. */
#define SPLIT_HAND_PIN GP29
#define SPLIT_HAND_PIN_LOW_IS_LEFT // High -> right, Low -> left.

/* VBUS detection. */
#define USB_VBUS_PIN GP19

/* CRC. */
#define CRC8_USE_TABLE
#define CRC8_OPTIMIZE_SPEED

#define I2C_DRIVER I2CD1
#define I2C1_SDA_PIN GP2
#define I2C1_SCL_PIN GP3
#define I2C1_CLOCK_SPEED 1000000
#define DIGITIZER_MOTION_PIN GP12
#define DIGITIZER_MOTION_PIN_ACTIVE_LOW yes
#define PROCYON_42_50

/* Reset. */
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP17
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U

// Reduce soft serial speed: Work around rp2040 issues
#define SELECT_SOFT_SERIAL_SPEED 4


// QP stuff
#define SPI_SCK_PIN GP22 // as per vik connector
#define SPI_MOSI_PIN GP23 // as per vik connector
#define SPI_MISO_PIN GP18 // Unused
#define LCD_RST_PIN GP16 // Unused, TODO connect to Vcc for now, test with SCL later
#define LCD_DC_PIN GP12 // vik_gp1
#define LCD_CS_PIN GP11 // vik_gp2
#define LCD_BLK_PIN GP4 // backlight, not used here, configured in keyboard.json
#define BACKLIGHT_PWM_DRIVER PWMD2
#define BACKLIGHT_PWM_CHANNEL RP2040_PWM_CHANNEL_A

#define SPI_DRIVER SPID0
#define LCD_SPI_DIVISOR 4
#define LCD_WAIT_TIME 150
#define LCD_ROTATION QP_ROTATION_0
#define LCD_OFFSET_X 0
#define LCD_OFFSET_Y 20
#define LCD_WIDTH 240 // Set according to your display specs
#define LCD_HEIGHT 280 // Set according to your display specs
#define SPI_MODE 3 // Set according to your display specs
#define ST7789 // Set according to your display specs GC_9A01 or ST7789
#define QUANTUM_PAINTER_SUPPORTS_NATIVE_COLORS TRUE
// Timeout configuration, default 30000 (30 sek). 0 = No timeout. Beware of image retention.
#define QUANTUM_PAINTER_DISPLAY_TIMEOUT 0