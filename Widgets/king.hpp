#ifndef KING_HPP
#define KING_HPP

#include "figure.hpp"

class King : public Widget {
public:
    King(App*, char, char, FIG_COLOR);
    virtual void draw() const override;
    virtual void handle(genv::event) override;
    virtual bool szabalyos(char, char) const override;
    virtual bool utesben(char,char) const override;
};


#endif