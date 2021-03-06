/*
 * custom_fakes.c 
 * tests 
 *
 * Created by Callum McColl on 22/06/2020.
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
 * Fifth FlooUNUSED(p), Boston, MA  02110-1301, USA.
 *
 */

#include "custom_fakes.h"

const gu_relative_coordinate pct_coord_to_rr_coord_custom_fake_result = { 10.0, 1000 };
const gu_percent_coordinate rr_coord_to_pct_coord_custom_fake_result = { -0.4, -0.2 };
const gu_percent_coordinate clamped_tolerance_rr_coord_to_pct_coord_custom_fake_result = { -0.2, -0.4 };

#ifndef UNUSED
#  ifdef __GNUC__
#    define UNUSED(x) UNUSED_ ## x __attribute__((__unused__))
#  else
#    define UNUSED(x) UNUSED_ ## x
#  endif
#endif

gu_optional_relative_coordinate pct_coord_to_rr_coord_custom_fake_true(const gu_percent_coordinate UNUSED(c), const gu_camera_pivot UNUSED(p), const int UNUSED(i))
{
    const gu_relative_coordinate temp = pct_coord_to_rr_coord_custom_fake_result;
    const gu_optional_relative_coordinate out = { true, temp };
    return out;
}

gu_optional_relative_coordinate pct_coord_to_rr_coord_custom_fake_false(const gu_percent_coordinate UNUSED(c), const gu_camera_pivot UNUSED(p), const int UNUSED(i))
{
    const gu_relative_coordinate temp = pct_coord_to_rr_coord_custom_fake_result;
    const gu_optional_relative_coordinate out = { false, temp };
    return out;
}

gu_optional_percent_coordinate rr_coord_to_pct_coord_custom_fake_true(const gu_relative_coordinate UNUSED(c), const gu_camera_pivot UNUSED(p), const int UNUSED(i))
{
    const gu_percent_coordinate temp = rr_coord_to_pct_coord_custom_fake_result;
    const gu_optional_percent_coordinate out = { true, temp };
    return out;
}

gu_optional_percent_coordinate rr_coord_to_pct_coord_custom_fake_false(const gu_relative_coordinate UNUSED(c), const gu_camera_pivot UNUSED(p), const int UNUSED(i))
{
    const gu_percent_coordinate temp = rr_coord_to_pct_coord_custom_fake_result;
    const gu_optional_percent_coordinate out = { false, temp };
    return out;
}

gu_optional_percent_coordinate clamped_tolerance_rr_coord_to_pct_coord_custom_fake_true(const gu_relative_coordinate UNUSED(c), const gu_camera_pivot UNUSED(p), const int UNUSED(i), const percent_d UNUSED(t))
{
    const gu_percent_coordinate temp = clamped_tolerance_rr_coord_to_pct_coord_custom_fake_result;
    const gu_optional_percent_coordinate out = { true, temp };
    return out;
}

gu_optional_percent_coordinate clamped_tolerance_rr_coord_to_pct_coord_custom_fake_false(const gu_relative_coordinate UNUSED(c), const gu_camera_pivot UNUSED(p), const int UNUSED(i), const percent_d UNUSED(t))
{
    const gu_percent_coordinate temp = clamped_tolerance_rr_coord_to_pct_coord_custom_fake_result;
    const gu_optional_percent_coordinate out = { false, temp };
    return out;
}
