#ifndef _WINDOW_HPP_
#define _WINDOW_HPP_

class Window {
    private:
        int wid;
        double width;
        double height;

    public:
        Window(double w, double h);
        Window(double x, double y, double w, double h);
        ~Window();

        int getId() const;
        void setTitle(const char *str);
        void clear();
        void wait();

};

#endif // _WINDOW_HPP_
