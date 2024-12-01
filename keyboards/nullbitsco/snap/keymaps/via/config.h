/* Copyright 2021 Jay Greco
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
// clang-format off
#pragma once

/* space savers */
#define DYNAMIC_KEYMAP_LAYER_COUNT 4

#define NUM_ENCODERS 1

#define MK_COMBINED
#define MOUSEKEY_INTERVAL 16
#define MOUSEKEY_MOVE_DELTA 4

#define MOUSEKEY_WHEEL_INTERVAL 40
#define MOUSEKEY_WHEEL_DELTA 1

#define TAPPING_TOGGLE 2

#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
#define NO_ACTION_ONESHOT
#define NO_MUSIC_MODE
#define LAYER_STATE_8BIT
