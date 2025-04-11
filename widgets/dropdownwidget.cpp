#include "dropdownwidget.hpp"
#include <sstream>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace genv;
using std::string;
using std::vector;
using std::stringstream;

DropDown::DropDown (int x, int y, int _sx, int _sy,int _small_x, int _small_y,  vector<string> _s): Widget(x, y, _sx, _sy), small_x(_small_x), small_y(_small_y), choices(_s) {
    if (small_x >= sx) sx = small_x;
    if (small_y >= sy) sy = small_y;
};

bool DropDown::is_selected(int px, int py) const {
    int casc = gout.cascent()+gout.cdescent();
    if (!drop){return px >= x && px <= x+small_x && py >= y && py <= y+small_y;}
    else return px >= x && px <= x+sx && py >= y && py <= y+sy;
}

void DropDown::draw() const {
    gout << move_to(x, y) << BLACK << box(sx, sy);
    int casc = gout.cascent()+gout.cdescent();
    stringstream _ss;
    _ss << choices.at(selected);
    int w = gout.twidth(_ss.str());
    string s = "";
    if (drop) {
        for (int i = 0; i+offset < choices.size() && (i+1)*casc <=sy; i++) {
            stringstream ss;
            ss.clear();
            ss << choices.at(i+offset);
            s = "";
            if (w > sx-15) {
                char c;
                while (gout.twidth(s) < sx-15) {
                    ss >> c;
                    s+=c;
                }
            } else s = ss.str();
            gout << move_to(x,i*casc+y) << ((i+offset == selected) ? ROYAL_BLUE : LIGHT_BLUE) << box(sx, casc) << ((i+offset == selected) ? WHITE : BLACK)
                 << move_to(x+10, casc*i+y+casc*2/3.0f) << text(s);
        }
    }
    else {
        int dx = std::max(small_x/8, 10);
        if (w > small_x-dx-10) {
            char c;
            while (gout.twidth(s) < small_x-dx-10 && s.length() != choices.at(selected).length()) {
                _ss >> c;
                s+=c;
            }
        } else s = _ss.str();

        gout << move_to(x, y) << LIGHT_GRAY << box (small_x, small_y) << move_to(x+5, y+small_y/2) << BLACK << text(s);
        int dy  = small_y/2;

        gout << move_to(x+small_x-dx, y+small_y/2-dy/2) << BLACK << line(dx/4, dy) << line(dx/4+1, -dy);
    }
};

void DropDown::handle(event ev) {
    if (drop) {
        int casc = (gout.cascent()+gout.cdescent());
        if (ev.button == btn_left && this->is_selected(ev.pos_x, ev.pos_y)) {
            int n = floor((ev.pos_y-y)/(casc));
            if (n >= 0 && n+offset < choices.size()) selected = n+offset;      
        }
        if (ev.keycode == key_up) {
            selected = (selected > 0) ? selected-1 : 0;
            while (selected < offset) offset--;
        }
        if (ev.keycode == key_down) {
            selected = std::min(selected+1, choices.size()-1);
            while (selected >= offset+sy/casc+2) offset++;
        }
        if (ev.button == btn_wheelup) {
            offset = (offset > 0) ? offset - 1 : 0;
        }
        if (ev.button == btn_wheeldown) {
            offset = (offset < choices.size()-sy/casc+2) ? offset+1 : choices.size()-1;
            
        }
    }
    if (ev.button == btn_left && this->is_selected(ev.pos_x, ev.pos_y)) drop = !drop;
};

inline Val DropDown::getval() const {
    return {0, choices.at(selected)};
};