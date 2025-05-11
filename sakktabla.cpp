#include "sakktabla.hpp"
#include "colors.hpp"
#include "Widgets/king.hpp"

using namespace genv;

Sakktabla::Sakktabla(int XX, int YY) : App(XX, YY) {
    background.open(XX, YY);
    for (int i = 0; i < XX/8; i++) {
        for (int j = 0; j < YY/8; j++) {
            if ((i % 2 == 0 && j %2 == 0) || (i %2 == 1 && j % 2 == 1)) background << WHITE;
            else background << BLACK;
            background << move_to(XX/8*i, YY/8*j) << box(XX/8, YY/8);
        }
    }
    gout << stamp(background, 0, 0);
    King* wk = new King(this, 'a', 4, FIG_WHITE);
}

