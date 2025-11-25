#include "../include/Window.hpp"
#include "../include/HandyWrapper.hpp"

Window::Window(double x, double y) : width(x), height(y) {
    wid = HgOpen(width, height);
}

Window::Window(double x, double y, double wd, double hg) : width(wd), height(hg) {
    wid = HgWOpen(x, y, width, height);
} 

Window::~Window() {
    HgWClose(wid);
}

int Window::getId() const {return wid;}

void Window::setTitle(const char *str) {
    HgSetTitle(str);
}

void Window::wait() {
    HgGetChar();
}

void Window::clear() {
    HgWClear(wid);
}
