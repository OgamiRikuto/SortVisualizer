#ifndef _BOX_HPP_
#define _BOX_HPP_

#include "HandyWrapper.hpp"
#include "Shape.hpp"

class Box : public Shape {
    private:
        double wd;
        double hg;
    
    public:
        Box(double x, double y, double width, double height);
        ~Box();
        
        void draw(int id, hgcolor clr) const override;
        void drawFill(int id, hgcolor clr, int s) const override; 

        void update(double x, double y, double width, double height);
};

#endif // _BOX_HPP_
