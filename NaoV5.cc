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
    update();
}

GU::NaoV5::NaoV5(gu_simple_whiteboard *t_wb)
{
    wb = t_wb;
    update();
}

GU::NaoV5::NaoV5(const NaoV5& other)
{
    wb = other.wb;
    const gu_nao temp = other;
    gu_nao::fieldPosition = temp.fieldPosition;
    gu_nao::joints = temp.joints;
    gu_nao::sightings = temp.sightings;
}

#if __cplusplus >= 201103L
GU::NaoV5::NaoV5(NaoV5&& other) {
    wb = other.wb;
    const gu_nao temp = other;
    gu_nao::fieldPosition = temp.fieldPosition;
    gu_nao::joints = temp.joints;
    gu_nao::sightings = temp.sightings;
    gu_nao_empty(&other);
    other.wb = wb;
}
#endif

GU::NaoV5::~NaoV5() {}

GU::NaoV5& GU::NaoV5::operator=(const GU::NaoV5& other) {
    if (&other == this) {
        return *this;
    }
    const gu_nao temp = other;
    gu_nao::fieldPosition = temp.fieldPosition;
    gu_nao::joints = temp.joints;
    gu_nao::sightings = temp.sightings;
    return *this;
}

#if __cplusplus >= 201103L
GU::NaoV5& GU::NaoV5::operator=(GU::NaoV5&& other) {
    if (&other == this) {
        return *this;
    }
    wb = other.wb;
    const gu_nao temp = other;
    gu_nao::fieldPosition = temp.fieldPosition;
    gu_nao::joints = temp.joints;
    gu_nao::sightings = temp.sightings;
    gu_nao_empty(&other);
    other.wb = wb;
    return *this;
}
#endif

GU::CameraPivot GU::NaoV5::cameraPivot() const
{
    return gu_nao_head_to_camera_pivot(gu_nao::joints.head);
}

gu_nao_joints GU::NaoV5::joints() const
{
    return gu_nao::joints;
}

gu_nao_sightings GU::NaoV5::sightings() const
{
    return gu_nao::sightings;
}

bool GU::NaoV5::fieldPosition(GU::FieldCoordinate & coordinate) const
{
    if (!gu_nao::fieldPosition.hasCoordinate)
        return false;
    coordinate = gu_nao::fieldPosition.field_coordinate;
    return true;
}

#if __cplusplus >= 201703L
std::optional<GU::FieldCoordinate> GU::NaoV5::fieldPosition() const
{
    if (!gu_nao::fieldPosition.hasCoordinate)
        return std::nullopt;
    return std::optional<GU::FieldCoordinate>(gu_nao::fieldPosition.field_coordinate);
}
#endif

void GU::NaoV5::empty()
{
    gu_nao_empty(this);
}

void GU::NaoV5::update()
{
    gu_nao_update_from_wb(this, wb);
}
