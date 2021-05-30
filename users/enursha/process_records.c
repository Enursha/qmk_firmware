#include "enursha.h"

__attribute__((weak)) bool process_record_secrets(uint16_t keycode, keyrecord_t *record) { return true; }

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case COLEMAK:
                set_single_persistent_default_layer(_COLEMAK);
                return false;
            case QWERTY:
                set_single_persistent_default_layer(_QWERTY);
                return false;
            case NUMBPAD:
                set_single_persistent_default_layer(_NUMBPAD);
                return false;
            case LOGIN:
                SEND_STRING (SS_LCTL(SS_LALT(SS_TAP(X_DELETE))));
                return false;
        }
    }
        //return process_record_keymap(keycode, record) && process_record_secrets(keycode, record);
        return process_record_secrets(keycode, record);
};
