#include QMK_KEYBOARD_H

enum sofle_layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes { KC_QWERTY = SAFE_RANGE };

#define MT_ESC MT(MOD_LCTL, KC_ESC)

#define OS_R OSL(_RAISE)
#define OS_L OSL(_LOWER)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT(
/*-----------------------------------------------------.                  .-----------------------------------------------------.
 |      ` |      1 |      2 |      3 |      4 |      5 |                  |      6 |      7 |      8 |      9 |      0 |    DEL |
 |--------+--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------+--------|
 |    TAB |      Q |      W |      E |      R |      T |                  |      Y |      U |      I |      O |      P |   BSPC |
 |--------+--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------+--------|
 |   ESC* |      A |      S |      D |      L |      G |--------..--------|      H |      J |      K |      L |      ; |      ' |
 |--------+--------+--------+--------+--------+--------|        ||        |--------+--------+--------+--------+--------+--------|
 | LSHIFT |      Z |      X |      C |      V |      B |--------||--------|      N |      M |      , |      . |      / | RSHIFT |
 '-----------------------------------------------------/        /\        \-----------------------------------------------------'
                |   LGUI |   LALT |  LOWER |  ENTER | /  SPACE /  \  ENTER \ |  SPACE |  RAISE |  RGUI  |   RALT |
                |        |        |        |        |/        /    \        \|        |        |        |        |
                '--------------------------------------------'      '--------------------------------------------*/
   KC_GRV,    KC_1,    KC_2,     KC_3,   KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_DEL,
   KC_TAB,    KC_Q,    KC_W,     KC_E,   KC_R,    KC_T,                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
   MT_ESC,    KC_A,    KC_S,     KC_D,   KC_F,    KC_G,                       KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  KC_LSFT,    KC_Z,    KC_X,     KC_C,   KC_V,    KC_B, XXXXXXX,  XXXXXXX,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
                 KC_LGUI, KC_LALT,    OS_L,   KC_ENT,  KC_SPC,        KC_ENT,  KC_SPC,    OS_R, KC_RGUI, KC_RALT
),

[_LOWER] = LAYOUT(
/*-----------------------------------------------------.                  .-----------------------------------------------------.
 |        |        |        |        |        |        |                  |     F6 |     F7 |     F8 |     F9 |    F10 |    F11 |
 |--------+--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------+--------|
 |        |        |        |        |        |        |                  |      6 |      7 |      8 |      9 |      0 |    F12 |
 |--------+--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------+--------|
 |        |        |        |        |        |        |--------..--------|      - |      = |      [ |      ] |      \ |        |
 |--------+--------+--------+--------+--------+--------|        ||        |--------+--------+--------+--------+--------+--------|
 |        |        |        |        |        |        |--------||--------|      ^ |      & |     *  |      ( |      ) |        |
 '-----------------------------------------------------/        /\        \-----------------------------------------------------'
                |        |        |        |        | /        /  \        \ |        |        |        |        |
                |        |        |        |        |/        /    \        \|        |        |        |        |
                '--------------------------------------------'      '--------------------------------------------*/
  _______, _______, _______, _______, _______, _______,                      KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  _______, _______, _______, _______, _______, _______,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_F12,
  _______, _______, _______, _______, _______, _______,                    KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, _______,
  _______, _______, _______, _______, _______, _______, _______,  _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
                 _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______
),

[_RAISE] = LAYOUT(
/*-----------------------------------------------------.                  .-----------------------------------------------------.
 |        |     F1 |     F2 |     F3 |     F4 |     F5 |                  |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------+--------|
 |        |      1 |      2 |      3 |      4 |      5 |                  |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------+--------|
 |        |      | |      } |      { |      + |      _ |--------..--------|        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------|        ||        |--------+--------+--------+--------+--------+--------|
 |        |      ! |      @ |      # |      $ |      % |--------||--------|        |        |        |        |        |        |
 '-----------------------------------------------------/        /\        \-----------------------------------------------------'
                |        |        |        |        | /        /  \        \ |        |        |        |        |
                |        |        |        |        |/        /    \        \|        |        |        |        |
                '--------------------------------------------'      '--------------------------------------------*/
  _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                    _______, _______, _______, _______, _______, _______,
  _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                    _______, _______, _______, _______, _______, _______,
  _______, KC_PIPE, KC_RCBR, KC_LCBR, KC_PLUS, KC_UNDS,                    _______, _______, _______, _______, _______, _______,
  _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, _______,  _______, _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______
),

[_ADJUST] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
                 _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______
  )
};
// clang-format on

#include <string.h>
#include "raw_hid.h"
void raw_hid_receive(uint8_t *data, uint8_t length) {
    switch (data[0]) {
        case 1:
            oled_write((char *)data + 1, false);
            break;
        default:
            break;
    }

    raw_hid_send(data, length);
}

#ifdef OLED_ENABLE

static void print_status_narrow(void) {
    oled_write_ln_P(PSTR("NOCAP"), false);

    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("BASED"), false);
            break;
        case _RAISE:
            oled_write_ln_P(PSTR("RAISE"), false);
            break;
        case _LOWER:
            oled_write_ln_P(PSTR("LOWER"), false);
            break;
        case _ADJUST:
            oled_write_ln_P(PSTR("     "), true);
            break;
        default:
            oled_write_ln_P(PSTR(" NIL "), false);
    }
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

bool oled_task_user(void) {
    print_status_narrow();
    return false;
}

#endif

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return true;
}

#endif
