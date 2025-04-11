#include "choicewidget.hpp"
#include <sstream>
#include <iostream>

using namespace genv;
using std::vector;
using std::string;
using std::stringstream;
using std::cout, std::endl;

ChoiceWidget::ChoiceWidget(int x, int y, int sx, int sy, const vector<string> & _s, const string& _font, int fontsize ): Widget(x, y, sx, sy) {
    //cout << __LINE__ << endl;
    for (auto i: _s) {
        choices.push_back({i, 1});
    }
    gout.load_font(_font, fontsize);
    int casc = gout.cascent()+gout.cdescent();
    all.open(800, choices.size()*casc);
    all.load_font(_font, fontsize);
    int lb = 1;
    all << WHITE;
    for (int i = 0; i < choices.size(); i++) {
        if (0) {
        // HA szükéges a sortörés, WIP
        stringstream ss;
        ss << choices.at(i).s;
        string s = "";
        char c;
        do {
            string tmp = "";
            while (all.twidth(tmp) < sx-10 && (s+tmp).length() != choices.at(i).s.length()) {
                ss >> c;
                tmp += c;
            }
            all << move_to(0, casc*(i+lb)+casc*2/3.0f) << text(tmp);
            if (tmp.length() != choices.at(i).s.length()) {
                choices.at(i).linec++;
                lb++;
            }
            s += tmp;
        } while(s.length() < choices.at(i).s.length());
        }
        string s = _s.at(i);
        all << move_to(0, casc*(i+lb)+casc*2/3.0f) << text(s);
    }
    all.transparent(true);
    choised.open(sx, sy);
    choised << move_to(0, 0) << WIN_BLUE << box(sx, sy);
    //canv.open(sx+10, sy+10);
    //canv.transparent(1);
    // canv << stamp(choised, 0, 0, sx, casc, 0, 0);
    // canv << WHITE << move_to(0,0) <<line(0, sy) << line(sx, 0) << line(0, -sy )<< line(-sx, 0);
    // canv << stamp(all, 0, casc, sx, sy, 0, 0);
};

void ChoiceWidget::draw() const {
    int casc = all.cascent()+all.cdescent();
    //int n=0, m;
    //for (int i = 0; i < selected; i++) {
      //  n += choices.at(i).linec;
    //}
    //m = choices.at(selected).linec;

    int ypos = casc*(1+(scroll-5)/float(sy-15)*choices.size());
    canvas c;
    c.open(sx, casc);
    c << stamp(choised, 0, ypos, sx, casc, 0,0);
    gout << BLACK << move_to(x, y) << box(sx+1,sy+1);
    //gout << WHITE << stamp(choised, 0, ypos, sx, casc, x, y+(casc));


    canv << stamp(c, 0, ((ypos)*selected));
    canv << WHITE << move_to(x,y) << line(0, sy) << line(sx, 0) << line(0, -sy )<< line(-sx, 0);
    canv << stamp(all,0, ypos, sx, sy,0,0);

    gout << stamp(canv, 0, ypos, sx, sy, x, y);
    //canv << move_to(0,0) << BLACK << box(sx, sy);
    //canv << stamp(choised, 0, ypos, sx, casc, 0, casc*selected);
    //canv << WHITE << move_to(0,0) <<line(0, sy) << line(sx, 0) << line(0, -sy )<< line(-sx, 0);
    //canv << stamp(all, 0, ypos, sx, sy, 0, 0);
    //gout << stamp(canv, x,y);
    gout << move_to(x+sx, y+scroll) << WHITE << box(-5, 10);
};

void ChoiceWidget::handle(event ev) {
    int casc = gout.cascent()+gout.cdescent();
    if (ev.keycode == key_down && selected < choices.size()-1) selected++;
    if (ev.keycode == key_up && selected > 0) selected--;
    if (ev.keycode == key_pgdn) {selected = (selected+10 < choices.size()) ? selected+10 : choices.size()-1;}
    if (ev.keycode == key_pgup) {selected = (selected-10 > 0) ? selected -10 : 0;}
    if (!0) {
        //ha kitalálom a scrollt!
        if (ev.button == btn_wheeldown) scroll--;
        if (ev.button == btn_wheelup) scroll++;
        if (ev.button == btn_left && x+sx-5 <=ev.pos_x && ev.pos_x <= x+sx && y+scroll <= ev.pos_y && ev.pos_y <= y+scroll+10) leftdown = 1; 
        if (leftdown && ev.type == ev_mouse && ev.button != -btn_left) {
            scroll == ev.pos_y-y-5;
        }
        if (ev.button == -btn_left || !(x+sx-5 <ev.pos_x && ev.pos_x < x+sx && y+scroll < ev.pos_y && ev.pos_y < y+scroll+10 )) leftdown = 0;
        if (scroll < 5) scroll = 5;
        if (scroll > sy-10) scroll = sy-10;
    }
    if (ev.button == btn_left && ! leftdown) {
        int n = ev.pos_y - y;
        int k = n/casc;
        if (k < choices.size()) selected = k;
    }
};

inline Val ChoiceWidget::getval() const {
    return {0, choices.at(selected).s};
};


