/*
 * =====================================================================================
 *
 *       Filename:  Bitmap.cpp
 *
 *    Description:  Source file for bitmap class
 *
 *        Version:  1.0
 *        Created:  04/08/2017 12:56:10 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Aditya Raman
 *
 * =====================================================================================
 */

#include <fstream>
#include "Bitmap.h"
#include "bitmapInfoHeader.h"
#include "bitmapFileHeader.h"

namespace bakar
{
    Bitmap::Bitmap(int width, int height):
        m_width(width),
        m_height(height)
    {
        m_pPixel = new uint8_t[width*height*3]{};
    }

    Bitmap::~Bitmap()
    {
        delete [] m_pPixel;
    }

    bool Bitmap::write(std::string filename)
    {
        bakar::bitmapFileHeader fileheader;
        bakar::bitmapInfoHeader infoheader;

        // Initialize the data to write to file
        fileheader.fileSize = static_cast<int>
            (sizeof(bakar::bitmapFileHeader) +
             sizeof(bakar::bitmapInfoHeader)) +
            m_width*m_height*3;

        fileheader.dataOffset = static_cast<int>
            (sizeof(bakar::bitmapFileHeader) +
             sizeof(bakar::bitmapInfoHeader));

        infoheader.width = m_width;
        infoheader.height = m_height;

        // Write to file
        std::ofstream file;
        file.open(filename, std::ios::out | std::ios::binary);

        if(!file)
        {
            return false;
        }

        char *fhPtr = reinterpret_cast<char *>
            (&fileheader);
        char *ihPtr = reinterpret_cast<char *>
            (&infoheader);
        char *pxlPtr = reinterpret_cast<char *>(m_pPixel);

        file.write(fhPtr, sizeof(fileheader));
        file.write(ihPtr, sizeof(infoheader));
        file.write(pxlPtr, m_width*m_height*3);

        file.close();

        if(!file)
        {
            return false;
        }


        return true;
    }

    void Bitmap::setPixel(int x, int y, uint8_t red,
            uint8_t green, uint8_t blue)
    {
        uint8_t *pPixel = m_pPixel;
        pPixel += (y*3)*m_width + (x*3);
        pPixel[0] = blue;
        pPixel[1] = green;
        pPixel[2] = red;
    }

} /* bakar */

