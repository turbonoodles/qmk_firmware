/* Copyright 2021 Craig McMahon
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _MEDIA
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    QMKURL
};

// Unicodes for special characters

enum unicode_names {
    BANG,
    IRONY,
    OHM,
    MICRO,
    omeg,
    OMEG,
    phi,
    PHI,
    alpha,
    cced,
    CCED,
    pi,
    PI,
    rho,
    tau,
    dta,
    DTA,
    beta,
    eta,
    kapa,
    sgma,
    SGMA,
    lbda,
    chi,
    zeta,
    eps
};

const uint32_t PROGMEM unicode_map[] = {
    [BANG]  = 0x203D,  // ‽
    [IRONY] = 0x2E2E,  // ⸮
    [OHM] = 0x2126,
    [MICRO] = 0x00b5,
    [omeg] = 0x03C9,
    [OMEG] = 0x03A9,
    [phi] = 0x03C6,
    [PHI] = 0x03A6,
    [alpha] = 0x03B1,
    [cced] = 0x00E7,
    [CCED] = 0x00C7,
    [pi] = 0x03c0,
    [PI] = 0x03A0,
    [rho] = 0x03c1,
    [tau] = 0x03c4,
    [dta] = 0x03b4,
    [DTA] = 0x0394,
    [beta] = 0x03b2,
    [eta] = 0x03b7,
    [kapa] = 0x03ba,
    [sgma] = 0x03c3,
    [SGMA] = 0x03a3,
    [lbda] = 0x03bb,
    [chi] = 0x03c7,
    [zeta] = 0x03b6,
    [eps] = 0x03B5
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
        KC_NO,         KC_NO,         KC_NO,       KC_B,        KC_N,     KC_NO,    KC_NO,   KC_F12,   KC_SLSH,      KC_RGHT, KC_LEFT, KC_DOWN, KC_RALT,  KC_NO,   
        KC_ESC,        KC_F6,         KC_F4,       KC_G,        KC_H,     KC_F6,    KC_NO,   KC_F11,   KC_QUOT,      KC_UP,   KC_NO,   KC_SPC,  KC_LALT,  KC_NO,   
        KC_A,          KC_S,          KC_D,        KC_F,        KC_J,     KC_K,     KC_L,    KC_BSLS,  KC_SCOLON,    KC_NO,   KC_RWIN, KC_RSPC, MO(_MEDIA),    KC_NO,                        
        KC_Q,          KC_W,          KC_E,        KC_R,        KC_U,     KC_I,     KC_O,    KC_NO,    KC_P,         KC_NO,   KC_NO,   KC_NO,   KC_PAUSE, KC_NO, 
        KC_1,          KC_2,          KC_3,        KC_4,        KC_7,     KC_8,     KC_9,    KC_F10,   KC_0,         KC_END,  KC_NO,   KC_NO,   KC_F5,    KC_PGDN,            
        KC_TAB,        KC_CAPS,       KC_F3,       KC_T,        KC_Y,     KC_RBRC,  KC_F7,   KC_BSPC,  KC_LBRC,      KC_NO,   KC_LWIN, KC_LSPO, KC_NO,    KC_NO,   
        KC_GRV,        KC_F1,         KC_F2,       KC_5,        KC_6,     KC_EQUAL, KC_F8,   KC_F9,    KC_MINUS,     KC_HOME, KC_INS,  KC_DEL,  KC_LCTL,  KC_PGUP,   
        KC_Z,          KC_X,          KC_C,        KC_V,        KC_M,     KC_COMMA, KC_DOT,  KC_ENTER, KC_NO,        KC_NO,   KC_NO,   KC_NO,   KC_RCTL,  KC_NO    
    ),
    [_MEDIA] = LAYOUT(
        KC_TRNS,       KC_TRNS,       KC_TRNS,     X(beta),     X(eta),   KC_TRNS,  KC_TRNS, KC_MNXT,  X(IRONY),     BL_BRTG, BL_TOGG, BL_DEC,  KC_TRNS,  KC_TRNS,
        KC_TRNS,       KC_TRNS,       KC_TRNS,     KC_TRNS,     KC_TRNS,  KC_TRNS,  KC_TRNS, KC_MPRV,  KC_TRNS,      BL_INC,  KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,
        X(alpha),      XP(sgma,SGMA), XP(dta,DTA), XP(phi,PHI), KC_TRNS,  X(kapa),  X(lbda), KC_TRNS,  KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,
        KC_TRNS,       XP(omeg,OMEG), X(eps),      X(rho),      KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,  XP(pi,PI),    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,
        X(BANG),       KC_TRNS,       KC_TRNS,     KC_TRNS,     KC_TRNS,  KC_TRNS,  KC_TRNS, KC_MPLY,  KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  BL_OFF,
        KC_TRNS,       KC_TRNS,       KC_TRNS,     X(tau),      KC_TRNS,  KC_TRNS,  KC_MUTE, KC_TRNS,  KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,
        KC_TRNS,       KC_TRNS,       KC_TRNS,     KC_TRNS,     KC_TRNS,  KC_PPLS,  KC_VOLD, KC_VOLU,  KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  BL_ON,
        XP(OHM,zeta),  X(chi),        KC_TRNS,     KC_TRNS,     X(MICRO), KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QMKBEST:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING("QMK is the best thing ever!");
            } else {
                // when keycode QMKBEST is released
            }
            break;
        case QMKURL:
            if (record->event.pressed) {
                // when keycode QMKURL is pressed
                SEND_STRING("https://qmk.fm/\n");
            } else {
                // when keycode QMKURL is released
            }
            break;
    }
    return true;
}
