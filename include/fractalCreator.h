/*
 * =====================================================================================
 *
 *       Filename:  fractalCreator.h
 *
 *    Description:  Include file for the fractal creator class
 *
 *        Version:  1.0
 *        Created:  04/09/2017 04:27:36 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Aditya Raman
 *
 * =====================================================================================
 */

#ifndef FRACTALCREATOR_H_
#define FRACTALCREATOR_H_

#include <vector>
#include <cstdint>
#include <string>
#include <cassert>
#include "zoom.h"
#include "zoomList.h"
#include "mandelbrot.h"
#include "Bitmap.h"
#include "RGB.h"

namespace bakar
{

    class fractalCreator
    {
        private:
            int m_width;
            int m_height;
            int m_total{0};
            bakar::zoomList m_zoomList;
            int *m_histogram;
            int *m_fractal;
            bakar::Bitmap m_bitmap;

            std::vector<int> m_ranges;
            std::vector<RGB> m_colors;
            std::vector<int> m_rangeTotals;

            bool m_bGotFirstRange{false};

        private:
            void calcIteration();
            void calcTotalIterations();
            void calcRangeTotals();
            void drawFractal();
            void writeBitmap(std::string name);
            int getRange(int iterations) const;

        public:
            fractalCreator(int width, int height);
            virtual ~fractalCreator();
            void setupFractal(std::string name);
            void addZoom(const zoom& zm);
            void addRange(double rangeEnd, const RGB &rgb);
    };

} /* bakar */

#endif /* ifndef FRACTALCREATOR_H_*/
