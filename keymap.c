#include QMK_KEYBOARD_H

enum sofle_layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_PRVWD,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_DLINE
};

#define MT_F MT(MOD_LCTL,KC_F)
#define MT_D MT(MOD_LGUI,KC_D)
#define MT_S MT(MOD_LALT,KC_S)
#define MT_J MT(MOD_RCTL,KC_J)
#define MT_K MT(MOD_LGUI,KC_K)
#define MT_L MT(MOD_LALT,KC_L)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT(
/*-----------------------------------------------------.                  .-----------------------------------------------------.
 |      ` |      1 |      2 |      3 |      4 |      5 |                  |      6 |      7 |      8 |      9 |      0 |  ENTER |
 |--------+--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------+--------|
 |    TAB |      Q |      W |      E |      R |      T |                  |      Y |      U |      I |      O |      P |   BSPC |
 |--------+--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------+--------|
 |    ESC |      A |     S* |     D* |     L* |      G |--------..--------|      H |     J* |     K* |     L* |      ; |      ' |
 |--------+--------+--------+--------+--------+--------|        ||        |--------+--------+--------+--------+--------+--------|
 | LSHIFT |      Z |      X |      C |      V |      B |--------||--------|      N |      M |      , |      . |      / | RSHIFT |
 '-----------------------------------------------------/        /\        \-----------------------------------------------------'
                |   LGUI |   LALT |  LOWER |  ENTER | /  SPACE /  \  ENTER \ |  SPACE |  RAISE |  RALT  |   RGUI |
                |        |        |        |        |/        /    \        \|        |        |        |        |
                '--------------------------------------------'      '--------------------------------------------*/
   KC_GRV,    KC_1,    KC_2,     KC_3,   KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_ENT,
   KC_TAB,    KC_Q,    KC_W,     KC_E,   KC_R,    KC_T,                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
   KC_ESC,    KC_A,    MT_S,     MT_D,   MT_F,    KC_G,                       KC_H,    MT_J,    MT_K,    MT_L, KC_SCLN, KC_QUOT,
  KC_LSFT,    KC_Z,    KC_X,     KC_C,   KC_V,    KC_B, XXXXXXX,  XXXXXXX,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
                 KC_LGUI,KC_LALT,MO(_LOWER),  KC_ENT, KC_ENT,        KC_SPC,  KC_SPC, MO(_RAISE), KC_RALT, KC_RGUI
),

[_LOWER] = LAYOUT(
/*-----------------------------------------------------.                  .-----------------------------------------------------.
 |        |        |        |        |        |        |                  |     F6 |     F7 |     F8 |     F9 |    F10 |    F11 |
 |--------+--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------+--------|
 |        |        |        |        |        |        |                  |      6 |      7 |      8 |      9 |     10 |    F12 |
 |--------+--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------+--------|
 |        |        |        |        |        |        |--------..--------|      ^ |      & |      * |      ( |      ) |      | |
 |--------+--------+--------+--------+--------+--------|        ||        |--------+--------+--------+--------+--------+--------|
 |        |        |        |        |        |        |--------||--------|      [ |      ] |      ; |      : |      \ |        |
 '-----------------------------------------------------/        /\        \-----------------------------------------------------'
                |        |        |        |        | /        /  \        \ |        |        |        |        |
                |        |        |        |        |/        /    \        \|        |        |        |        |
                '--------------------------------------------'      '--------------------------------------------*/
  _______, _______, _______, _______, _______, _______,                      KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  _______, _______, _______, _______, _______, _______,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_F12,
  _______, _______, _______, _______, _______, _______,                    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
  _______, _______, _______, _______, _______, _______, _______,  _______, KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, _______,
                 _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______
),

[_RAISE] = LAYOUT(
/*-----------------------------------------------------.                  .-----------------------------------------------------.
 |        |     F1 |     F2 |     F3 |     F4 |     F5 |                  |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------+--------|
 |        |      1 |      2 |      3 |      4 |      5 |                  |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------|                  |--------+--------+--------+--------+--------+--------|
 |        |      ! |      @ |      # |      $ |      % |--------..--------|        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------|        ||        |--------+--------+--------+--------+--------+--------|
 |        |      = |      - |      + |      { |      } |--------||--------|        |        |        |        |        |        |
 '-----------------------------------------------------/        /\        \-----------------------------------------------------'
                |        |        |        |        | /        /  \        \ |        |        |        |        |
                |        |        |        |        |/        /    \        \|        |        |        |        |
                '--------------------------------------------'      '--------------------------------------------*/
  _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                    _______, _______, _______, _______, _______, _______,
  _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                    _______, _______, _______, _______, _______, _______,
  _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                    _______, _______, _______, _______, _______, _______,
  _______,  KC_EQL, KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, _______,  _______, _______, _______, _______, _______, _______, _______,
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

#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xd4, 0xe8, 0x0d, 0xc2, 0x48, 0x02, 0xc5,
        0x20, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0xe8, 0xd0, 0x2a, 0xc4, 0x40, 0x04, 0xd2, 0x00, 0x88, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe8,
        0xd0, 0x2a, 0xc4, 0x40, 0x04, 0xd2, 0x00, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe8, 0xd0, 0x2a, 0xc4, 0x40, 0x04, 0xd2,
        0x00, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0xe8, 0xd0, 0x2a, 0xc4, 0x40, 0x04, 0xd2, 0x00, 0x88, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0xa0, 0xed, 0xed, 0xfa, 0xe7, 0xbd, 0xe2, 0xb4,
        0xe9, 0x10, 0x02, 0x14, 0x40, 0x20, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x80, 0x00, 0xed, 0xee, 0xf2, 0xef, 0xb5, 0xea, 0xb0, 0xf5, 0x00, 0x08, 0x10, 0x40,
        0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0xed,
        0xee, 0xf2, 0xef, 0xb5, 0xea, 0xb0, 0xf5, 0x00, 0x08, 0x10, 0x40, 0x00, 0x80, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0xed, 0xee, 0xf2, 0xef, 0xb5, 0xea, 0xb0,
        0xf5, 0x00, 0x08, 0x10, 0x40, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x80, 0x00, 0xed, 0xee, 0xf2, 0xef, 0xb5, 0xea, 0xb0, 0xf5, 0x00, 0x08, 0x10, 0x40,
        0x00, 0x00, 0x80, 0xc0, 0xc0, 0x88, 0x72, 0x04, 0x7e, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0x7f,
        0xff, 0xaf, 0x70, 0x2a, 0x40, 0x20, 0x00, 0xee, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80,
        0x90, 0x2a, 0x60, 0x5f, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0x6f, 0x50, 0x34, 0x41,
        0x20, 0x00, 0xdc, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x90, 0x2a, 0x60, 0x5f, 0xff,
        0x7f, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0x6f, 0x50, 0x34, 0x41, 0x20, 0x00, 0xdc, 0x20, 0x00,
        0x00, 0x00, 0x00, 0x80, 0x80, 0x90, 0x2a, 0x60, 0x5f, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0x7f,
        0xff, 0x6f, 0x50, 0x34, 0x41, 0x20, 0x00, 0xdc, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80,
        0x90, 0x2a, 0x60, 0x5f, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xaf, 0x70, 0x2a, 0x40,
        0x16, 0x14, 0x6f, 0x5a, 0x37, 0x4d, 0x7f, 0xcb, 0x3c, 0xc0, 0xbc, 0x03, 0x0f, 0x02, 0x4f, 0x09,
        0x03, 0xfe, 0xad, 0x5b, 0xe4, 0x3c, 0x48, 0x15, 0x2f, 0x08, 0x00, 0x0c, 0x18, 0x6f, 0x15, 0x7f,
        0x55, 0xab, 0x5f, 0xf4, 0x08, 0xf4, 0x0b, 0x0b, 0x06, 0x0b, 0x45, 0x0b, 0xed, 0xb7, 0x6d, 0xd8,
        0x24, 0x7c, 0x05, 0x5b, 0x04, 0x00, 0x1c, 0x08, 0x5f, 0x35, 0x6f, 0x55, 0xbb, 0x6f, 0xb4, 0x48,
        0xb4, 0x0b, 0x0b, 0x06, 0x4b, 0x05, 0x0b, 0xed, 0xb7, 0x6d, 0xd8, 0x24, 0x7c, 0x05, 0x5b, 0x04,
        0x18, 0x14, 0x7f, 0x05, 0x7f, 0x55, 0x6b, 0xdf, 0x34, 0xc8, 0x34, 0x0b, 0x0b, 0x06, 0x4b, 0x05,
        0x0b, 0xed, 0xb7, 0x6d, 0xd8, 0x24, 0x7c, 0x05, 0x5b, 0x04, 0x00, 0x1c, 0x08, 0x5f, 0x35, 0x6f,
        0x55, 0xbb, 0x6f, 0xb4, 0x48, 0xb4, 0x0b, 0x0b, 0x06, 0x4b, 0x05, 0x0b, 0xde, 0x75, 0xab, 0x5c
    };

    oled_write_raw_P(qmk_logo, sizeof(qmk_logo));
}

static void print_status_narrow(void) {
    oled_write_ln_P(PSTR(""), false);
    oled_write_ln_P(PSTR(".TUNA"), false);
    oled_write_ln_P(PSTR(""), false);

    oled_write_ln_P(PSTR("LAYER"), false);
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
    oled_write_P(PSTR("\n\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
    return false;
}

#endif

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            break;
        case KC_NXTWD:
             if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            break;
        case KC_LSTRT:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                     //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                } else {
                    register_code(KC_HOME);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_code(KC_HOME);
                }
            }
            break;
        case KC_LEND:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                } else {
                    register_code(KC_END);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_code(KC_END);
                }
            }
            break;
        case KC_DLINE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_BSPC);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_BSPC);
            }
            break;
        case KC_COPY:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_C);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_C);
            }
            return false;
        case KC_PASTE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_V);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_V);
            }
            return false;
        case KC_CUT:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_X);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_X);
            }
            return false;
            break;
        case KC_UNDO:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_Z);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_Z);
            }
            return false;
    }
    return true;
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
