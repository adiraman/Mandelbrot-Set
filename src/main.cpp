/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Main prg
 *
 *        Version:  1.0
 *        Created:  04/08/2017 12:36:08 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Aditya Raman
 *
 * =====================================================================================
 */

#include <iostream>
#include "fractalCreator.h"
#include "RGB.h"
#include "zoom.h"

int main()
{
    bakar::fractalCreator frac(800, 600);

    frac.addRange(0.0, bakar::RGB(0, 0, 225));
    frac.addRange(0.05, bakar::RGB(255, 99, 71));
    frac.addRange(0.08, bakar::RGB(255, 215, 0));
    frac.addRange(1.0, bakar::RGB(255, 255, 255));

    frac.addZoom(bakar::zoom(295, 202, 0.1));
    frac.addZoom(bakar::zoom(312, 304, 0.1));

    frac.setupFractal("mandelbrot.bmp");

    std::cout << "Finished !" << std::endl;

    return 0;
}

