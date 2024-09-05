/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#define ST_GEM QK_STENO_GEMINI

enum kuru_layers {
  _COLEMAK,
  _QWERTY,
  _LOWER,
  _RAISE,
  _PLOVER
};

enum kuru_keycodes {
  COLEMAK = SAFE_RANGE,
  QWERTY,
  SW_LANG
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define PLOVER TG(_PLOVER)

static uint16_t current_default_layer = _COLEMAK;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Colemak-DH
 * ,-----------------------------------------.                ,-----------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   B  |                |   J  |   L  |   U  |   Y  |   ;  | Esc  |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * | Ctrl |   A  |   R  |   S  |   T  |   G  |                |   M  |   N  |   E  |   I  |   O  | '    |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   D  |   V  |                |   K  |   H  |   ,  |   .  |   /  | Alt  |
 * `---------------------------+------+------+------.  ,------+-----------------------------------------'
 *                             | GUI  |Lower |Enter |  |Space | Bksp |Raise |
 *                             `--------------------'  `--------------------'
 */
[_COLEMAK] = LAYOUT_split_3x6_3(
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                               KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_ESC,
    KC_LCTL, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                               KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                               KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_LALT,
                                        KC_LGUI, LOWER,   KC_ENT,           KC_SPC,  KC_BSPC, RAISE
),

/* QWERTY
 * ,-----------------------------------------.                ,-----------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                |   Y  |   U  |   I  |   O  |   P  | Esc  |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |                |   H  |   J  |   K  |   L  |   ;  | '    |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |                |   N  |   M  |   ,  |   .  |   /  | Alt  |
 * `---------------------------+------+------+------.  ,------+-----------------------------------------'
 *                             | GUI  |Lower |Enter |  |Space | Bksp |Raise |
 *                             `--------------------'  `--------------------'
 */
[_QWERTY] = LAYOUT_split_3x6_3(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_ESC,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_LALT,
                                        KC_LGUI, LOWER,   KC_ENT,           KC_SPC,  KC_BSPC, RAISE
),

/* Lower
 * ,-----------------------------------------.                ,-----------------------------------------.
 * | Tab  |   !  |   @  |   #  |   $  |   %  |                |   ^  |   &  |   *  |   (  |   )  |   \  |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * | Ctrl |   1  |   2  |   3  |   4  |   5  |                |   -  |   =  |   `  |   [  |   ]  |   |  |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * | Shift|   6  |   7  |   8  |   9  |   0  |                |   _  |   +  |   ~  |   {  |   }  | Alt  |
 * `---------------------------+------+------+------.  ,------+-----------------------------------------'
 *                             | GUI  |      |Enter |  |Space | Bksp |      |
 *                             `--------------------'  `--------------------'
 */
[_LOWER] = LAYOUT_split_3x6_3(
    KC_TAB,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSLS,
    KC_LCTL, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_MINS, KC_EQL,  KC_GRV,  KC_LBRC, KC_RBRC, KC_PIPE,
    KC_LSFT, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                               KC_UNDS, KC_PLUS, KC_TILD, KC_LCBR, KC_RCBR, KC_LALT,
                                        KC_LGUI, _______, KC_ENT,           KC_SPC,  KC_BSPC, _______
),

/* Raise
 * ,-----------------------------------------.                ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * | Ctrl |SwLang|QWERTY|Colemk|Plover|PrtSc |                |   ←  |   ↓  |   ↑  |   →  | PGUP | Caps |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * | Shift|      |      |      |      |      |                | Home | End  | Ins  | Del  | PGDN | Alt  |
 * `---------------------------+------+------+------.  ,------+-----------------------------------------'
 *                             |      |      |      |  | Reset|      |      |
 *                             `--------------------'  `--------------------'
 */
[_RAISE] = LAYOUT_split_3x6_3(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                              KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    KC_LCTL, SW_LANG, QWERTY,  COLEMAK, PLOVER,  KC_PSCR,                            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_PGUP, KC_CAPS,
    KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            KC_HOME, KC_END,  KC_INS,  KC_DEL,  KC_PGDN, KC_LALT,
                                        _______, _______, _______,          QK_BOOT, _______, _______
),
    
/* Plover
 * ,-----------------------------------------.                ,-----------------------------------------.
 * | res1 |  #1  |  #2  |  #3  |  #4  |  #5  |                |  #6  |  #7  |  #8  |  #9  |  #A  |  Fn  |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * | res2 | S1-  |   T  |   P  |   H  |  *1  |                |  *3  |   F  |   P  |   L  |   T  |   D  |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * | Exit | S2-  |   K  |   W  |   R  |  *2  |                |  *4  |   R  |   B  |   G  |   S  |   Z  |
 * `---------------------------+------+------+------.  ,------+-----------------------------------------'
 *                             |   A  |   O  |  AO  |  |  EU  |   E  |   U  |
 *                             `--------------------'  `--------------------'
 */
[_PLOVER] = LAYOUT_split_3x6_3(
    STN_RE1, STN_N1,  STN_N2,  STN_N3,  STN_N4,  STN_N5,                             STN_N6,  STN_N7,  STN_N8,  STN_N9,  STN_NA,  STN_FN,
    STN_RE2, STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1,                            STN_ST3, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,
    PLOVER,  STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2,                            STN_ST4, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,
                                        STN_A,   STN_O,   STN_AO,           STN_EU,  STN_E,   STN_U
)

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case COLEMAK:
      if (record->event.pressed) {
        default_layer_set(1U<<_COLEMAK);
        layer_move(_COLEMAK);
        current_default_layer = _COLEMAK;
      }
      return false;
      break;
    case QWERTY:
      if (record->event.pressed) {
        default_layer_set(1U<<_QWERTY);
        layer_move(_QWERTY);
        current_default_layer = _QWERTY;
      }
      return false;
      break;
    case SW_LANG:
      if (record->event.pressed) {
        switch (current_default_layer) {
          case _COLEMAK:
            default_layer_set(1U<<_QWERTY);
            layer_move(_QWERTY);
            current_default_layer = _QWERTY;
            break;
          case _QWERTY:
            default_layer_set(1U<<_COLEMAK);
            layer_move(_COLEMAK);
            current_default_layer = _COLEMAK;
            break;
        }
        register_code(KC_LGUI);
        register_code(KC_SPC);
      } else {
        unregister_code(KC_LGUI);
        unregister_code(KC_SPC);
      }
      return false;
      break;
  }
  return true;
}
