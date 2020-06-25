/*
 * robot_tests.cc 
 * tests 
 *
 * Created by Callum McColl on 18/06/2020.
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

#include "gurobots_tests.hpp"

#include <stdbool.h>

namespace CGTEST {
    
    class RobotTests: public GURobotsTests {};

    TEST_F(RobotTests, Equality) {
        const gu_robot nao = GU_NAO_V5_ROBOT(0.0f, 0.0f, 0, 0, 0);
        const gu_robot pepper = GU_PEPPER_ROBOT(0.0f, 0.0f, 0, 0, 0);

        gu_camera_pivot_equals_fake.return_val = true;
        gu_field_coordinate_equals_fake.return_val = true;
        ASSERT_TRUE(gu_robot_equals(nao, nao, 0.0001f));
        ASSERT_EQ(gu_camera_pivot_equals_fake.call_count, 1);
        equals(gu_camera_pivot_equals_fake.arg0_val, nao.head);
        equals(gu_camera_pivot_equals_fake.arg1_val, nao.head);
        assert_near(gu_camera_pivot_equals_fake.arg2_val, 0.0001f, 0.00001f);
        ASSERT_EQ(gu_field_coordinate_equals_fake.call_count, 1);
        equals(gu_field_coordinate_equals_fake.arg0_val, nao.position);
        equals(gu_field_coordinate_equals_fake.arg1_val, nao.position);
        gu_camera_pivot_equals_reset();
        gu_field_coordinate_equals_reset();

        gu_camera_pivot_equals_fake.return_val = true;
        gu_field_coordinate_equals_fake.return_val = true;
        ASSERT_TRUE(gu_robot_equals(pepper, pepper, 0.0001f));
        ASSERT_EQ(gu_camera_pivot_equals_fake.call_count, 1);
        equals(gu_camera_pivot_equals_fake.arg0_val, pepper.head);
        equals(gu_camera_pivot_equals_fake.arg1_val, pepper.head);
        assert_near(gu_camera_pivot_equals_fake.arg2_val, 0.0001f, 0.00001f);
        ASSERT_EQ(gu_field_coordinate_equals_fake.call_count, 1);
        equals(gu_field_coordinate_equals_fake.arg0_val, pepper.position);
        equals(gu_field_coordinate_equals_fake.arg1_val, pepper.position);
        gu_camera_pivot_equals_reset();
        gu_field_coordinate_equals_reset();

        gu_camera_pivot_equals_fake.return_val = true;
        gu_field_coordinate_equals_fake.return_val = true;
        ASSERT_TRUE(gu_robot_equals(nao, pepper, 0.0001f));
        ASSERT_EQ(gu_camera_pivot_equals_fake.call_count, 1);
        equals(gu_camera_pivot_equals_fake.arg0_val, nao.head);
        equals(gu_camera_pivot_equals_fake.arg1_val, pepper.head);
        assert_near(gu_camera_pivot_equals_fake.arg2_val, 0.0001f, 0.00001f);
        ASSERT_EQ(gu_field_coordinate_equals_fake.call_count, 1);
        equals(gu_field_coordinate_equals_fake.arg0_val, nao.position);
        equals(gu_field_coordinate_equals_fake.arg1_val, pepper.position);
        gu_camera_pivot_equals_reset();
        gu_field_coordinate_equals_reset();
    }

}  // namespace
