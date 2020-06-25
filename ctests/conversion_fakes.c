/*
 * conversion_fakes.c 
 * tests 
 *
 * Created by Callum McColl on 19/06/2020.
 * Copyright © 2020 Callum McColl. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above
 *    copyright notice, this list of conditions and the following
 *    disclaimer in the documentation and/or other materials
 *    provided with the distribution.
 *
 * 3. All advertising materials mentioning features or use of this
 *    software must display the following acknowledgement:
 *
 *        This product includes software developed by Callum McColl.
 *
 * 4. Neither the name of the author nor the names of contributors
 *    may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER
 * OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * -----------------------------------------------------------------------
 * This program is free software; you can redistribute it and/or
 * modify it under the above terms or under the terms of the GNU
 * General Public License as published by the Free Software Foundation;
 * either version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see http://www.gnu.org/licenses/
 * or write to the Free Software Foundation, Inc., 51 Franklin Street,
 * Fifth Floor, Boston, MA  02110-1301, USA.
 *
 */

#include "conversion_fakes.h"

const gu_camera_coordinate cam_result = {19, 23, 1920, 1080};
const gu_pixel_coordinate px_result = {-19, -23, 1920, 1080};
const gu_percent_coordinate pct_result = {-0.19f, -0.23f};
const gu_relative_coordinate rr_result = {15, 100};
const gu_cartesian_coordinate cartesian_result = {-36, 70};
const gu_field_coordinate field_result = {{ -36, 70}, 32};

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wcast-qual"

DEFINE_FAKE_VALUE_FUNC(gu_pixel_coordinate, cam_coord_to_px_coord, const gu_camera_coordinate)
DEFINE_FAKE_VALUE_FUNC(gu_camera_coordinate, px_coord_to_cam_coord, const gu_pixel_coordinate)
DEFINE_FAKE_VALUE_FUNC(gu_percent_coordinate, px_coord_to_pct_coord, const gu_pixel_coordinate)
DEFINE_FAKE_VALUE_FUNC(gu_pixel_coordinate, pct_coord_to_px_coord, const gu_percent_coordinate, const pixels_u, const pixels_u)

DEFINE_FAKE_VALUE_FUNC(bool, px_coord_to_rr_coord, const gu_pixel_coordinate, const gu_camera_pivot, gu_relative_coordinate *, const int)
DEFINE_FAKE_VALUE_FUNC(bool, pct_coord_to_rr_coord, const gu_percent_coordinate, const gu_camera_pivot, gu_relative_coordinate *, const int)

DEFINE_FAKE_VALUE_FUNC(bool, rr_coord_to_pct_coord, const gu_relative_coordinate, const gu_camera_pivot, const int, gu_percent_coordinate *)
DEFINE_FAKE_VALUE_FUNC(bool, rr_coord_to_px_coord, const gu_relative_coordinate, const gu_camera_pivot, const int, gu_pixel_coordinate *, pixels_u, pixels_u)

// Converting from the robot relative coordinate system to the field coordinate systems.
DEFINE_FAKE_VALUE_FUNC(gu_cartesian_coordinate, rr_coord_to_cartesian_coord, const gu_relative_coordinate)
DEFINE_FAKE_VALUE_FUNC(gu_cartesian_coordinate, rr_coord_to_cartesian_coord_from_source, const gu_relative_coordinate, const gu_cartesian_coordinate)
DEFINE_FAKE_VALUE_FUNC(gu_field_coordinate, rr_coord_to_field_coord, const gu_relative_coordinate, const degrees_t)
DEFINE_FAKE_VALUE_FUNC(gu_field_coordinate, rr_coord_to_field_coord_from_source, const gu_relative_coordinate, const gu_field_coordinate, const degrees_t)

// Converting from field coordinates to relative coordinates.
DEFINE_FAKE_VALUE_FUNC(gu_relative_coordinate, cartesian_coord_to_rr_coord, const gu_cartesian_coordinate)
DEFINE_FAKE_VALUE_FUNC(gu_relative_coordinate, cartesian_coord_to_rr_coord_from_source, const gu_cartesian_coordinate, const gu_cartesian_coordinate)
DEFINE_FAKE_VALUE_FUNC(gu_relative_coordinate, field_coord_to_rr_coord_to_target, const gu_field_coordinate, const gu_cartesian_coordinate)
#pragma clang diagnostic pop
