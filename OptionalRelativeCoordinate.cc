/*
 * OptionalRelativeCoordinate.cc 
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

#include "OptionalRelativeCoordinate.hpp"

GU::OptionalRelativeCoordinate::OptionalRelativeCoordinate() {}

GU::OptionalRelativeCoordinate::OptionalRelativeCoordinate(const bool canSee, const GU::RelativeCoordinate coordinate)
{
    set_canSee(canSee);
    set_coordinate(coordinate);
}

GU::OptionalRelativeCoordinate::OptionalRelativeCoordinate(const GU::OptionalRelativeCoordinate& other)
{
    set_canSee(other.canSee());
    set_coordinate(other.coordinate());
}

GU::OptionalRelativeCoordinate::OptionalRelativeCoordinate(const gu_optional_relative_coordinate &other)
{
    set_canSee(other.canSee);
    set_coordinate(other.coordinate);
}

#if __cplusplus >= 201103L
GU::OptionalRelativeCoordinate::OptionalRelativeCoordinate(GU::OptionalRelativeCoordinate&& other)
{
    set_canSee(other.canSee());
    other.set_canSee(0.0f);
    set_coordinate(other.coordinate());
    other.set_coordinate(GU::RelativeCoordinate());
}
#endif

GU::OptionalRelativeCoordinate::~OptionalRelativeCoordinate() {}

GU::OptionalRelativeCoordinate& GU::OptionalRelativeCoordinate::operator=(const GU::OptionalRelativeCoordinate& other)
{
    if (&other == this)
    {
        return *this;
    }
    set_canSee(other.canSee());
    set_coordinate(other.coordinate());
    return *this;
}

GU::OptionalRelativeCoordinate& GU::OptionalRelativeCoordinate::operator=(const gu_optional_relative_coordinate& other)
{
    if (&other == this)
    {
        return *this;
    }
    set_canSee(other.canSee);
    set_coordinate(other.coordinate);
    return *this;
}

#if __cplusplus >= 201103L
GU::OptionalRelativeCoordinate& GU::OptionalRelativeCoordinate::operator=(GU::OptionalRelativeCoordinate&& other)
{
    if (&other == this)
    {
        return *this;
    }
    set_canSee(other.canSee());
    other.set_canSee(false);
    set_coordinate(other.coordinate());
    other.set_coordinate(GU::RelativeCoordinate());
    return *this;
}
#endif

bool GU::OptionalRelativeCoordinate::canSee() const
{
    return gu_optional_relative_coordinate::canSee;
}

void GU::OptionalRelativeCoordinate::set_canSee(const bool newValue)
{
    gu_optional_relative_coordinate::canSee = newValue;
}

GU::RelativeCoordinate GU::OptionalRelativeCoordinate::coordinate() const
{
    return gu_optional_relative_coordinate::coordinate;
}

void GU::OptionalRelativeCoordinate::set_coordinate(const GU::RelativeCoordinate newValue)
{
    gu_optional_relative_coordinate::coordinate = newValue;
}
