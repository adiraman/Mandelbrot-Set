/*
 * =====================================================================================
 *
 *       Filename:  zoom.h
 *
 *    Description:  Include file for the zoom class
 *
 *        Version:  1.0
 *        Created:  04/09/2017 10:25:05 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Aditya Raman
 *
 * =====================================================================================
 */

#ifndef ZOOM_H_
#define ZOOM_H_

namespace bakar
{
    struct zoom
    {
        int x{0};
        int y{0};
        double scale{0};

        zoom(int x, int y, double scale): x(x), y(y), scale(scale)
        {

        }
    };


} /* bakar */

#endif /* ifndef ZOOM_H_ */

