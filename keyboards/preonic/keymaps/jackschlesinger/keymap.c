#include QMK_KEYBOARD_H
#include "features/caps_word.h"

enum preonic_layers {
  _QWERTY,
  _WINQWERTY,
  _GAME,
  _LOWER,
  _RAISE,
  _ADJUST,
  _PROGRAMMING,
  _MOUSE,
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  WINQWERTY,
  GAME,
  BACKLIT,
  PROG,
  MOUSE,
  SQOPEN,
  SQCLS,
  AND,
  OR,
  GREATEREQ,
  LESSEQ,
  PLUSEQ,
  MINUSEQ,
  ISEQ,
  NOTEQ,
  DECREMENT,
  INCREMENT,
  TIMESEQ,
  DIVEQ,
};

typedef struct {
    bool is_press_action;
    uint8_t state;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP, // Send two single taps
    TRIPLE_TAP,
    TRIPLE_HOLD,
    TRIPLE_SINGLE_TAP,

    NO_TAP_STATE
};

enum {
    TAB_GRV,
    ESC_GRV,
    CTRL_CAD,
    CURLY,
    PARENS,
    SQUARE,
    TRIANGLE,
    ESC_MOUSE
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define PROG MO(_PROGRAMMING)

// Left-hand home row mods
#define HOME_A LCTL_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LGUI_T(KC_D)
#define HOME_F LSFT_T(KC_F)

// Right-hand home row mods
#define HOME_J RSFT_T(KC_J)
#define HOME_K RGUI_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_SCLN RCTL_T(KC_SCLN)

// Windows home row mods
#define W_HOME_A LGUI_T(KC_A)
#define W_HOME_D LCTL_T(KC_D)
#define W_HOME_K RCTL_T(KC_K)
#define W_HOME_SCLN RGUI_T(KC_SCLN)

#define ESC_MOUSE LT(_MOUSE, KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_preonic_grid(
  TD(TAB_GRV),       KC_1,     KC_2,     KC_3,     KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,     KC_0,        KC_BSPC,
  TD(TAB_GRV),  KC_Q,     KC_W,     KC_E,     KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,     KC_O,     KC_P,       KC_BSPC,
  ESC_MOUSE,    HOME_A,   HOME_S,   HOME_D,   HOME_F,  KC_G,    KC_H,    HOME_J,  HOME_K,   HOME_L,   HOME_SCLN,  KC_QUOT,
  KC_LSFT,      KC_Z,     KC_X,     KC_C,     KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,    KC_ENT,
  TD(CTRL_CAD), KC_LALT,  KC_LGUI,  PROG,     LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT,  KC_DOWN,  KC_UP,      KC_RIGHT
),

[_WINQWERTY] = LAYOUT_preonic_grid(
  TD(TAB_GRV),  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  TD(TAB_GRV),  KC_Q,     KC_W,     KC_E,     KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,     KC_O,     KC_P,        KC_BSPC,
  ESC_MOUSE,    W_HOME_A, HOME_S,   W_HOME_D, HOME_F,  KC_G,    KC_H,    HOME_J,  W_HOME_K, HOME_L,   W_HOME_SCLN, KC_QUOT,
  KC_LSFT,      KC_Z,     KC_X,     KC_C,     KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,     KC_ENT,
  TD(CTRL_CAD), KC_LALT,  KC_LGUI,  PROG,     LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT,  KC_DOWN,  KC_UP,       KC_RIGHT
),

[_MOUSE] = LAYOUT_preonic_grid(
  TD(TAB_GRV),  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  _______, _______,    _______,    _______,    _______,    _______, _______, KC_MS_WH_LEFT, KC_MS_WH_DOWN, KC_MS_WH_UP, KC_MS_WH_RIGHT, KC_MS_ACCEL0,
  _______, KC_MS_BTN3, KC_MS_BTN2, KC_MS_BTN1, _______,    _______, _______, KC_MS_LEFT,    KC_MS_DOWN,    KC_MS_UP,    KC_MS_RIGHT,    KC_MS_ACCEL1,
  _______, _______,    _______,    KC_MS_BTN5, KC_MS_BTN4, _______, _______, _______,       _______,       _______,     _______,        KC_MS_ACCEL2,
  _______, _______,    _______,    _______,    _______,    _______, _______, _______,       _______,       _______,     _______,        _______
),

[_GAME] = LAYOUT_preonic_grid(
  TD(TAB_GRV),  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_ESC,        KC_Q,  KC_W,  KC_E,  KC_R,  KC_5,    KC_6,    KC_7,   KC_8,     KC_9,     KC_0,     KC_BSPC,
  KC_TAB,        KC_A,  KC_S,  KC_D,  KC_F,  KC_G,    KC_H,    KC_J,   KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
  KC_LSFT,       KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,    KC_N,    KC_M,   KC_COMM,  KC_UP,    KC_SLSH,  KC_ENT,
  TD(CTRL_CAD),  KC_4,  KC_3,  KC_2,  KC_1,  KC_SPC,  KC_SPC,  RAISE,  KC_LEFT,  KC_DOWN,  KC_RIGHT, LOWER
),

[_LOWER] = LAYOUT_preonic_grid(
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSPC,
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSPC,
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE,
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  _______,
  _______, _______, _______, _______, _______, _______, _______, _______,    KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY
),

[_RAISE] = LAYOUT_preonic_grid(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

[_ADJUST] = LAYOUT_preonic_grid(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,   RGB_VAI, RGB_VAD, KC_DEL ,
  _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  WINQWERTY, _______, _______, _______,
  _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF,  _______, _______, GAME,
  _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______
),

[_PROGRAMMING] = LAYOUT_preonic_grid(
   TD(TAB_GRV),  KC_1,      KC_2,     KC_3,      KC_4,     KC_5,      KC_6,         KC_7,         KC_8,     KC_9,    KC_0,      KC_BSPC,
   KC_PERC,      KC_LPRN,   KC_RPRN,  GREATEREQ, LESSEQ,   DIVEQ,     NOTEQ,        TD(PARENS),   KC_P7,    KC_P8,   KC_P9,     KC_PSLS, 
    KC_MINS,     KC_LCBR,   KC_RCBR,  OR,        AND,      TIMESEQ,   ISEQ,         TD(CURLY),    KC_P4,    KC_P5,   KC_P6,     KC_PAST, 
    KC_UNDS,     SQOPEN,    SQCLS,    PLUSEQ,    MINUSEQ,  DECREMENT, TD(TRIANGLE), TD(SQUARE),   KC_P1,    KC_P2,   KC_P3,     KC_PMNS,  
    _______,     KC_GT,     ISEQ,     _______,   _______,  INCREMENT, INCREMENT,    KC_NLCK,      KC_P0,    KC_PDOT, KC_PENT,   KC_PPLS
)

};


layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_caps_word(keycode, record)) {
   return false; 
  }

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case WINQWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_WINQWERTY);
      }
      return false;
      break;
    case GAME:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_GAME);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        #ifdef KEYBOARD_planck_rev5
          writePinLow(E6);
        #endif
      } else {
        unregister_code(KC_RSFT);
        #ifdef KEYBOARD_planck_rev5
          writePinHigh(E6);
        #endif
      }
      return false;
      break;
    case PROG:
      if (record->event.pressed) {
        layer_on(_PROGRAMMING);
      } 
      else {
        layer_off(_PROGRAMMING);
      }
      break;
    case SQOPEN:
      if (record->event.pressed) {
        SEND_STRING("[");
      }
      break;
    case SQCLS:
      if (record->event.pressed) {
        SEND_STRING("]");
      }
      break;
    case AND:
      if (record->event.pressed) {
        SEND_STRING("&&");
      }
      break;
    case OR:
      if (record->event.pressed) {
        SEND_STRING("||");
      }
      break;
    case GREATEREQ:
      if (record->event.pressed) {
        SEND_STRING(">=");
      }
      break;
    case LESSEQ:
      if (record->event.pressed) {
        SEND_STRING("<=");
      }
      break;
    case PLUSEQ:
      if (record->event.pressed) {
        SEND_STRING("+=");
      }
      break;
    case MINUSEQ:
      if (record->event.pressed) {
        SEND_STRING("-=");
      }
      break;
    case ISEQ:
      if (record->event.pressed) {
        SEND_STRING("==");
      }
      break;
    case NOTEQ:
      if (record->event.pressed) {
        SEND_STRING("!=");
      }
      break;
    case DECREMENT:
      if (record->event.pressed) {
        SEND_STRING("--");
      }
      break;
    case INCREMENT:
      if (record->event.pressed) {
        SEND_STRING("++");
      }
      break;
    case TIMESEQ:
      if (record->event.pressed) {
        SEND_STRING("*=");
      }
      break;
    case DIVEQ:
      if (record->event.pressed) {
        SEND_STRING("/=");
      }
      break;
  }
  return true;
};

void keyboard_post_init_user(void) {
  // Call the post init code.
  rgblight_disable_noeeprom(); // enables Rgb, without saving settings
}

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(1, KC_A):
        case LT(1, KC_S):
        case LT(1, KC_D):
        case LT(1, KC_F):
        case LT(1, KC_J):
        case LT(1, KC_K):
        case LT(1, KC_L):
        case LT(1, KC_SCLN):
          return true;
        default:
          return false;
    }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(1, KC_A):
        case LT(1, KC_S):
        case LT(1, KC_D):
        case LT(1, KC_F):
        case LT(1, KC_J):
        case LT(1, KC_K):
        case LT(1, KC_L):
        case LT(1, KC_SCLN):
            return true;
        default:
            return false;
    }
}
int get_dance_status(qk_tap_dance_state_t *state) {
  //NOTE: Interrupted means we are trying to do separate taps

  if (state->count == 1) {
    return (state->interrupted || !state->pressed) ? SINGLE_TAP : SINGLE_HOLD;
  }
  else if (state->count == 2) {
    if (state->interrupted) 
      return DOUBLE_SINGLE_TAP;
    return state->pressed ? DOUBLE_HOLD : DOUBLE_TAP;
  } 
  else if (state->count == 3) {
    if (state->interrupted) 
      return TRIPLE_SINGLE_TAP;
    return state->pressed ? TRIPLE_HOLD : TRIPLE_TAP;
  }
  
  return NO_TAP_STATE;
}

//initialize an instance of 'tap' for the 'x' tap dance.
static tap ctrltap_state = { 
  .is_press_action = true,
  .state = 0
};

void ctrltap_finished(qk_tap_dance_state_t *state, void *user_data) {
  ctrltap_state.state = get_dance_status(state);
  switch (ctrltap_state.state) {
    case SINGLE_TAP: 
      register_code(KC_LCTL); 
      break;
    case SINGLE_HOLD: 
      register_code(KC_LCTL); 
      break;
    case DOUBLE_SINGLE_TAP: 
      tap_code(KC_LCTL); register_code(KC_LCTL); 
      break;
    case DOUBLE_HOLD: 
      register_code(KC_LCTL); 
      break;
    case TRIPLE_TAP: 
      register_code (KC_LCTL);   register_code (KC_LALT);   register_code (KC_DEL);
      break;
  }
}

/*
  Handles the ctrl key tap dance reset event
*/
void ctrltap_reset(qk_tap_dance_state_t *state, void *user_data) {
  switch (ctrltap_state.state) {
    case SINGLE_TAP: 
    case SINGLE_HOLD:
    case DOUBLE_HOLD:
    case DOUBLE_SINGLE_TAP:
      unregister_code(KC_LCTL); 
      break;

    case TRIPLE_TAP:
      unregister_code (KC_LCTL); unregister_code (KC_LALT); unregister_code (KC_DEL);
      break;
  }
  ctrltap_state.state = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [TAB_GRV] =  ACTION_TAP_DANCE_DOUBLE(KC_TAB, KC_GRV),
    [ESC_GRV] =  ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_GRV),
    [CTRL_CAD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ctrltap_finished, ctrltap_reset),
    [CURLY] =    ACTION_TAP_DANCE_DOUBLE(KC_LCBR, KC_RCBR),
    [PARENS] =   ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_RPRN),
    [SQUARE] =   ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC),
    [TRIANGLE] =   ACTION_TAP_DANCE_DOUBLE(KC_LT, KC_GT),
};
