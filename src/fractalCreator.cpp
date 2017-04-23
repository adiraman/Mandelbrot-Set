/*
 * =====================================================================================
 *
 *       Filename:  fractalCreator.cpp
 *
 *    Description:  source file for fractal creator class
 *
 *        Version:  1.0
 *        Created:  04/09/2017 04:33:34 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Aditya Raman
 *
 * =====================================================================================
 */

#include "fractalCreator.h"

namespace bakar
{

    void fractalCreator::addRange(double rangeEnd, const RGB &rgb)
    {
        m_ranges.push_back(rangeEnd*mandelbrot::MAX_ITER);
        m_colors.push_back(rgb);

        if (m_bGotFirstRange)
        {
            m_rangeTotals.push_back(0);
        }

        m_bGotFirstRange = true;
    }

    int fractalCreator::getRange(int iterations) const
    {
        unsigned int range = 0;

        for (unsigned int i = 1; i < m_ranges.size(); i++)
        {
            range = i;

            if (m_ranges[i] > iterations)
            {
                break;
            }
        }

        range--;
        //assert(range > -1);
        assert(range >= 0);
        assert(range < m_ranges.size());

        return range;
    }

    void fractalCreator::addZoom(const zoom &zm)
    {
	    m_zoomList.add(zm);
    }

    void fractalCreator::setupFractal(std::string name)
    {
	    calcIteration();
	    calcTotalIterations();
        calcRangeTotals();
	    drawFractal();
	    writeBitmap(name);
    }

    fractalCreator::fractalCreator(int width, int height):
        m_width(width), m_height(height),
        m_zoomList(m_width, m_height),
        m_bitmap(m_width, m_height)
    {
        m_histogram = new int[bakar::mandelbrot::MAX_ITER]{0};
        m_fractal = new int[m_width*m_height]{0};
        m_zoomList.add(zoom(m_width/2, m_height/2, 4.0/m_width));
    }

    fractalCreator::~fractalCreator()
    {

        delete [] m_histogram;
        delete [] m_fractal;

    }

    void fractalCreator::calcIteration()
    {
        for (int y = 0; y < m_height; y++)
        {
	        for (int x = 0; x < m_width; x++)
	        {
		        std::pair<double, double> coords =
                    m_zoomList.doZoom(x, y);

                int iterations =
                    bakar::mandelbrot::getIterations(
                            coords.first, coords.second);

		        m_fractal[y * m_width + x] = iterations;

		        if(iterations != bakar::mandelbrot::MAX_ITER)
		        {
			        m_histogram[iterations]++;
		        }

	        }
        }

    }

    void fractalCreator::drawFractal()
    {
        /* RGB startColor(0, 0, 0); */
        /* RGB endColor(0, 0, 255); */
        /* RGB colorDiff = endColor - startColor; */

        for (int y = 0; y < m_height; y++)
        {
	        for (int x = 0; x < m_width; x++)
	        {
		        int iterations = m_fractal[y * m_width + x];

                int range = getRange(iterations);
                int rangeTotal = m_rangeTotals[range];
                int rangeStart = m_ranges[range];

                RGB &startColor = m_colors[range];
                RGB &endColor = m_colors[range + 1];
                RGB colorDiff = endColor - startColor;

		        uint8_t red = 0;
		        uint8_t green = 0;
		        uint8_t blue = 0;

		        if (iterations != bakar::mandelbrot::MAX_ITER)
		        {
			        int totalPixels = 0;

			        for (int i = rangeStart; i <= iterations; i++)
			        {
				        totalPixels += m_histogram[i];
			        }

			        red = startColor.r + colorDiff.r *
                        (double)totalPixels/rangeTotal;

                    green = startColor.g + colorDiff.g *
                        (double)totalPixels/rangeTotal;

                    blue = startColor.b + colorDiff.b *
                        (double)totalPixels/rangeTotal;

		        }

		        m_bitmap.setPixel(x, y, red, green, blue);

	        }
        }

    }

    void fractalCreator::calcRangeTotals()
    {
        int rangeInd = 0;

        for (int i = 0; i < mandelbrot::MAX_ITER; i++)
        {
            int pixels = m_histogram[i];

            if(i >= m_ranges[rangeInd + 1])
            {
                rangeInd++;
            }

            m_rangeTotals[rangeInd] += pixels;
        }
    }

    void fractalCreator::calcTotalIterations()
    {
        for (int i = 0; i < bakar::mandelbrot::MAX_ITER; i++)
        {
	        m_total += m_histogram[i];
        }
    }

    void fractalCreator::writeBitmap(std::string name)
    {
        m_bitmap.write(name);
    }


} /* bakar */

