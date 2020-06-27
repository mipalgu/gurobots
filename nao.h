/*
 * nao.h 
 * gurobots 
 *
 * Created by Callum McColl on 27/06/2020.
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

#ifndef GUROBOTS_NAO_H
#define GUROBOTS_NAO_H

#include <guunits/guunits.h>
#include <gucoordinates/gucoordinates.h>
#include <stdbool.h>

#include <gusimplewhiteboard/gusimplewhiteboard.h>

#include "hand_sensors.h"
#include "fmr_sensors.h"
#include "pitch_joint.h"
#include "pitch_roll_joint.h"
#include "pitch_yaw_joint.h"
#include "yaw_roll_joint.h"
#include "yaw_joint.h"
#include "yp_joint.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct gu_nao_head {
    gu_pitch_yaw_joint neck;
    gu_fmr_sensors buttons;
} gu_nao_head;

bool gu_nao_head_equals(const gu_nao_head lhs, const gu_nao_head rhs);
gu_camera_pivot gu_nao_head_to_camera_pivot(const gu_nao_head);

typedef struct gu_nao_arm {
    gu_pitch_roll_joint shoulder;
    gu_yaw_roll_joint elbow;
    gu_yaw_joint wrist;
    gu_hand_sensors hand;
} gu_nao_arm;

bool gu_nao_arm_equals(const gu_nao_arm lhs, const gu_nao_arm rhs);

typedef struct gu_nao_leg {
    gu_yp_joint hip; 
    gu_pitch_joint knee;
    gu_pitch_roll_joint ankle;
} gu_nao_leg;

bool gu_nao_leg_equals(const gu_nao_leg lhs, const gu_nao_leg rhs);

typedef struct gu_nao {
    gu_nao_head head;
    gu_field_coordinate fieldPosition;
    gu_nao_arm leftArm;
    gu_nao_arm rightArm;
    gu_nao_leg leftLeg;
    gu_nao_leg rightLeg;
} gu_nao;

bool gu_nao_equals(const gu_nao lhs, const gu_nao rhs);
void gu_nao_update_from_wb(gu_nao *, gu_simple_whiteboard *);
void gu_nao_empty(gu_nao *);

#ifdef __cplusplus
}
#endif

#endif  /* GUROBOTS_NAO_H */
