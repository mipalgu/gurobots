/*
 * SoccerLocations.cc 
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

#include "SoccerLocations.hpp"

GU::SoccerLocations::SoccerLocations() {}

GU::SoccerLocations::SoccerLocations(const GU::OptionalRelativeCoordinate t_rawBall, const GU::OptionalRelativeCoordinate t_rawLeftGoalPost, const GU::OptionalRelativeCoordinate t_rawRightGoalPost, const GU::OptionalRelativeCoordinate t_rawGoal)
{
    set_rawBall(t_rawBall);
    set_rawLeftGoalPost(t_rawLeftGoalPost);
    set_rawRightGoalPost(t_rawRightGoalPost);
    set_rawGoal(t_rawGoal);
}

#if __cplusplus >= 201703L
GU::SoccerLocations::SoccerLocations(const std::optional<GU::RelativeCoordinate> t_ball, const std::optional<GU::RelativeCoordinate> t_leftGoalPost, const std::optional<GU::RelativeCoordinate> t_rightGoalPost, const std::optional<GU::RelativeCoordinate> t_goal)
{
    set_ball(t_ball);
    set_leftGoalPost(t_leftGoalPost);
    set_rightGoalPost(t_rightGoalPost);
    set_goal(t_goal);
}
#endif

GU::SoccerLocations::SoccerLocations(const GU::SoccerLocations& other)
{
    set_rawBall(other.rawBall());
    set_rawLeftGoalPost(other.rawLeftGoalPost());
    set_rawRightGoalPost(other.rawRightGoalPost());
    set_rawGoal(other.rawGoal());
}

GU::SoccerLocations::SoccerLocations(const gu_soccer_locations &other)
{
    set_rawBall(other.ball);
    set_rawLeftGoalPost(other.leftGoalPost);
    set_rawRightGoalPost(other.rightGoalPost);
    set_rawGoal(other.goal);
}

#if __cplusplus >= 201103L
GU::SoccerLocations::SoccerLocations(GU::SoccerLocations&& other)
{
    set_rawBall(other.rawBall());
    other.set_rawBall(GU::OptionalRelativeCoordinate());
    set_rawLeftGoalPost(other.rawLeftGoalPost());
    other.set_rawLeftGoalPost(GU::OptionalRelativeCoordinate());
    set_rawRightGoalPost(other.rawRightGoalPost());
    other.set_rawRightGoalPost(GU::OptionalRelativeCoordinate());
    set_rawGoal(other.rawGoal());
    other.set_rawGoal(GU::OptionalRelativeCoordinate());
}
#endif

GU::SoccerLocations::~SoccerLocations() {}

GU::SoccerLocations& GU::SoccerLocations::operator=(const GU::SoccerLocations& other)
{
    if (&other == this)
    {
        return *this;
    }
    set_rawBall(other.rawBall());
    set_rawLeftGoalPost(other.rawLeftGoalPost());
    set_rawRightGoalPost(other.rawRightGoalPost());
    set_rawGoal(other.rawGoal());
    return *this;
}

GU::SoccerLocations& GU::SoccerLocations::operator=(const gu_soccer_locations& other)
{
    if (&other == this)
    {
        return *this;
    }
    set_rawBall(other.ball);
    set_rawLeftGoalPost(other.leftGoalPost);
    set_rawRightGoalPost(other.rightGoalPost);
    set_rawGoal(other.goal);
    return *this;
}

#if __cplusplus >= 201103L
GU::SoccerLocations& GU::SoccerLocations::operator=(GU::SoccerLocations&& other)
{
    if (&other == this)
    {
        return *this;
    }
    set_rawBall(other.rawBall());
    other.set_rawBall(GU::OptionalRelativeCoordinate());
    set_rawLeftGoalPost(other.rawLeftGoalPost());
    other.set_rawLeftGoalPost(GU::OptionalRelativeCoordinate());
    set_rawRightGoalPost(other.rawRightGoalPost());
    other.set_rawRightGoalPost(GU::OptionalRelativeCoordinate());
    set_rawGoal(other.rawGoal());
    other.set_rawGoal(GU::OptionalRelativeCoordinate());
    return *this;
}
#endif

GU::OptionalRelativeCoordinate GU::SoccerLocations::rawBall() const
{
    return gu_soccer_locations::ball;
}

void GU::SoccerLocations::set_rawBall(const GU::OptionalRelativeCoordinate newValue)
{
    gu_soccer_locations::ball = newValue;
}

GU::OptionalRelativeCoordinate GU::SoccerLocations::rawLeftGoalPost() const
{
    return gu_soccer_locations::leftGoalPost;
}

void GU::SoccerLocations::set_rawLeftGoalPost(const GU::OptionalRelativeCoordinate newValue)
{
    gu_soccer_locations::leftGoalPost = newValue;
}

GU::OptionalRelativeCoordinate GU::SoccerLocations::rawRightGoalPost() const
{
    return gu_soccer_locations::rightGoalPost;
}

void GU::SoccerLocations::set_rawRightGoalPost(const GU::OptionalRelativeCoordinate newValue)
{
    gu_soccer_locations::rightGoalPost = newValue;
}

GU::OptionalRelativeCoordinate GU::SoccerLocations::rawGoal() const
{
    return gu_soccer_locations::goal;
}

void GU::SoccerLocations::set_rawGoal(const GU::OptionalRelativeCoordinate newValue)
{
    gu_soccer_locations::goal = newValue;
}

#if __cplusplus >= 201703L
std::optional<GU::RelativeCoordinate> GU::SoccerLocations::ball() const
{
    return GU::OptionalRelativeCoordinate(gu_soccer_locations::ball).asOptional();
}

void GU::SoccerLocations::set_ball(const std::optional<GU::RelativeCoordinate> newValue)
{
    gu_soccer_locations::ball = GU::OptionalRelativeCoordinate(newValue);
}

std::optional<GU::RelativeCoordinate> GU::SoccerLocations::leftGoalPost() const
{
    return GU::OptionalRelativeCoordinate(gu_soccer_locations::leftGoalPost).asOptional();
}

void GU::SoccerLocations::set_leftGoalPost(const std::optional<GU::RelativeCoordinate> newValue)
{
    gu_soccer_locations::leftGoalPost = GU::OptionalRelativeCoordinate(newValue);
}

std::optional<GU::RelativeCoordinate> GU::SoccerLocations::rightGoalPost() const
{
    return GU::OptionalRelativeCoordinate(gu_soccer_locations::rightGoalPost).asOptional();
}

void GU::SoccerLocations::set_rightGoalPost(const std::optional<GU::RelativeCoordinate> newValue)
{
    gu_soccer_locations::rightGoalPost = GU::OptionalRelativeCoordinate(newValue);
}

std::optional<GU::RelativeCoordinate> GU::SoccerLocations::goal() const
{
    return GU::OptionalRelativeCoordinate(gu_soccer_locations::goal).asOptional();
}

void GU::SoccerLocations::set_goal(const std::optional<GU::RelativeCoordinate> newValue)
{
    gu_soccer_locations::goal = GU::OptionalRelativeCoordinate(newValue);
}
#endif

