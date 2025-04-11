#include "graphics.hpp"
#include "app.hpp"

int main() {
    App myapp = App(800, 800);
    myapp.event_loop();
    return 0;
}