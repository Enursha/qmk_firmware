#pragma once
#include "enursha.h"

enum userspace_custom_keycodes {
    COLEMAK = SAFE_RANGE,
    QWERTY,
    NUMBPAD,
    KC_SECRET_1,
    KC_SECRET_2,
    KC_SECRET_3,
    KC_SECRET_4,
    KC_SECRET_5,
    LOGIN,
};

bool process_record_secrets(uint16_t keycode, keyrecord_t *record);
bool process_record_keymap(uint16_t keycode, keyrecord_t *record);
