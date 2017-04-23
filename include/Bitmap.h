/*
 * =====================================================================================
 *
 *       Filename:  Bitmap.h
 *
 *    Description:  Include file for class bitmap
 *
 *        Version:  1.0
 *        Created:  04/08/2017 12:32:59 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Aditya Raman
 *
 * =====================================================================================
 */

#ifndef BITMAP_H
#define BITMAP_H

#include <string>
#include <cstdint>

namespace bakar
{

    class Bitmap
    {
        private:
            int m_width{0};
            int m_height{0};
            uint8_t *m_pPixel{nullptr};

        public:
            Bitmap(int width, int height);
            virtual ~Bitmap();
            bool write(std::string filename);
            void setPixel(int x, int y, uint8_t red,
                    uint8_t green, uint8_t blue);
    };

}

#endif /* BITMAP_H */
