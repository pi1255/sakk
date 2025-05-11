#include "king.hpp"

using namespace genv;

King::King(App* app, char row, char col, FIG_COLOR fcol): Widget(app, row, col, fcol) {};

void King::draw() const {
    gout << move_to((col-'a')*parent->XX/8,(8-row)*parent->YY/8) << WIN_BLUE << text(fcolor);
}

void King::handle(event ev) {};

bool King::szabalyos(char col, char row) const {return 1;};

bool King::utesben(char col, char row) const {return 1;};