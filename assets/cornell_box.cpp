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

#include "cornell_box.h"

#if 1

extern float cornell_box_white[3] = {0.88693428747836056, 0.69685426957557162, 0.66683170946841896};

extern float cornell_box_green[3] = {0.10529997257385908, 0.37748901230216947, 0.076469893263632627};

extern float cornell_box_red[3] = {0.57128971777566862, 0.042392882862369932, 0.044485041430903594};

extern float cornell_box_light[3] = {20.746706169696839, 10.823394563519930, 2.7645892325051604};

#else

#include "../thirdparty/pbrt/core/spectrum.h"

// http://www.graphics.cornell.edu/online/box/data.html

// TODO: different RGB data
// https://casual-effects.com/data/index.html

static Float const cornell_box_white_green_red_lambda[] = {400, 404, 408, 412, 416, 420, 424, 428, 432, 436, 440, 444, 448, 452, 456, 460, 464, 468, 472, 476, 480, 484, 488, 492, 496, 500, 504, 508, 512, 516, 520, 524, 528, 532, 536, 540, 544, 548, 552, 556, 560, 564, 568, 572, 576, 580, 584, 588, 592, 596, 600, 604, 608, 612, 616, 620, 624, 628, 632, 636, 640, 644, 648, 652, 656, 660, 664, 668, 672, 676, 680, 684, 688, 692, 696, 700};

static Float const cornell_box_white_sampled[] = {0.343, 0.445, 0.551, 0.624, 0.665, 0.687, 0.708, 0.723, 0.715, 0.710, 0.745, 0.758, 0.739, 0.767, 0.777, 0.765, 0.751, 0.745, 0.748, 0.729, 0.745, 0.757, 0.753, 0.750, 0.746, 0.747, 0.735, 0.732, 0.739, 0.734, 0.725, 0.721, 0.733, 0.725, 0.732, 0.743, 0.744, 0.748, 0.728, 0.716, 0.733, 0.726, 0.713, 0.740, 0.754, 0.764, 0.752, 0.736, 0.734, 0.741, 0.740, 0.732, 0.745, 0.755, 0.751, 0.744, 0.731, 0.733, 0.744, 0.731, 0.712, 0.708, 0.729, 0.730, 0.727, 0.707, 0.703, 0.729, 0.750, 0.760, 0.751, 0.739, 0.724, 0.730, 0.740, 0.737};

static Float const cornell_box_green_sampled[] = {0.092, 0.096, 0.098, 0.097, 0.098, 0.095, 0.095, 0.097, 0.095, 0.094, 0.097, 0.098, 0.096, 0.101, 0.103, 0.104, 0.107, 0.109, 0.112, 0.115, 0.125, 0.140, 0.160, 0.187, 0.229, 0.285, 0.343, 0.390, 0.435, 0.464, 0.472, 0.476, 0.481, 0.462, 0.447, 0.441, 0.426, 0.406, 0.373, 0.347, 0.337, 0.314, 0.285, 0.277, 0.266, 0.250, 0.230, 0.207, 0.186, 0.171, 0.160, 0.148, 0.141, 0.136, 0.130, 0.126, 0.123, 0.121, 0.122, 0.119, 0.114, 0.115, 0.117, 0.117, 0.118, 0.120, 0.122, 0.128, 0.132, 0.139, 0.144, 0.146, 0.150, 0.152, 0.157, 0.159};

static Float const cornell_box_red_sampled[] = {0.040, 0.046, 0.048, 0.053, 0.049, 0.050, 0.053, 0.055, 0.057, 0.056, 0.059, 0.057, 0.061, 0.061, 0.060, 0.062, 0.062, 0.062, 0.061, 0.062, 0.060, 0.059, 0.057, 0.058, 0.058, 0.058, 0.056, 0.055, 0.056, 0.059, 0.057, 0.055, 0.059, 0.059, 0.058, 0.059, 0.061, 0.061, 0.063, 0.063, 0.067, 0.068, 0.072, 0.080, 0.090, 0.099, 0.124, 0.154, 0.192, 0.255, 0.287, 0.349, 0.402, 0.443, 0.487, 0.513, 0.558, 0.584, 0.620, 0.606, 0.609, 0.651, 0.612, 0.610, 0.650, 0.638, 0.627, 0.620, 0.630, 0.628, 0.642, 0.639, 0.657, 0.639, 0.635, 0.642};

static Float const cornell_box_light_lambda[] = {400.0, 500.0, 600.0, 700.0};

static Float const cornell_box_light_sampled[] = {0.0, 8.0, 15.6, 18.4};

static pbrt::RGBSpectrum const cornell_box_white_rgb = pbrt::RGBSpectrum::FromSampled(cornell_box_white_green_red_lambda, cornell_box_white_sampled, 76);

static pbrt::RGBSpectrum const cornell_box_green_rgb = pbrt::RGBSpectrum::FromSampled(cornell_box_white_green_red_lambda, cornell_box_green_sampled, 76);

static pbrt::RGBSpectrum const cornell_box_red_rgb = pbrt::RGBSpectrum::FromSampled(cornell_box_white_green_red_lambda, cornell_box_red_sampled, 76);

static pbrt::RGBSpectrum const cornell_box_light_rgb = pbrt::RGBSpectrum::FromSampled(cornell_box_light_lambda, cornell_box_light_sampled, 4);

extern float cornell_box_white[3] = {cornell_box_white_rgb[0], cornell_box_white_rgb[1], cornell_box_white_rgb[2]};

extern float cornell_box_green[3] = {cornell_box_green_rgb[0], cornell_box_green_rgb[1], cornell_box_green_rgb[2]};

extern float cornell_box_red[3] = {cornell_box_red_rgb[0], cornell_box_red_rgb[1], cornell_box_red_rgb[2]};

extern float cornell_box_light[3] = {cornell_box_light_rgb[0], cornell_box_light_rgb[1], cornell_box_light_rgb[2]};

#endif