// Copyright 2025 Dasky (@daskygit)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define BASE 0

enum custom_keycodes {
  CLEAR = SAFE_RANGE
};

// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    QK_BOOT, KC_1  , KC_2  , KC_3  , KC_4  , KC_5  , KC_6  , KC_7  , KC_8  , KC_9  , KC_0  , QK_BOOT,
    KC_MPLY, KC_QUOTE, KC_COMMA, KC_DOT, KC_P  , KC_Y  , KC_F  , KC_G  , KC_C  , KC_R  , KC_L  , KC_VOLD,
    CLEAR , KC_A  , LGUI_T(KC_O), LALT_T(KC_E), LCTL_T(KC_U), LT(2,KC_I), LT(2,KC_D), RCTL_T(KC_H), RALT_T(KC_T), RGUI_T(KC_N), KC_S  , CLEAR,
    KC_MPRV, KC_SCLN, KC_Q  , KC_J  , KC_K  , LSFT_T(KC_X), OSM(MOD_LSFT), OSM(MOD_RSFT), RSFT_T(KC_B), KC_M  , KC_W  , KC_V  , KC_Z  , KC_MNXT,
                      LT(2,KC_SPACE), KC_LALT, KC_LCTL, OSL(1), LT(2,KC_SPACE), LT(2,KC_SPACE), OSL(1), KC_RCTL, KC_RALT, LT(2,KC_SPACE),
                    //Left Encoder Press                                           Right Encoder Press
                            OSM(MOD_LSFT),                                                         OSM(MOD_RSFT)
  ),
  [1] = LAYOUT(
    KC_TRNS, KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 , KC_F6 , KC_F7 , KC_F8 , KC_F9 , KC_F10, KC_F11,
    KC_TRNS, LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_4), LSFT(KC_5), LSFT(KC_6), LSFT(KC_7), LSFT(KC_8), LSFT(KC_9), LSFT(KC_0), KC_TRNS,
    CLEAR , LSFT(KC_LBRC), LSFT(KC_RBRC), LSFT(KC_9), LSFT(KC_0), KC_EQUAL, KC_SLASH, KC_MINUS, LSFT(KC_MINUS), KC_LBRC, KC_RBRC, CLEAR,
    KC_TRNS, KC_TRNS, KC_TRNS, LSFT(KC_GRAVE), LSFT(KC_BSLS), KC_GRAVE, KC_TRNS, KC_TRNS, KC_BSLS, LSFT(KC_EQUAL), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(3) , KC_TRNS, KC_TRNS, KC_TRNS,
                    //Left Encoder Press                                           Right Encoder Press
                            KC_MUTE,                                                         KC_MPLY
  ),
  [2] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_INSERT, KC_PSCR, KC_APPLICATION, KC_NO , KC_ESCAPE, KC_BSPC, KC_NO , KC_UP , KC_NO , KC_NO , KC_BSPC,
    KC_TRNS, KC_LALT, KC_LCTL, KC_LSFT, KC_NO , KC_TAB, KC_ENTER, KC_LEFT, KC_DOWN, KC_RIGHT, KC_DELETE, KC_NO,
    KC_TRNS, LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), OSM(MOD_LSFT), KC_TRNS, KC_TRNS, OSM(MOD_RSFT), KC_NO , KC_NO , KC_NO , KC_NO , KC_TRNS,
                      KC_TRNS, KC_TRNS, KC_TRNS, MO(3) , KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                    //Left Encoder Press                                           Right Encoder Press
                            KC_MUTE,                                                         KC_MPLY
  ),
  [3] = LAYOUT(
    KC_NO , BL_TOGG, BL_DOWN, BL_UP , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO,
    QK_BOOT, KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , QK_BOOT, KC_NO , KC_NO , KC_NO , KC_NO , KC_NO,
    RM_TOGG, RM_HUEU, RM_SATU, RM_VALU, KC_NO , KC_NO , KC_NO , KC_VOLD, KC_MUTE, KC_VOLU, KC_NO , KC_NO,
    RM_NEXT, RM_HUED, RM_SATD, RM_VALD, KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_MPRV, KC_MPLY, KC_MNXT, KC_NO , KC_NO,
                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                    //Left Encoder Press                                           Right Encoder Press
                            KC_MUTE,                                                         KC_MPLY
  )
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
[0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT)},
[1] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS)},
[2] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS)},
[3] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS)}
};
#endif

#ifdef CHORDAL_HOLD
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM = LAYOUT(
    'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', 'L', 'L', '*', '*', 'R', 'R', 'R', 'R', 'R', 'R',
                      '*', '*', '*', '*', '*', '*', '*', '*', '*', '*',
                            '*',                                                         '*'
);

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(2, KC_I):
        case LT(2, KC_D):
        case LCTL_T(KC_U):
        case LALT_T(KC_E):
        case LGUI_T(KC_O):
        case RCTL_T(KC_H):
        case RALT_T(KC_T):
        case RGUI_T(KC_N):
        case LSFT_T(KC_X):
        case RSFT_T(KC_B):
            return 350;
        default:
            return TAPPING_TERM;
    }
}
#endif
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case CLEAR:
        caps_word_off();
        clear_oneshot_mods();
        clear_oneshot_locked_mods();
        clear_keyboard();
        reset_oneshot_layer();
        layer_clear();
        layer_on(BASE);
#ifdef RGB_MATRIX_ENABLE
        rgb_matrix_set_color_all(0, 0, 0);
#endif
        return false;
    }
  }
  return true;
}
