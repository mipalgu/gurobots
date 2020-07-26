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

#define GU_NAO_V5_TOP_CAMERA gu_camera_make(6.364f, 5.871f, 1.2f, 47.64f, 60.97f) 
#define GU_NAO_V5_BOTTOM_CAMERA gu_camera_make(1.774f, 5.071f, 39.7f, 47.64f, 60.97f)

#define GU_NAO_V5_HEAD(p, y) (gu_camera_pivot) { .pitch = p, .yaw = y, .height = 41.7f, .cameras = {GU_NAO_V5_TOP_CAMERA, GU_NAO_V5_BOTTOM_CAMERA}, .numCameras = 2}

bool gu_nao_head_sensors_equals(const gu_nao_head_sensors lhs, const gu_nao_head_sensors rhs)
{
    return lhs.touchFront == rhs.touchFront
        && lhs.touchMiddle == rhs.touchMiddle
        && lhs.touchRear == rhs.touchRear;
}

bool gu_nao_head_equals(const gu_nao_head lhs, const gu_nao_head rhs)
{
    return gu_pitch_yaw_joint_equals(lhs.neck, rhs.neck, 0.0001f)
        && gu_nao_head_sensors_equals(lhs.buttons, rhs.buttons);
}

gu_camera_pivot gu_nao_head_to_camera_pivot(const gu_nao_head head)
{
    const gu_camera_pivot pivot = GU_NAO_V5_HEAD(head.neck.pitch, head.neck.yaw);
    return pivot;
}

bool gu_nao_hand_sensors_equals(const gu_nao_hand_sensors lhs, const gu_nao_hand_sensors rhs)
{
    return lhs.touchLeft == rhs.touchLeft
        && lhs.touchBack == rhs.touchBack
        && lhs.touchRight == rhs.touchRight;
}

bool gu_nao_arm_equals(const gu_nao_arm lhs, const gu_nao_arm rhs)
{
    return gu_pitch_roll_joint_equals(lhs.shoulder, rhs.shoulder, 0.0001f)
        && gu_yaw_roll_joint_equals(lhs.elbow, rhs.elbow, 0.0001f)
        && gu_yaw_joint_equals(lhs.wrist, rhs.wrist, 0.0001f)
        && gu_nao_hand_sensors_equals(lhs.hand, rhs.hand);
}

bool gu_nao_leg_equals(const gu_nao_leg lhs, const gu_nao_leg rhs)
{
    return gu_yp_joint_equals(lhs.hip, rhs.hip, 0.0001f)
        && gu_pitch_joint_equals(lhs.knee, rhs.knee, 0.0001f)
        && gu_pitch_roll_joint_equals(lhs.ankle, rhs.ankle, 0.0001f);
}

bool gu_nao_joints_equals(const gu_nao_joints lhs, const gu_nao_joints rhs)
{
    return gu_nao_head_equals(lhs.head, rhs.head)
        && gu_nao_arm_equals(lhs.leftArm, rhs.leftArm)
        && gu_nao_arm_equals(lhs.rightArm, rhs.rightArm)
        && gu_nao_leg_equals(lhs.leftLeg, rhs.leftLeg)
        && gu_nao_leg_equals(lhs.rightLeg, rhs.rightLeg);
}

bool gu_nao_equals(const gu_nao lhs, const gu_nao rhs)
{
    return gu_optional_field_coordinate_equals(lhs.fieldPosition, rhs.fieldPosition)
        && gu_nao_joints_equals(lhs.joints, rhs.joints)
        && gu_soccer_sightings_equals(lhs.sightings, rhs.sightings);
}

bool gu_nao_wb_indexes_equals(const gu_nao_wb_indexes lhs, const gu_nao_wb_indexes rhs)
{
    return lhs.torsoSensors == rhs.torsoSensors
        && lhs.topParticles == rhs.topParticles
        && lhs.handSensors == rhs.handSensors
        && lhs.headSensors == rhs.headSensors
        && lhs.legSensors == rhs.legSensors
        && lhs.ballLocation == rhs.ballLocation
        && lhs.leftGoalPostLocation == rhs.leftGoalPostLocation
        && lhs.rightGoalPostLocation == rhs.rightGoalPostLocation
        && lhs.goalLocation == rhs.goalLocation;
}

gu_nao_wb_indexes gu_nao_wb_indexes_default()
{
    const gu_nao_wb_indexes temp = {
        kSENSORSTorsoJointSensors_v,
        kTopParticles_v,
        kSensorsHandSensors_v,
        kSensorsHeadSensors_v,
        kSENSORSLegJointSensors_v,
        kBallLocation_v,
        kLeftGoalPostLocation_v,
        kRightGoalPostLocation_v,
        kRightGoalPostLocation_v
    };
    return temp;
}

gu_nao_wb_types gu_nao_wb_types_from_wb(gu_simple_whiteboard * wb)
{
    const gu_nao_wb_indexes indexes = gu_nao_wb_indexes_default();
    return gu_nao_wb_types_from_custom_wb(wb, indexes);
}

gu_nao_wb_types gu_nao_wb_types_from_custom_wb(gu_simple_whiteboard * wb, const gu_nao_wb_indexes indexes)
{
    const struct wb_sensors_torsojointsensors torsoSensors = *((struct wb_sensors_torsojointsensors *) gsw_current_message(wb, indexes.torsoSensors));
    const struct wb_top_particles topParticles = *((struct wb_top_particles*) gsw_current_message(wb, indexes.topParticles));
    const struct wb_sensors_hand_sensors handSensors = *((struct wb_sensors_hand_sensors*) gsw_current_message(wb, indexes.handSensors));
    const struct wb_sensors_head_sensors headSensors = *((struct wb_sensors_head_sensors*) gsw_current_message(wb, indexes.headSensors));
    const struct wb_sensors_legjointsensors legSensors = *((struct wb_sensors_legjointsensors*) gsw_current_message(wb, indexes.legSensors));
    const struct wb_location ballLocation = *((struct wb_location*) gsw_current_message(wb, indexes.ballLocation));
    const struct wb_location leftGoalPostLocation = *((struct wb_location*) gsw_current_message(wb, indexes.leftGoalPostLocation));
    const struct wb_location rightGoalPostLocation = *((struct wb_location*) gsw_current_message(wb, indexes.rightGoalPostLocation));
    const struct wb_location goalLocation = *((struct wb_location*) gsw_current_message(wb, indexes.goalLocation));
    const gu_nao_wb_types temp = {
        torsoSensors,
        topParticles,
        handSensors,
        headSensors,
        legSensors,
        ballLocation,
        leftGoalPostLocation,
        rightGoalPostLocation,
        goalLocation
    };
    return temp;
}

void gu_nao_update_from_wb(gu_nao * nao, gu_simple_whiteboard * wb)
{
    const gu_nao_wb_indexes indexes = gu_nao_wb_indexes_default();
    gu_nao_update_from_custom_wb(nao, wb, indexes);
}

void gu_nao_update_from_custom_wb(gu_nao * nao, gu_simple_whiteboard * wb, const gu_nao_wb_indexes indexes)
{
    const gu_nao_wb_types types = gu_nao_wb_types_from_custom_wb(wb, indexes);
    gu_nao_update_from_wb_types(nao, types);
}

void gu_nao_update_from_wb_types(gu_nao * nao, const gu_nao_wb_types types)
{
    // Head
    nao->joints.head.neck.pitch = rad_f_to_deg_f(f_to_rad_f(types.torsoSensors.HeadPitch));
    nao->joints.head.neck.yaw = rad_f_to_deg_f(f_to_rad_f(types.torsoSensors.HeadYaw));
    nao->joints.head.buttons.touchFront = types.headSensors.Head_Touch_Front;
    nao->joints.head.buttons.touchMiddle = types.headSensors.Head_Touch_Middle;
    nao->joints.head.buttons.touchRear = types.headSensors.Head_Touch_Rear;
    // Field Position
    nao->fieldPosition.hasCoordinate = types.topParticles.particles[0].confidence > 0.6f;
    nao->fieldPosition.field_coordinate.position.x = i16_to_cm_t(types.topParticles.particles[0].position.x);
    nao->fieldPosition.field_coordinate.position.y = i16_to_cm_t(types.topParticles.particles[0].position.y);
    nao->fieldPosition.field_coordinate.heading = i16_to_deg_t(types.topParticles.particles[0].headingInDegrees);
    // Left Arm
    nao->joints.leftArm.shoulder.pitch = rad_f_to_deg_f(f_to_rad_f(types.torsoSensors.LShoulderPitch));
    nao->joints.leftArm.shoulder.roll = rad_f_to_deg_f(f_to_rad_f(types.torsoSensors.LShoulderRoll));
    nao->joints.leftArm.elbow.yaw = rad_f_to_deg_f(f_to_rad_f(types.torsoSensors.LElbowYaw));
    nao->joints.leftArm.elbow.roll = rad_f_to_deg_f(f_to_rad_f(types.torsoSensors.LElbowRoll));
    nao->joints.leftArm.wrist.yaw = rad_f_to_deg_f(f_to_rad_f(types.torsoSensors.LWristYaw));
    nao->joints.leftArm.hand.touchLeft = types.handSensors.LHand_Touch_Left;
    nao->joints.leftArm.hand.touchBack = types.handSensors.LHand_Touch_Back;
    nao->joints.leftArm.hand.touchRight = types.handSensors.LHand_Touch_Right;
    // Right Arm
    nao->joints.rightArm.shoulder.pitch = rad_f_to_deg_f(f_to_rad_f(types.torsoSensors.RShoulderPitch));
    nao->joints.rightArm.shoulder.roll = rad_f_to_deg_f(f_to_rad_f(types.torsoSensors.RShoulderRoll));
    nao->joints.rightArm.elbow.yaw = rad_f_to_deg_f(f_to_rad_f(types.torsoSensors.RElbowYaw));
    nao->joints.rightArm.elbow.roll = rad_f_to_deg_f(f_to_rad_f(types.torsoSensors.RElbowRoll));
    nao->joints.rightArm.wrist.yaw = rad_f_to_deg_f(f_to_rad_f(types.torsoSensors.RWristYaw));
    nao->joints.rightArm.hand.touchLeft = types.handSensors.RHand_Touch_Left;
    nao->joints.rightArm.hand.touchBack = types.handSensors.RHand_Touch_Back;
    nao->joints.rightArm.hand.touchRight = types.handSensors.RHand_Touch_Right;
    // Left Leg
    nao->joints.leftLeg.hip.pitch = rad_f_to_deg_f(f_to_rad_f(types.legSensors.LHipPitch));
    nao->joints.leftLeg.hip.yawPitch = rad_f_to_deg_f(f_to_rad_f(types.legSensors.LHipYawPitch));
    nao->joints.leftLeg.hip.roll = rad_f_to_deg_f(f_to_rad_f(types.legSensors.LHipYawPitch));
    nao->joints.leftLeg.knee.pitch = rad_f_to_deg_f(f_to_rad_f(types.legSensors.LKneePitch));
    nao->joints.leftLeg.ankle.pitch = rad_f_to_deg_f(f_to_rad_f(types.legSensors.LAnklePitch));
    nao->joints.leftLeg.ankle.roll = rad_f_to_deg_f(f_to_rad_f(types.legSensors.LAnkleRoll));
    // Right Leg
    nao->joints.rightLeg.hip.pitch = rad_f_to_deg_f(f_to_rad_f(types.legSensors.RHipPitch));
    nao->joints.rightLeg.hip.yawPitch = rad_f_to_deg_f(f_to_rad_f(types.legSensors.RHipYawPitch));
    nao->joints.rightLeg.hip.roll = rad_f_to_deg_f(f_to_rad_f(types.legSensors.RHipYawPitch));
    nao->joints.rightLeg.knee.pitch = rad_f_to_deg_f(f_to_rad_f(types.legSensors.RKneePitch));
    nao->joints.rightLeg.ankle.pitch = rad_f_to_deg_f(f_to_rad_f(types.legSensors.RAnklePitch));
    nao->joints.rightLeg.ankle.roll = rad_f_to_deg_f(f_to_rad_f(types.legSensors.RAnkleRoll));
    // Sightings
    nao->sightings.ball = wb_location_to_optional_relative_coordinate(types.ballLocation);
    nao->sightings.leftGoalPost = wb_location_to_optional_relative_coordinate(types.leftGoalPostLocation);
    nao->sightings.rightGoalPost = wb_location_to_optional_relative_coordinate(types.rightGoalPostLocation);
    nao->sightings.goal = wb_location_to_optional_relative_coordinate(types.goalLocation);
}

void gu_nao_empty(gu_nao * nao)
{
    const gu_nao empty = { .joints = { .head = { .neck = { .pitch = 0.0f} } } };
    *nao = empty;
}
