#include QMK_KEYBOARD_H

enum layer_names {
  _QWERTY,
  _QWERTY_WIN,
  _GAME,
  _LOWER,
  _RAISE,
  _ADJUST,
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  QWERTY_WIN,
  GAME,
  BACKLIT,
  EXT_PLV,
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
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

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

// Left-hand home row mods
#define HOME_A_WIN LGUI_T(KC_A)
#define HOME_D_WIN LCTL_T(KC_D)

// Right-hand home row mods
#define HOME_K_WIN RCTL_T(KC_K)
#define HOME_SCLN_WIN RGUI_T(KC_SCLN)

// Defines for task manager and such
#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
* 
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Func |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  | Enter|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  `   | GUI  | Alt  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_5x12(
    TD(ESC_GRV),  KC_1,          KC_2,     KC_3,     KC_4,    KC_5,    KC_6,    KC_7,    KC_8,     KC_9,     KC_0,       KC_DEL,
    TD(TAB_GRV),  KC_Q,          KC_W,     KC_E,     KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,     KC_O,     KC_P,       KC_BSPC,
    KC_ESC,       HOME_A,        HOME_S,   HOME_D,   HOME_F,  KC_G,    KC_H,    HOME_J,  HOME_K,   HOME_L,   HOME_SCLN,  KC_QUOT,
    KC_LSFT,      KC_Z,          KC_X,     KC_C,     KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,    KC_ENT,
    TD(CTRL_CAD), TD(CTRL_CAD),  KC_LALT,  KC_LGUI,  LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT,  KC_DOWN,  KC_UP,      KC_RIGHT
),

/* Qwerty Windows
* 
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Func |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  | Enter|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  `   | GUI  | Alt  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY_WIN] = LAYOUT_ortho_5x12(
    TD(ESC_GRV),  KC_1,          KC_2,     KC_3,       KC_4,    KC_5,    KC_6,    KC_7,    KC_8,       KC_9,     KC_0,          KC_DEL,
    TD(TAB_GRV),  KC_Q,          KC_W,     KC_E,       KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,       KC_O,     KC_P,          KC_BSPC,
    KC_ESC,       HOME_A_WIN,    HOME_S,   HOME_D_WIN, HOME_F,  KC_G,    KC_H,    HOME_J,  HOME_K_WIN, HOME_L,   HOME_SCLN_WIN, KC_QUOT,
    KC_LSFT,      KC_Z,          KC_X,     KC_C,       KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM,    KC_DOT,   KC_SLSH,       KC_ENT,
    TD(CTRL_CAD), TD(CTRL_CAD),  KC_LALT,  KC_LGUI,    LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT,    KC_DOWN,  KC_UP,         KC_RIGHT
),

/* Game
 * ,------------------------------------------------------------------------------.
 * | Esc  |  Q  |  W  |  E  |  R  |  5  |  6  |   7  |   8  |   9  |   0   | Bksp |
 * |------+-----+-----+-----+-----+-----+-----+------+------+------+-------+------|
 * | Tab  |  A  |  S  |  D  |  F  |  G  |  H  |   J  |   K  |   L  |   ;   |  "   |
 * |------+-----+-----+-----+-----+-----+-----+------+------+------+-------+------|
 * | Shift|  Z  |  X  |  C  |  V  |  B  |  N  |   M  |   ,  |  Up  |   /   |Enter |
 * |------+-----+-----+-----+-----+-----+-----+------+------+------+-------+------|
 * | Ctrl |  4  |  3  |  2  |  1  |   Space   |Raise | Left | Down | Right |Lower |
 * `-------------------------------------------------------------------------------'
 */
[_GAME] = LAYOUT_ortho_5x12(
    KC_ESC,        KC_1,  KC_2,  KC_3,  KC_4,  KC_5,    KC_6,    KC_7,   KC_8,     KC_9,     KC_0,     KC_DEL,
    KC_ESC,        KC_Q,  KC_W,  KC_E,  KC_R,  KC_5,    KC_6,    KC_7,   KC_8,     KC_9,     KC_0,     KC_BSPC,
    KC_TAB,        KC_A,  KC_S,  KC_D,  KC_F,  KC_G,    KC_H,    KC_J,   KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
    KC_LSFT,       KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,    KC_N,    KC_M,   KC_COMM,  KC_UP,    KC_SLSH,  KC_ENT,
    TD(CTRL_CAD),  KC_4,  KC_3,  KC_2,  KC_1,  KC_SPC,  KC_SPC,  RAISE,  KC_LEFT,  KC_DOWN,  KC_RIGHT, LOWER
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_5x12(
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,      KC_F8,      KC_F9,   KC_F10,  KC_F11,
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  _______,
    _______, _______, _______, _______, _______, _______, _______, _______,    KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_5x12(
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,      KC_F8,      KC_F9,   KC_F10,  KC_F11,
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|Qwerty|      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|TermOn|TermOf|      |      | GAME |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_ortho_5x12(
    _______, _______, _______,  _______, _______, _______, _______, _______, _______,    _______, _______, _______,
    _______, _______, _______,  _______, _______, _______, _______, _______, _______,    _______, _______, _______,
    _______, _______, _______,  _______, _______, _______, _______, QWERTY,  QWERTY_WIN, _______, _______, _______,
    _______, _______, _______,  _______, _______, _______, _______, _______, _______,    _______, _______, GAME,
    _______, _______, _______,  _______, _______, _______, _______, _______, _______,    _______, _______, _______
)
};



void keyboard_post_init_user(void) {
  // Call the post init code.
  rgblight_disable_noeeprom(); // enables Rgb, without saving settings
}

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case QWERTY_WIN:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY_WIN);
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

/* Return an integer that corresponds to what kind of tap dance should be executed.
 *
 * How to figure out tap dance state: interrupted and pressed.
 *
 * Interrupted: If the state of a dance dance is "interrupted", that means that another key has been hit
 *  under the tapping term. This is typically indicitive that you are trying to "tap" the key.
 *
 * Pressed: Whether or not the key is still being pressed. If this value is true, that means the tapping term
 *  has ended, but the key is still being pressed down. This generally means the key is being "held".
 *
 * One thing that is currenlty not possible with qmk software in regards to tap dance is to mimic the "permissive hold"
 *  feature. In general, advanced tap dances do not work well if they are used with commonly typed letters.
 *  For example "A". Tap dances are best used on non-letter keys that are not hit while typing letters.
 *
 * Good places to put an advanced tap dance:
 *  z,q,x,j,k,v,b, any function key, home/end, comma, semi-colon
 *
 * Criteria for "good placement" of a tap dance key:
 *  Not a key that is hit frequently in a sentence
 *  Not a key that is used frequently to double tap, for example 'tab' is often double tapped in a terminal, or
 *    in a web form. So 'tab' would be a poor choice for a tap dance.
 *  Letters used in common words as a double. For example 'p' in 'pepper'. If a tap dance function existed on the
 *    letter 'p', the word 'pepper' would be quite frustating to type.
 *
 * For the third point, there does exist the 'DOUBLE_SINGLE_TAP', however this is not fully tested
 *
 */
int get_dance_status(tap_dance_state_t *state) {
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

void ctrltap_finished(tap_dance_state_t *state, void *user_data) {
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
void ctrltap_reset(tap_dance_state_t *state, void *user_data) {
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

tap_dance_action_t tap_dance_actions[] = {
    [TAB_GRV] =  ACTION_TAP_DANCE_DOUBLE(KC_TAB, KC_GRV),
    [ESC_GRV] =  ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_GRV),
    [CTRL_CAD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ctrltap_finished, ctrltap_reset),
    [CURLY] =    ACTION_TAP_DANCE_DOUBLE(KC_LCBR, KC_RCBR),
    [PARENS] =   ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_RPRN),
    [SQUARE] =   ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC),
    [TRIANGLE] =   ACTION_TAP_DANCE_DOUBLE(KC_LT, KC_GT),
};