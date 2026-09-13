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

enum preonic_keycodes {
  CLEAR = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Layer: BASE
 * +---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+
 * |    1    |    2    |    3    |    4    |    5    |  CLEAR  |  CLEAR  |    6    |    7    |    8    |    9    |    0    |
 * +---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+
 * |  QUOT   |  COMM   |   DOT   |    P    |    Y    |   ESC   |  BSPC   |    F    |    G    |    C    |    R    |    L    |
 * +---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+
 * |    A    | HOME_O  | HOME_E  | HOME_U  | INDX_I  |   TAB   |   ENT   | INDX_D  | HOME_H  | HOME_T  | HOME_N  |    S    |
 * +---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+
 * |  SCLN   |    Q    |    J    |    K    | DIAG_X  |OSM(LSFT)|OSM(RSFT)| DIAG_B  |    M    |    W    |    V    |    Z    |
 * +---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+
 * |  MUTE   |  MPLY   |OSL(INDX)|OSL(MOVE)| SPAC_I  |OSL(SYMB)|OSL(SYMB)| SPAC_I  |OSL(MOVE)|OSL(INDX)|  VOLD   |  VOLU   |
 * +---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+
*/
[BASE] = LAYOUT_preonic_grid(
        KC_1, KC_2, KC_3, KC_4, KC_5, CLEAR, CLEAR, KC_6, KC_7, KC_8, KC_9, KC_0,
        KC_QUOT, KC_COMM, KC_DOT, KC_P, KC_Y, KC_ESC, KC_BSPC, KC_F, KC_G, KC_C, KC_R, KC_L,
        KC_A, HOME_O, HOME_E, HOME_U, INDX_I, KC_TAB, KC_ENT, INDX_D, HOME_H, HOME_T, HOME_N, KC_S,
        KC_SCLN, KC_Q, KC_J, KC_K, DIAG_X, OSM(MOD_LSFT), OSM(MOD_RSFT), DIAG_B, KC_M, KC_W, KC_V, KC_Z,
        KC_MUTE, KC_MPLY, OSL(INDX), OSL(MOVE), SPAC_I, OSL(SYMB), OSL(SYMB), SPAC_I, OSL(MOVE), OSL(INDX), KC_VOLD, KC_VOLU
),

/* Layer: SYMB
 * +---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+
 * |   F1    |   F2    |   F3    |   F4    |   F5    |         |         |   F6    |   F7    |   F8    |   F9    |   F10   |
 * +---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+
 * |  EXLM   |   AT    |  HASH   |   DLR   |  PERC   |         |         |  CIRC   |  AMPR   |  ASTR   |   F11   |   F12   |
 * +---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+
 * |  LCBR   |  RCBR   |  LPRN   |  RPRN   |   EQL   |         |         |  SLSH   |  MINS   |  UNDS   |  LBRC   |  RBRC   |
 * +---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+
 * |         |         |  TILD   |  PIPE   |   GRV   |         |         |  QUES   |  BSLS   |  PLUS   |   INS   |   DEL   |
 * +---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+
 * |         |         |         |         | CW_TOGG |         |         | CW_TOGG |         |         |         |         |
 * +---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+
*/
[SYMB] = LAYOUT_preonic_grid(
        KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, _______, _______, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,
        KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, _______, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_F11, KC_F12,
        KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, KC_EQL, _______, _______, KC_SLSH, KC_MINS, KC_UNDS, KC_LBRC, KC_RBRC,
        _______, _______, KC_TILD, KC_PIPE, KC_GRV, _______, _______, KC_QUES, KC_BSLS, KC_PLUS, KC_INS, KC_DEL,
        _______, _______, _______, _______, CW_TOGG, _______, _______, CW_TOGG, _______, _______, _______, _______
),

/* Layer: MOVE
 * +---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+
 * |         |         |         |         |         |         |         |         |         |         |         |         |
 * +---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+
 * |         |         |  MS_UP  |         | MS_WHLU |         |         | MS_BTN5 | MS_ACL0 | MS_ACL1 | MS_ACL2 |         |
 * +---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+
 * |         | MS_LEFT | MS_DOWN | MS_RGHT | MS_WHLD |         |         | MS_BTN4 | MS_BTN1 | MS_BTN3 | MS_BTN2 |         |
 * +---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+
 * | QK_BOOT | RM_TOGG | RM_PREV | RM_NEXT |         |         |         |RCTL(RGUI|         | RM_VALD | RM_VALU | QK_BOOT |
 * +---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+
 * |         |         |         |         |         |         |         |         |         |         |         |         |
 * +---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+
*/
[MOVE] = LAYOUT_preonic_grid(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, MS_UP, _______, MS_WHLU, _______, _______, MS_BTN5, MS_ACL0, MS_ACL1, MS_ACL2, _______,
        _______, MS_LEFT, MS_DOWN, MS_RGHT, MS_WHLD, _______, _______, MS_BTN4, MS_BTN1, MS_BTN3, MS_BTN2, _______,
        QK_BOOT, RM_TOGG, RM_PREV, RM_NEXT, _______, _______, _______, RCTL(RGUI(KC_Q)), _______, RM_VALD, RM_VALU, QK_BOOT,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Layer: INDX
 * +---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+
 * |         |         |         |         |         |         |         |         |         | MS_BTN3 |         |         |
 * +---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+
 * |         |RCTL(HOME|  PGUP   |RCTL(END)|   ESC   |         |         |  BSPC   | MS_BTN1 |   UP    | MS_BTN2 |         |
 * +---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+
 * |         |  HOME   |  PGDN   |   END   |   TAB   |         |         |   ENT   |  LEFT   |  DOWN   |  RIGHT  |         |
 * +---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+
 * |         |RSFT(TAB)|RCTL(RSFT|RCTL(RSFT|         |         |         |         |RCTL(RSFT|RCTL(TAB)|         |         |
 * +---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+
 * |         |         |         |         |         |         |         |         |         |         |         |         |
 * +---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+
*/
[INDX] = LAYOUT_preonic_grid(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, MS_BTN3, _______, _______,
        _______, RCTL(KC_HOME), KC_PGUP, RCTL(KC_END), KC_ESC, _______, _______, KC_BSPC, MS_BTN1, KC_UP, MS_BTN2, _______,
        _______, KC_HOME, KC_PGDN, KC_END, KC_TAB, _______, _______, KC_ENT, KC_LEFT, KC_DOWN, KC_RIGHT, _______,
        _______, RSFT(KC_TAB), RCTL(RSFT(KC_PGUP)), RCTL(RSFT(KC_PGDN)), _______, _______, _______, _______, RCTL(RSFT(KC_TAB)), RCTL(KC_TAB), _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),
};

#ifdef CHORDAL_HOLD
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM = LAYOUT_preonic_grid(
    'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R',
    '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'
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



void clear(void) {
  caps_word_off();
  clear_oneshot_mods();
  clear_oneshot_locked_mods();
  clear_keyboard();
  reset_oneshot_layer();
  layer_clear();
  layer_on(BASE);
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
