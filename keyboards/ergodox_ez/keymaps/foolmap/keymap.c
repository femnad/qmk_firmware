#include QMK_KEYBOARD_H
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys
#define MISC 3

#define ONESHOT_TAP_TOGGLE 2
#define ONESHOT_TIMEOUT 5000

enum custom_keycodes {
#ifdef ORYX_CONFIGURATOR
  EPRM = EZ_SAFE_RANGE,
#else
  EPRM = SAFE_RANGE,
#endif
  VRSN,
  RGB_SLD,
  CLEAR
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Keymap 0: Basic Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |!MISC   |  1   |  2   |  3   |  4   |  5   | ESC  |           | BSPC |  6   |  7   |  8   |  9   |  0   |   !MISC|
 * |--------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |MPRV    |  '   |  ,   |  .   |  P   |  Y   | TAB  |           | ENT  |  F   |  G   |  C   |  R   |  L   |    VOLU|
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |MNXT    |  A   |  O   |  E   |  U   |  I   |------|           |------|  D   |  H   |  T   |  N   |  S   |    VOLD|
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |CLEAR   |  ;   |  Q   |  J   |  K   |  X   |^LSFT |           |^RSFT |  B   |  M   |  W   |  V   |  Z   |   CLEAR|
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | HOME | PGUP |PGDOWN| END  |^LGUI |                                       |^RGUI | LEFT | DOWN |  UP  |RIGHT |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |@SYMB |!MDIA |       |!MDIA |@SYMB |
 *                                 ,------|------|------|       |------+------+------.
 *                                 | SPC  |^LCTL | MPLY |       | MUTE |^RCTL | SPC  |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |^LALT |       |^RALT |      |      |
 *                                 `--------------------'       `--------------------'
 */

[BASE] = LAYOUT_ergodox(
        // left hand
        TG(MISC),      KC_1,        KC_2,    KC_3,   KC_4,   KC_5,   KC_ESC,
        KC_MPRV,       KC_QUOT,     KC_COMM, KC_DOT, KC_P,   KC_Y,   KC_TAB,
        KC_MNXT,       KC_A,        KC_O,    KC_E,   KC_U,   KC_I,
        CLEAR,         KC_SCLN,     KC_Q,    KC_J,   KC_K,   KC_X,   OSM(MOD_LSFT),
        KC_HOME,       KC_PGUP,   KC_PGDOWN, KC_END, OSM(MOD_LGUI),
                                                                    OSL(SYMB), TG(MDIA),
                                                                               KC_MPLY,
                                                        KC_SPC, OSM(MOD_LCTL), OSM(MOD_LALT),
        // right hand
        KC_BSPC,      KC_6,   KC_7,   KC_8,   KC_9,   KC_0,      TG(MISC),
        KC_ENT,       KC_F,   KC_G,   KC_C,   KC_R,   KC_L,      KC_VOLU,
                      KC_D,   KC_H,   KC_T,   KC_N,   KC_S,      KC_VOLD,
        OSM(MOD_RSFT),KC_B,   KC_M,   KC_W,   KC_V,   KC_Z,      CLEAR,
                              OSM(MOD_RGUI),KC_LEFT,  KC_DOWN,   KC_UP, KC_RIGHT,
        TG(MDIA), OSL(SYMB),
        KC_MUTE,
        OSM(MOD_RALT), OSM(MOD_RCTL), KC_SPC
),

/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  | F10  |     F11|
 * |--------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |        |  !   |  @   |  #   |  $   |  %   |      |           |      |  ^   |  &   |  *   |      |      |     F12|
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  {   |  }   |  (   |  )   |  =   |------|           |------|  /   |  -   |  _   |  [   |  ]   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |  ~   |  |   |  `   |      |           |      |  \   |  +   | DEL  | INS  |  \   |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */

[SYMB] = LAYOUT_ergodox(
       // left hand
       _______,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  _______,
       _______,KC_EXLM,KC_AT,  KC_HASH,KC_DLR, KC_PERC,_______,
       _______,KC_LCBR,KC_RCBR,KC_LPRN,KC_RPRN,KC_EQL,
       _______,_______,_______,KC_TILD,KC_PIPE,KC_GRV,_______,
       _______,_______,_______,_______,_______,
                                       _______,_______,
                                               _______,
                               _______,_______,_______,
       // right hand
       _______, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       _______, KC_CIRC, KC_AMPR,KC_ASTR, _______, _______, KC_F12,
                KC_SLSH, KC_MINS,KC_UNDS, KC_LBRC, KC_RBRC, _______,
       _______, KC_BSLS, KC_PLUS,KC_DEL,  KC_INS,  KC_BSLS, _______,
                         _______,_______, _______, _______, _______,
       _______, _______,
       _______,
       _______, _______, _______
),

/* Keymap 2: Media Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MS_U |      | WH_U |      |           |      |      | BTN1 | BTN2 | BTN3 |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |RESET   |      | MS_L | MS_D | MS_R | WH_D |------|           |------|      | ACL2 | ACL1 | ACL0 |      |   RESET|
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | MUTE | VOLD | VOLU | MPLY |      |      |           |      |      | WH_L | WH_R | MPRV | MNXT |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */

[MDIA] = LAYOUT_ergodox(
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, KC_MS_U, _______, KC_WH_U, _______,
       RESET,   _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D,
       _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY, _______, _______,
       _______, _______, _______, _______, _______,
                                           _______, _______,
                                                    _______,
                                  _______, _______, _______,
    // right hand
       _______,  _______, _______, _______, _______, _______, _______,
       _______,  _______, KC_BTN1, KC_BTN2, KC_BTN3, _______, _______,
                 _______, KC_ACL2, KC_ACL1, KC_ACL0, _______, RESET,
       _______,  _______, KC_WH_L, KC_WH_R, KC_MPRV, KC_MNXT, _______,
                          _______, _______, _______, _______, _______,
       _______, _______,
       _______,
       _______, _______, _______
),



/* Keymap 3: Misc Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |        |      |      | PGUP |      |      |      |           |      |      |      |  UP  |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      | HOME |PGDOWN| END  |      |------|           |------|      | LEFT | DOWN |RIGHT |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */

[MISC] = LAYOUT_ergodox(
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, KC_PGUP, _______, _______, _______,
       _______, _______, KC_HOME, KC_PGDOWN, KC_END,_______,
       _______,   _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______,          _______,
                                           _______, _______,
                                                    _______,
                                  _______, _______, _______,
    // right hand
       _______,  _______, _______, _______, _______,  _______, _______,
       _______,  _______, _______, KC_UP,   _______,  _______, _______,
                 _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______,
       _______,  _______, _______, _______, _______,  _______, _______,
                          _______, _______, _______,  _______, _______,
       _______,  _______,
       _______,
       _______, _______, _______
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case EPRM:
        eeconfig_init();
        return false;
      case VRSN:
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        return false;
      #ifdef RGBLIGHT_ENABLE
      case RGB_SLD:
        rgblight_mode(1);
        return false;
      #endif
      case CLEAR:
        reset_oneshot_layer();
        clear_oneshot_mods();
        clear_keyboard();
        layer_clear();
        layer_on(BASE);
        rgb_matrix_sethsv_noeeprom(0, 0, 0);
        return false;
    }
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
  rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
  rgb_matrix_sethsv_noeeprom(0, 0, 0);
};

void oneshot_locked_mods_changed_user(uint8_t mods) {
  if (mods & MOD_MASK_SHIFT) {
    rgb_matrix_sethsv_noeeprom(HSV_MAGENTA);
  } else if (!mods) {
    rgb_matrix_sethsv_noeeprom(0, 0, 0);
  }
}

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = get_highest_layer(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }

  return state;
};
