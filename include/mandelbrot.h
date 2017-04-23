/*
 * =====================================================================================
 *
 *       Filename:  mandelbrot.h
 *
 *    Description:  Include file for the mandelbrot class
 *
 *        Version:  1.0
 *        Created:  04/08/2017 07:07:35 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Aditya Raman
 *
 * =====================================================================================
 */

#ifndef MANDELBROT_H_
#define MANDELBROT_H_

namespace bakar
{
    class mandelbrot
    {
        public:
            static const int MAX_ITER = 1000;

        public:
            mandelbrot();
            virtual ~mandelbrot();
            static int getIterations(double x, double y);
    };

} /* bakar */

#endif /* ifndef MANDELBROT_H_ */

