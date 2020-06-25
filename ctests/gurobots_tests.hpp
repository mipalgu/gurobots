/*
 * gucoordinates_tests.hpp 
 * ctests 
 *
 * Created by Callum McColl on 23/06/2020.
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

#ifndef GUROBOTS_TESTS_HPP
#define GUROBOTS_TESTS_HPP

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wzero-as-null-pointer-constant"
#pragma clang diagnostic ignored "-Wfloat-equal"
#pragma clang diagnostic ignored "-Wsign-compare"
#pragma clang diagnostic ignored "-Wmissing-noreturn"
#pragma clang diagnostic ignored "-Wshift-sign-overflow"
#pragma clang diagnostic ignored "-Wused-but-marked-unused"
#pragma clang diagnostic ignored "-Wundef"
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#pragma clang diagnostic ignored "-Wc++11-long-long"
#pragma clang diagnostic ignored "-Wc++11-extensions"
#pragma clang diagnostic ignored "-Wdeprecated"
#include <gtest/gtest.h>
#pragma clang diagnostic pop

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#include "fff.h"
#pragma clang diagnostic pop

#include "../gurobots.h"
#include "fakes.h"
#include "custom_fakes.h"

#include <math.h>

namespace CGTEST {

    class GURobotsTests: public ::testing::Test {
        protected:

        virtual void SetUp() {
            ALL_FAKES(RESET_FAKE);
            FFF_RESET_HISTORY();
        }

        virtual void TearDown() {
            ALL_FAKES(RESET_FAKE);
            FFF_RESET_HISTORY();
        }

        bool near(const float lhs, const float rhs) const
        {
            const float tolerance = 0.00001f;
            return fabsf(lhs - rhs) < tolerance;
        }

        void assert_near(const float lhs, const float rhs, const float tolerance) const
        {
            ASSERT_LE(fabsf(lhs - rhs), tolerance);
        }

        void equals(const gu_camera_pivot lhs, const gu_camera_pivot rhs)
        {
            ASSERT_TRUE(near(lhs.headPitch, rhs.headPitch));
            ASSERT_TRUE(near(lhs.headYaw, rhs.headYaw));
            ASSERT_EQ(lhs.numCameras, rhs.numCameras);
            for (int i = 0; i < lhs.numCameras; i++)
            {
                const gu_camera lcamera = lhs.cameras[i];
                const gu_camera rcamera = rhs.cameras[i];
                assert_near(lcamera.height, rcamera.height, 0.0001f);
                assert_near(lcamera.height, rcamera.height, 0.0001f);
                assert_near(lcamera.centerOffset, rcamera.centerOffset, 0.0001f);
                assert_near(lcamera.vDirection, rcamera.vDirection, 0.0001f);
                assert_near(lcamera.vFov, rcamera.vFov, 0.0001f);
                assert_near(lcamera.hFov, rcamera.hFov, 0.0001f);
                assert_near(lhs.cameraHeightOffsets[i], rhs.cameraHeightOffsets[i], 0.0001f);
            }
        }

        void nequals(const gu_camera_pivot lhs, const gu_camera_pivot rhs)
        {
            if (!(near(lhs.headPitch, rhs.headPitch)
                    && near(lhs.headYaw, rhs.headYaw)
                    && near(lhs.numCameras, rhs.numCameras)
               ))
            {
                ASSERT_FALSE(near(lhs.headPitch, rhs.headPitch)
                    && near(lhs.headYaw, rhs.headYaw)
                    && near(lhs.numCameras, rhs.numCameras)
                    );
                return;
            }
            for (int i = 0; i < lhs.numCameras; i++)
            {
                const gu_camera lcamera = lhs.cameras[i];
                const gu_camera rcamera = rhs.cameras[i];
                ASSERT_FALSE(
                        near(lcamera.height, rcamera.height)
                        && near(lcamera.centerOffset,rcamera.centerOffset)
                        && near(lcamera.vDirection, rcamera.vDirection)
                        && near(lcamera.vFov, rcamera.vFov)
                        && near(lcamera.hFov, rcamera.hFov)
                        && near(lhs.cameraHeightOffsets[i], rhs.cameraHeightOffsets[i])
                        );
            }
        }

        void equals(const gu_cartesian_coordinate lhs, const gu_cartesian_coordinate rhs)
        {
            ASSERT_EQ(lhs.x, rhs.x);
            ASSERT_EQ(lhs.y, rhs.y);
        }

        void nequals(const gu_cartesian_coordinate lhs, const gu_cartesian_coordinate rhs)
        {
            ASSERT_FALSE(lhs.x == rhs.x && lhs.y == rhs.y);
        }

        void equals(const gu_field_coordinate lhs, const gu_field_coordinate rhs)
        {
            equals(lhs.position, rhs.position);
            ASSERT_EQ(lhs.heading, rhs.heading);
        }

        void nequals(const gu_field_coordinate lhs, const gu_field_coordinate rhs)
        {
            ASSERT_FALSE(
                    lhs.position.x == rhs.position.x
                    && lhs.position.y == rhs.position.y
                    && lhs.heading == rhs.heading
                );
        }

    };

}

#endif  /* GUROBOTS_TESTS_HPP */
