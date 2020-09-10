/*
 * soccer_sightings.c 
 * gurobots 
 *
 * Created by Callum McColl on 10/09/2020.
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

#include "soccer_sightings.h"

bool gu_soccer_sightings_equals(const gu_soccer_sightings lhs, const gu_soccer_sightings rhs)
{
    if (lhs.numLines != rhs.numLines || lhs.numCorners != rhs.numCorners || lhs.numTIntersections != rhs.numTIntersections || lhs.numCrosses != rhs.numCrosses) return false;
    const bool simpleEquals = gu_optional_ellipse_sighting_equals(lhs.ball, rhs.ball)
        && gu_optional_rectangle_sighting_equals(lhs.genericPost, rhs.genericPost)
        && gu_optional_rectangle_sighting_equals(lhs.leftGoalPost, rhs.leftGoalPost)
        && gu_optional_rectangle_sighting_equals(lhs.rightGoalPost, rhs.rightGoalPost)
        && gu_optional_rectangle_sighting_equals(lhs.crossbar, rhs.crossbar);
    if (!simpleEquals) return false;
    for (int i = 0; i < lhs.numLines; i++)
    {
        if (!(gu_line_sighting_equals(lhs.lines[i], rhs.lines[i]))) return false;
    }
    for (int i = 0; i < lhs.numCorners; i++)
    {
        if (!(gu_pixel_coordinate_equals(lhs.lineCorners[i], rhs.lineCorners[i]))) return false;
    }
    for (int i = 0; i < lhs.numTIntersections; i++)
    {
        if (!(gu_pixel_coordinate_equals(lhs.lineTIntersections[i], rhs.lineTIntersections[i]))) return false;
    }
    for (int i = 0; i < lhs.numCrosses; i++)
    {
        if (!(gu_pixel_coordinate_equals(lhs.lineCrosses[i], rhs.lineCrosses[i]))) return false;
    }
    return true;
}

void gu_soccer_sightings_update_from_wb_vision_detection_goal(gu_soccer_sightings *sightings, const struct wb_vision_detection_goal goal, const uint16_t resWidth, const uint16_t resHeight)
{
    sightings->genericPost.has_value = false;
    sightings->leftGoalPost.has_value = false;
    sightings->rightGoalPost.has_value = false;
    if (goal.sightingType == NoGoalDetected) return;
    if (goal.post1.sightingType != NoPostDetected)
    {
        switch (goal.post1.sightingType)
        {
            case GenericPost:
                sightings->genericPost = wb_vision_detection_goal_post_to_opt_rectangle_sighting(goal.post1, resWidth, resHeight);
                break;
            case LeftPost:
                sightings->leftGoalPost = wb_vision_detection_goal_post_to_opt_rectangle_sighting(goal.post1, resWidth, resHeight);
                break;
            case RightPost:
                sightings->rightGoalPost = wb_vision_detection_goal_post_to_opt_rectangle_sighting(goal.post1, resWidth, resHeight);
                break;
        }
    }
    if (goal.post2.sightingType != NoPostDetected && goal.sightingType == DoublePostGoal)
    {
        switch (goal.post2.sightingType)
        {
            case GenericPost:
                sightings->genericPost = wb_vision_detection_goal_post_to_opt_rectangle_sighting(goal.post2, resWidth, resHeight);
                break;
            case LeftPost:
                sightings->leftGoalPost = wb_vision_detection_goal_post_to_opt_rectangle_sighting(goal.post2, resWidth, resHeight);
                break;
            case RightPost:
                sightings->rightGoalPost = wb_vision_detection_goal_post_to_opt_rectangle_sighting(goal.post2, resWidth, resHeight);
                break;
        }
    }
}
