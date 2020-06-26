/*
 * NaoV5.cc
 * build
 *
 * Created by Callum McColl on 22/6/20.
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

#include "NaoV5.hpp"

#include "robot.h"

#include <guunits/guunits.h>

#include <gusimplewhiteboard/gusimplewhiteboard.h>
#include <gusimplewhiteboard/guwhiteboardtypelist_c_generated.h>
#include <gusimplewhiteboard/typeClassDefs/wb_sensors_torsojointsensors.h>
#include <gusimplewhiteboard/typeClassDefs/wb_top_particles.h>
#include <gusimplewhiteboard/typeClassDefs/wb_sensors_hand_sensors.h>

GU::NaoV5::NaoV5() {
    wb = get_local_singleton_whiteboard()->wb;
    set_headPitch(0.0f);
    set_headYaw(0.0f);
    gu_nao::head.cameras[GU_NAO_V5_TOP_CAMERA_INDEX] = GU_NAO_V5_TOP_CAMERA;
    gu_nao::head.cameras[GU_NAO_V5_BOTTOM_CAMERA_INDEX] = GU_NAO_V5_BOTTOM_CAMERA;
    gu_nao::head.cameraHeightOffsets[GU_NAO_V5_TOP_CAMERA_INDEX] = GU_NAO_V5_TOP_CAMERA_HEIGHT_OFFSET;
    gu_nao::head.cameraHeightOffsets[GU_NAO_V5_BOTTOM_CAMERA_INDEX] = GU_NAO_V5_BOTTOM_CAMERA_HEIGHT_OFFSET;
    gu_nao::head.numCameras = 2;
}

GU::NaoV5::NaoV5(gu_simple_whiteboard *t_wb)
{
    wb = t_wb;
    set_headPitch(0.0f);
    set_headYaw(0.0f);
    gu_nao::head.cameras[GU_NAO_V5_TOP_CAMERA_INDEX] = GU_NAO_V5_TOP_CAMERA;
    gu_nao::head.cameras[GU_NAO_V5_BOTTOM_CAMERA_INDEX] = GU_NAO_V5_BOTTOM_CAMERA;
    gu_nao::head.cameraHeightOffsets[GU_NAO_V5_TOP_CAMERA_INDEX] = GU_NAO_V5_TOP_CAMERA_HEIGHT_OFFSET;
    gu_nao::head.cameraHeightOffsets[GU_NAO_V5_BOTTOM_CAMERA_INDEX] = GU_NAO_V5_BOTTOM_CAMERA_HEIGHT_OFFSET;
    gu_nao::head.numCameras = 2;
}

GU::NaoV5::NaoV5(const NaoV5& other)
{
    wb = other.wb;
    set_headPitch(other.headPitch());
    set_headYaw(other.headYaw());
    gu_nao::head.cameras[GU_NAO_V5_TOP_CAMERA_INDEX] = GU_NAO_V5_TOP_CAMERA;
    gu_nao::head.cameras[GU_NAO_V5_BOTTOM_CAMERA_INDEX] = GU_NAO_V5_BOTTOM_CAMERA;
    gu_nao::head.cameraHeightOffsets[GU_NAO_V5_TOP_CAMERA_INDEX] = GU_NAO_V5_TOP_CAMERA_HEIGHT_OFFSET;
    gu_nao::head.cameraHeightOffsets[GU_NAO_V5_BOTTOM_CAMERA_INDEX] = GU_NAO_V5_BOTTOM_CAMERA_HEIGHT_OFFSET;
    gu_nao::head.numCameras = 2;
}

#if __cplusplus >= 201103L
GU::NaoV5::NaoV5(NaoV5&& other) {
    wb = other.wb;
    set_headPitch(other.headPitch());
    set_headYaw(other.headYaw());
    other.set_headPitch(0.0f);
    other.set_headYaw(0.0f);
}
#endif

GU::NaoV5::~NaoV5() {}

GU::NaoV5& GU::NaoV5::operator=(const GU::NaoV5& other) {
    if (&other == this) {
        return *this;
    }
    set_headPitch(other.headPitch());
    set_headYaw(other.headYaw());
    return *this;
}

#if __cplusplus >= 201103L
GU::NaoV5& GU::NaoV5::operator=(GU::NaoV5&& other) {
    if (&other == this) {
        return *this;
    }
    wb = other.wb;
    set_headPitch(other.headPitch());
    set_headYaw(other.headYaw());
    other.set_headPitch(0.0f);
    other.set_headYaw(0.0f);
    return *this;
}
#endif

GU::CameraPivot GU::NaoV5::head() const
{
    return gu_nao::head;
}

degrees_f GU::NaoV5::headPitch() const
{
    return gu_nao::head.pitch;
}

void GU::NaoV5::set_headPitch(const degrees_f newValue)
{
    gu_nao::head.pitch = newValue;
}

degrees_f GU::NaoV5::headYaw() const
{
    return gu_nao::head.yaw;
}

void GU::NaoV5::set_headYaw(const degrees_f newValue)
{
    gu_nao::head.yaw = newValue;
}

degrees_f GU::NaoV5::leftShoulderPitch() const
{
    return lShoulderPitch_;
}

degrees_f GU::NaoV5::leftShoulderRoll() const
{
    return lShoulderRoll_;
}

degrees_f GU::NaoV5::leftElbowYaw() const
{
    return lElbowYaw_;
}

degrees_f GU::NaoV5::leftElbowRoll() const
{
    return lElbowRoll_;
}

degrees_f GU::NaoV5::rightShoulderPitch() const
{
    return rShoulderPitch_;
}

degrees_f GU::NaoV5::rightShoulderRoll() const
{
    return rShoulderRoll_;
}

degrees_f GU::NaoV5::rightElbowYaw() const
{
    return rElbowYaw_;
}

degrees_f GU::NaoV5::rightElbowRoll() const
{
    return rElbowRoll_;
}

degrees_f GU::NaoV5::leftWristYaw() const
{
    return lWristYaw_;
}

degrees_f GU::NaoV5::rightWristYaw() const
{
    return rWristYaw_;
}

bool GU::NaoV5::leftHandTouchLeft() const
{
    return gu_nao::handSensors.leftHandTouchLeft;
}

bool GU::NaoV5::leftHandTouchBack() const
{
    return gu_nao::handSensors.leftHandTouchBack;
}

bool GU::NaoV5::leftHandTouchRight() const
{
    return gu_nao::handSensors.leftHandTouchRight;
}

bool GU::NaoV5::rightHandTouchLeft() const
{
    return gu_nao::handSensors.rightHandTouchLeft;
}

bool GU::NaoV5::rightHandTouchBack() const
{
    return gu_nao::handSensors.rightHandTouchBack;
}

bool GU::NaoV5::rightHandTouchRight() const
{
    return gu_nao::handSensors.rightHandTouchRight;
}

void GU::NaoV5::update()
{
    gu_nao_update_from_wb(this, wb);
}
