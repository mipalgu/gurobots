/*
 * soccer_sightings.h 
 * gurobots 
 *
 * Created by Callum McColl on 10/09/2020.
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

#ifndef GUROBOTS_SOCCER_SIGHTINGS_H
#define GUROBOTS_SOCCER_SIGHTINGS_H

#include <gucoordinates/gucoordinates.h>

#include "optional_ellipse_sighting.h"
#include "optional_rectangle_sighting.h"
#include "optional_horizon_sighting.h"
#include "optional_line_sighting.h"

#define GUROBOTS_SOCCER_SIGHTINGS_MAX_LINE_SIGHTINGS 7
#define GUROBOTS_SOCCER_SIGHTINGS_MAX_LINE_CORNER_SIGHTINGS 8
#define GUROBOTS_SOCCER_SIGHTINGS_MAX_LINE_T_INTERSECTION_SIGHTINGS 8
#define GUROBOTS_SOCCER_SIGHTINGS_MAX_LINE_CROSS_SIGHTINGS 3

#ifdef __cplusplus
extern "C" {
#endif

typedef struct gu_soccer_sightings {
    gu_optional_ellipse_sighting ball;
    gu_optional_rectangle_sighting genericPost;
    gu_optional_rectangle_sighting leftGoalPost;
    gu_optional_rectangle_sighting rightGoalPost;
    gu_optional_rectangle_sighting crossbar;
    gu_optional_horizon_sighting horizon;
    gu_line_sighting lines[GUROBOTS_SOCCER_SIGHTINGS_MAX_LINE_SIGHTINGS];
    gu_pixel_coordinate lineCorners[GUROBOTS_SOCCER_SIGHTINGS_MAX_LINE_CORNER_SIGHTINGS];
    gu_pixel_coordinate lineTIntersections[GUROBOTS_SOCCER_SIGHTINGS_MAX_LINE_T_INTERSECTION_SIGHTINGS];
    gu_pixel_coordinate lineCrosses[GUROBOTS_SOCCER_SIGHTINGS_MAX_LINE_CROSS_SIGHTINGS];
    int numLines;
    int numCorners;
    int numTIntersections;
    int numCrosses;
} gu_soccer_sightings;

bool gu_soccer_sightings_equals(const gu_soccer_sightings lhs, const gu_soccer_sightings rhs);

#ifdef __cplusplus
}
#endif

#endif  /* GUROBOTS_SOCCER_SIGHTINGS_H */
