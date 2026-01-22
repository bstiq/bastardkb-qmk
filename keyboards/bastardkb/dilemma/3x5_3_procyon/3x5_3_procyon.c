/**
 * Copyright 2020 Christopher Courtney <drashna@live.com> (@drashna)
 * Copyright 2021 Quentin LEBASTARD <qlebastard@gmail.com>
 * Copyright 2022 Charly Delay <charly@codesink.dev> (@0xcharly)
 * Copyright 2023 casuanoob <casuanoob@hotmail.com> (@casuanoob)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Publicw License as published by
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

#include "qp.h"
#include "qp_comms.h"
#include "3x5_3_procyon.h"

#include "qp_st77xx_opcodes.h"
#include "gfx/POC.qgf.h"
#include "gfx/bar_blue.qgf.h"
#include "gfx/bar_gray.qgf.h"
#include "gfx/bar_green.qgf.h"
#include "gfx/fonts.qff.h"

#include "color.h"

#include "dilemma.h"

painter_device_t lcd;

void keyboard_post_init_kb(void) {
    if (is_keyboard_left()) {
        // Display timeout
        wait_ms(LCD_WAIT_TIME);

        lcd = qp_st7789_make_spi_device(LCD_HEIGHT, LCD_WIDTH, LCD_CS_PIN, LCD_DC_PIN, LCD_RST_PIN, LCD_SPI_DIVISOR, SPI_MODE);
        qp_init(lcd, LCD_ROTATION);

        // Display offset
        qp_set_viewport_offsets(lcd, LCD_OFFSET_X, LCD_OFFSET_Y);

        // load fonts
        font_layer    = qp_load_font_mem(font_gridlitepbslayer);
        font_menu     = qp_load_font_mem(font_gridlitepbsmenu);
        font_menu_off = qp_load_font_mem(font_gridlitepbsmenuoff);

        // Power on display, fill with white
        qp_power(lcd, 1);
        qp_rect(lcd, 0, 0, 300, 300, HSV_BLACK, 1);

        prev_layer = 99;
        bk_display_layer_number();
        keyboard_post_init_user();
    }
}

void housekeeping_task_kb(void) {
    static uint32_t last_draw = 0;
    if (timer_elapsed32(last_draw) > 33) { // throttle
        last_draw = timer_read32();
        bk_display_layer_number();
        qp_flush(lcd);
    }
}

void bk_display_layer_number(void) {
  
}

void render_mods(uint16_t x, uint16_t y, bool render_all) {

}