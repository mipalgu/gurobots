/*
 * GUCoordinatesTests.hpp 
 * tests 
 *
 * Created by Callum McColl on 20/06/2020.
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

#ifndef GUCOORDINATESTESTS_HPP
#define GUCOORDINATESTESTS_HPP

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

#include "../gucoordinates.h"
#include "fakes.h"
#include "custom_fakes.h"

#include <typeinfo>

#include <math.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wglobal-constructors"

#define TEST2_F(testclassname, testname) \
    TEST_F(testclassname, testname)

#define RO3_TEST_F(className) \
    TEST2_F(testclassname(className), RO3) { \
        ro3_test(); \
    }

#if __cplusplus >= 201103L
#define RO5_TEST_Fs(className) \
    RO3_TEST_F(className) \
    TEST2_F(testclassname(className), RO5) { \
        ro5_test(); \
    }
#else
#define RO5_TEST_Fs(className) RO3_TEST_F(className)
#endif

#define testclassname(className) className##CPPTests
#define equals_reset(strctName) strctName##_equals_reset();
#define equals_func(strctName) strctName##_equals
#define equals_fake(strctName) strctName##_equals_fake

#pragma clang diagnostic pop

namespace CGTEST {

    template <typename Class>
    class GUCoordinatesTests: public ::testing::Test {
        private:

        protected:

            GU::Robot nao;
            GU::Camera topCamera;
            GU::Camera bottomCamera;

            virtual void SetUp() {
                ALL_FAKES(RESET_FAKE);
                FFF_RESET_HISTORY();
                nao = GU_NAO_V5_ROBOT(0.0f, 0.0f);
                topCamera = GU_NAO_V5_TOP_CAMERA;
                bottomCamera = GU_NAO_V5_BOTTOM_CAMERA;
            }

            virtual void TearDown() {
                ALL_FAKES(RESET_FAKE);
                FFF_RESET_HISTORY();
            }

            virtual void preamble() {}

            virtual Class initial() = 0;

            virtual void change(Class &) {}

            virtual Class empty() = 0;

            void ro3_test() {
                preamble();
                Class obj = initial();
#pragma clang diangostic push
#pragma clang diagnostic ignored "-Wself-assign"
                obj = obj;
#pragma clang diagnostic pop
                equals(obj, obj);
                Class obj2 = Class(obj);
                equals(obj, obj2);
                Class obj3 = obj2;
                equals(obj, obj3);
                change(obj);
                nequals(obj, obj3);
                equals(obj2, obj3);
                Class obj4;
                obj4 = obj3;
                equals(obj4, obj3);
                Class * obj5 = &obj4;
                equals(obj4, *obj5);
            }

#if __cplusplus >= 201103L
            void ro5_test() {
                Class obj = initial();
                Class obj2 = initial();
                Class obj3 = std::move(obj);
                nequals(obj3, obj);
                equals(obj3, obj2);
                equals(obj, empty());
                Class obj4;
                obj4 = std::move(obj3);
                nequals(obj4, obj3);
                equals(obj4, obj2);
                equals(obj3, empty());
                Class * obj5 = &obj4;
                obj4 = std::move(*obj5);
                nequals(obj4, obj3);
                equals(obj4, obj2);
                nequals(*obj5, obj3);
                equals(*obj5, obj2);
                equals(*obj5, obj4);
            }
#endif

            bool near(const float lhs, const float rhs) const
            {
                const float tolerance = 0.00001f;
                return fabsf(lhs - rhs) < tolerance;
            }

            void assert_near(const float lhs, const float rhs, const float tolerance) const
            {
                ASSERT_LE(fabsf(lhs - rhs), tolerance);
            }

            void equals(const GU::CameraCoordinate lhs, const GU::CameraCoordinate rhs)
            {
                ASSERT_EQ(lhs.x(), rhs.x());
                ASSERT_EQ(lhs.y(), rhs.y());
                ASSERT_EQ(lhs.resWidth(), rhs.resWidth());
                ASSERT_EQ(lhs.resHeight(), rhs.resHeight());
            }

            void nequals(const GU::CameraCoordinate lhs, const GU::CameraCoordinate rhs)
            {
                ASSERT_FALSE(lhs.x() == rhs.x()
                        && lhs.y() == rhs.y()
                        && lhs.resWidth() == rhs.resWidth()
                        && lhs.resHeight() == rhs.resHeight()
                        );
            }

            void equals(const GU::Camera lhs, const GU::Camera rhs)
            {
                ASSERT_TRUE(near(lhs.height(), rhs.height()));
                ASSERT_TRUE(near(lhs.centerOffset(), rhs.centerOffset()));
                ASSERT_TRUE(near(lhs.vDirection(), rhs.vDirection()));
                ASSERT_TRUE(near(lhs.vFov(), rhs.vFov()));
                ASSERT_TRUE(near(lhs.hFov(), rhs.hFov()));
            }

            void nequals(const GU::Camera lhs, const GU::Camera rhs)
            {
                ASSERT_FALSE(
                        near(lhs.height(), rhs.height())
                        && near(lhs.centerOffset(), rhs.centerOffset())
                        && near(lhs.vDirection(), rhs.vDirection())
                        && near(lhs.vFov(), rhs.vFov())
                        && near(lhs.hFov(), rhs.hFov())
                        );
            }

            void equals(const GU::PixelCoordinate lhs, const GU::PixelCoordinate rhs)
            {
                ASSERT_EQ(lhs.x(), rhs.x());
                ASSERT_EQ(lhs.y(), rhs.y());
                ASSERT_EQ(lhs.resWidth(), rhs.resWidth());
                ASSERT_EQ(lhs.resHeight(), rhs.resHeight());
            }

            void nequals(const GU::PixelCoordinate lhs, const GU::PixelCoordinate rhs)
            {
                ASSERT_FALSE(
                        lhs.x() == rhs.x()
                        && lhs.y() == rhs.y()
                        && lhs.resWidth() == rhs.resWidth()
                        && lhs.resHeight() == rhs.resHeight()
                    );
            }

            void equals(const GU::PercentCoordinate lhs, const GU::PercentCoordinate rhs)
            {
                ASSERT_TRUE(near(lhs.x(), rhs.x()));
                ASSERT_TRUE(near(lhs.y(), rhs.y()));
            }

            void nequals(const GU::PercentCoordinate lhs, const GU::PercentCoordinate rhs)
            {
                ASSERT_FALSE(
                        near(lhs.x(), rhs.x())
                        && near(lhs.y(), rhs.y())
                    );
            }

            void equals(const GU::RelativeCoordinate lhs, const GU::RelativeCoordinate rhs)
            {
                ASSERT_EQ(lhs.direction(), rhs.direction());
                ASSERT_EQ(lhs.distance(), rhs.distance());
            }

            void nequals(const GU::RelativeCoordinate lhs, const GU::RelativeCoordinate rhs)
            {
                ASSERT_FALSE(
                        lhs.direction() == rhs.direction()
                        && lhs.distance() == rhs.distance()
                    );
            }

            void equals(const GU::CartesianCoordinate lhs, const GU::CartesianCoordinate rhs)
            {
                ASSERT_EQ(lhs.x(), rhs.x());
                ASSERT_EQ(lhs.y(), rhs.y());
            }

            void nequals(const GU::CartesianCoordinate lhs, const GU::CartesianCoordinate rhs)
            {
                ASSERT_FALSE(lhs.x() == rhs.x() && lhs.y() == rhs.y());
            }

            void equals(const GU::FieldCoordinate lhs, const GU::FieldCoordinate rhs)
            {
                equals(lhs.position(), rhs.position());
                ASSERT_EQ(lhs.heading(), rhs.heading());
            }

            void nequals(const GU::FieldCoordinate lhs, const GU::FieldCoordinate rhs)
            {
                ASSERT_FALSE(
                        lhs.position().x() == rhs.position().x()
                        && lhs.position().y() == rhs.position().y()
                        && lhs.heading() == rhs.heading()
                    );
            }

            void equals(const GU::Robot lhs, const GU::Robot rhs)
            {
                ASSERT_TRUE(near(lhs.headPitch(), rhs.headPitch()));
                ASSERT_TRUE(near(lhs.headYaw(), rhs.headYaw()));
                ASSERT_EQ(lhs.numCameras(), rhs.numCameras());
                for (int i = 0; i < lhs.numCameras(); i++)
                {
                    const GU::Camera lcamera = lhs.camera(i);
                    const GU::Camera rcamera = rhs.camera(i);
                    ASSERT_TRUE(near(lcamera.height(), rcamera.height()));
                    ASSERT_TRUE(near(lcamera.centerOffset(), rcamera.centerOffset()));
                    ASSERT_TRUE(near(lcamera.vDirection(), rcamera.vDirection()));
                    ASSERT_TRUE(near(lcamera.vFov(), rcamera.vFov()));
                    ASSERT_TRUE(near(lcamera.hFov(), rcamera.hFov()));
                    ASSERT_TRUE(near(lhs.cameraHeightOffset(i), rhs.cameraHeightOffset(i)));
                }
            }

            void nequals(const GU::Robot lhs, const GU::Robot rhs)
            {
                if (!(near(lhs.headPitch(), rhs.headPitch())
                        && near(lhs.headYaw(), rhs.headYaw())
                        && near(lhs.numCameras(), rhs.numCameras())
                   ))
                {
                    ASSERT_FALSE(near(lhs.headPitch(), rhs.headPitch())
                        && near(lhs.headYaw(), rhs.headYaw())
                        && near(lhs.numCameras(), rhs.numCameras())
                        );
                    return;
                }
                for (int i = 0; i < lhs.numCameras(); i++)
                {
                    const GU::Camera lcamera = lhs.camera(i);
                    const GU::Camera rcamera = rhs.camera(i);
                    ASSERT_FALSE(
                            near(lcamera.height(), rcamera.height())
                            && near(lcamera.centerOffset(),rcamera.centerOffset())
                            && near(lcamera.vDirection(), rcamera.vDirection())
                            && near(lcamera.vFov(), rcamera.vFov())
                            && near(lcamera.hFov(), rcamera.hFov())
                            && near(lhs.cameraHeightOffset(i), rhs.cameraHeightOffset(i))
                            );
                }
            }

            void equals(const GU::NaoV5 lhs, const GU::NaoV5 rhs)
            {
                assert_near(lhs.headPitch(), rhs.headPitch(), 0.0001f);
                assert_near(lhs.headYaw(), rhs.headYaw(), 0.0001f);
            }

            void nequals(const GU::NaoV5 lhs, const GU::NaoV5 rhs)
            {
                ASSERT_FALSE(near(lhs.headPitch(), rhs.headPitch()) && near(lhs.headYaw(), rhs.headYaw()));
            }

    };

}

#endif  /* GUCOORDINATESTESTS_HPP */
