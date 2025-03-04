/*
 * This file is part of the Micro Python project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2015 Damien P. George
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include "MicroBit.h"
#include "microbitobj.h"

extern "C" {

#include "py/runtime.h"
#include "modmicrobit.h"
#include "microbitimage.h"


#define IMAGE_T const monochrome_5by5_t 

IMAGE_T microbit_const_image_heart_obj = SMALL_IMAGE(
    0,1,0,1,0,
    1,1,1,1,1,
    1,1,1,1,1,
    0,1,1,1,0,
    0,0,1,0,0
);

IMAGE_T microbit_const_image_heart_small_obj = SMALL_IMAGE(
    0,0,0,0,0,
    0,1,0,1,0,
    0,1,1,1,0,
    0,0,1,0,0,
    0,0,0,0,0
);

IMAGE_T microbit_const_image_happy_obj = SMALL_IMAGE(
    0,0,0,0,0,
    0,1,0,1,0,
    0,0,0,0,0,
    1,0,0,0,1,
    0,1,1,1,0
);

IMAGE_T microbit_const_image_smile_obj = SMALL_IMAGE(
    0,0,0,0,0,
    0,0,0,0,0,
    0,0,0,0,0,
    1,0,0,0,1,
    0,1,1,1,0
);

IMAGE_T microbit_const_image_sad_obj = SMALL_IMAGE(
    0,0,0,0,0,
    0,1,0,1,0,
    0,0,0,0,0,
    0,1,1,1,0,
    1,0,0,0,1
);

IMAGE_T microbit_const_image_confused_obj = SMALL_IMAGE(
    0,0,0,0,0,
    0,1,0,1,0,
    0,0,0,0,0,
    0,1,0,1,0,
    1,0,1,0,1
);

IMAGE_T microbit_const_image_angry_obj = SMALL_IMAGE(
    1,0,0,0,1,
    0,1,0,1,0,
    0,0,0,0,0,
    1,1,1,1,1,
    1,0,1,0,1
);

IMAGE_T microbit_const_image_asleep_obj = SMALL_IMAGE(
    0,0,0,0,0,
    1,1,0,1,1,
    0,0,0,0,0,
    0,1,1,1,0,
    0,0,0,0,0
);

IMAGE_T microbit_const_image_surprised_obj = SMALL_IMAGE(
    0,1,0,1,0,
    0,0,0,0,0,
    0,0,1,0,0,
    0,1,0,1,0,
    0,0,1,0,0
);

IMAGE_T microbit_const_image_yes_obj = SMALL_IMAGE(
    0,0,0,0,0,
    0,0,0,0,1,
    0,0,0,1,0,
    1,0,1,0,0,
    0,1,0,0,0
);

IMAGE_T microbit_const_image_no_obj = SMALL_IMAGE(
    1,0,0,0,1,
    0,1,0,1,0,
    0,0,1,0,0,
    0,1,0,1,0,
    1,0,0,0,1
);

IMAGE_T microbit_const_image_clock12_obj = SMALL_IMAGE(
    0,0,1,0,0,
    0,0,1,0,0,
    0,0,1,0,0,
    0,0,0,0,0,
    0,0,0,0,0
);

IMAGE_T microbit_const_image_clock1_obj = SMALL_IMAGE(
    0,0,0,1,0,
    0,0,0,1,0,
    0,0,1,0,0,
    0,0,0,0,0,
    0,0,0,0,0
);

IMAGE_T microbit_const_image_clock2_obj = SMALL_IMAGE(
    0,0,0,0,0,
    0,0,0,1,1,
    0,0,1,0,0,
    0,0,0,0,0,
    0,0,0,0,0
);

IMAGE_T microbit_const_image_clock3_obj = SMALL_IMAGE(
    0,0,0,0,0,
    0,0,0,0,0,
    0,0,1,1,1,
    0,0,0,0,0,
    0,0,0,0,0
);

IMAGE_T microbit_const_image_clock4_obj = SMALL_IMAGE(
    0,0,0,0,0,
    0,0,0,0,0,
    0,0,1,0,0,
    0,0,0,1,1,
    0,0,0,0,0
);

IMAGE_T microbit_const_image_clock5_obj = SMALL_IMAGE(
    0,0,0,0,0,
    0,0,0,0,0,
    0,0,1,0,0,
    0,0,0,1,0,
    0,0,0,1,0
);

IMAGE_T microbit_const_image_clock6_obj = SMALL_IMAGE(
    0,0,0,0,0,
    0,0,0,0,0,
    0,0,1,0,0,
    0,0,1,0,0,
    0,0,1,0,0
);

IMAGE_T microbit_const_image_clock7_obj = SMALL_IMAGE(
    0,0,0,0,0,
    0,0,0,0,0,
    0,0,1,0,0,
    0,1,0,0,0,
    0,1,0,0,0
);

IMAGE_T microbit_const_image_clock8_obj = SMALL_IMAGE(
    0,0,0,0,0,
    0,0,0,0,0,
    0,0,1,0,0,
    1,1,0,0,0,
    0,0,0,0,0
);

IMAGE_T microbit_const_image_clock9_obj = SMALL_IMAGE(
    0,0,0,0,0,
    0,0,0,0,0,
    1,1,1,0,0,
    0,0,0,0,0,
    0,0,0,0,0
);

IMAGE_T microbit_const_image_clock10_obj = SMALL_IMAGE(
    0,0,0,0,0,
    1,1,0,0,0,
    0,0,1,0,0,
    0,0,0,0,0,
    0,0,0,0,0
);

IMAGE_T microbit_const_image_clock11_obj = SMALL_IMAGE(
    0,1,0,0,0,
    0,1,0,0,0,
    0,0,1,0,0,
    0,0,0,0,0,
    0,0,0,0,0
);

IMAGE_T microbit_const_image_arrow_n_obj = SMALL_IMAGE(
    0,0,1,0,0,
    0,1,1,1,0,
    1,0,1,0,1,
    0,0,1,0,0,
    0,0,1,0,0
);

IMAGE_T microbit_const_image_arrow_ne_obj = SMALL_IMAGE(
    0,0,1,1,1,
    0,0,0,1,1,
    0,0,1,0,1,
    0,1,0,0,0,
    1,0,0,0,0
);

IMAGE_T microbit_const_image_arrow_e_obj = SMALL_IMAGE(
    0,0,1,0,0,
    0,0,0,1,0,
    1,1,1,1,1,
    0,0,0,1,0,
    0,0,1,0,0
);

IMAGE_T microbit_const_image_arrow_se_obj = SMALL_IMAGE(
    1,0,0,0,0,
    0,1,0,0,0,
    0,0,1,0,1,
    0,0,0,1,1,
    0,0,1,1,1
);

IMAGE_T microbit_const_image_arrow_s_obj = SMALL_IMAGE(
    0,0,1,0,0,
    0,0,1,0,0,
    1,0,1,0,1,
    0,1,1,1,0,
    0,0,1,0,0
);

IMAGE_T microbit_const_image_arrow_sw_obj = SMALL_IMAGE(
    0,0,0,0,1,
    0,0,0,1,0,
    1,0,1,0,0,
    1,1,0,0,0,
    1,1,1,0,0
);

IMAGE_T microbit_const_image_arrow_w_obj = SMALL_IMAGE(
    0,0,1,0,0,
    0,1,0,0,0,
    1,1,1,1,1,
    0,1,0,0,0,
    0,0,1,0,0
);

IMAGE_T microbit_const_image_arrow_nw_obj = SMALL_IMAGE(
    1,1,1,0,0,
    1,1,0,0,0,
    1,0,1,0,0,
    0,0,0,1,0,
    0,0,0,0,1
);

}
