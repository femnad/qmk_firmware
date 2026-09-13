#include QMK_KEYBOARD_H
#include "version.h"

#define BASE 0
#define SYMB 1
#define MOVE 2
#define INDX 3

#define DIAG_B MT(MOD_RSFT, KC_B)
#define DIAG_X MT(MOD_LSFT, KC_X)
#define HOME_E MT(MOD_LALT, KC_E)
#define HOME_H MT(MOD_RCTL, KC_H)
#define HOME_N MT(MOD_RGUI, KC_N)
#define HOME_O MT(MOD_LGUI, KC_O)
#define HOME_T MT(MOD_RALT, KC_T)
#define HOME_U MT(MOD_LCTL, KC_U)
#define INDX_I LT(INDX, KC_I)
#define INDX_D LT(INDX, KC_D)
#define SPAC_I LT(INDX, KC_SPACE)
#define CAPS_WORD_LEFT_INDEX 37
#define CAPS_WORD_RIGHT_INDEX 77
#define INDX_OSL_LEFT_INDEX 36
#define INDX_OSL_RIGHT_INDEX 76
#define LEFT_SHIFT_INDEX 39
#define RIGHT_SHIFT_INDEX 79
#define MOVE_OSL_LEFT_INDEX 10
#define MOVE_OSL_RIGHT_INDEX 50
#define SYMB_OSL_LEFT_INDEX 38
#define SYMB_OSL_RIGHT_INDEX 78

enum custom_keycodes {
  CLEAR = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Layer: BASE
 * +---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+
 * |OSL(MOVE)|    0    |    9    |    8    |    7    |    6    |                   |    5    |    4    |    3    |    2    |    1    |OSL(MOVE)|
 * +---------+---------+---------+---------+---------+---------+                   +---------+---------+---------+---------+---------+---------+
 * |  BSPC   |    L    |    R    |    C    |    G    |    F    |                   |    Y    |    P    |   DOT   |  COMM   |  QUOT   |   ESC   |
 * +---------+---------+---------+---------+---------+---------+                   +---------+---------+---------+---------+---------+---------+
 * |  CLEAR  |    S    | HOME_N  | HOME_T  | HOME_H  | INDX_D  |                   | INDX_I  | HOME_U  | HOME_E  | HOME_O  |    A    |  CLEAR  |
 * +---------+---------+---------+---------+---------+---------+                   +---------+---------+---------+---------+---------+---------+
 * |   TAB   |  SCLN   |    Q    |    J    |    K    | DIAG_X  |OSM(LSFT)|OSM(RSFT)| DIAG_B  |    M    |    W    |    V    |    Z    |   ENT   |
 * +---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+
 *                     |  VOLU   |  VOLD   |OSL(INDX)| SPAC_I  |OSL(SYMB)|OSL(SYMB)| SPAC_I  |OSL(INDX)|  MPLY   |  MUTE   |
 *                     +---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+
 *                                                             |OSM(RSFT)|OSM(LSFT)|
 *                                                             +---------+---------+
*/
[BASE] = LAYOUT(
        OSL(MOVE), KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, OSL(MOVE),
        KC_ESC, KC_QUOT, KC_COMM, KC_DOT, KC_P, KC_Y, KC_F, KC_G, KC_C, KC_R, KC_L, KC_BSPC,
        CLEAR, KC_A, HOME_O, HOME_E, HOME_U, INDX_I, INDX_D, HOME_H, HOME_T, HOME_N, KC_S, CLEAR,
        KC_TAB, KC_SCLN, KC_Q, KC_J, KC_K, DIAG_X, OSM(MOD_LSFT), OSM(MOD_RSFT), DIAG_B, KC_M, KC_W, KC_V, KC_Z, KC_ENT,
        KC_MUTE, KC_MPLY, OSL(INDX), SPAC_I, OSL(SYMB), OSL(SYMB), SPAC_I, OSL(INDX), KC_VOLD, KC_VOLU,
        OSM(MOD_LSFT), OSM(MOD_RSFT)
),

/* Layer: SYMB
 * +---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+
 * |         |   F10   |   F9    |   F8    |   F7    |   F6    |                   |   F5    |   F4    |   F3    |   F2    |   F1    |         |
 * +---------+---------+---------+---------+---------+---------+                   +---------+---------+---------+---------+---------+---------+
 * |         |   F12   |   F11   |  ASTR   |  AMPR   |  CIRC   |                   |  PERC   |   DLR   |  HASH   |   AT    |  EXLM   |         |
 * +---------+---------+---------+---------+---------+---------+                   +---------+---------+---------+---------+---------+---------+
 * |         |  RBRC   |  LBRC   |  UNDS   |  MINS   |  SLSH   |                   |   EQL   |  RPRN   |  LPRN   |  RCBR   |  LCBR   |         |
 * +---------+---------+---------+---------+---------+---------+                   +---------+---------+---------+---------+---------+---------+
 * |         |         |         |  TILD   |  PIPE   |   GRV   |         |         |  QUES   |  BSLS   |  PLUS   |   INS   |   DEL   |         |
 * +---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+
 *                     |         |         |         | CW_TOGG |         |         | CW_TOGG |         |         |         |
 *                     +---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+
 *                                                             |         |         |
 *                                                             +---------+---------+
*/
[SYMB] = LAYOUT(
        _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, _______,
        _______, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_F11, KC_F12, _______,
        _______, KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, KC_EQL, KC_SLSH, KC_MINS, KC_UNDS, KC_LBRC, KC_RBRC, _______,
        _______, _______, _______, KC_TILD, KC_PIPE, KC_GRV, _______, _______, KC_QUES, KC_BSLS, KC_PLUS, KC_INS, KC_DEL, _______,
        _______, _______, _______, CW_TOGG, _______, _______, CW_TOGG, _______, _______, _______,
        _______, _______
),

/* Layer: MOVE
 * +---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+
 * |         |         |         |         |         |         |                   |         |         |         |         |         |         |
 * +---------+---------+---------+---------+---------+---------+                   +---------+---------+---------+---------+---------+---------+
 * |         |         | MS_ACL2 | MS_ACL1 | MS_ACL0 | MS_BTN5 |                   | MS_WHLU |         |  MS_UP  | BL_TOGG |  BL_UP  |         |
 * +---------+---------+---------+---------+---------+---------+                   +---------+---------+---------+---------+---------+---------+
 * |         |         | MS_BTN2 | MS_BTN3 | MS_BTN1 | MS_BTN4 |                   | MS_WHLD | MS_RGHT | MS_DOWN | MS_LEFT | BL_DOWN |         |
 * +---------+---------+---------+---------+---------+---------+                   +---------+---------+---------+---------+---------+---------+
 * |         | QK_BOOT | RM_TOGG | RM_PREV | RM_NEXT |         |         |         |RCTL(RGUI|         | RM_VALD | RM_VALU | QK_BOOT |         |
 * +---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+
 *                     |         |         |         |         |         |         |         |         |         |         |
 *                     +---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+
 *                                                             |         |         |
 *                                                             +---------+---------+
*/
[MOVE] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, BL_UP, BL_TOGG, MS_UP, _______, MS_WHLU, MS_BTN5, MS_ACL0, MS_ACL1, MS_ACL2, _______, _______,
        _______, BL_DOWN, MS_LEFT, MS_DOWN, MS_RGHT, MS_WHLD, MS_BTN4, MS_BTN1, MS_BTN3, MS_BTN2, _______, _______,
        _______, QK_BOOT, RM_TOGG, RM_PREV, RM_NEXT, _______, _______, _______, RCTL(RGUI(KC_Q)), _______, RM_VALD, RM_VALU, QK_BOOT, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______
),

/* Layer: INDX
 * +---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+
 * |         |         |         | MS_BTN3 |         |         |                   |         |         |         |         |         |         |
 * +---------+---------+---------+---------+---------+---------+                   +---------+---------+---------+---------+---------+---------+
 * |         |         | MS_BTN2 |   UP    | MS_BTN1 |  BSPC   |                   |   ESC   |RCTL(END)|  PGUP   |RCTL(HOME|         |         |
 * +---------+---------+---------+---------+---------+---------+                   +---------+---------+---------+---------+---------+---------+
 * |         |         |  RIGHT  |  DOWN   |  LEFT   |   ENT   |                   |   TAB   |   END   |  PGDN   |  HOME   |         |         |
 * +---------+---------+---------+---------+---------+---------+                   +---------+---------+---------+---------+---------+---------+
 * |         |         |RSFT(TAB)|RCTL(RSFT|RCTL(RSFT|         |         |         |         |RCTL(RSFT|RCTL(TAB)|         |         |         |
 * +---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+
 *                     |         |         |         |         |         |         |         |         |         |         |
 *                     +---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+
 *                                                             |         |         |
 *                                                             +---------+---------+
*/
[INDX] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, MS_BTN3, _______, _______, _______,
        _______, _______, RCTL(KC_HOME), KC_PGUP, RCTL(KC_END), KC_ESC, KC_BSPC, MS_BTN1, KC_UP, MS_BTN2, _______, _______,
        _______, _______, KC_HOME, KC_PGDN, KC_END, KC_TAB, KC_ENT, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______,
        _______, _______, RSFT(KC_TAB), RCTL(RSFT(KC_PGUP)), RCTL(RSFT(KC_PGDN)), _______, _______, _______, _______, RCTL(RSFT(KC_TAB)), RCTL(KC_TAB), _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______
),
};

#ifdef CHORDAL_HOLD
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM = LAYOUT(
    'L', 'L', 'L', 'L', 'L', 'L',           'R', 'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', 'L', 'L',           'R', 'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', 'L', 'L',           'R', 'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 'R',
              'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R',
                                  '*', '*'
);

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case DIAG_B:
    case DIAG_X:
    case HOME_E:
    case HOME_H:
    case HOME_N:
    case HOME_O:
    case HOME_T:
    case HOME_U:
    case INDX_I:
    case INDX_D:
    case SPAC_I:
      return 350;
    default:
      return TAPPING_TERM;
  }
}
#endif

void maybe_reset_rgb_matrix(uint8_t mods) {
  if (mods == 0) {
    rgb_matrix_set_color_all(0, 0, 0);
  }
}

void oneshot_mods_changed_user(uint8_t mods) {
  maybe_reset_rgb_matrix(mods);
}

void oneshot_locked_mods_changed_user(uint8_t mods) {
  maybe_reset_rgb_matrix(mods);
}

void reset_color(int index) {
  rgb_matrix_set_color(index, 0, 0, 0);
}

void clear(void) {
  caps_word_off();
  clear_oneshot_mods();
  clear_oneshot_locked_mods();
  clear_keyboard();
  reset_oneshot_layer();
  layer_clear();
  layer_on(BASE);
  rgb_matrix_set_color_all(0, 0, 0);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case CLEAR:
        clear();
        return false;
    }
  }
  return true;
}

bool rgb_matrix_indicators_user(void) {
  uint8_t mods = get_oneshot_mods();
  uint8_t locked_mods = get_oneshot_locked_mods();

#if defined(LEFT_SHIFT_INDEX) && defined(RIGHT_SHIFT_INDEX)
  if (mods & MOD_MASK_SHIFT) {
    rgb_matrix_set_color(LEFT_SHIFT_INDEX, 128, 0, 128);
    rgb_matrix_set_color(RIGHT_SHIFT_INDEX, 128, 0, 128);
  } else if (locked_mods & MOD_MASK_SHIFT) {
    rgb_matrix_set_color(LEFT_SHIFT_INDEX, 255, 0, 255);
    rgb_matrix_set_color(RIGHT_SHIFT_INDEX, 255, 0, 255);
  } else {
    reset_color(LEFT_SHIFT_INDEX);
    reset_color(RIGHT_SHIFT_INDEX);
  }
#endif

#if defined(INDX_OSL_LEFT_INDEX) && defined(INDX_OSL_RIGHT_INDEX)
#if defined(SYMB_OSL_LEFT_INDEX) && defined(SYMB_OSL_RIGHT_INDEX)
#if defined(MOVE_OSL_LEFT_INDEX) && defined(MOVE_OSL_RIGHT_INDEX)
  uint8_t osl_state = get_oneshot_layer_state();
  uint8_t osl_left_index = 0, osl_right_index = 0;
  uint8_t osl_r = 0, osl_g = 0, osl_b = 0;
  switch (get_oneshot_layer()) {
    case INDX:
      osl_left_index = INDX_OSL_LEFT_INDEX;
      osl_right_index = INDX_OSL_RIGHT_INDEX;
      osl_r = 255;
      break;
    case SYMB:
      osl_left_index = SYMB_OSL_LEFT_INDEX;
      osl_right_index = SYMB_OSL_RIGHT_INDEX;
      osl_b = 255;
      break;
    case MOVE:
      osl_left_index = MOVE_OSL_LEFT_INDEX;
      osl_right_index = MOVE_OSL_RIGHT_INDEX;
      osl_g = 255;
      break;
  }

  if (osl_state & ONESHOT_TOGGLED) {
    rgb_matrix_set_color(osl_left_index, osl_r, osl_g, osl_b);
    rgb_matrix_set_color(osl_right_index, osl_r, osl_g, osl_b);
  } else if (osl_state) {
    rgb_matrix_set_color(osl_left_index, osl_r / 2, osl_g / 2, osl_b / 2);
    rgb_matrix_set_color(osl_right_index, osl_r / 2, osl_g / 2, osl_b / 2);
  } else {
    reset_color(INDX_OSL_LEFT_INDEX);
    reset_color(INDX_OSL_RIGHT_INDEX);
    reset_color(SYMB_OSL_LEFT_INDEX);
    reset_color(SYMB_OSL_RIGHT_INDEX);
    reset_color(MOVE_OSL_LEFT_INDEX);
    reset_color(MOVE_OSL_RIGHT_INDEX);
  }
#endif
#endif
#endif

#if defined(CAPS_WORD_LEFT_INDEX) && defined(CAPS_WORD_RIGHT_INDEX)
  if (is_caps_word_on()) {
    rgb_matrix_set_color(CAPS_WORD_LEFT_INDEX, 255, 255, 0);
    rgb_matrix_set_color(CAPS_WORD_RIGHT_INDEX, 255, 255, 0);
  } else {
    reset_color(CAPS_WORD_LEFT_INDEX);
    reset_color(CAPS_WORD_RIGHT_INDEX);
  }
#endif

  return true;
}
