#include "king.hpp"

using namespace genv;

King::King(App* app, char row, char col, FIG_COLOR fcol): Figure(app, row, col, fcol) {};

void King::draw() const {
    gout << stamp(c, )
}