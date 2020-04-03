/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#include QMK_KEYBOARD_H
#include "muse.h"
#include "keymap_extras/keymap_fr_ch.h"


extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _QWERTY_WIN,
  _LOWER_WIN,
  _RAISE_WIN,
  _ARROWS,
  _ADJUST,
  _ADJUST_WIN,
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  QWERTY_WIN,
  COLEMAK,
  EXT_PLV,
  MACRO_CIRC,
  MACRO_TICK,
  MACRO_TILD,
  MACRO_TILD_WIN,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define LOWER_WIN MO(_LOWER_WIN)
#define RAISE_WIN MO(_RAISE_WIN)
#define ARROWS MO(_ARROWS)


// This redifines some values for the apple swiss keyboard
#define CTL_TAB    MT(MOD_LCTL, KC_TAB)
#define AFR_CH_AT   ALGR(KC_G) // @
#define AFR_CH_LCBR ALGR(KC_8) // {
#define AFR_CH_RCBR ALGR(KC_9) // }
#define AFR_CH_LBRC ALGR(KC_5) // [
#define AFR_CH_RBRC ALGR(KC_6) // ]
#define AFR_CH_PIPE ALGR(KC_7) // pipe
#define AFR_CH_BSLS ALGR(S(KC_7)) // backslash
#define AFR_CH_TILD ALGR(KC_N) // ~
#define AFR_CH_LESS KC_GRV // <
#define AFR_CH_MORE S(KC_GRV) // >

// Fixing the FR_CH
#define FR_CH_RCBR_2 ALGR(FR_CH_DLR)     // }
#define FR_CH_RBRC_2 ALGR(FR_CH_DIAE)     // ]
#define FR_CH_PIPE_2 ALGR(KC_7)     // pipe

// Moving around
#define CTL_E      MT(MOD_LCTL, KC_E)
#define CTL_A      MT(MOD_LCTL, KC_A)
#define ALT_LEFT   MT(MOD_LALT, KC_LEFT)
#define ALT_RIGHT  MT(MOD_LALT, KC_RIGHT)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,----------------------------------------------------------------------------------------.
 * | Esc       |   Q  |   W  |   E  |   R  |   T  |   Z  |   U  |   I  |   O  |   P  | Bksp |
 * |-----------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab/Ctrl  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   é  |Enter |
 * |-----------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift     |   Y  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   -  |Shift |
 * |-----------+------+------+------+------+------+------+------+------+------+------+------|
 * | Arrow     | Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `----------------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_ESC,  FR_CH_Q,    FR_CH_W,    FR_CH_E,    FR_CH_R,    FR_CH_T,    FR_CH_Z,    FR_CH_U,    FR_CH_I,    FR_CH_O,    FR_CH_P,    KC_BSPC,
    CTL_TAB, FR_CH_A,    FR_CH_S,    FR_CH_D,    FR_CH_F,    FR_CH_G,    FR_CH_H,    FR_CH_J,    FR_CH_K,    FR_CH_L,    FR_CH_OE,   KC_ENT,
    KC_LSFT, FR_CH_Y,    FR_CH_X,    FR_CH_C,    FR_CH_V,    FR_CH_B,    FR_CH_N,    FR_CH_M,    FR_CH_COMM, FR_CH_DOT,  FR_CH_MINS, KC_RSFT,
    ARROWS,  KC_LCTL,    KC_LALT,    KC_LGUI,    LOWER,      KC_SPC,     KC_SPC,     RAISE,      KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT
),

[_QWERTY_WIN] = LAYOUT_planck_grid(
    KC_ESC,  FR_CH_Q,    FR_CH_W,    FR_CH_E,    FR_CH_R,    FR_CH_T,    FR_CH_Z,    FR_CH_U,    FR_CH_I,    FR_CH_O,    FR_CH_P,    KC_BSPC,
    CTL_TAB, FR_CH_A,    FR_CH_S,    FR_CH_D,    FR_CH_F,    FR_CH_G,    FR_CH_H,    FR_CH_J,    FR_CH_K,    FR_CH_L,    FR_CH_OE,   KC_ENT,
    KC_LSFT, FR_CH_Y,    FR_CH_X,    FR_CH_C,    FR_CH_V,    FR_CH_B,    FR_CH_N,    FR_CH_M,    FR_CH_COMM, FR_CH_DOT,  FR_CH_MINS, KC_RSFT,
    ARROWS,  KC_LCTL,    KC_LALT,    KC_LCTL,    LOWER_WIN,      KC_SPC,     KC_SPC,     RAISE_WIN,      KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT
),


[_ARROWS] = LAYOUT_planck_grid(
    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,     _______,   ALT_LEFT,  ALT_RIGHT, _______,   _______,  _______,
    KC_F8,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,    KC_LEFT,   KC_DOWN,   KC_UP,     KC_RIGHT,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,   _______,   CTL_A,     CTL_E,     _______,   _______,  _______,
    _______,  _______,  _______,  KC_LGUI,  _______,  _______,   _______,   _______,   _______,   _______,   _______,  _______
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   +  |   "  |   *  |   ç  |   %  |   &  |   /  |   (  |   )  |   =  |  ?   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   ^  |      |      |      |      |      |   @  |   :  |   {  |   }  |   \  |  $   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |   #  |   |  |   [  |   ]  |   !  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */



[_LOWER] = LAYOUT_planck_grid(
    MACRO_TILD, FR_CH_PLUS,  FR_CH_DQOT,  FR_CH_ASTR,  FR_CH_CCED,  FR_CH_PERC,  FR_CH_AMPR,  FR_CH_SLSH,   FR_CH_LPRN,   FR_CH_RPRN,   FR_CH_EQL,    FR_CH_QST,
    MACRO_CIRC,  _______,     _______,     _______,     _______,     _______,     AFR_CH_AT,   FR_CH_COLN,   AFR_CH_LCBR,  AFR_CH_RCBR,  AFR_CH_BSLS,  FR_CH_DLR,
    _______,     _______,     _______,     _______,     _______,     _______,     FR_CH_HASH,  AFR_CH_PIPE,  AFR_CH_LBRC,  AFR_CH_RBRC,  FR_CH_EXLM,   _______,
    _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,      KC_MNXT,      KC_VOLD,      KC_VOLU,      KC_MPLY
),

[_LOWER_WIN] = LAYOUT_planck_grid(
    MACRO_TILD_WIN, FR_CH_PLUS,  FR_CH_DQOT,  FR_CH_ASTR,  FR_CH_CCED,  FR_CH_PERC,  FR_CH_AMPR,  FR_CH_SLSH,   FR_CH_LPRN,   FR_CH_RPRN,   FR_CH_EQL,    FR_CH_QST,
    MACRO_CIRC,  _______,     _______,     _______,     _______,     _______,     FR_CH_AT,   FR_CH_COLN,   FR_CH_LCBR,  FR_CH_RCBR_2,  FR_CH_BSLS,  FR_CH_DLR,
    _______,     _______,     _______,     _______,     _______,     _______,     FR_CH_HASH,  FR_CH_PIPE_2,  FR_CH_LBRC,  FR_CH_RBRC_2,  FR_CH_EXLM,   _______,
    _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,      KC_MNXT,      KC_VOLD,      KC_VOLU,      KC_MPLY
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   0  |   1  |   2  |   3  |   '  |   `  |      |      |      |  ^_  |   è  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   ^  |   4  |   5  |   6  |   "  |   <  |      |      |      |  `_  |   à  |   $  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   7  |   8  |   9  |   *  |   >  |      |      |      |  ¨_  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */


[_RAISE] = LAYOUT_planck_grid(
    KC_0,        KC_1,     KC_2,     KC_3,     FR_CH_DQOT,  MACRO_TICK,   _______,  _______, AFR_CH_TILD,  FR_CH_CIRC, FR_CH_UE, _______,
    MACRO_CIRC,  KC_4,     KC_5,     KC_6,     FR_CH_QUOT,  AFR_CH_LESS,  _______,  _______,  _______,  FR_CH_GRV,  FR_CH_AE, FR_CH_DLR,
    _______,     KC_7,     KC_8,     KC_9,     FR_CH_ASTR,  AFR_CH_MORE,  _______,  _______,  _______,  FR_CH_DIAE, _______,  _______,
    _______,     _______,  _______,  _______,  _______,     _______,      _______,  _______,  _______,  _______,    _______,  _______
),

[_RAISE_WIN] = LAYOUT_planck_grid(
    KC_0,        KC_1,     KC_2,     KC_3,     FR_CH_DQOT,  MACRO_TICK,   _______,  _______, FR_CH_TILD,  FR_CH_CIRC, FR_CH_UE, _______,
    MACRO_CIRC,  KC_4,     KC_5,     KC_6,     FR_CH_QUOT,  FR_CH_LESS,  _______,  _______,   _______,  FR_CH_GRV,  FR_CH_AE, FR_CH_DLR,
    _______,     KC_7,     KC_8,     KC_9,     FR_CH_ASTR,  FR_CH_MORE,  _______,  _______,   _______,  FR_CH_DIAE, _______,  _______,
    _______,     _______,  _______,  _______,  _______,     _______,      _______,  _______,  _______,  _______,    _______,  _______
),


/* Plover layer (http://opensteno.org)
 * ,-----------------------------------------------------------------------------------.
 * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Exit |      |      |   A  |   O  |             |   E  |   U  |      |      |      |
 * `-----------------------------------------------------------------------------------'
[_PLOVER] = LAYOUT_planck_grid(
    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1   ,
    XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
    XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    EXT_PLV, XXXXXXX, XXXXXXX, KC_C,    KC_V,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    XXXXXXX, XXXXXXX, XXXXXXX
),
 */


/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|      |      |Plover|      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      | WIN  |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______,  _______,  _______,  _______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______,
    QWERTY, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, QWERTY_WIN
),

[_ADJUST_WIN] = LAYOUT_planck_grid(
    _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______,  _______,  _______,  _______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______,
    QWERTY, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, QWERTY_WIN
)


};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
  return update_tri_layer_state(state, _LOWER_WIN, _RAISE_WIN, _ADJUST_WIN);
}

const uint16_t PROGMEM test_combo[] = {KC_J, KC_K, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {COMBO(test_combo, KC_ESC)};


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

    case MACRO_CIRC:
      if (record->event.pressed) {
        SEND_STRING("= ");
      } else { }
      break;
    case MACRO_TICK:
      if (record->event.pressed) {
        SEND_STRING("+ ");
      } else { }
      break;
    case MACRO_TILD_WIN:
      if (record->event.pressed) {
        SEND_STRING(SS_ALGR("=") " ");
      } else { }
      break;
    case MACRO_TILD:
      if (record->event.pressed) {
        SEND_STRING(SS_ALGR("n") " ");
      } else { }
      break;
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_DOWN);
      #else
        tap_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_UP);
      #else
        tap_code(KC_PGUP);
      #endif
    }
  }
}

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
#ifdef AUDIO_ENABLE
            static bool play_sound = false;
#endif
            if (active) {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_song); }
#endif
                layer_on(_ADJUST);
            } else {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_gb_song); }
#endif
                layer_off(_ADJUST);
            }
#ifdef AUDIO_ENABLE
            play_sound = true;
#endif
            break;
        }
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
  #endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
