/*
 * PitchRollJoint.cc 
 * gurobots 
 *
 * Created by Callum McColl on 27/07/2020.
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

#include "PitchRollJoint.hpp"

GU::PitchRollJoint::PitchRollJoint() {}

GU::PitchRollJoint::PitchRollJoint(const degrees_f t_pitch, const degrees_f t_roll)
{
    set_pitch(t_pitch);
    set_roll(t_roll);
}

GU::PitchRollJoint::PitchRollJoint(const GU::PitchRollJoint& other)
{
    set_pitch(other.pitch());
    set_roll(other.roll());
}

GU::PitchRollJoint::PitchRollJoint(const gu_pitch_roll_joint &other)
{
    set_pitch(other.pitch);
    set_roll(other.roll);
}

#if __cplusplus >= 201103L
GU::PitchRollJoint::PitchRollJoint(GU::PitchRollJoint&& other)
{
    set_pitch(other.pitch());
    other.set_pitch(0.0f);
    set_roll(other.roll());
    other.set_roll(0.0f);
}
#endif

GU::PitchRollJoint::~PitchRollJoint() {}

GU::PitchRollJoint& GU::PitchRollJoint::operator=(const GU::PitchRollJoint& other)
{
    if (&other == this)
    {
        return *this;
    }
    set_pitch(other.pitch());
    set_roll(other.roll());
    return *this;
}

GU::PitchRollJoint& GU::PitchRollJoint::operator=(const gu_pitch_roll_joint& other)
{
    if (&other == this)
    {
        return *this;
    }
    set_pitch(other.pitch);
    set_roll(other.roll);
    return *this;
}

#if __cplusplus >= 201103L
GU::PitchRollJoint& GU::PitchRollJoint::operator=(GU::PitchRollJoint&& other)
{
    if (&other == this)
    {
        return *this;
    }
    set_pitch(other.pitch());
    other.set_pitch(0.0f);
    set_roll(other.roll());
    other.set_roll(0.0f);
    return *this;
}
#endif

degrees_f GU::PitchRollJoint::pitch() const
{
    return gu_pitch_roll_joint::pitch;
}

void GU::PitchRollJoint::set_pitch(const degrees_f newValue)
{
    gu_pitch_roll_joint::pitch = newValue;
}

degrees_f GU::PitchRollJoint::roll() const
{
    return gu_pitch_roll_joint::roll;
}

void GU::PitchRollJoint::set_roll(const degrees_f newValue)
{
    gu_pitch_roll_joint::roll = newValue;
}
