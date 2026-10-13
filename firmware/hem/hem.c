#include QMK_KEYBOARD_H
#include <stdio.h>

#ifdef OLED_ENABLE
// 128x32: name, active layer, caps lock and the current RGB effect/brightness
bool oled_task_kb(void) {
    if (!oled_task_user()) return false;
    oled_write_ln_P(PSTR("HEM  b4ym4x"), false);
    oled_write_P(get_highest_layer(layer_state) ? PSTR("Fn   ") : PSTR("Base "), false);
    oled_write_ln_P(host_keyboard_led_state().caps_lock ? PSTR("CAPS") : PSTR("    "), false);
#    ifdef RGB_MATRIX_ENABLE
    char buf[22];
    snprintf(buf, sizeof(buf), "RGB %2d  bri %3d", rgb_matrix_get_mode(), rgb_matrix_get_val());
    oled_write_ln(buf, false);
#    endif
    return false;
}
#endif
