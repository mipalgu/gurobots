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

#include <guunits/guunits.h>

GU::NaoV5::NaoV5() {
    set_headPitch(0.0f);
    set_headYaw(0.0f);
}

GU::NaoV5::NaoV5(const degrees_f t_headPitch, const degrees_f t_headYaw)
{
    set_headPitch(t_headPitch);
    set_headYaw(t_headYaw);
}

GU::NaoV5::NaoV5(const NaoV5& other)
{
    set_headPitch(other.headPitch());
    set_headYaw(other.headYaw());
}

GU::NaoV5::NaoV5(const ::wb_sensors_torsojointsensors& joints)
{
    set_headPitch(rad_f_to_deg_f(f_to_rad_f(joints.HeadPitch())));
    set_headYaw(rad_f_to_deg_f(f_to_rad_f(joints.HeadYaw())));
}

#if __cplusplus >= 201103L
GU::NaoV5::NaoV5(NaoV5&& other) {
    _headPitch = other.headPitch();
    _headYaw = other.headYaw();
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

GU::NaoV5& GU::NaoV5::operator=(const ::wb_sensors_torsojointsensors& joints)
{
    set_headPitch(rad_f_to_deg_f(f_to_rad_f(joints.HeadPitch())));
    set_headYaw(rad_f_to_deg_f(f_to_rad_f(joints.HeadYaw())));
    return *this;
}

#if __cplusplus >= 201103L
GU::NaoV5& GU::NaoV5::operator=(GU::NaoV5&& other) {
    if (&other == this) {
        return *this;
    }
    set_headPitch(other.headPitch());
    set_headYaw(other.headYaw());
    other.set_headPitch(0.0f);
    other.set_headYaw(0.0f);
    return *this;
}
#endif

degrees_f GU::NaoV5::headPitch() const
{
    return _headPitch;
}

void GU::NaoV5::set_headPitch(const degrees_f newValue)
{
    _headPitch = newValue;
}

degrees_f GU::NaoV5::headYaw() const
{
    return _headYaw;
}

void GU::NaoV5::set_headYaw(const degrees_f newValue)
{
    _headYaw = newValue;
}

GU::CameraPivot GU::NaoV5::toCameraPivot() const
{
    return GU_NAO_V5_HEAD(_headPitch, _headYaw);
}




/*
#if __cplusplus 201703L
std::optional<RelativeCoordinate> GU::NaoV5::topCameraRelativeCoordinate(const GU::CameraCoordinate & coord)
{
    return coord.relativeCoordinate(*this, NAO_V5_TOP_CAMERA_INDEX);
}

std::optional<RelativeCoordinate> GU::NaoV5::topCameraRelativeCoordinate(const GU::PixelCoordinate & coord)
{
    return coord.relativeCoordinate(*this, NAO_V5_TOP_CAMERA_INDEX);
}

std::optional<RelativeCoordinate> topCameraRelativeCoordinate(const GU::PercentCoordinate & coord)
{
    return coord.relativeCoordinate(*this, NAO_V5_TOP_CAMERA_INDEX);
}

std::optional<RelativeCoordinate> bottomCameraRelativeCoordinate(const GU::CameraCoordinate & coord)
{
    return coord.relativeCoordinate(*this, NAO_V5_BOTTOM_CAMERA_INDEX);
}

std::optional<RelativeCoordinate> bottomCameraRelativeCoordinate(const GU::PixelCoordinate & coord)
{
    return coord.relativeCoordinate(*this, NAO_V5_BOTTOM_CAMERA_INDEX);
}

std::optional<RelativeCoordinate> bottomCameraRelativeCoordinate(const GU::PercentCoordinate & coord)
{
    return coord.relativeCoordinate(*this, NAO_V5_BOTTOM_CAMERA_INDEX);
}
#endif
*/
