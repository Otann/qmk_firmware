/* Copyright 2021 Anton Chebotaev */

#include QMK_KEYBOARD_H

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _FN
};


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
 *  You can use _______ in place for KC_TRNS (transparent)   *
 *  Or you can use XXXXXXX for KC_NO (NOOP)                  *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#undef TAPPING_TOGGLE
#define TAPPING_TOGGLE 2
#define PERMISSIVE_HOLD

#define LOWER TT(_LOWER)
#define RAISE TT(_RAISE)
#define FN_LAYER MO(_FN)

#define PREV_TAB LGUI(KC_LCBR)
#define NEXT_TAB LGUI(KC_RCBR)

#define CTRL_ESC LCTL_T(KC_ESC)
#define SHFT_GRV LSFT_T(KC_GRV)
#define SHFT_SPC LSFT_T(KC_SPC)
#define GUI_SLSH RGUI_T(KC_SLSH)

#define MEGA_PST QK_LSFT | QK_LALT | QK_LGUI | KC_V

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  Up  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  FN  |   /  |   ⌃  |   ⌥  |   ⌘  |    Space    |Lower |Raise | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_mit(
    KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,     KC_Y,     KC_U,    KC_I,     KC_O,    KC_P,    KC_BSPC,
    CTRL_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,     KC_H,     KC_J,    KC_K,     KC_L,    KC_SCLN, KC_QUOT,
    SHFT_GRV,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,     KC_N,     KC_M,    KC_COMM,  KC_DOT,  KC_UP,   KC_SFTENT,
    FN_LAYER,  KC_SLSH, KC_LCTL, KC_LALT, KC_LGUI, SHFT_SPC,           LOWER,   RAISE,    KC_LEFT, KC_DOWN, KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |      |  ⌘{  |  ⌘}  |      |      |      |   -  |   =  |   [  |   ]  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   \  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | TRNS |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | TRNS | TRNS | TRNS | TRNS |     Del     | TRNS | TRNS |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_mit(
    XXXXXXX, XXXXXXX, PREV_TAB, NEXT_TAB, XXXXXXX, XXXXXXX, XXXXXXX, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, XXXXXXX,
    KC_GRV,  KC_1,    KC_2,     KC_3,     KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
    _______, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, _______, _______,  _______,  _______, KC_BSPC,          _______, _______, XXXXXXX, XXXXXXX, XXXXXXX
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |  _   |  +   |   {  |   }  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |  &   |  *   |   (  |   )  |   |  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | TRNS |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | TRNS | TRNS | TRNS | TRNS |     Bksp    | TRNS | TRNS |      |      |      |
 * `-----------------------------------------------------------------------------------'
  */
[_RAISE] = LAYOUT_planck_mit(
    XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, XXXXXXX,
    KC_TILD, KC_EXLM, KC_AT,    KC_HASH,  KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
    _______, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, _______, _______,  _______,  _______, KC_DEL,           _______, _______, XXXXXXX, XXXXXXX, XXXXXXX
),

/* FN Layer 
 * ,-----------------------------------------------------------------------------------.
 * |      |reset |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      | ⇧⌥⌘v |      |      |      |      |      |brgh- |brgh+ |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |  play/pause | prev | next | vol- | mute | vol+ |
 * `-----------------------------------------------------------------------------------'
 */
[_FN] = LAYOUT_planck_mit(
    XXXXXXX, RESET,   XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL,
    XXXXXXX, KC_F1,   KC_F2,   KC_F3,    KC_F4,    KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  MEGA_PST, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BRID, KC_BRIU,
    _______, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  KC_MPLY,          KC_MRWD, KC_MFFD, KC_VOLD, KC_MUTE, KC_VOLU
)

};