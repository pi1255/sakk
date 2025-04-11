#ifndef DROPDOWN_HPP
#define DROPDOWN_HPP

#include "widgets.hpp"
#include <vector>
#include <string>

class DropDown : public Widget {
protected:
    int small_x, small_y;
    std::vector<std::string> choices;
    bool drop = false;
    size_t selected = 0;
    size_t offset = 0;
public:
    DropDown(int, int, int , int, int, int,  std::vector<std::string>);
    virtual void draw() const override;
    virtual void handle(genv::event) override;
    virtual inline Val getval() const override;
    virtual bool is_selected(int, int) const override;
};

#endif