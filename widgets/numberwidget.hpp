#ifndef NUMBERWIDGET_HPP
#define NUMBERWIDGET_HPP

#include "widgets.hpp"

class NumberWidget : public Widget {
protected:
    int const minval;
    int const  maxval;
    int val;
    bool mouse_pressed = false;
    int left_size;
    int right_size ;
    bool write = false;
    bool neg = true;
public:
    NumberWidget(int x, int y, int sx, int sy, int minval, int maxval, int val);
    NumberWidget(int x, int y, int sx, int sy, int minval, int maxval);
    virtual void handle(genv::event) override;
    virtual void draw() const override;
    virtual inline Val getval() const override;
};


#endif