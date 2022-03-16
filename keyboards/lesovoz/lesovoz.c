/* Copyright 2022 Caleb Lightfoot
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
#include "lesovoz.h"

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    writePin(LED1, record->event.pressed);
    return process_record_user(keycode, record);
}
layer_state_t layer_state_set_kb(layer_state_t state) {
    if (get_highest_layer(state) > 0) {
        // LED2 on when layer active
        writePinLow(LED1);
        writePin(LED2, state);
    } else {
        // LED2 off when layer not active
        writePinLow(LED2);
    }

    return layer_state_set_user(state);
}
