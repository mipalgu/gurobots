/*
 * SoccerLocations.hpp 
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

#ifndef GUROBOTS_SOCCERLOCATIONS_HPP
#define GUROBOTS_SOCCERLOCATIONS_HPP

#include "soccer_locations.h"

#include <guunits/guunits.h>
#include <gucoordinates/gucoordinates.h>

#include <cstdlib>

#if __cplusplus >= 201703L
#include <optional>
#endif

namespace GU {

    struct SoccerLocations: public gu_soccer_locations {

        SoccerLocations();
        SoccerLocations(const OptionalRelativeCoordinate, const OptionalRelativeCoordinate, const OptionalRelativeCoordinate, const OptionalRelativeCoordinate);
#if __cplusplus >= 201703L
        SoccerLocations(const std::optional<RelativeCoordinate>, const std::optional<RelativeCoordinate>, const std::optional<RelativeCoordinate>, const std::optional<RelativeCoordinate>);
#endif
        SoccerLocations(const SoccerLocations& other);
        SoccerLocations(const gu_soccer_locations& other);
#if __cplusplus >= 201103L
        SoccerLocations(SoccerLocations&& other);
#endif
        ~SoccerLocations();
        SoccerLocations& operator=(const SoccerLocations& other);
        SoccerLocations& operator=(const gu_soccer_locations& other);
#if __cplusplus >= 201103L
        SoccerLocations& operator=(SoccerLocations&& other);
#endif

        OptionalRelativeCoordinate rawBall() const;
        void set_rawBall(const OptionalRelativeCoordinate);
        
        OptionalRelativeCoordinate rawLeftGoalPost() const;
        void set_rawLeftGoalPost(const OptionalRelativeCoordinate);
        
        OptionalRelativeCoordinate rawRightGoalPost() const;
        void set_rawRightGoalPost(const OptionalRelativeCoordinate);
        
        OptionalRelativeCoordinate rawGoal() const;
        void set_rawGoal(const OptionalRelativeCoordinate);
        
#if __cplusplus >= 201703L
        std::optional<RelativeCoordinate> ball() const;
        void set_ball(const std::optional<RelativeCoordinate>);
        
        std::optional<RelativeCoordinate> leftGoalPost() const;
        void set_leftGoalPost(const std::optional<RelativeCoordinate>);
        
        std::optional<RelativeCoordinate> rightGoalPost() const;
        void set_rightGoalPost(const std::optional<RelativeCoordinate>);
        
        std::optional<RelativeCoordinate> goal() const;
        void set_goal(const std::optional<RelativeCoordinate>);
#endif

    };

}

#endif  /* GUROBOTS_SOCCERLOCATIONS_HPP */
