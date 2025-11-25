#include "../include/Layer.hpp"

Layer::Layer() {
    layers = HgWAddDoubleLayer(0);
    isDouble = true;
}

Layer::~Layer() {
    if(isDouble) HgLRemoveDoubleLayer(layers);
    else HgLRemove(lid);
}

Layer::Layer(int wid) {
    lid = HgWAddLayer(wid);
}

int Layer::getId() {return lid;}

void Layer::clear() {
    HgLClear(lid);
}

void Layer::show(int flag) {
    HgLShow(lid, flag);
}

void Layer::lswitch() {
    lid = HgLSwitch(&layers);
    HgLClear(lid);
}
