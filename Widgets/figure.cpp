#include "figure.hpp"

Widget::Widget(App* app, char row, char col, FIG_COLOR fcol): parent(app), fcolor(fcol), row(row), col(col) {
    parent->register_widget(this);
};

bool Widget::is_selected(int px, int py) const {
    return px / (parent->getWidth()/8) == (int)col && py/(parent->getHeight()/8) == (int)row;
}