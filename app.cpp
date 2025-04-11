#include "app.hpp"
#include "colors.hpp"
#include "Figures/figure.hpp"

using namespace genv;

App::App(size_t XX, size_t YY): XX(XX), YY(YY) {
    gout.open(XX, YY);
    background.open(XX, YY);
    for (int i = 0; i < XX;i = i+XX/8)
    for (int j = 0;j < YY; j = j+YY/8)
    background << move_to(i, j) << ((i % 2 == 0 && j % 2 == 0 || i%2 ==1 && j %2 == 1) ? BLACK : WHITE) << box(XX/8, YY/8);
    gout << stamp(background, 0,0);
    gout << refresh;
};

void App::event_loop() {
    event ev;
    int focus = -1;
    for (auto i: figures) i->draw();
    gout << refresh;
    while (gin >> ev && ev.keycode != key_escape) {
        gout << move_to(0,0) << BLACK << box(XX, YY);
        if (ev.button == btn_left) {
            for (int i = 0; i < figures.size(); i++) {
                if (figures.at(i)->is_selected(ev.pos_x, ev.pos_y)) focus = i;
            }
        }
        if (focus != -1) figures.at(focus)->handle(ev);
        gout << stamp(background, 0,0);
        for (auto i: figures) i->draw();
        gout << refresh;
    }

};

App::~App() {
    for (auto i: figures) delete i;
}

void App::register_figure(Figure* f){
    figures.push_back(f);
}
void App::action(event) {};