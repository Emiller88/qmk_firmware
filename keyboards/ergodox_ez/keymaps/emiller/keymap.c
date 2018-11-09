#include QMK_KEYBOARD_H
#include "action_layer.h"
#include "debug.h"
#include "version.h"

#define BASE 0 // default layer
#define VIM 1  // symbols
#define NUM 2  // media keys

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};
// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 /* Keymap 0: Basic layer
  * ,--------------------------------------------------.           ,--------------------------------------------------.
  * | `      |   1  |   2  |   3  |   4  |   5  | ⇧⌘P |           | PROJ |   6  |   7  |   8  |   9  |   0  |  BSPC  |
  * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
  * |  Tab   |   Q  |   W  |   E  |   R  |   T  |  `   |           |   -  |   Y  |   U  |   I  |   O  |   P  |   \    |
  * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
  * |  Esc   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
  * |--------+------+------+------+------+------|   =  |           |   +  |------+------+------+------+------+--------|
  * |   L⇧   |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  |   R⇧   |
  * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
  *   | CTRL | ALT  |  (   |  [   |   {  |                                       |  }   |  ]   |   )  |   ⌥   | ⌃  |
  *   `----------------------------------'                                       `----------------------------------'
  *                                        ,-------------.       ,-------------.
  *                                        | HOME | END  |       | PGDN | PGUP |
  *                                 ,------|------|------|       |------+------+------.
  *                                 |SPACE |      |      |       |      | BSP  |      |
  *                                 |      | VIM  |------|       |------|      |Enter |
  *                                 |  ⌘  |      |      |       |      |  ⌘  |      |
  *                                 `--------------------'       `--------------------'
  */
  [BASE] = LAYOUT_ergodox(
    // Left Hand
    KC_GRAVE,KC_1,  KC_2,   KC_3,    KC_4,   KC_5, KC_DEL,
    KC_TAB ,KC_Q,   KC_W,   KC_E,    KC_R,   KC_T, KC_GRV,
    KC_ESC ,KC_A,   KC_S,   KC_D,    KC_F,   KC_G,
    KC_LSFT,KC_Z,   KC_X,   KC_C,    KC_V,   KC_B, KC_EQL,
    KC_LCTL,KC_LALT,KC_LPRN,KC_LBRC, KC_LCBR,

                                           KC_HOME, KC_END,
                                                    MO(NUM),
                             KC_SPC, MO(VIM), KC_LALT,


    // Right Hand
                              KC_DEL , KC_6, KC_7,   KC_8,    KC_9,   KC_0,   KC_BSPC,
                              KC_MINS, KC_Y, KC_U,   KC_I,    KC_O,   KC_P,   KC_BSLS,
                                       KC_H, KC_J,   KC_K,    KC_L,   KC_SCLN,KC_QUOT,
                              KC_PLUS, KC_N, KC_M,   KC_COMM, KC_DOT, KC_SLSH,KC_RSFT,
                                             KC_RCBR,KC_RBRC, KC_RPRN,KC_RALT,KC_RCTL,

    KC_PGUP,  KC_PGDN,
    KC_LGUI,
    MO(NUM), KC_BSPC,KC_ENT
  ),

/* Keymap 1: Vim Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   @  |   {  |   }  |   |  |      |           |      |      |      |      |      |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   #  |   $  |   (  |   )  |   `  |------|           |------| Left |  Up  | Down | Rght |      |  Play  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |      |      | Prev | Next |      |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EPRM  |      |      |      |      |                                       |VolUp |VolDn | Mute |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Animat|      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Bright|Bright|      |       |      |      |Brwser|
 *                                 |ness- |ness+ |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// VIM & SYMBOLS
[VIM] = LAYOUT_ergodox(
       // left hand
       VRSN,   KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_TRNS,KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_PIPE,KC_TRNS,
       KC_TRNS,KC_HASH,KC_DLR, KC_LPRN,KC_RPRN,KC_GRV,
       KC_TRNS,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,KC_TRNS,
          EPRM,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       RGB_MOD,KC_TRNS,
                                               KC_TRNS,
                               RGB_VAD,RGB_VAI,KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_TRNS, KC_MPLY,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                          KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
),
/* Keymap 2: Numpad and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |      |    . |   0  |   =  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |Toggle|Solid |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |Hue-  |Hue+  |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[NUM] = LAYOUT_ergodox(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_UP,   KC_7,   KC_8,    KC_9,    KC_ASTR, KC_F12,
                KC_DOWN, KC_4,   KC_5,    KC_6,    KC_PLUS, KC_TRNS,
       KC_TRNS, KC_AMPR, KC_1,   KC_2,    KC_3,    KC_BSLS, KC_TRNS,
                         KC_TRNS,KC_DOT,  KC_0,    KC_EQL,  KC_TRNS,
       RGB_TOG, RGB_SLD,
       KC_TRNS,
       KC_TRNS, RGB_HUD, RGB_HUI
),
};

// clang-format on

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(NUM) // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  // MACRODOWN only works in this function
  switch (id) {
  case 0:
    if (record->event.pressed) {
      SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
    }
    break;
  case 1:
    if (record->event.pressed) { // For resetting EEPROM
      eeconfig_init();
    }
    break;
  }
  return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  // dynamically generate these.
  case EPRM:
    if (record->event.pressed) {
      eeconfig_init();
    }
    return false;
    break;
  case VRSN:
    if (record->event.pressed) {
      SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
    }
    return false;
    break;
  case RGB_SLD:
    if (record->event.pressed) {
#ifdef RGBLIGHT_ENABLE
      rgblight_mode(1);
#endif
    }
    return false;
    break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void){

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

  uint8_t layer = biton32(layer_state);

  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
  // TODO: Make this relevant to the ErgoDox EZ.
  case NUM:
    ergodox_right_led_1_on();
    break;
  case VIM:
    ergodox_right_led_2_on();
    break;
  default:
    // none
    break;
  }
};
