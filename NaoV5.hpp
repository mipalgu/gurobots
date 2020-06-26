/*
 * NaoV5.hpp
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

#ifndef NAO_V5_HPP
#define NAO_V5_HPP

#include "robot.h"

#include "gucoordinates/gucoordinates.h"
#include <cstdlib>

#include <guunits/guunits.h>
#include <gusimplewhiteboard/gusimplewhiteboard.h>

#ifdef __cpp_lib_optional
#include <optional>
#endif

namespace GU {

    struct NaoV5: public gu_robot {

    private:
        gu_simple_whiteboard *wb;

        degrees_f lShoulderPitch_;
        degrees_f lShoulderRoll_;
        degrees_f lElbowYaw_;
        degrees_f lElbowRoll_;
        degrees_f rShoulderPitch_;
        degrees_f rShoulderRoll_;
        degrees_f rElbowYaw_;
        degrees_f rElbowRoll_;
        degrees_f lWristYaw_;
        degrees_f rWristYaw_;

        bool lHandTouchLeft_;
        bool lHandTouchBack_;
        bool lHandTouchRight_;
        bool rHandTouchLeft_;
        bool rHandTouchBack_;
        bool rHandTouchRight_;

    protected:
        void set_headPitch(const degrees_f);
        void set_headYaw(const degrees_f);
    
    public:
        NaoV5();
        NaoV5(gu_simple_whiteboard *wb);
        NaoV5(const NaoV5& other);
#if __cplusplus >= 201103L
        NaoV5(NaoV5&& other);
#endif
        ~NaoV5();
        NaoV5& operator=(const NaoV5& other);
#if __cplusplus >= 201103L
        NaoV5& operator=(NaoV5&& other);
#endif

        GU::CameraPivot head() const;

        degrees_f headPitch() const;
        degrees_f headYaw() const;
        degrees_f leftShoulderPitch() const;
        degrees_f leftShoulderRoll() const;
        degrees_f leftElbowYaw() const;
        degrees_f leftElbowRoll() const;
        degrees_f rightShoulderPitch() const;
        degrees_f rightShoulderRoll() const;
        degrees_f rightElbowYaw() const;
        degrees_f rightElbowRoll() const;
        degrees_f leftWristYaw() const;
        degrees_f rightWristYaw() const;

        bool leftHandTouchLeft() const;
        bool leftHandTouchBack() const;
        bool leftHandTouchRight() const;
        bool rightHandTouchLeft() const;
        bool rightHandTouchBack() const;
        bool rightHandTouchRight() const;

        void update();

/*
#ifdef __cpp_lib_optional
        std::optional<RelativeCoordinate> topCameraRelativeCoordinate(const GU::CameraCoordinate &);
        std::optional<RelativeCoordinate> topCameraRelativeCoordinate(const GU::PixelCoordinate &);
        std::optional<RelativeCoordinate> topCameraRelativeCoordinate(const GU::PercentCoordinate &);
        std::optional<RelativeCoordinate> bottomCameraRelativeCoordinate(const GU::CameraCoordinate &);
        std::optional<RelativeCoordinate> bottomCameraRelativeCoordinate(const GU::PixelCoordinate &);
        std::optional<RelativeCoordinate> bottomCameraRelativeCoordinate(const GU::PercentCoordinate &);
#endif
*/

    };

}



#endif /* NAO_V5_HPP */
