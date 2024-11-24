/* Copyright 2021 Jay Greco
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
#include QMK_KEYBOARD_H
#include "keycode_lookup.h"

// clang-format off
enum layers {
    _BASE,
    _VIA1,
    _VIA2
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_all(
             KC_ESC,   KC_F1,   KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,    KC_F7,  KC_F8,  KC_F9,   KC_F10,    KC_F11,    KC_F12,   KC_PSCR,  KC_PAUS,
    KC_F13,  KC_GRV,   KC_1,    KC_2,   KC_3,   KC_4,   KC_5,   KC_6,     KC_7,   KC_8,   KC_9,    KC_0,      KC_MINS,   KC_EQL,   KC_BSPC,  KC_DEL,   KC_HOME,
    KC_F14,  KC_TAB,   KC_Q,    KC_W,   KC_E,   KC_R,           KC_T,     KC_Y,   KC_U,   KC_I,    KC_O,      KC_P,      KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_END,
    KC_F15,  KC_CAPS,  KC_A,    KC_S,   KC_D,   KC_F,           KC_G,     KC_H,   KC_J,   KC_K,    KC_L,      KC_SCLN,   KC_QUOT,  KC_ENT,             KC_PGUP,
    KC_F16,  KC_LSFT,  KC_NUHS, KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,     KC_N,   KC_M,   KC_COMM, KC_DOT,    KC_SLSH,   KC_RSFT,            KC_UP,    KC_PGDN,
    KC_F17,  KC_LCTL,  KC_LGUI, KC_LALT,     MO(_VIA1),         KC_SPC,   KC_SPC,                  MO(_VIA1), KC_RALT,   KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT
  ),
    [_VIA1] = LAYOUT_all(
            QK_BOOT,KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,          KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,          KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,          KC_NO,
    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,          KC_NO,  KC_NO,
    KC_NO,  KC_NO,  KC_NO,  KC_NO,          KC_NO,          KC_NO,    KC_NO,                  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO
  ),
    [_VIA2] = LAYOUT_all(
            KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,          KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,          KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,          KC_NO,
    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,          KC_NO,  KC_NO,
    KC_NO,  KC_NO,  KC_NO,  KC_NO,          KC_NO,          KC_NO,    KC_NO,                  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO
  )
};
// clang-format on

char last_keycode_string[32] = { 0 };

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_VIA1] = { ENCODER_CCW_CW(KC_NO, KC_NO)   },
    [_VIA2] = { ENCODER_CCW_CW(KC_NO, KC_NO)    }
};
#endif

// https://docs.qmk.fm/custom_quantum_functions#process-record-function-documentation
#ifdef OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Record the mapped keycode if it's pressed
    if (record->event.pressed) {
        uint16_t mapped_keycode = get_record_keycode(record, false);
        char *keycode_str = translate_keycode_to_string(mapped_keycode);
        memset(last_keycode_string, 0, sizeof(last_keycode_string));
        strcpy(last_keycode_string, keycode_str);
    }
    return true;
}

bool oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case _VIA1:
            oled_write_P(PSTR("Fn 1\n"), false);
            break;
        case _VIA2:
            oled_write_P(PSTR("Fn 2\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

#ifdef WPM_ENABLE
    oled_write_P(PSTR("WPM: "), false);
    oled_write_ln(get_u8_str(get_current_wpm(), ' '), false);
#endif

    oled_write_P(PSTR("Key: "), false);

    oled_write_ln(last_keycode_string, false);

    return false;
}
#endif
