#ifndef APP_HPP
#define APP_HPP

#include <vector>
#include "graphics.hpp"

class Figure;

class App {
public:
    const size_t XX;
    const size_t YY;
    std::vector<Figure*> figures;
    genv::canvas background;
public:
    App(size_t XX, size_t YY);
    ~App();
    void event_loop();
    void register_figure(Figure*);
    virtual void action(genv::event);
    inline size_t getWidth() const {return XX;};
    inline size_t getHeight() const {return YY;};
};

#endif