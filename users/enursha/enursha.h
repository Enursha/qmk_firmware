#pragma once
#include QMK_KEYBOARD_H
#include "quantum.h"
#include "action.h"
#include "version.h"

#include "process_records.h"

enum userspace_layers {
  _COLEMAK,
  _QWERTY,
  _SYMBOL,
  _NUMBPAD,
};
