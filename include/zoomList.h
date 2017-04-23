/*
 * =====================================================================================
 *
 *       Filename:  zoomList.h
 *
 *    Description:  Include file for the zoomList class
 *
 *        Version:  1.0
 *        Created:  04/09/2017 11:01:30 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Aditya Raman
 *
 * =====================================================================================
 */

#ifndef ZOOMLIST_H_
#define ZOOMLIST_H_

#include <vector>
#include <utility>
#include "zoom.h"

namespace bakar
{

    class zoomList
    {
        private:
            double m_xCenter{0};
            double m_yCenter{0};
            double m_scale{1.0};
            int m_width{0};
            int m_height{0};
            std::vector<zoom> zooms;


        public:
            zoomList(int width, int height);
            void add(const zoom &zm);
            std::pair<double, double> doZoom(int x, int y);
    };

}

#endif /* ZOOMLIST_H_ */
