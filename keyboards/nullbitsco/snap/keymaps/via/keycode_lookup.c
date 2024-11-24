/* Copyright 2021 Seth Bonner <fl3tching101@gmail.com>
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

#include "keycode_lookup.h"
#include "quantum_keycodes.h"
#include "via.h"
#include QMK_KEYBOARD_H

#define num_keycodes ARRAY_SIZE(lookup_table)

int cmp(const void *v1, const void *v2)
{
    const lookup_table_t *c1 = v1;
    const lookup_table_t *c2 = v2;

    return (c1->keycode - c2->keycode);
}

static char hex_key_str[7];

/*
    Returns a pointer to a string containing the string describing the keycode, such as those found here:
    https://beta.docs.qmk.fm/using-qmk/simple-keycodes/keycodes

    Will return a string that says "UNKNOWN" if the keycode cannot be found.
*/
char* translate_keycode_to_string(uint16_t code)
{
    lookup_table_t * result = NULL;
    lookup_table_t target = {.key_string = "", .keycode = code};
    char * return_p;

    result = bsearch(&target, lookup_table, num_keycodes, sizeof(lookup_table_t), cmp);

    if(result != NULL)
    {
        return_p = result->key_string;
    }
    else
    {
        snprintf(hex_key_str, sizeof(hex_key_str), "0x%04X", code);
        return hex_key_str;
    }

    return (return_p);
}

lookup_table_t lookup_table[] =
{
 {"NO", KC_NO},
 {"__", KC_TRNS},
 {"A", KC_A},
 {"B", KC_B},
 {"C", KC_C},
 {"D", KC_D},
 {"E", KC_E},
 {"F", KC_F},
 {"G", KC_G},
 {"H", KC_H},
 {"I", KC_I},
 {"J", KC_J},
 {"K", KC_K},
 {"L", KC_L},
 {"M", KC_M},
 {"N", KC_N},
 {"O", KC_O},
 {"P", KC_P},
 {"Q", KC_Q},
 {"R", KC_R},
 {"S", KC_S},
 {"T", KC_T},
 {"U", KC_U},
 {"V", KC_V},
 {"W", KC_W},
 {"X", KC_X},
 {"Y", KC_Y},
 {"Z", KC_Z},
 {"1", KC_1},
 {"2", KC_2},
 {"3", KC_3},
 {"4", KC_4},
 {"5", KC_5},
 {"6", KC_6},
 {"7", KC_7},
 {"8", KC_8},
 {"9", KC_9},
 {"0", KC_0},
 {"MUP", MS_UP},
 {"MDN", MS_DOWN},
 {"MLF", MS_LEFT},
 {"MRT", MS_RGHT},
 {"MB1", MS_BTN1},
 {"MB2", MS_BTN2},
 {"MWU", MS_WHLU},
 {"MWD", MS_WHLD},
 {"MWL", MS_WHLL},
 {"MWR", MS_WHLR}, // 0x00DC
 {"MO1", 0x5221},
 {"TG2", 0x5262}
//  {"KC_ENT", KC_ENT},
//  {"KC_ESC", KC_ESC},
//  {"KC_BSPC", KC_BSPC},
//  {"KC_TAB", KC_TAB},
//  {"KC_SPC", KC_SPC},
//  {"KC_MINS", KC_MINS},
//  {"KC_EQL", KC_EQL},
//  {"KC_LBRC", KC_LBRC},
//  {"KC_RBRC", KC_RBRC},
//  {"KC_BSLS", KC_BSLS},
//  {"KC_NUHS", KC_NUHS},
//  {"KC_SCLN", KC_SCLN},
//  {"KC_QUOT", KC_QUOT},
//  {"KC_GRV", KC_GRV},
//  {"KC_COMM", KC_COMM},
//  {"KC_DOT", KC_DOT},
//  {"KC_SLSH", KC_SLSH},
//  {"KC_CAPS", KC_CAPS},
//  {"KC_F1", KC_F1},
//  {"KC_F2", KC_F2},
//  {"KC_F3", KC_F3},
//  {"KC_F4", KC_F4},
//  {"KC_F5", KC_F5},
//  {"KC_F6", KC_F6},
//  {"KC_F7", KC_F7},
//  {"KC_F8", KC_F8},
//  {"KC_F9", KC_F9},
//  {"KC_F10", KC_F10},
//  {"KC_F11", KC_F11},
//  {"KC_F12", KC_F12},
//  {"KC_PSCR", KC_PSCR},
//  {"KC_SCRL", KC_SCRL},
//  {"KC_PAUS", KC_PAUS},
//  {"KC_INS", KC_INS},
//  {"KC_HOME", KC_HOME},
//  {"KC_PGUP", KC_PGUP},
//  {"KC_DEL", KC_DEL},
//  {"KC_END", KC_END},
//  {"KC_PGDN", KC_PGDN},
//  {"KC_RGHT", KC_RGHT},
//  {"KC_LEFT", KC_LEFT},
//  {"KC_DOWN", KC_DOWN},
//  {"KC_UP", KC_UP},
//  {"KC_NUM", KC_NUM},
//  {"KC_PSLS", KC_PSLS},
//  {"KC_PAST", KC_PAST},
//  {"KC_PMNS", KC_PMNS},
//  {"KC_PPLS", KC_PPLS},
//  {"KC_PENT", KC_PENT},
//  {"KC_P1", KC_P1},
//  {"KC_P2", KC_P2},
//  {"KC_P3", KC_P3},
//  {"KC_P4", KC_P4},
//  {"KC_P5", KC_P5},
//  {"KC_P6", KC_P6},
//  {"KC_P7", KC_P7},
//  {"KC_P8", KC_P8},
//  {"KC_P9", KC_P9},
//  {"KC_P0", KC_P0},
//  {"KC_PDOT", KC_PDOT},
//  {"KC_NUBS", KC_NUBS},
//  {"KC_APP", KC_APP},
//  {"KC_KB_POWER", KC_KB_POWER},
//  {"KC_PEQL", KC_PEQL},
//  {"KC_F13", KC_F13},
//  {"KC_F14", KC_F14},
//  {"KC_F15", KC_F15},
//  {"KC_F16", KC_F16},
//  {"KC_F17", KC_F17},
//  {"KC_F18", KC_F18},
//  {"KC_F19", KC_F19},
//  {"KC_F20", KC_F20},
//  {"KC_F21", KC_F21},
//  {"KC_F22", KC_F22},
//  {"KC_F23", KC_F23},
//  {"KC_F24", KC_F24},
//  {"KC_EXECUTE", KC_EXECUTE},
//  {"KC_HELP", KC_HELP},
//  {"KC_MENU", KC_MENU},
//  {"KC_SELECT", KC_SELECT},
//  {"KC_STOP", KC_STOP},
//  {"KC_AGAIN", KC_AGAIN},
//  {"KC_UNDO", KC_UNDO},
//  {"KC_CUT", KC_CUT},
//  {"KC_COPY", KC_COPY},
//  {"KC_PASTE", KC_PASTE},
//  {"KC_FIND", KC_FIND},
//  {"KC_LCAP", KC_LCAP},
//  {"KC_LNUM", KC_LNUM},
//  {"KC_LSCR", KC_LSCR},
//  {"KC_PCMM", KC_PCMM},
//  {"KC_KP_EQUAL_AS400", KC_KP_EQUAL_AS400},
//  {"KC_INT1", KC_INT1},
//  {"KC_INT2", KC_INT2},
//  {"KC_INT3", KC_INT3},
//  {"KC_INT4", KC_INT4},
//  {"KC_INT5", KC_INT5},
//  {"KC_INT6", KC_INT6},
//  {"KC_INT7", KC_INT7},
//  {"KC_INT8", KC_INT8},
//  {"KC_INT9", KC_INT9},
//  {"KC_LNG1", KC_LNG1},
//  {"KC_LNG2", KC_LNG2},
//  {"KC_LNG3", KC_LNG3},
//  {"KC_LNG4", KC_LNG4},
//  {"KC_LNG5", KC_LNG5},
//  {"KC_LNG6", KC_LNG6},
//  {"KC_LNG7", KC_LNG7},
//  {"KC_LNG8", KC_LNG8},
//  {"KC_LNG9", KC_LNG9},
//  {"KC_ERAS", KC_ERAS},
//  {"KC_SYRQ", KC_SYRQ},
//  {"KC_CANCEL", KC_CANCEL},
//  {"KC_CLR", KC_CLR},
//  {"KC_CLEAR", KC_CLEAR},
//  {"KC_PRIOR", KC_PRIOR},
//  {"KC_OUT", KC_OUT},
//  {"KC_OPER", KC_OPER},
//  {"KC_CLEAR_AGAIN", KC_CLEAR_AGAIN},
//  {"KC_CRSEL", KC_CRSEL},
//  {"KC_EXSEL", KC_EXSEL},
//  {"KC_PWR", KC_PWR},
//  {"KC_SLEP", KC_SLEP},
//  {"KC_WAKE", KC_WAKE},
//  {"KC_MUTE", KC_MUTE},
//  {"KC_VOLU", KC_VOLU},
//  {"KC_VOLD", KC_VOLD},
//  {"KC_MNXT", KC_MNXT},
//  {"KC_MPRV", KC_MPRV},
//  {"KC_MSTP", KC_MSTP},
//  {"KC_MPLY", KC_MPLY},
//  {"KC_MSEL", KC_MSEL},
//  {"KC_EJCT", KC_EJCT},
//  {"KC_MAIL", KC_MAIL},
//  {"KC_CALC", KC_CALC},
//  {"KC_MYCM", KC_MYCM},
//  {"KC_WWW_SEARCH", KC_WWW_SEARCH},
//  {"KC_WWW_HOME", KC_WWW_HOME},
//  {"KC_WWW_BACK", KC_WWW_BACK},
//  {"KC_WWW_FORWARD", KC_WWW_FORWARD},
//  {"KC_WWW_STOP", KC_WWW_STOP},
//  {"KC_WWW_REFRESH", KC_WWW_REFRESH},
//  {"KC_WWW_FAVORITES", KC_WWW_FAVORITES},
//  {"KC_MFFD", KC_MFFD},
//  {"KC_MRWD", KC_MRWD},
//  {"KC_BRIU", KC_BRIU},
//  {"KC_BRID", KC_BRID},
//  {"KC_LCTL", KC_LCTL},
//  {"KC_LSFT", KC_LSFT},
//  {"KC_LALT", KC_LALT},
//  {"KC_LGUI", KC_LGUI},
//  {"KC_RCTL", KC_RCTL},
//  {"KC_RSFT", KC_RSFT},
//  {"KC_RALT", KC_RALT},
//  {"KC_RGUI", KC_RGUI},
//  {"KC_MS_UP", KC_MS_UP},
//  {"KC_MS_DOWN", KC_MS_DOWN},
//  {"KC_MS_LEFT", KC_MS_LEFT},
//  {"KC_MS_RIGHT", KC_MS_RIGHT},
//  {"KC_MS_BTN1", KC_MS_BTN1},
//  {"KC_MS_BTN2", KC_MS_BTN2},
//  {"KC_MS_BTN3", KC_MS_BTN3},
//  {"KC_MS_BTN4", KC_MS_BTN4},
//  {"KC_MS_BTN5", KC_MS_BTN5},
//  {"KC_MS_WH_UP", KC_MS_WH_UP},
//  {"KC_MS_WH_DOWN", KC_MS_WH_DOWN},
//  {"KC_MS_WH_LEFT", KC_MS_WH_LEFT},
//  {"KC_MS_WH_RIGHT", KC_MS_WH_RIGHT},
//  {"KC_MS_ACCEL0", KC_MS_ACCEL0},
//  {"KC_MS_ACCEL1", KC_MS_ACCEL1},
//  {"KC_MS_ACCEL2", KC_MS_ACCEL2},
//  {"KC_EXLM", KC_EXLM},
//  {"KC_AT", KC_AT},
//  {"KC_HASH", KC_HASH},
//  {"KC_DLR", KC_DLR},
//  {"KC_PERC", KC_PERC},
//  {"KC_CIRC", KC_CIRC},
//  {"KC_AMPR", KC_AMPR},
//  {"KC_ASTR", KC_ASTR},
//  {"KC_LPRN", KC_LPRN},
//  {"KC_RPRN", KC_RPRN},
//  {"KC_UNDS", KC_UNDS},
//  {"KC_PLUS", KC_PLUS},
//  {"KC_LCBR", KC_LCBR},
//  {"KC_RCBR", KC_RCBR},
//  {"KC_PIPE", KC_PIPE},
//  {"KC_COLN", KC_COLN},
//  {"KC_DQUO", KC_DQUO},
//  {"KC_TILD", KC_TILD},
//  {"KC_LT", KC_LT},
//  {"KC_GT", KC_GT},
//  {"KC_QUES", KC_QUES},
//  {"QK_BOOT", QK_BOOT},
//  {"DB_TOGG", DB_TOGG},
//  {"NK_TOGG", NK_TOGG},
//  {"QK_GESC", QK_GESC},
//  {"AU_ON", AU_ON},
//  {"AU_OFF", AU_OFF},
//  {"AU_TOGG", AU_TOGG},
//  {"CK_TOGG", CK_TOGG},
//  {"CK_ON", CK_ON},
//  {"CK_OFF", CK_OFF},
//  {"CK_UP", CK_UP},
//  {"CK_DOWN", CK_DOWN},
//  {"CK_RST", CK_RST},
//  {"MU_ON", MU_ON},
//  {"MU_OFF", MU_OFF},
//  {"MU_TOGG", MU_TOGG},
//  {"MU_NEXT", MU_NEXT},
//  {"BL_ON", BL_ON},
//  {"BL_OFF", BL_OFF},
//  {"BL_DOWN", BL_DOWN},
//  {"BL_UP", BL_UP},
//  {"BL_TOGG", BL_TOGG},
//  {"BL_STEP", BL_STEP},
//  {"BL_BRTG", BL_BRTG},
//  {"UG_TOGG", UG_TOGG},
//  {"UG_NEXT", UG_NEXT},
//  {"UG_PREV", UG_PREV},
//  {"UG_HUEU", UG_HUEU},
//  {"UG_HUED", UG_HUED},
//  {"UG_SATU", UG_SATU},
//  {"UG_SATD", UG_SATD},
//  {"UG_VALU", UG_VALU},
//  {"UG_VALD", UG_VALD},
//  {"UG_SPDU", UG_SPDU},
//  {"UG_SPDD", UG_SPDD},
//  {"RGB_M_P", RGB_M_P},
//  {"RGB_M_B", RGB_M_B},
//  {"RGB_M_R", RGB_M_R},
//  {"RGB_M_SW", RGB_M_SW},
//  {"RGB_M_SN", RGB_M_SN},
//  {"RGB_M_K", RGB_M_K},
//  {"RGB_M_X", RGB_M_X},
//  {"RGB_M_G", RGB_M_G},
//  {"SC_LSPO", SC_LSPO},
//  {"SC_RSPC", SC_RSPC},
//  {"SC_SENT", SC_SENT},
//  {"SC_LCPO", SC_LCPO},
//  {"SC_RCPC", SC_RCPC},
//  {"SC_LAPO", SC_LAPO},
//  {"SC_RAPC", SC_RAPC},
//  {"TL_LOWR", TL_LOWR},
//  {"TL_UPPR", TL_UPPR},
//  {"QK_MACRO_0", QK_MACRO_0},
//  {"QK_MACRO_1", QK_MACRO_1},
//  {"QK_MACRO_2", QK_MACRO_2},
//  {"QK_MACRO_3", QK_MACRO_3},
//  {"QK_MACRO_4", QK_MACRO_4},
//  {"QK_MACRO_5", QK_MACRO_5},
//  {"QK_MACRO_6", QK_MACRO_6},
//  {"QK_MACRO_7", QK_MACRO_7},
//  {"QK_MACRO_8", QK_MACRO_8},
//  {"QK_MACRO_9", QK_MACRO_9},
//  {"QK_MACRO_10", QK_MACRO_10},
//  {"QK_MACRO_11", QK_MACRO_11},
//  {"QK_MACRO_12", QK_MACRO_12},
//  {"QK_MACRO_13", QK_MACRO_13},
//  {"QK_MACRO_14", QK_MACRO_14},
//  {"QK_MACRO_15", QK_MACRO_15},
//  {"QK_KB_0", QK_KB_0},
//  {"QK_KB_1", QK_KB_1},
//  {"QK_KB_2", QK_KB_2},
//  {"QK_KB_3", QK_KB_3},
//  {"QK_KB_4", QK_KB_4},
//  {"QK_KB_5", QK_KB_5},
//  {"QK_KB_6", QK_KB_6},
//  {"QK_KB_7", QK_KB_7},
//  {"QK_KB_8", QK_KB_8},
//  {"QK_KB_9", QK_KB_9},
//  {"QK_KB_10", QK_KB_10},
//  {"QK_KB_11", QK_KB_11},
//  {"QK_KB_12", QK_KB_12},
//  {"QK_KB_13", QK_KB_13},
//  {"QK_KB_14", QK_KB_14},
//  {"QK_KB_15", QK_KB_15}
};
