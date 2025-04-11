#include "widgets.hpp"

Widget::Widget(int x, int y, int sx, int sy): x(x), y(y), sx(sx), sy(sy) {};

bool Widget::is_selected(int px, int py) const {
    return px >= x && px <= x+sx && py >= y && py <= y+sy;
}
