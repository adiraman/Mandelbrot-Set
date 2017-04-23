/*
 * =====================================================================================
 *
 *       Filename:  RGB.h
 *
 *    Description:  Include file for the RGC color class
 *
 *        Version:  1.0
 *        Created:  04/09/2017 06:30:23 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Aditya Raman
 *
 * =====================================================================================
 */

#ifndef RGB_H_
#define RGB_H_

namespace bakar
{

    struct RGB
    {
        double r;
        double g;
        double b;

        RGB(double red, double green, double blue);
    };

    RGB operator-(const RGB &x, const RGB &y);
} /* bakar */

#endif /* ifndef RGB_H_ */
