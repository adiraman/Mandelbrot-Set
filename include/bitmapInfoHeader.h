/*
 * =====================================================================================
 *
 *       Filename:  bitmapInfoHeader.h
 *
 *    Description:  Inlude file for bitmap info header
 *
 *        Version:  1.0
 *        Created:  04/08/2017 11:43:33 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Aditya Raman
 *
 * =====================================================================================
 */

#ifndef BITMAPINFOHEADER_H_
#define BITMAPINFOHEADER_H_

#include <cstdint>


namespace bakar
{

#pragma pack(push, 2)

    struct bitmapInfoHeader
    {
        int32_t headerSize{40};
        int32_t width;
        int32_t height;
        int16_t planes{1};
        int16_t bitsPerPixel{24};
        int32_t compression{0};
        int32_t dataSize{0};
        int32_t horizontalResolution{2400};
        int32_t colors{0};
        int32_t importantColors{0};
    };

#pragma pack(pop)

}

#endif /* BITMAPINFOHEADER_H_ */

