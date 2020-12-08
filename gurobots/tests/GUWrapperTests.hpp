/*
 * GUWrapperTests.hpp 
 * tests 
 *
 * Created by Callum McColl on 24/06/2020.
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

#ifndef GUWRAPPERTESTS_HPP
#define GUWRAPPERTESTS_HPP

#include "GUCoordinatesTests.hpp"

#define C_CONVERTIBLE_TEST_F(className) \
    TEST2_F(testclassname(className), ConvertibleToC) { \
        c_convertible_test(); \
    }

#define EQUALS_TEST_F(className, strctName) \
    TEST2_F(testclassname(className), Equality) { \
        equals_fake(strctName).return_val = true; \
        const GU::className obj = initial(); \
        const GU::className obj2 = empty(); \
        ASSERT_EQ(obj, obj); \
        ASSERT_EQ(equals_fake(strctName).call_count, 1); \
        equals_reset(strctName) \
        equals_fake(strctName).return_val = false; \
        ASSERT_NE(obj, obj2); \
        ASSERT_EQ(equals_fake(strctName).call_count, 1); \
        equals_reset(strctName) \
        equals_fake(strctName).return_val = true; \
        const GU::className obj3 = initial(); \
        const strctName obj4 = cempty(); \
        const strctName obj5 = obj; \
        ASSERT_EQ(obj3, obj5); \
        ASSERT_EQ(equals_fake(strctName).call_count, 1); \
        equals_reset(strctName) \
        equals_fake(strctName).return_val = false; \
        ASSERT_TRUE(obj3 != obj4); \
        ASSERT_EQ(equals_fake(strctName).call_count, 1); \
    }

#define TO_C_TEST_F(className, strctName) \
    TEST2_F(testclassname(className), TO_C) { \
        const GU::className obj = initial(); \
        const strctName converted = obj; \
        equals(obj, converted); \
    }

#define WRAPPER_TEST_Fs(className, strctName) \
    RO5_TEST_Fs(className) \
    C_CONVERTIBLE_TEST_F(className) \
    EQUALS_TEST_F(className, strctName) \
    TO_C_TEST_F(className, strctName)

#define GETTER_TEST_NAME_F(className, testName, resultType, call, get) \
    TEST2_F(testclassname(className), testName) {\
        const GU::resultType result = GU::resultType(call##_result); \
        call##_fake.return_val = result; \
        equals(initial().get, result); \
        ASSERT_EQ(call##_fake.call_count, 1); \
        call##_reset(); \
    }

#define GETTER_TEST_F(className, resultType, call, get) \
    GETTER_TEST_NAME_F(className, resultType, resultType, call, get)

#define GETTER_BOOL_TEST_NAME_F(className, testName, resultType, call, get) \
    TEST2_F(testclassname(className), testName) {\
        call##_fake.custom_fake = call##_custom_fake_true; \
        const GU::resultType result = GU::resultType(call##_custom_fake_result); \
        GU::resultType temp; \
        if (initial().get) \
        { \
            equals(temp, result); \
            ASSERT_EQ(call##_fake.call_count, 1); \
            call##_reset(); \
        } else { \
            FAIL() << "Result is false from initial().get"; \
        } \
        call##_fake.custom_fake = call##_custom_fake_false; \
        ASSERT_FALSE(initial().get); \
    }

#define GETTER_BOOL_TEST_F(className, resultType, call, get) \
    GETTER_BOOL_TEST_NAME_F(className, resultType##Bool, resultType, call, get)

#define GETTER_BOOL_IM_TEST_NAME_F(className, testName, resultType, failCall, resultCall, get) \
    TEST2_F(testclassname(className), testName) {\
        failCall##_fake.custom_fake = failCall##_custom_fake_true; \
        resultCall##_fake.return_val = resultCall##_result; \
        const GU::resultType result = GU::resultType(resultCall##_result); \
        GU::resultType temp; \
        if (initial().get) \
        { \
            equals(temp, result); \
            ASSERT_EQ(failCall##_fake.call_count, 1); \
            ASSERT_EQ(resultCall##_fake.call_count, 1); \
        } else { \
            FAIL() << "Result is false from initial().get"; \
        } \
        failCall##_reset(); \
        resultCall##_reset(); \
        failCall##_fake.custom_fake = failCall##_custom_fake_false; \
        ASSERT_FALSE(initial().get); \
    }

#define GETTER_BOOL_IM_TEST_F(className, resultType, failCall, resultCall, get) \
    GETTER_BOOL_IM_TEST_NAME_F(className, resultType##Bool, resultType, failCall, resultCall, get)

#if __cplusplus >= 201703L
#define GETTER_OPT_TEST_NAME_F(className, testName, resultType, call, get) \
    TEST2_F(testclassname(className), testName) {\
        call##_fake.custom_fake = call##_custom_fake_true; \
        const GU::resultType result = GU::resultType(call##_custom_fake_result); \
        const std::optional<GU::resultType> out = initial().get; \
        if (out.has_value()) \
        { \
            equals(out.value(), result); \
            ASSERT_EQ(call##_fake.call_count, 1); \
            call##_reset(); \
        } else { \
            FAIL() << "Result is nullopt from initial().get"; \
        } \
        call##_fake.custom_fake = call##_custom_fake_false; \
        const std::optional<GU::resultType> out2 = initial().get; \
        ASSERT_FALSE(out2.has_value()); \
    }

#define GETTER_OPT_TEST_F(className, resultType, call, get) \
    GETTER_OPT_TEST_NAME_F(className, resultType, resultType, call, get)

#define GETTER_OPT_IM_TEST_NAME_F(className, testName, resultType, failCall, resultCall, get) \
    TEST2_F(testclassname(className), testName) { \
        failCall##_fake.custom_fake = failCall##_custom_fake_true; \
        resultCall##_fake.return_val = resultCall##_result; \
        const GU::resultType result = GU::resultType(resultCall##_result); \
        const std::optional<GU::resultType> out = initial().get; \
        if (out.has_value()) \
        { \
            equals(out.value(), result); \
            ASSERT_EQ(failCall##_fake.call_count, 1); \
            ASSERT_EQ(resultCall##_fake.call_count, 1); \
        } else { \
            FAIL() << "Result is nullopt from initial().get"; \
        } \
        failCall##_reset(); \
        resultCall##_reset(); \
        failCall##_fake.custom_fake = failCall##_custom_fake_false; \
        const std::optional<GU::resultType> out2 = initial().get; \
        ASSERT_FALSE(out2.has_value()); \
    }

#define GETTER_OPT_IM_TEST_F(className, resultType, failCall, resultCall, get) \
    GETTER_OPT_IM_TEST_NAME_F(className, resultType, resultType, failCall, resultCall, get)
#else
#define GETTER_OPT_TEST_NAME_F(className, testName, resultType, call, get)
#define GETTER_OPT_TEST_F(className, resultType, call, get)
#define GETTER_OPT_IM_TEST_NAME_F(className, testName, resultType, failCall, resultCall, get)
#define GETTER_OPT_IM_TEST_F(className, resultType, failCall, resultCall, get)
#endif

namespace CGTEST {

    template <typename Class, typename Strct>
    class GUWrapperTests: public GUCoordinatesTests<Class>
    {
        protected:

            virtual void cchange(Strct &) = 0;

            virtual Strct cempty() = 0;

            void c_convertible_test()
            {
                Strct obj = {};
                cchange(obj);
                Class obj2 = obj;
                Class obj3;
                obj3 = obj;
                this->equals(obj, obj2);
                this->equals(obj, obj3);
                this->equals(obj2, obj3);
                Strct * obj4 = &obj3;
                obj3 = *obj4;
                this->equals(obj3, *obj4);
            }

    };

}

#endif  /* GUWRAPPERTESTS_HPP */
