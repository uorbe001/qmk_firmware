#include QMK_KEYBOARD_H
#include "uorbe001.h"

extern keymap_config_t keymap_config;

#define UC_TILDE_LOWER_A 0x00e1
#define UC_TILDE_UPPER_A 0x00c1
#define UC_TILDE_LOWER_E 0x00e9
#define UC_TILDE_UPPER_E 0x00c9
#define UC_TILDE_LOWER_I 0x00ed
#define UC_TILDE_UPPER_I 0x00cd
#define UC_TILDE_LOWER_O 0x00d3
#define UC_TILDE_UPPER_O 0x00f3
#define UC_TILDE_LOWER_U 0x00fa
#define UC_TILDE_UPPER_U 0x00da
#define UC_TILDE_LOWER_N 0x00d1
#define UC_TILDE_UPPER_N 0x00f1
#define UC_EURO 0x20ac
#define UC_GBP 0x00a3
#define UC_IQ_MARK 0x00bf

enum custom_keycodes {
  ACCENTSWP = SAFE_RANGE,
  TILDE_A,
  TILDE_E,
  TILDE_I,
  TILDE_O,
  TILDE_U,
  TILDE_N,
  INV_1,
  INV_2,
  INV_3,
  INV_4,
  INV_5,
  INV_6,
  INV_7,
  INV_8,
  INV_9,
  INV_0
};

enum layers {
  WORKMANP,
  NUM_LAYER,
  FUNC_LAYER,
  ACCENTSWP_LAYER
};

#define MAGIC_F LT(FUNC_LAYER, KC_F)
#define MAGIC_T LT(FUNC_LAYER, KC_T)
#define MAGIC_D LT(NUM_LAYER, KC_D)
#define MAGIC_H LT(NUM_LAYER, KC_H)
#define CTL_ESC CTL_T(KC_ESCAPE)
#define CMD_QUOT RGUI_T(KC_QUOT)
#define SPACE_LSHIFT RSFT_T(KC_SPACE)
#define SPACE_RSHIFT LSFT_T(KC_SPACE)
#define ENT_CTL CTL_T(KC_ENTER)
#define MINUS_ALT LALT_T(KC_MINUS)
#define EQL_ALT RALT_T(KC_EQUAL)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [WORKMANP] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     ACCENTSWP, INV_1,  INV_2,  INV_3,   INV_4,    INV_5,                              INV_6,   INV_7,   INV_8,  INV_9,   INV_0,   KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_D,    KC_R,    KC_W,    KC_B,                               KC_J,    KC_F,    KC_U,    KC_P,    KC_SCLN, TD(INV_BRACKETS),
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     CTL_ESC, KC_A, KC_S, MAGIC_H, MAGIC_T, KC_G,                              KC_Y,    KC_N,    KC_E,    KC_O,    KC_I,    CMD_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSPO, KC_Z,    KC_X,    KC_M,    KC_C,    KC_V,    KC_SPACE,         KC_SPACE, KC_K,   KC_L,    KC_COMM, KC_DOT, TD(SLASH), KC_RSPC,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    MINUS_ALT, ENT_CTL, KC_SPACE,                KC_SPACE,ENT_CTL,EQL_ALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [FUNC_LAYER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F12,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, DF(WORKMANP),
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [NUM_LAYER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                         _______, KC_KP_ASTERISK,KC_KP_SLASH, KC_KP_MINUS,_______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_PLUS, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            KC_KP_0, KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_ENTER, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, KC_KP_0, KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_DOT, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [ACCENTSWP_LAYER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRAVE, _______, _______, _______,UC(UC_EURO),UC(UC_GBP),                          _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, TILDE_U, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, TILDE_A, _______, _______, _______, _______,                            _______, TILDE_N,TILDE_E,TILDE_O, TILDE_I, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______,_______,UC(UC_IQ_MARK),_______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

void matrix_init_user(void) {
    set_unicode_input_mode(UC_OSX); // REPLACE UC_XXXX with the Unicode Input Mode for your OS. See table below.
};

bool accents_layer_on = false;

void disable_accents_layer (keyrecord_t *record) {
    if (accents_layer_on && !record->event.pressed) {
      clear_oneshot_layer_state(ONESHOT_PRESSED);
      reset_oneshot_layer();
      accents_layer_on = false;
    }
}

bool send_shifty_unicode (uint16_t regular, uint16_t shifted) {
  bool is_capital = ( keyboard_report->mods & (MOD_BIT(KC_LSFT) |MOD_BIT(KC_RSFT)) );

  unicode_input_start();
  register_hex(is_capital ? shifted : regular);
  unicode_input_finish();
  return false;
}

bool process_shifty_unicode (keyrecord_t *record, uint16_t regular, uint16_t shifted) {
  disable_accents_layer(record);

  if (!record->event.pressed) {
    return send_shifty_unicode(regular, shifted);
  }

  return true;
}

bool invert_key(keyrecord_t* record, uint16_t target) {
    const uint8_t shift = MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT);

    if (record->event.pressed) {
        bool shift_pressed = keyboard_report->mods & shift;
        bool l_shift_pressed = keyboard_report->mods & MOD_BIT(KC_LSFT);
        bool r_shift_pressed = keyboard_report->mods & MOD_BIT(KC_RSFT);

        if (shift_pressed) {
            unregister_mods(shift);
        } else {
            register_mods(MOD_BIT(KC_LSFT));
        }

        register_code(target & 0xFF);
        unregister_code(target & 0xFF);

        if (!shift_pressed) {
            unregister_mods(MOD_BIT(KC_LSFT));
        }

        if (r_shift_pressed) {
            register_mods(MOD_BIT(KC_RSFT));
        }

        if (l_shift_pressed) {
            register_mods(MOD_BIT(KC_LSFT));
        }
    }

    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case TILDE_A:
      return process_shifty_unicode(record, UC_TILDE_LOWER_A, UC_TILDE_UPPER_A);
    case TILDE_E:
      return process_shifty_unicode(record, UC_TILDE_LOWER_E, UC_TILDE_UPPER_E);
    case TILDE_I:
      return process_shifty_unicode(record, UC_TILDE_LOWER_I, UC_TILDE_UPPER_I);
    case TILDE_U:
      return process_shifty_unicode(record, UC_TILDE_LOWER_U, UC_TILDE_UPPER_U);
    case TILDE_O:
      return process_shifty_unicode(record, UC_TILDE_UPPER_O, UC_TILDE_LOWER_O);
    case TILDE_N:
      return process_shifty_unicode(record, UC_TILDE_UPPER_N, UC_TILDE_LOWER_N);
    case INV_1:
      return invert_key(record, KC_1);
    case INV_2:
      return invert_key(record, KC_2);
    case INV_3:
      return invert_key(record, KC_3);
    case INV_4:
      return invert_key(record, KC_4);
    case INV_5:
      return invert_key(record, KC_5);
    case INV_6:
      return invert_key(record, KC_6);
    case INV_7:
      return invert_key(record, KC_7);
    case INV_8:
      return invert_key(record, KC_8);
    case INV_9:
      return invert_key(record, KC_9);
    case INV_0:
      return invert_key(record, KC_0);
    case ACCENTSWP:
      if (!record->event.pressed) {
        // Do something else when release
        accents_layer_on = true;
        set_oneshot_layer(ACCENTSWP_LAYER, ONESHOT_PRESSED);
      }
      return false; // Skip all further processing of this key
    default:
      disable_accents_layer(record);
      return true; // Process all other keycodes normally
  }
}
