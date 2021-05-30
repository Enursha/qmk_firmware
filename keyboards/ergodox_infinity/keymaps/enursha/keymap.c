#include "enursha.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 * MEH:   Alt+Control+Shift
 * HYPER: Alt+Control+Shift+Gui
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   BKTK |  1 ! | 2 "  | 3 £  | 4 $  | 5 %  |LOCKS |           | RGUI |  6 ^ | 7 &  |  8 * | 9 (  |  0 ) |  ESC   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   TAB  |   Q  |   W  |   F  |   P  |   G  |TG(3) |           |TG(4) |   J  |   L  |   U  |   Y  |  ; : |  RCTL  |
 * |--------+------+------+------+------+------|F-lck |           |N-lck |------+------+------+------+------+--------|
 * |  LCTL  |   A  |   R  |   S  |   T  |   D  |------|           |------|   H  |   N  |   E  |   I  |   O  |  ENT   |
 * |--------+------+------+------+------+------|ENTER |			  | MEH  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   K  |   M  |  , < |  . > |  '@  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LGUI |      |  ~#  | LATL |TG NUM|                                       | LEFT | DOWN |  UP  | RIGHT|  RALT  |
 *   `----------------------------------'                                       `------------------------------------'
 *                                        ,--------------.       ,--------------.
 *                                        |  Esc | App   |       | Ins  | Del   |
 *                                 ,------|------|-------|       |------+-------+------.
 *                                 |      |      | Home  |       | PgUp |       |      |
 *                                 |SPACE | MO(2)|-------|       |------| MO(2) | BKSP |
 *                                 |      |Symbol| End   |       | PgDn |Symbol |      |
 *                                 `---------------------'       `---------------------'
 */
[_COLEMAK] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_GRV,         KC_1,             KC_2,             KC_3,               KC_4,           KC_5,           LGUI(KC_L),
        KC_TAB,         KC_Q,             KC_W,             KC_F,               KC_P,           KC_G,           TG(_NUMBPAD),
        KC_LCTL,        KC_A,             KC_R,             KC_S,               KC_T,           KC_D,
        KC_LSFT,        KC_Z,             KC_X,             KC_C,               KC_V,           KC_B,           KC_ENT,
        KC_LGUI,        TG(_QWERTY),      KC_NUHS,          KC_LALT,            TG(_NUMBPAD),

                                                                                                KC_ESC,         KC_APP,
								                                                                                                KC_HOME,
                                                                                KC_SPC,	        MO(_SYMBOL),    KC_END,

        // right hand
	    KC_RGUI,        KC_6,		      KC_7,             KC_8,               KC_9,	        KC_0,           KC_ESC,
        TG(_NUMBPAD),   KC_J,             KC_L,             KC_U,               KC_Y,           KC_SCLN,        KC_RCTL,
                        KC_H,             KC_N,             KC_E,               KC_I,           KC_O,           KC_ENT,
        KC_MEH,         KC_K,             KC_M,             KC_COMM,            KC_DOT,         KC_QUOT,        KC_RSFT,
                        KC_LEFT,          KC_DOWN,          KC_UP,              KC_RIGHT,       KC_RALT,

        KC_INS,         KC_DEL,
        KC_PGUP,
        KC_PGDN,        MO(_SYMBOL),     KC_BSPC
    ),

/* Keymap 1: QWERTY layer (games)
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 |      |      |------|       |------|        |      |
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
[_QWERTY] = LAYOUT_ergodox(  // layer 1: QWERTY layer (games)

    // left hand
       KC_TRNS,         KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,        KC_TRNS,
       KC_TRNS,         KC_Q,             KC_W,             KC_E,             KC_R,             KC_T,           KC_TRNS,
       KC_TRNS,         KC_A,             KC_S,             KC_D,             KC_F,             KC_G,
       KC_TRNS,         KC_Z,             KC_X,             KC_C,             KC_V,             KC_B,           KC_TRNS,
       KC_TRNS,         KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,

                                                                                                KC_TRNS,        KC_TRNS,
                                                                                                                KC_TRNS,
                                                                              KC_TRNS,          KC_TRNS,        KC_TRNS,

    // right hand
       KC_TRNS,          KC_TRNS,         KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,        KC_TRNS,
       KC_TRNS,          KC_Y,            KC_U,             KC_I,             KC_O,             KC_P,           KC_TRNS,
                         KC_H,            KC_J,             KC_K,             KC_L,             KC_SCLN,        KC_TRNS,
       KC_TRNS,          KC_N,            KC_M,             KC_TRNS,          KC_TRNS,          KC_TRNS,        KC_TRNS,
                                          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,        KC_TRNS,
       KC_TRNS,          KC_TRNS,
       KC_TRNS,
       KC_TRNS,          KC_TRNS,         KC_TRNS
    ),

/* Keymap 2: Symbol Layer
*
* ,--------------------------------------------------.           ,--------------------------------------------------.
* |        |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |  F7  |  F8  |  F9  | F10  | F11  | F12  |        |
* |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
* |        |   !  |   +  |  <   |   %  |  £   | DF(1)|           |      |  &   |   [  |   ]  |   \  |  :   |        |
* |--------+------+------+------+------+------|QWERTY|           |      |------+------+------+------+------+--------|
* |        |   |  |  -_  |  >   |   =  |  "   |------|           |------|  *   |   {  |   }  |   /  |  ?   |        |
* |--------+------+------+------+------+------| DF(0)|           |      |------+------+------+------+------+--------|
* |        | NUBS | NUHS |  /   |   $  |  ^   |COLEMAK           |      |  |   |   (  |   )  |   '  |  @   |        |
* `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
*   | LOGIN|      |      |      |      |                                       |      |      |      |      |      |
*   `----------------------------------'                                       `----------------------------------'
*                                        ,-------------.       ,-------------.
*                                        |      |      |       |      |      |
*                                 ,------|------|------|       |------+------+------.
*                                 |      |      |      |       |      |      |      |
*                                 |      | MO(4)|------|       |------| MO(4)| DEL  |
*                                 |      |Keypad|      |       |      |Keypad|      |
*                                 `--------------------'       `--------------------'
*/
// SYMBOLS
[_SYMBOL] = LAYOUT_ergodox(

       // left hand
       KC_TRNS,            KC_F1,            KC_F2,           KC_F3,          KC_F4,            KC_F5,            KC_F6,
       KC_TRNS,            KC_EXCLAIM,       KC_PLUS,         KC_LT,          KC_PERC,          KC_HASH,          DF(_QWERTY),
       KC_LBRC,            LSFT(KC_NUBS),    KC_MINS,         KC_GT,          KC_EQUAL,         KC_AT,
       KC_TRNS,            KC_NUBS,          KC_NUHS,         KC_SLSH,        KC_DOLLAR,        KC_CIRC,          DF(_COLEMAK),
       LOGIN,              KC_TRNS,          KC_TRNS,         KC_SECRET_2,    KC_SECRET_1,

                           KC_TRNS,          KC_TRNS,
                                             KC_TRNS,
       KC_TRNS,            MO(_NUMBPAD),     KC_TRNS,

       // right hand
       KC_F7,              KC_F8,            KC_F9,            KC_F10,         KC_F11,           KC_F12,           KC_TRNS,
       KC_TRNS,            KC_AMPERSAND,     KC_LBRC,          KC_RBRC,        KC_BSLS,          KC_COLN,          KC_TRNS,
                           KC_ASTERISK,      KC_LCBR,          KC_RCBR,        KC_SLSH,          KC_QUES,          KC_TRNS,
       KC_TRNS,            KC_PIPE,          KC_LPRN,          KC_RPRN,        KC_QUOT,           KC_DQT,          KC_TRNS,
                                             KC_TRNS,          KC_TRNS,        KC_TRNS,          KC_TRNS,          KC_TRNS,

       KC_TRNS,            KC_TRNS,
       KC_TRNS,
       KC_TRNS,            MO(_NUMBPAD),     KC_DEL
),

/* Keymap 3: Numlock
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | RESET  |      |      |      |P-SCRE|S-LOCK|PAUSE |           |NLOCK | CALC |  =   |  /   |  *   |      | RESET  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | VERSION|      |      |      |      |      |      |           |      | Vol+ |  7   |  8   |  9   |  -   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      | MS_B2| MS_B1|      |------|           |------| Vol- |  4   |  5   |  6   |  +   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | MS_U | MS_D | MS_L | MS_R |      | HYPR |           | HYPR | Mute |  1   |  2   |  3   |Enter |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EPRM |      |      |      |      |                                       |  0   |  0   |  .   | RCTL | RCTL |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | BL_SP|      |       |LEDTOG|BREATH|
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Bright|Bright|      |       |      |      |      |
 *                                 |ness- |ness+ |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */

[_NUMBPAD] = LAYOUT_ergodox(
       RESET,               KC_LSFT,          KC_LSFT,          KC_SYSREQ,        KC_PSCR,         KC_SLCK,       KC_PAUSE,
       KC_TRNS,             KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,         KC_TRNS,       KC_TRNS,
       DEBUG,               KC_TRNS,          KC_TRNS,          KC_BTN2,          KC_BTN1,         KC_TRNS,
       KC_TRNS,             KC_MS_U,          KC_MS_D,          KC_MS_L,          KC_MS_R,         KC_TRNS,       KC_HYPR,
       KC_TRNS,             KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,

                            BL_STEP,	      KC_TRNS,
                                              KC_TRNS,
		BL_DEC,              BL_INC,	      KC_TRNS,

       // right hand
       KC_NLCK,             KC_CALC,          KC_PEQL,          KC_PSLS,          KC_PAST,          KC_LSFT,      RESET,
       KC_TRNS,             KC_VOLU,          KC_P7,            KC_P8,            KC_P9,            KC_PMNS,      KC_TRNS,
                            KC_VOLD,          KC_P4,            KC_P5,            KC_P6,            KC_PPLS,      KC_TRNS,
       KC_HYPR,             KC_MUTE,          KC_P1,            KC_P2,            KC_P3,            KC_PENT,      KC_TRNS,
                            KC_P0,            KC_P0,            KC_PDOT,          KC_RCTL,          KC_RCTL,

                                                                                                    BL_TOGG, 	  BL_BRTG,
                                                                                                                  KC_TRNS,
	                                                                              KC_TRNS, 	        KC_TRNS,      KC_TRNS
),

};
