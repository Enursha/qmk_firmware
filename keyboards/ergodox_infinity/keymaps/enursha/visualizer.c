/*
Copyright 2017 Fred Sundvik

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


// Currently we are assuming that both the backlight and LCD are enabled
// But it's entirely possible to write a custom visualizer that use only
// one of them

#ifndef LCD_BACKLIGHT_ENABLE
#error This visualizer needs that LCD backlight is enabled
#endif

#ifndef LCD_ENABLE
#error This visualizer needs that LCD is enabled
#endif

#include "visualizer.h"
#include "visualizer_keyframes.h"
#include "lcd_keyframes.h"
#include "lcd_backlight_keyframes.h"
#include "system/serial_link.h"
#include "led.h"
#include "default_animations.h"
#include "util.h"
#include "enursha.h"

#define RED 0
#define ORANGE 21
#define YELLOW 42
#define SPRING_GREEN 64
#define GREEN 85
#define TURQUOISE 107
#define CYAN 127
#define OCEAN 149
#define BLUE 170
#define VIOLET 192
#define MAGENTA 212
#define RASPBERRY 234

static const uint32_t logo_background_color = LCD_COLOR(0, 0, 255);
static const uint32_t initial_color = LCD_COLOR(0, 0, 255);
static const uint32_t colemak_color = LCD_COLOR(BLUE, 255, 255);
static const uint32_t qwerty_color = LCD_COLOR(RED, 255, 255);
static const uint32_t symbol_color = LCD_COLOR(YELLOW, 255, 255);
static const uint32_t numbpad_color = LCD_COLOR(GREEN, 255, 255);

static bool initial_update = true;

// Feel free to modify the animations below, or even add new ones if needed

static keyframe_animation_t lcd_layer_display = {
    .num_frames = 1,
    .loop = false,
    .frame_lengths = {gfxMillisecondsToTicks(0)},
    .frame_functions = {lcd_keyframe_display_layer_and_led_states}
};

// The color animation animates the LCD color when you change layers
static keyframe_animation_t color_animation = {
    .num_frames = 2,
    .loop = false,
    // Note that there's a 200 ms no-operation frame,
    // this prevents the color from changing when activating the layer
    // momentarily
    .frame_lengths = {gfxMillisecondsToTicks(200), gfxMillisecondsToTicks(500)},
    .frame_functions = {keyframe_no_operation, lcd_backlight_keyframe_animate_color},
};

void initialize_user_visualizer(visualizer_state_t* state) {
    // The brightness will be dynamically adjustable in the future
    // But for now, change it here.
    lcd_backlight_brightness(255);
    state->current_lcd_color = initial_color;
    state->target_lcd_color = logo_background_color;
    initial_update = true;
    backlight_enable();
    backlight_level(3);
    start_keyframe_animation(&default_startup_animation);
};

/* enum ergodox_layers {
  _COLEMAK,
  _QWERTY,
  _SYMBOL,
  _NUMBPAD
}; */

// This function should be implemented by the keymap visualizer
// Don't change anything else than state->target_lcd_color and state->layer_text as that's the only thing
// that the simple_visualizer assumes that you are updating
// Also make sure that the buffer passed to state->layer_text remains valid until the previous animation is
// stopped. This can be done by either double buffering it or by using constant strings
static void get_visualizer_layer_and_color(visualizer_state_t* state) {
    //uint8_t saturation = 255;

    uint8_t layer = biton32(state->status.layer);
    //state->target_lcd_color = LCD_COLOR(layer << 2, saturation, 0xFF);

    switch(layer) {
        case _COLEMAK:
            state->layer_text = "COLEMAK";
            state->target_lcd_color = colemak_color;
            break;
        case _QWERTY:
            state->layer_text = "QWERTY";
            state->target_lcd_color = qwerty_color;
            break;
        case _SYMBOL:
            state->layer_text = "SYMBOLS";
            state->target_lcd_color = symbol_color;
            break;
        case _NUMBPAD:
            state->layer_text = "NUMPAD";
            state->target_lcd_color = numbpad_color;
            break;
        default:
            state->layer_text = "NONE";
            break;
    }

   //uint8_t default_layer = biton32(state->status.default_layer);

   //switch(default_layer) {
   //    case _COLEMAK:
   //        state->layer_text = "COLEMAK";
   //        state->target_lcd_color = colemak_color;
   //        break;
   //     case _QWERTY:
   //         state->layer_text = "QWERTY";
   //         state->target_lcd_color = qwerty_color;
   //         break;
   //}
};

void update_user_visualizer_state(visualizer_state_t* state, visualizer_keyboard_status_t* prev_status) {
    // Add more tests, change the colors and layer texts here
    // Usually you want to check the high bits (higher layers first)
    // because that's the order layers are processed for keypresses
    // You can for check for example:
    // state->status.layer
    // state->status.default_layer
    // state->status.leds (see led.h for available statuses)

    uint32_t prev_color = state->target_lcd_color;
    const char* prev_layer_text = state->layer_text;

    get_visualizer_layer_and_color(state);

    if (initial_update || prev_color != state->target_lcd_color) {
        start_keyframe_animation(&color_animation);
    }

    if (initial_update || prev_layer_text != state->layer_text) {
        start_keyframe_animation(&lcd_layer_display);
    }
    // You can also stop existing animations, and start your custom ones here
    // remember that you should normally have only one animation for the LCD
    // and one for the background. But you can also combine them if you want.
};

void user_visualizer_suspend(visualizer_state_t* state) {
    state->layer_text = "Suspending...";
    uint8_t hue = LCD_HUE(state->current_lcd_color);
    uint8_t sat = LCD_SAT(state->current_lcd_color);
    state->target_lcd_color = LCD_COLOR(hue, sat, 0);
    start_keyframe_animation(&default_suspend_animation);
};

void user_visualizer_resume(visualizer_state_t* state) {
    lcd_backlight_brightness(255);
    state->current_lcd_color = initial_color;
    state->target_lcd_color = logo_background_color;
    initial_update = true;
    backlight_enable();
    start_keyframe_animation(&default_startup_animation);
};

