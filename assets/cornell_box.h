//
// Copyright (C) YuqiaoZhang(HanetakaChou)
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published
// by the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.
//

#ifndef _CORNELL_BOX_H_
#define _CORNELL_BOX_H_ 1

#include <stdint.h>

// NOTE: The ceiling will not cast shadow since we use the backface culling.

// http://www.graphics.cornell.edu/online/box/data.html

// https://casual-effects.com/data/index.html

// Floor

static constexpr uint32_t const g_cornell_box_floor_vertex_count = 4U;

extern float const g_cornell_box_floor_vertex_postion[3U * g_cornell_box_floor_vertex_count];

extern float const g_cornell_box_floor_vertex_normal[3U * g_cornell_box_floor_vertex_count];

static constexpr uint32_t const g_cornell_box_floor_index_count = 6U;

extern uint16_t const g_cornell_box_floor_index[g_cornell_box_floor_index_count];

// Ceiling

static constexpr uint32_t const g_cornell_box_ceiling_vertex_count = 4U;

extern float const g_cornell_box_ceiling_vertex_postion[3U * g_cornell_box_ceiling_vertex_count];

extern float const g_cornell_box_ceiling_vertex_normal[3U * g_cornell_box_ceiling_vertex_count];

static constexpr uint32_t const g_cornell_box_ceiling_index_count = 6U;

extern uint16_t const g_cornell_box_ceiling_index[g_cornell_box_ceiling_index_count];

// Back Wall

static constexpr uint32_t const g_cornell_box_back_wall_vertex_count = 4U;

extern float const g_cornell_box_back_wall_vertex_postion[3U * g_cornell_box_back_wall_vertex_count];

extern float const g_cornell_box_back_wall_vertex_normal[3U * g_cornell_box_back_wall_vertex_count];

static constexpr uint32_t const g_cornell_box_back_wall_index_count = 6U;

extern uint16_t const g_cornell_box_back_wall_index[g_cornell_box_back_wall_index_count];

// Right Wall

static constexpr uint32_t const g_cornell_box_right_wall_vertex_count = 4U;

extern float const g_cornell_box_right_wall_vertex_postion[3U * g_cornell_box_right_wall_vertex_count];

extern float const g_cornell_box_right_wall_vertex_normal[3U * g_cornell_box_right_wall_vertex_count];

static constexpr uint32_t const g_cornell_box_right_wall_index_count = 6U;

extern uint16_t const g_cornell_box_right_wall_index[g_cornell_box_right_wall_index_count];

// Left Wall

static constexpr uint32_t const g_cornell_box_left_wall_vertex_count = 4U;

extern float const g_cornell_box_left_wall_vertex_postion[3U * g_cornell_box_left_wall_vertex_count];

extern float const g_cornell_box_left_wall_vertex_normal[3U * g_cornell_box_left_wall_vertex_count];

static constexpr uint32_t const g_cornell_box_left_wall_index_count = 6U;

extern uint16_t const g_cornell_box_left_wall_index[g_cornell_box_left_wall_index_count];

// Short Block

static constexpr uint32_t const g_cornell_box_short_block_vertex_count = 482U;

extern float const g_cornell_box_short_block_vertex_postion[3U * g_cornell_box_short_block_vertex_count];

extern float const g_cornell_box_short_block_vertex_normal[3U * g_cornell_box_short_block_vertex_count];

static constexpr uint32_t const g_cornell_box_short_block_index_count = 2880U;

extern uint16_t const g_cornell_box_short_block_index[g_cornell_box_short_block_index_count];

// Tall Block

static constexpr uint32_t const g_cornell_box_tall_block_vertex_count = 482U;

extern float const g_cornell_box_tall_block_vertex_postion[3U * g_cornell_box_tall_block_vertex_count];

extern float const g_cornell_box_tall_block_vertex_normal[3U * g_cornell_box_tall_block_vertex_count];

static constexpr uint32_t const g_cornell_box_tall_block_index_count = 2880U;

extern uint16_t const g_cornell_box_tall_block_index[g_cornell_box_tall_block_index_count];

#endif