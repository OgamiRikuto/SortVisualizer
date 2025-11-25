#ifndef _LAYER_HPP_
#define _LAYER_HPP_

#include "HandyWrapper.hpp"

class Layer {
    private:
        bool isDouble = false;
        int lid;
        doubleLayer layers;
    
    public:
        Layer();
        Layer(int wid);
        ~Layer();

        int getId();

        void clear();
        void show(int flag);
        void lswitch();
};

#endif // _LAYER_HPP_
