#include "app.hpp"
#include "colors.hpp"
#include "Widgets/figure.hpp"

using namespace genv;

App::App(size_t XX, size_t YY): XX(XX), YY(YY) {
    gout.open(XX, YY);
    gout << refresh;
};

void App::event_loop() {
    event ev;
    int focus = -1;
    for (auto i: widgets) i->draw();
    gout << refresh;
    while (gin >> ev && ev.keycode != key_escape) {
        gout << stamp(background, 0, 0);
        if (ev.button == btn_left) {
            for (int i = 0; i < widgets.size(); i++) {
                if (widgets.at(i)->is_selected(ev.pos_x, ev.pos_y)) focus = i;
            }
        }
        if (focus != -1) widgets.at(focus)->handle(ev);
        gout << stamp(background, 0,0);
        for (auto i: widgets) i->draw();
        gout << refresh;
    }

};

App::~App() {
    for (auto i: widgets) delete i;
}

void App::register_widget(Widget* f){
    widgets.push_back(f);
}