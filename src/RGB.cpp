/*
 * =====================================================================================
 *
 *       Filename:  RGB.cpp
 *
 *    Description:  source file for the rgb color class
 *
 *        Version:  1.0
 *        Created:  04/09/2017 06:34:37 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Aditya Raman
 *
 * =====================================================================================
 */

#include "RGB.h"

namespace bakar
{

    RGB::RGB(double red, double green, double blue): r(red),
    g(green), b(blue)
    {

    }

    RGB operator-(const RGB &x, const RGB &y)
    {
        return RGB(x.r-y.r, x.g-y.g, x.b-y.b);
    }

} /* bakar */

