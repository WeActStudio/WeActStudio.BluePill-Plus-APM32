/*!
 * @file        sc_math.h
 *
 * @brief       Math function
 *
 * @version     V1.0.2
 *
 * @date        2022-01-05
 *
 * @attention
 *
 *  Copyright (C) 2020-2022 Geehy Semiconductor
 *
 *  You may not use this file except in compliance with the
 *  GEEHY COPYRIGHT NOTICE (GEEHY SOFTWARE PACKAGE LICENSE).
 *
 *  The program is only for reference, which is distributed in the hope
 *  that it will be usefull and instructional for customers to develop
 *  their software. Unless required by applicable law or agreed to in
 *  writing, the program is distributed on an "AS IS" BASIS, WITHOUT
 *  ANY WARRANTY OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the GEEHY SOFTWARE PACKAGE LICENSE for the governing permissions
 *  and limitations under the License.
 */

#ifndef __SC_MATH_H
#define __SC_MATH_H

extern float sc_math_sin(float x);
extern float sc_math_cos(float x);
extern float sc_math_tan(float x);
extern float sc_math_asin(float x);
extern float sc_math_acos(float x);
extern float sc_math_atan(float x);
extern float sc_math_atan2(float y, float x);

extern float sc_math_invsqrt(float x);
extern float sc_math_mac(float x, float y, float z);
extern float sc_math_sum_N(float* x, unsigned char n);
extern float sc_math_sub_N(float* x, unsigned char n);
extern float sc_math_prdct(float* x, unsigned char n);
extern float sc_math_sumsq(float* x, unsigned char n);

#endif
