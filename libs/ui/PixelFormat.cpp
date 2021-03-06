/*
 * Copyright (C) 2007 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <ui/PixelFormat.h>
#include <hardware/hardware.h>

// ----------------------------------------------------------------------------
namespace android {
// ----------------------------------------------------------------------------

ssize_t bytesPerPixel(PixelFormat format) {
    switch (format) {
        case PIXEL_FORMAT_RGBA_8888:
        case PIXEL_FORMAT_RGBX_8888:
        case PIXEL_FORMAT_BGRA_8888:
            return 4;
        case PIXEL_FORMAT_RGB_888:
            return 3;
        case PIXEL_FORMAT_RGB_565:
        case PIXEL_FORMAT_RGBA_5551:
        case PIXEL_FORMAT_RGBA_4444:
#ifdef STE_HARDWARE
        case HAL_PIXEL_FORMAT_YCrCb_422_SP:
        case HAL_PIXEL_FORMAT_YCbCr_422_P:
        case HAL_PIXEL_FORMAT_YCrCb_422_P:
        case HAL_PIXEL_FORMAT_CbYCrY_422_I:
        case HAL_PIXEL_FORMAT_YCbCr_420_SP:
        case HAL_PIXEL_FORMAT_YCbCr_420_SP_TILED:
        case HAL_PIXEL_FORMAT_YCrCb_420_SP_TILED:
        case HAL_PIXEL_FORMAT_YCbCr_420_P:
        case HAL_PIXEL_FORMAT_YCrCb_420_P:
        case HAL_PIXEL_FORMAT_YCbCr_420_I:
        case HAL_PIXEL_FORMAT_CbYCrY_420_I:
        case HAL_PIXEL_FORMAT_YCBCR42XMBN:
#endif
	    return 1;
    }
    return BAD_VALUE;
}

ssize_t bitsPerPixel(PixelFormat format) {
    switch (format) {
        case PIXEL_FORMAT_RGBA_8888:
        case PIXEL_FORMAT_RGBX_8888:
        case PIXEL_FORMAT_BGRA_8888:
            return 32;
        case PIXEL_FORMAT_RGB_888:
            return 24;
        case PIXEL_FORMAT_RGB_565:
        case PIXEL_FORMAT_RGBA_5551:
        case PIXEL_FORMAT_RGBA_4444:
#ifdef STE_HARDWARE
	case HAL_PIXEL_FORMAT_YCrCb_422_SP:
	case HAL_PIXEL_FORMAT_YCbCr_422_P:
	case HAL_PIXEL_FORMAT_YCrCb_422_P:
	case HAL_PIXEL_FORMAT_CbYCrY_422_I:
#endif
            return 16;
#ifdef STE_HARDWARE
	case HAL_PIXEL_FORMAT_YCbCr_420_SP:
	case HAL_PIXEL_FORMAT_YCbCr_420_SP_TILED:
	case HAL_PIXEL_FORMAT_YCrCb_420_SP_TILED:
	case HAL_PIXEL_FORMAT_YCbCr_420_P:
	case HAL_PIXEL_FORMAT_YCrCb_420_P:
	case HAL_PIXEL_FORMAT_YCbCr_420_I:
	case HAL_PIXEL_FORMAT_CbYCrY_420_I:
	case HAL_PIXEL_FORMAT_YCBCR42XMBN:
#endif
	    return 12;
    }
    return BAD_VALUE;
}

// ----------------------------------------------------------------------------
}; // namespace android
// ----------------------------------------------------------------------------

