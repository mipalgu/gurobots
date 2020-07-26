/*
 * SoccerSightings.cc 
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

#include "SoccerSightings.hpp"

GU::SoccerSightings::SoccerSightings() {}

GU::SoccerSightings::SoccerSightings(const GU::OptionalRelativeCoordinate t_rawBall, const GU::OptionalRelativeCoordinate t_rawLeftGoalPost, const GU::OptionalRelativeCoordinate t_rawRightGoalPost, const GU::OptionalRelativeCoordinate t_rawGoal)
{
    set_rawBall(t_rawBall);
    set_rawLeftGoalPost(t_rawLeftGoalPost);
    set_rawRightGoalPost(t_rawRightGoalPost);
    set_rawGoal(t_rawGoal);
}

#if __cplusplus >= 201703L
GU::SoccerSightings::SoccerSightings(const std::optional<GU::RelativeCoordinate> t_ball, const std::optional<GU::RelativeCoordinate> t_leftGoalPost, const std::optional<GU::RelativeCoordinate> t_rightGoalPost, const std::optional<GU::RelativeCoordinate> t_goal)
{
    set_ball(t_ball);
    set_leftGoalPost(t_leftGoalPost);
    set_rightGoalPost(t_rightGoalPost);
    set_goal(t_goal);
}
#endif

GU::SoccerSightings::SoccerSightings(const GU::SoccerSightings& other)
{
    set_rawBall(other.rawBall());
    set_rawLeftGoalPost(other.rawLeftGoalPost());
    set_rawRightGoalPost(other.rawRightGoalPost());
    set_rawGoal(other.rawGoal());
}

GU::SoccerSightings::SoccerSightings(const gu_soccer_sightings &other)
{
    set_rawBall(other.ball);
    set_rawLeftGoalPost(other.leftGoalPost);
    set_rawRightGoalPost(other.rightGoalPost);
    set_rawGoal(other.goal);
}

#if __cplusplus >= 201103L
GU::SoccerSightings::SoccerSightings(GU::SoccerSightings&& other)
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

GU::SoccerSightings::~SoccerSightings() {}

GU::SoccerSightings& GU::SoccerSightings::operator=(const GU::SoccerSightings& other)
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

GU::SoccerSightings& GU::SoccerSightings::operator=(const gu_soccer_sightings& other)
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
GU::SoccerSightings& GU::SoccerSightings::operator=(GU::SoccerSightings&& other)
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

GU::OptionalRelativeCoordinate GU::SoccerSightings::rawBall() const
{
    return gu_soccer_sightings::ball;
}

void GU::SoccerSightings::set_rawBall(const GU::OptionalRelativeCoordinate newValue)
{
    gu_soccer_sightings::ball = newValue;
}

GU::OptionalRelativeCoordinate GU::SoccerSightings::rawLeftGoalPost() const
{
    return gu_soccer_sightings::leftGoalPost;
}

void GU::SoccerSightings::set_rawLeftGoalPost(const GU::OptionalRelativeCoordinate newValue)
{
    gu_soccer_sightings::leftGoalPost = newValue;
}

GU::OptionalRelativeCoordinate GU::SoccerSightings::rawRightGoalPost() const
{
    return gu_soccer_sightings::rightGoalPost;
}

void GU::SoccerSightings::set_rawRightGoalPost(const GU::OptionalRelativeCoordinate newValue)
{
    gu_soccer_sightings::rightGoalPost = newValue;
}

GU::OptionalRelativeCoordinate GU::SoccerSightings::rawGoal() const
{
    return gu_soccer_sightings::goal;
}

void GU::SoccerSightings::set_rawGoal(const GU::OptionalRelativeCoordinate newValue)
{
    gu_soccer_sightings::goal = newValue;
}

#if __cplusplus >= 201703L
std::optional<GU::RelativeCoordinate> GU::SoccerSightings::ball() const
{
    return GU::OptionalRelativeCoordinate(gu_soccer_sightings::ball).asOptional();
}

void GU::SoccerSightings::set_ball(const std::optional<GU::RelativeCoordinate> newValue)
{
    gu_soccer_sightings::ball = GU::OptionalRelativeCoordinate(newValue);
}

std::optional<GU::RelativeCoordinate> GU::SoccerSightings::leftGoalPost() const
{
    return GU::OptionalRelativeCoordinate(gu_soccer_sightings::leftGoalPost).asOptional();
}

void GU::SoccerSightings::set_leftGoalPost(const std::optional<GU::RelativeCoordinate> newValue)
{
    gu_soccer_sightings::leftGoalPost = GU::OptionalRelativeCoordinate(newValue);
}

std::optional<GU::RelativeCoordinate> GU::SoccerSightings::rightGoalPost() const
{
    return GU::OptionalRelativeCoordinate(gu_soccer_sightings::rightGoalPost).asOptional();
}

void GU::SoccerSightings::set_rightGoalPost(const std::optional<GU::RelativeCoordinate> newValue)
{
    gu_soccer_sightings::rightGoalPost = GU::OptionalRelativeCoordinate(newValue);
}

std::optional<GU::RelativeCoordinate> GU::SoccerSightings::goal() const
{
    return GU::OptionalRelativeCoordinate(gu_soccer_sightings::goal).asOptional();
}

void GU::SoccerSightings::set_goal(const std::optional<GU::RelativeCoordinate> newValue)
{
    gu_soccer_sightings::goal = GU::OptionalRelativeCoordinate(newValue);
}
#endif

