#include QMK_KEYBOARD_H


enum preonic_layers {
 BASE,
 SYMB,
 MDIA,
};

enum preonic_keycodes {
  CLEAR = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Layer: BASE
 * +------+------+------+------+------+------+------+------+------+------+------+------+
 * |  1   |  2   |  3   |  4   |  5   |  ~   |  `   |  6   |  7   |  8   |  9   |  0   |
 * +------+------+------+------+------+------+------+------+------+------+------+------+
 * |  '   |  ,   |  .   |  P   |  Y   | ESC  | BSPC |  F   |  G   |  C   |  R   |  L   |
 * +------+------+------+------+------+------+------+------+------+------+------+------+
 * |  A   |  O   |  E   |  U   |  I   | TAB  | ENT  |  D   |  H   |  T   |  N   |  S   |
 * +------+------+------+------+------+------+------+------+------+------+------+------+
 * |  ;   |  Q   |  J   |  K   |  X   |^LSFT |^RSFT |  B   |  M   |  W   |  V   |  Z   |
 * +------+------+------+------+------+------+------+------+------+------+------+------+
 * |^LGUI |@MDIA |^LALT |^LCTL |@SYMB | SPC  | SPC  |@SYMB |^RCTL |^RALT |@MDIA |^LGUI |
 * +------+------+------+------+------+------+------+------+------+------+------+------+
 *
 */

[BASE] = LAYOUT_preonic_grid(
        KC_1,          KC_2,      KC_3,          KC_4,          KC_5,      KC_TILD,       KC_GRV,        KC_6,      KC_7,          KC_8,          KC_9,      KC_0,
        KC_QUOT,       KC_COMM,   KC_DOT,        KC_P,          KC_Y,      KC_ESC,        KC_BSPC,       KC_F,      KC_G,          KC_C,          KC_R,      KC_L,
        KC_A,          KC_O,      KC_E,          KC_U,          KC_I,      KC_TAB,        KC_ENT,        KC_D,      KC_H,          KC_T,          KC_N,      KC_S,
        KC_SCLN,       KC_Q,      KC_J,          KC_K,          KC_X,      OSM(MOD_LSFT), OSM(MOD_RSFT), KC_B,      KC_M,          KC_W,          KC_V,      KC_Z,
        OSM(MOD_LGUI), OSL(MDIA), OSM(MOD_LALT), OSM(MOD_LCTL), OSL(SYMB), KC_SPC,        KC_SPC,        OSL(SYMB), OSM(MOD_RCTL), OSM(MOD_RALT), OSL(MDIA), OSM(MOD_LGUI)
),

/* Layer: SYMB
 * +------+------+------+------+------+------+------+------+------+------+------+------+
 * |  F1  |  F2  |  F3  |  F4  |  F5  |      |      |  F6  |  F7  |  F8  |  F9  | F10  |
 * +------+------+------+------+------+------+------+------+------+------+------+------+
 * |  !   |  @   |  #   |  $   |  %   |      |      |  ^   |  &   |  *   |  (   |  )   |
 * +------+------+------+------+------+------+------+------+------+------+------+------+
 * |  {   |  }   |  (   |  )   |  =   |      |      |  /   |  -   |      |  [   |  ]   |
 * +------+------+------+------+------+------+------+------+------+------+------+------+
 * |CLEAR |      |  ~   |  |   |  `   |      |      |  \   |  +   | DEL  | INS  |CLEAR |
 * +------+------+------+------+------+------+------+------+------+------+------+------+
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * +------+------+------+------+------+------+------+------+------+------+------+------+
 *
 */

[SYMB] = LAYOUT_preonic_grid(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
        KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, KC_EQL,  _______, _______, KC_SLSH, KC_MINS, KC_UNDS, KC_LBRC, KC_RBRC,
        CLEAR,   _______, KC_TILD, KC_PIPE, KC_GRV,  _______, _______, KC_BSLS, KC_PLUS, KC_DEL,  KC_INS,  CLEAR,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Layer: MDIA
 * +------+------+------+------+------+------+------+------+------+------+------+------+
 * |      |      |      |      |      | VOLD | VOLU |      |      |      | F11  | F12  |
 * +------+------+------+------+------+------+------+------+------+------+------+------+
 * |      |      | PGUP |      |      | MUTE | MPLY |      |      |  UP  |      |      |
 * +------+------+------+------+------+------+------+------+------+------+------+------+
 * |      | HOME | PGDN | END  | INS  | MPRV | MNXT | DEL  | LEFT | DOWN | RGHT |      |
 * +------+------+------+------+------+------+------+------+------+------+------+------+
 * |      |      |      |      | BOOT |      |      | BOOT |      |      |      |      |
 * +------+------+------+------+------+------+------+------+------+------+------+------+
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * +------+------+------+------+------+------+------+------+------+------+------+------+
 */

[MDIA] = LAYOUT_preonic_grid(
        _______, _______, _______, _______, _______, KC_VOLD, KC_VOLU, _______, _______, _______, KC_F11,  KC_F12,
        _______, _______, KC_PGUP, _______, _______, KC_MUTE, KC_MPLY, _______, _______, KC_UP,   _______, _______,
        _______, KC_HOME, KC_PGDN, KC_END,  KC_INS,  KC_MPRV, KC_MNXT, KC_DEL,  KC_LEFT, KC_DOWN, KC_RGHT, _______,
        _______, _______, _______, _______, QK_BOOT, _______, _______, QK_BOOT, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case CLEAR:
        clear_oneshot_mods();
        clear_oneshot_locked_mods();
        clear_keyboard();
        reset_oneshot_layer();
        layer_clear();
        layer_on(BASE);
        return false;
    }
 }
  return true;
}
