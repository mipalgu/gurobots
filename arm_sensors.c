/*
 * arm_sensors.c 
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

#include "arm_sensors.h"


bool gu_arm_sensors_equals(const gu_arm_sensors lhs, const gu_arm_sensors rhs, const degrees_f tolerance)
{
    return 
        fabsf(lhs.leftShoulderPitch - rhs.leftShoulderPitch) <= tolerance
        && fabsf(lhs.leftShoulderRoll - rhs.leftShoulderRoll) <= tolerance
        && fabsf(lhs.leftElbowYaw - rhs.leftElbowYaw) <= tolerance
        && fabsf(lhs.leftElbowRoll - rhs.leftElbowRoll) <= tolerance
        && fabsf(lhs.rightShoulderPitch - rhs.rightShoulderPitch) <= tolerance
        && fabsf(lhs.rightShoulderRoll - rhs.rightShoulderRoll) <= tolerance
        && fabsf(lhs.rightElbowYaw - rhs.rightElbowYaw) <= tolerance
        && fabsf(lhs.rightElbowRoll - rhs.rightElbowRoll) <= tolerance
        && fabsf(lhs.leftWristYaw - rhs.leftWristYaw) <= tolerance
        && fabsf(lhs.rightWristYaw - rhs.rightWristYaw) <= tolerance;
}

void gu_arm_sensors_update_from_wb(gu_arm_sensors * armSensors, const struct wb_sensors_torsojointsensors torsoSensors)
{
     armSensors->leftShoulderPitch = rad_f_to_deg_f(f_to_rad_f(torsoSensors.LShoulderPitch));
     armSensors->leftShoulderRoll = rad_f_to_deg_f(f_to_rad_f(torsoSensors.LShoulderRoll));
     armSensors->leftElbowYaw = rad_f_to_deg_f(f_to_rad_f(torsoSensors.LElbowYaw));
     armSensors->leftElbowRoll = rad_f_to_deg_f(f_to_rad_f(torsoSensors.LElbowRoll));
     armSensors->rightShoulderPitch = rad_f_to_deg_f(f_to_rad_f(torsoSensors.RShoulderPitch));
     armSensors->rightShoulderRoll = rad_f_to_deg_f(f_to_rad_f(torsoSensors.RShoulderRoll));
     armSensors->rightElbowYaw = rad_f_to_deg_f(f_to_rad_f(torsoSensors.RElbowYaw));
     armSensors->rightElbowRoll = rad_f_to_deg_f(f_to_rad_f(torsoSensors.RElbowRoll));
     armSensors->leftWristYaw = rad_f_to_deg_f(f_to_rad_f(torsoSensors.LWristYaw));
     armSensors->rightWristYaw = rad_f_to_deg_f(f_to_rad_f(torsoSensors.RWristYaw));
}
