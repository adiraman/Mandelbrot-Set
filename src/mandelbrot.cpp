/*
 * =====================================================================================
 *
 *       Filename:  mandelbrot.cpp
 *
 *    Description:  Source file for the mandelbrot class
 *
 *        Version:  1.0
 *        Created:  04/08/2017 07:23:23 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Aditya Raman
 *
 * =====================================================================================
 */

#include <complex>
#include "mandelbrot.h"

namespace bakar
{
    mandelbrot::mandelbrot()
    {

    }

    mandelbrot::~mandelbrot()
    {

    }

    int mandelbrot::getIterations(double x, double y)
    {
        std::complex<double> z = 0;
        std::complex<double> c(x, y);

        int iter = 0;

        while(iter <  mandelbrot::MAX_ITER)
        {
            z = z*z +c;
			if(abs(z) > 2)
    	    {
        	    break;
        	}
			++iter;
        }

        return iter;
    }
} /* bakar */

