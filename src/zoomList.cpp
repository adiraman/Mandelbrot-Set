/*
 * =====================================================================================
 *
 *       Filename:  zoomList.cpp
 *
 *    Description:  Source file for zoomList class
 *
 *        Version:  1.0
 *        Created:  04/09/2017 11:07:30 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Aditya Raman
 *
 * =====================================================================================
 */

#include "zoomList.h"

namespace bakar
{
    zoomList::zoomList(int width, int height): m_width(width),
    m_height(height)
    {

    }

    void zoomList::add(const zoom &zm)
    {
        zooms.push_back(zm);

        m_xCenter += (zm.x - m_width/2)*m_scale;
        m_yCenter += -(zm.y - m_height/2)*m_scale;

        m_scale *= zm.scale;

    }

    std::pair<double, double> zoomList::doZoom(int x, int y)
    {
        double xFractal = (x - m_width/2)*m_scale + m_xCenter;
        double yFractal = (y - m_height/2)*m_scale + m_yCenter;

        return std::pair<double,double>(xFractal, yFractal);
    }

} /* bakar */

