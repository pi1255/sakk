#ifndef CHOICEWIDGET_HPP
#define CHOICEWIDGET_HPP
#include "widgets.hpp"
#include <vector>
#include <string>

struct _string {
    std::string s;
    size_t linec;
};

class ChoiceWidget : public Widget {
protected:
    std::vector<_string> choices;
    int selected = 0;
    genv::canvas all, choised, canv;
    bool choose = false;
    int values = 0;
    int scroll = 5;
    bool leftdown = false;
public:
    ChoiceWidget(int x, int y, int sx, int sy, const std::vector<std::string> &s, const std::string & _font, int fontsize = 16);
    virtual void draw() const override;
    virtual void handle(genv::event) override;
    virtual inline Val getval() const override;
};

#endif