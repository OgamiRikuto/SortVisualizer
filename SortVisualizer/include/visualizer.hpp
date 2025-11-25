#ifndef _VISUALIZER_HPP_
#define _VISUALIZER_HPP_

#include<vector>
#include "Box.hpp"
#include "Layer.hpp"
#include "handy.hpp"

std::vector<Box> initBox(Layer& l, const std::vector<int>& values, double startX, double startY);

void updateBox(std::vector<Box>& boxes, const std:: vector<int>& values, double startX, double startY);

void drawBoxes(Layer& l, const std::vector<Box>& boxes, hgcolor clr);

#endif // _VISUALIZER_HPP_
