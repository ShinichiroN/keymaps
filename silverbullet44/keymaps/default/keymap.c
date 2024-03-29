/* Copyright 2019 SwanMatch
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

// Defines the keycodes used by our macros in process_record_user
//enum custom_keycodes {
//  QMKBEST = SAFE_RANGE,
//  QMKURL
//};
enum layer {
    _QWERTY,
    _CURSOL,
    _CALC,
    _ADJUST,
};

enum custom_keycodes {
  RGBRST = SAFE_RANGE,
  KC_00,
  ALTAB
};
#define CALC LT(_CALC,   KC_ESC)
#define CUSL LT(_CURSOL, KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                                  ,-----------------------------------------.
 * |TabMOS|   Q  |   W  |   E  |   R  |   T  |                                  |   Y  |   U  |   I  |   O  |   P  |  =   |
 * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
 * |Shift |   A  |   S  |   D  |   F  |   G  |                                  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
 * | Ctrl |   Z  |   X  |   C  |   V  |   B  |-------.-------.  ,---------------|   N  |   M  |   ,  |   .  |   /  |  -   |
 * `-----------------------------------------/       /       /   \       \      \----------------------------------------'
 *                          | Alt  | Bksp | / Shift / Calc  /     \ Cursol\ Ctrl | Del  |  App  |
 *                          |  F5  |      |/ Space /  Esc  /       \  Tab  \ Enter\     |  F12  |
 *                          `-----------------------------'         '---------------------------'
 */
  [_QWERTY] = LAYOUT(
    KC_TAB,    KC_Q, KC_W, KC_E, KC_R, KC_T,                KC_Y,   KC_U,    KC_I,    KC_O,   KC_P,    KC_MINS,
    KC_LSFT,   KC_A, KC_S, KC_D, KC_F, KC_G,                KC_H,   KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT,
    KC_LCTRL,  KC_Z, KC_X, KC_C, KC_V, KC_B,                KC_N,   KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_MINS,
     CALC, KC_BSPC, KC_SPC, KC_LALT,    KC_DEL, CUSL, KC_LCMD,KC_ENT 
  ),

/* Cursol
 * ,-----------------------------------------.                                  ,-----------------------------------------.
 * |      |  F1  |  F2  | PgUp |  F4  |  F5  |                                  |  F6  |  F7  |  F8  |  F9  | F10  |PrtSc |
 * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
 * |      |  ~   | Home | PgDw | End  |  (   |                                  |  )   | Left | Down |Right | F8   | F12  |
 * |------+------+------+------+------+------+                                  +------+------+------+------+------+------|
 * |      |  `   | CLft |  F3  | CRgt |SALTAB|-------.-------.  ,---------------|ALTTAB| OSL  |  F8  | OSR  |      |      |
 * `-----------------------------------------/       /       /   \       \      \----------------------------------------'
 *                          |      |      | /       /       /     \       \      \  |      |      |
 *                          |      |      |/       /       /       \       \      \ |      |      |
 *                          `-----------------------------'         '-----------------------------'
 */
  [_CURSOL] = LAYOUT(
  RESET ,  KC_F1,   KC_F2,      KC_PGUP, KC_F4,      KC_F5,                              KC_F6,   KC_F7,        KC_F8,   KC_F9,        KC_F10,  RESET,
  _______, KC_TILD, KC_HOME,    KC_PGDN, KC_END,     KC_LPRN,                            KC_LEFT, KC_DOWN,      KC_UP, KC_RGHT,      KC_PIPE, KC_F12,
  _______, KC_GRV,  C(KC_LEFT), KC_F3,   C(KC_RGHT), S(ALTAB),                           ALTAB,   KC_PGDN, KC_F8,   LCA(KC_RGHT), KC_BSLS, RGBRST,
                                _______,    _______, C(KC_SPC), MO(_ADJUST),    _______, _______, _______, _______
  ),

/* Calculater
 * ,-----------------------------------------.                                  ,-----------------------------------------.
 * |      |  1   |  2   |  3   |  4   |  5   |                                  |  6   |  7   |  8   |  9   |  0   |      |
 * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
 * |      |  @   |  #   |  $   |  %   |  [   |                                  |  ]   |  4   |  5   |  6   |  +   |      |
 * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
 * |      |  ^   |  &   |  *   |  !   |  {   |-------.-------.  ,---------------|  }   |  1   |  2   |  3   |  =   |      |
 * `-----------------------------------------/       /       /   \       \       \----------------------------------------'
 *                          |      |      | /       /       /     \       \       \  |      |      |
 *                          |      |      |/       /       /       \       \   0   \ |  00  |  .   |
 *                          `-----------------------------'         '------------------------------'
 */
  [_CALC] = LAYOUT(
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  _______, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_LBRC,                        KC_RBRC, KC_LPRN,    KC_RPRN,    KC_MINS,    KC_PLUS, KC_NUBS,
  _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_EXLM, KC_LCBR,                        KC_RCBR, KC_LCBR,    KC_RCBR,    KC_BSLS,    KC_EQL, _______,
                             _______, _______, _______, _______,   MO(_ADJUST), KC_0,    KC_00,   KC_PDOT
  ),

/*   ADJUST
 * ,-----------------------------------------.                                  ,-----------------------------------------.
 * |      |      |      |FrqRst|      |      |                                  |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
 * |      |      |Music |FrqUp |Sound |      |                                  | SPD+ | MOD+ | VAL+ | SAD+ | HUE+ |      |
 * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
 * |      |      |Scale |FrqDwn|      |      |-------.-------.  ,---------------| SPD- | SPD- | VAL- | SAD- | HUE- |      |
 * `-----------------------------------------/       /       /   \       \       \----------------------------------------'
 *                          |      |      | /       /       /     \       \       \  |      |      |
 *                          |      |      |/       /       /       \       \       \ |      |      |
 *                          `-----------------------------'         '------------------------------'
*/

  [_ADJUST] = LAYOUT(
  _______, XXXXXXX, XXXXXXX, CK_RST,  XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, _______,
  XXXXXXX, XXXXXXX, MU_TOG,  CK_UP,   AU_TOG,  XXXXXXX,                      RGB_SPI, RGB_MOD,  RGB_VAI, RGB_SAI, RGB_HUI, XXXXXXX,
  XXXXXXX, XXXXXXX, MU_MOD,  CK_DOWN, XXXXXXX, XXXXXXX,                      RGB_SPD, RGB_RMOD, RGB_VAD, RGB_SAD, RGB_HUD, XXXXXXX,
                             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  )
};

#ifdef RGBLIGHT_ENABLE
// Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

int  RGB_current_mode;
bool alt_pressed = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
#ifdef RGBLIGHT_ENABLE
        case RGBRST:
            if (record->event.pressed) {
                eeconfig_update_rgblight_default();
                rgblight_enable();
                RGB_current_mode = rgblight_config.mode;
            }
            break;
#endif
        case KC_SCLN:
            if (keyboard_report->mods & MOD_BIT(KC_LSFT)) {
                if (record->event.pressed) {
                    unregister_code(KC_LSFT);
                    tap_code16(keycode);
                    register_code(KC_LSFT);
                }
                /*  } else if (keyboard_report->mods & MOD_BIT(KC_RSFT)) {
                    if (record->event.pressed) {
                      unregister_code(KC_RSFT);
                      tap_code16(keycode);
                      register_code(KC_RSFT);
                    } */
            } else {
                if (record->event.pressed) {
                    tap_code16(S(keycode));
                }
            }
            return false;
            break;
        case KC_00:
            if (record->event.pressed) {
                tap_code(KC_0);
                register_code(KC_0);
            } else {
                unregister_code(KC_0);
            }
            return false;
            break;
        case S(ALTAB):
        case ALTAB:
            if (record->event.pressed) {
                if (!alt_pressed) {
                    alt_pressed = true;
                    register_code(KC_LALT);
                }
                if (keycode == S(ALTAB)) {
                    register_code(KC_LSFT);
                }
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
                if (keycode == S(ALTAB)) {
                    unregister_code(KC_LSFT);
                }
            }
            return false;
            break;
        default:
            if (alt_pressed) {
                alt_pressed = false;
                unregister_code(KC_LALT);
                if (record->event.pressed) {
                    return false;
                }
            }
            break;
    }
    return true;
}

void matrix_init_user(void) {
#ifdef RGBLIGHT_ENABLE
    RGB_current_mode = rgblight_config.mode;
#endif
}

