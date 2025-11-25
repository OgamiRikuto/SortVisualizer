#include "../include/visualizer.hpp"
#include "../include/config.hpp"

std::vector<Box> initBox(Layer& l, const std::vector<int>& values, double startX, double startY) {
    std::vector<Box> boxes;
    for(size_t i=0; i < values.size(); i++) {
        double x = startX + i * (BOX_WIDTH + BOX_SPACING);
        double height = values[i] * BOX_HEIGHT_MIN;
        boxes.emplace_back(x, startY, BOX_WIDTH, height);
    }

    l.lswitch();
    for(auto& box : boxes) {
        box.drawFill(l.getId(), HG_BLUE, 0);
    }

    return boxes;
}

void updateBox(std::vector<Box>& boxes, const std::vector<int>& values, double startX, double startY) {
    for(size_t i=0; i<boxes.size(); i++) {
        double x = startX + i * (BOX_WIDTH + BOX_SPACING);
        double height = values[i] * BOX_HEIGHT_MIN;
        boxes[i].update(x, startY, BOX_WIDTH, height);
    }
}

void drawBoxes(Layer& l, const std::vector<Box>& boxes, hgcolor clr) {
    l.lswitch();
    for(const auto& box : boxes) {
        box.drawFill(l.getId(), clr, 1);
    }
    HgSleep(DELAY);
}
