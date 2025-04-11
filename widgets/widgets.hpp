#ifndef WIDGETS_HPP
#define WIDGETS_HPP
#include <string>
#include "../graphics.hpp"
#include "../colors.hpp"

struct Val {
    int intval;
    std::string stringval;
};


class Widget {
protected:
    int x, y,sx, sy;
public:
    Widget(int, int, int, int);
    virtual bool is_selected(int, int) const;
    virtual void draw() const = 0;
    virtual void handle(genv::event) = 0;
    virtual inline Val getval() const = 0;
};

#endif