/*
 * nao.c 
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

#include "nao.h"

#include <guunits/guunits.h>
#include <gusimplewhiteboard/guwhiteboardtypelist_c_generated.h>
#include <gusimplewhiteboard/typeClassDefs/wb_sensors_torsojointsensors.h>
#include <gusimplewhiteboard/typeClassDefs/wb_top_particles.h>
#include <gusimplewhiteboard/typeClassDefs/wb_sensors_head_sensors.h>
#include <gusimplewhiteboard/typeClassDefs/wb_sensors_legjointsensors.h>

#define GU_NAO_V5_TOP_CAMERA gu_camera_make(6.364f, 5.871f, 1.2f, 47.64f, 60.97f) 
#define GU_NAO_V5_TOP_CAMERA_HEIGHT_OFFSET 41.7f
#define GU_NAO_V5_BOTTOM_CAMERA gu_camera_make(1.774f, 5.071f, 39.7f, 47.64f, 60.97f)
#define GU_NAO_V5_BOTTOM_CAMERA_HEIGHT_OFFSET 41.7f

#define GU_NAO_V5_HEAD(p, y) (gu_camera_pivot) { .pitch = p, .yaw = y, .cameras = {GU_NAO_V5_TOP_CAMERA, GU_NAO_V5_BOTTOM_CAMERA}, .cameraHeightOffsets = {GU_NAO_V5_TOP_CAMERA_HEIGHT_OFFSET, GU_NAO_V5_BOTTOM_CAMERA_HEIGHT_OFFSET}, .numCameras = 2}

bool gu_nao_head_equals(const gu_nao_head lhs, const gu_nao_head rhs)
{
    return gu_pitch_yaw_joint_equals(lhs.neck, rhs.neck, 0.0001f)
        && gu_fmr_sensors_equals(lhs.buttons, rhs.buttons);
}

gu_camera_pivot gu_nao_head_to_camera_pivot(const gu_nao_head head)
{
    const gu_camera_pivot pivot = GU_NAO_V5_HEAD(head.neck.pitch, head.neck.yaw);
    return pivot;
}

bool gu_nao_arm_equals(const gu_nao_arm lhs, const gu_nao_arm rhs)
{
    return gu_pitch_roll_joint_equals(lhs.shoulder, rhs.shoulder, 0.0001f)
        && gu_yaw_roll_joint_equals(lhs.elbow, rhs.elbow, 0.0001f)
        && gu_yaw_joint_equals(lhs.wrist, rhs.wrist, 0.0001f)
        && gu_hand_sensors_equals(lhs.hand, rhs.hand);
}

bool gu_nao_leg_equals(const gu_nao_leg lhs, const gu_nao_leg rhs)
{
    return gu_yp_joint_equals(lhs.hip, rhs.hip, 0.0001f)
        && gu_pitch_joint_equals(lhs.knee, rhs.knee, 0.0001f)
        && gu_pitch_roll_joint_equals(lhs.ankle, rhs.ankle, 0.0001f);
}

bool gu_nao_equals(const gu_nao lhs, const gu_nao rhs)
{
    return gu_nao_head_equals(lhs.head, rhs.head)
        && gu_field_coordinate_equals(lhs.fieldPosition, rhs.fieldPosition)
        && gu_nao_arm_equals(lhs.leftArm, rhs.leftArm)
        && gu_nao_arm_equals(lhs.rightArm, rhs.rightArm)
        && gu_nao_leg_equals(lhs.leftLeg, rhs.leftLeg)
        && gu_nao_leg_equals(lhs.rightLeg, rhs.rightLeg);
}

void gu_nao_update_from_wb(gu_nao * nao, gu_simple_whiteboard * wb)
{
    const struct wb_sensors_torsojointsensors torsoSensors = *((struct wb_sensors_torsojointsensors *) gsw_current_message(wb, kSENSORSTorsoJointSensors_v));
    const struct wb_top_particles topParticles = *((struct wb_top_particles*) gsw_current_message(wb, kTopParticles_v));
    const struct wb_sensors_hand_sensors handSensors = *((struct wb_sensors_hand_sensors*) gsw_current_message(wb, kSensorsHandSensors_v));
    const struct wb_sensors_head_sensors headSensors = *((struct wb_sensors_head_sensors*) gsw_current_message(wb, kSensorsHeadSensors_v));
    const struct wb_sensors_legjointsensors legSensors = *((struct wb_sensors_legjointsensors*) gsw_current_message(wb, kSENSORSLegJointSensors_v));
    // Head
    nao->head.neck.pitch = rad_f_to_deg_f(f_to_rad_f(torsoSensors.HeadPitch));
    nao->head.neck.yaw = rad_f_to_deg_f(f_to_rad_f(torsoSensors.HeadYaw));
    nao->head.buttons.touchFront = headSensors.Head_Touch_Front;
    nao->head.buttons.touchMiddle = headSensors.Head_Touch_Middle;
    nao->head.buttons.touchRear = headSensors.Head_Touch_Rear;
    // Field Position
    nao->fieldPosition.position.x = i16_to_cm_t(topParticles.particles[0].position.x);
    nao->fieldPosition.position.y = i16_to_cm_t(topParticles.particles[0].position.y);
    nao->fieldPosition.heading = i16_to_deg_t(topParticles.particles[0].headingInDegrees);
    // Left Arm
    nao->leftArm.shoulder.pitch = rad_f_to_deg_f(f_to_rad_f(torsoSensors.LShoulderPitch));
    nao->leftArm.shoulder.roll = rad_f_to_deg_f(f_to_rad_f(torsoSensors.LShoulderRoll));
    nao->leftArm.elbow.yaw = rad_f_to_deg_f(f_to_rad_f(torsoSensors.LElbowYaw));
    nao->leftArm.elbow.roll = rad_f_to_deg_f(f_to_rad_f(torsoSensors.LElbowRoll));
    nao->leftArm.wrist.yaw = rad_f_to_deg_f(f_to_rad_f(torsoSensors.LWristYaw));
    nao->leftArm.hand.touchLeft = handSensors.LHand_Touch_Left;
    nao->leftArm.hand.touchBack = handSensors.LHand_Touch_Back;
    nao->leftArm.hand.touchRight = handSensors.LHand_Touch_Right;
    // Right Arm
    nao->rightArm.shoulder.pitch = rad_f_to_deg_f(f_to_rad_f(torsoSensors.RShoulderPitch));
    nao->rightArm.shoulder.roll = rad_f_to_deg_f(f_to_rad_f(torsoSensors.RShoulderRoll));
    nao->rightArm.elbow.yaw = rad_f_to_deg_f(f_to_rad_f(torsoSensors.RElbowYaw));
    nao->rightArm.elbow.roll = rad_f_to_deg_f(f_to_rad_f(torsoSensors.RElbowRoll));
    nao->rightArm.wrist.yaw = rad_f_to_deg_f(f_to_rad_f(torsoSensors.RWristYaw));
    nao->rightArm.hand.touchLeft = handSensors.RHand_Touch_Left;
    nao->rightArm.hand.touchBack = handSensors.RHand_Touch_Back;
    nao->rightArm.hand.touchRight = handSensors.RHand_Touch_Right;
    // Left Leg
    nao->leftLeg.hip.pitch = rad_f_to_deg_f(f_to_rad_f(legSensors.LHipPitch));
    nao->leftLeg.hip.yawPitch = rad_f_to_deg_f(f_to_rad_f(legSensors.LHipYawPitch));
    nao->leftLeg.hip.roll = rad_f_to_deg_f(f_to_rad_f(legSensors.LHipYawPitch));
    nao->leftLeg.knee.pitch = rad_f_to_deg_f(f_to_rad_f(legSensors.LKneePitch));
    nao->leftLeg.ankle.pitch = rad_f_to_deg_f(f_to_rad_f(legSensors.LAnklePitch));
    nao->leftLeg.ankle.roll = rad_f_to_deg_f(f_to_rad_f(legSensors.LAnkleRoll));
    // Right Leg
    nao->rightLeg.hip.pitch = rad_f_to_deg_f(f_to_rad_f(legSensors.RHipPitch));
    nao->rightLeg.hip.yawPitch = rad_f_to_deg_f(f_to_rad_f(legSensors.RHipYawPitch));
    nao->rightLeg.hip.roll = rad_f_to_deg_f(f_to_rad_f(legSensors.RHipYawPitch));
    nao->rightLeg.knee.pitch = rad_f_to_deg_f(f_to_rad_f(legSensors.RKneePitch));
    nao->rightLeg.ankle.pitch = rad_f_to_deg_f(f_to_rad_f(legSensors.RAnklePitch));
    nao->rightLeg.ankle.roll = rad_f_to_deg_f(f_to_rad_f(legSensors.RAnkleRoll));
}

void gu_nao_empty(gu_nao * nao)
{
    const gu_nao empty = { .head = { .neck = { .pitch = 0.0f} } };
    *nao = empty;
}
