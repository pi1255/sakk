#ifndef FIGHURE_HPP
#define FIGURE_HPP

#include "../app.hpp"

enum FIG_COLOR {
    FIG_WHITE = 0, FIG_BLACK
};

class Widget {
protected:
    App * parent;
    FIG_COLOR fcolor;
    char row, col;
    genv::canvas c;
public:
    Widget(App * app, char row, char col, FIG_COLOR fcol);
    bool is_selected(int, int) const;
    virtual void draw() const = 0;
    virtual void handle(genv::event) = 0;
    virtual bool szabalyos(char, char) const = 0;
    virtual bool utesben(char, char) const = 0;
};


#endif