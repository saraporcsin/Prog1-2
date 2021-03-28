#include "GUI.h"
#include "Graph.h"

using namespace Graph_lib;

struct Lines_window : Graph_lib::Window {
    Lines_window(Point xy, int w, int h, const string& title);
    Open_polyline lines;

    bool wait_for_button();

private:
    Button next_button;
    Button quit_button;

    In_box next_x;
    In_box next_y;

    Out_box xy_out;

    Menu   color_menu;
    void   red_pressed();
    void   blue_pressed();
    void   black_pressed();
    void   change_color(Color c);
    Button color_button;
    void   color_pressed();
    void   hide_color();

    Menu   style_menu;
    void   dot_pressed();
    void   solid_pressed();
    void   change_style(Line_style ls);
    Button style_button;
    void   style_pressed();
    void   hide_style();

    In_box in_style;
    Button input_style;
    void   capture_style();

    void next();
    void quit();
};