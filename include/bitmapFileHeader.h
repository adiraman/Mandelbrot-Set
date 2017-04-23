/*
 * =====================================================================================
 *
 *       Filename:  bitmapFileHeader.h
 *
 *    Description:  Include file for bitmap file header
 *
 *        Version:  1.0
 *        Created:  04/08/2017 10:08:49 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Aditya Raman
 *
 * =====================================================================================
 */

#ifndef BITMAPFILEHEADER_H_
#define BITMAPFILEHEADER_H_

#include <cstdint>

namespace bakar
{
#pragma pack(push,2)

    struct bitmapFileHeader
    {
        char header[2]{'B', 'M'};
        int32_t fileSize;
        int32_t reserved{0};
        int32_t dataOffset;
    };

#pragma pack(pop)

}

#endif /*BITMAPFILEHEADER_H_*/
