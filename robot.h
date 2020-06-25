/*
 * robot.h 
 * gunavigation 
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

#ifndef ROBOT_H
#define ROBOT_H

#include <stdbool.h>
#include <gucoordinates/gucoordinates.h>

#ifdef __cplusplus
extern "C" {
#endif

#define GU_NAO_V5_TOP_CAMERA gu_camera_make(48.064f, 5.871f, 1.2f, 47.64f, 60.97f) 
#define GU_NAO_V5_BOTTOM_CAMERA gu_camera_make(43.474f, 5.071f, 39.7f, 47.64f, 60.97f)

#define GU_PEPPER_TOP_CAMERA gu_camera_make(115.3f, 8.68f, 0.0f, 44.3f, 55.2f)
#define GU_PEPPER_BOTTOM_CAMERA gu_camera_make(105.15f, 9.36f, 40.0f, 44.3f, 55.2f)

#define GU_NAO_V5_HEAD(p, y) (gu_camera_pivot) {.headPitch = p, .headYaw = y, .cameras = {GU_NAO_V5_TOP_CAMERA, GU_NAO_V5_BOTTOM_CAMERA}, .cameraHeightOffsets = {41.7f, 41.7f}, .numCameras = 2}
#define GU_NAO_V5_TOP_CAMERA_INDEX 0
#define GU_NAO_V5_BOTTOM_CAMERA_INDEX 1 

#define GU_PEPPER_HEAD(p, y) {p, y, {GU_PEPPER_TOP_CAMERA, GU_PEPPER_BOTTOM_CAMERA}, {0.0f, 0.0f}, 2}

#define GU_NAO_V5_ROBOT(hp, hy, x, y, t) (gu_robot) { .head = { hp, hy, {GU_NAO_V5_TOP_CAMERA, GU_NAO_V5_BOTTOM_CAMERA}, { 41.7f, 41.7f }, 2 }, .position = { { x, y }, t } }

#define GU_PEPPER_ROBOT(hp, hy, x, y, t) (gu_robot) { .head = { hp, hy, {GU_PEPPER_TOP_CAMERA, GU_PEPPER_BOTTOM_CAMERA}, { 0.0f, 0.0f }, 2 }, .position = { { x, y }, t } }

typedef struct gu_robot
{

    gu_camera_pivot head;
    gu_field_coordinate position;

} gu_robot;

bool gu_robot_equals(const gu_robot, const gu_robot, const float);

#ifdef __cplusplus
}
#endif

#endif  /* ROBOT_H */
