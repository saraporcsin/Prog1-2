#include "Lines_window.h"
#include "GUI.h"
#include "Graph.h"

Lines_window::Lines_window(Point xy, int w, int h, const string& title)
  : Window{xy, w, h, title},
    next_button{
        Point{x_max() - 300, 0}, 150, 40, "Next point",
        [](Address, Address pw) { reference_to<Lines_window>(pw).next(); }},
    quit_button{
        Point{x_max() - 150, 0}, 150, 40, "Quit",
        [](Address, Address pw) { reference_to<Lines_window>(pw).quit(); }},
    next_x{Point{300, 0}, 50, 40, "next x:"},
    next_y{Point{450, 0}, 50, 40, "next y:"}, xy_out{Point{100, 0}, 100, 40,
                                                     "current (x,y):"},
    color_menu({x_max() - 150, 40}, 150, 40, Menu::vertical, "Colors"),
    select_color({x_max() - 150, 40}, 150, 40, "Select Color",
                 [](Address, Address pw) {
                     reference_to<Lines_window>(pw).select_color_pressed();
                 }),
    style_menu({x_max() - 300, 40}, 150, 40, Menu::vertical, "Styles"),
    select_style({x_max() - 300, 40}, 150, 40, "Select Style",
                 [](Address, Address pw) {
                     reference_to<Lines_window>(pw).select_style_pressed();
                 }),
    style_inbox({x_max() - 300, 40}, 150, 40, ""),
    style_ok({x_max() - 300, 80}, 150, 40, "OK",
             [](Address, Address pw) {
                 reference_to<Lines_window>(pw).style_ok_pressed();
             }),
    color_inbox({x_max() - 150, 40}, 150, 40, ""),
    color_ok({x_max() - 150, 80}, 150, 40, "OK", [](Address, Address pw) {
        reference_to<Lines_window>(pw).color_ok_pressed();
    }) {

    attach(next_button);
    attach(quit_button);
    attach(next_x);
    attach(next_y);
    attach(xy_out);
    attach(lines);

    // color_menu.attach(new Button({0, 0}, 0, 0, "Red", [](Address, Address pw)
    // {
    //     reference_to<Lines_window>(pw).red_pressed();
    // }));
    // color_menu.attach(new Button({0, 0}, 0, 0, "Blue", [](Address, Address
    // pw) {
    //     reference_to<Lines_window>(pw).blue_pressed();
    // }));
    // color_menu.attach(
    //     new Button({0, 0}, 0, 0, "Black", [](Address, Address pw) {
    //         reference_to<Lines_window>(pw).black_pressed();
    //     }));
    // attach(color_menu);
    // color_menu.hide();
    attach(select_color);

    // style_menu.attach(
    //     new Button({0, 0}, 0, 0, "Solid", [](Address, Address pw) {
    //         reference_to<Lines_window>(pw).solid_pressed();
    //     }));

    // style_menu.attach(new Button({0, 0}, 0, 0, "Dot", [](Address, Address pw)
    // {
    //     reference_to<Lines_window>(pw).dot_pressed();
    // }));
    // attach(style_menu);
    // style_menu.hide();
    attach(select_style);
    attach(style_inbox);
    attach(style_ok);
    attach(color_inbox);
    attach(color_ok);
    color_inbox.hide();
    color_ok.hide();
    style_inbox.hide();
    style_ok.hide();
}

void Lines_window::change_color(Color c) {
    lines.set_color(c);
}

void Lines_window::red_pressed() {
    change_color(Color::red);
    color_pressed();
    redraw();
}

void Lines_window::blue_pressed() {
    change_color(Color::blue);
    color_pressed();
    redraw();
}

void Lines_window::black_pressed() {
    change_color(Color::black);
    color_pressed();
    redraw();
}

void Lines_window::select_color_pressed() {
    select_color.hide();
    color_inbox.show();
    color_ok.show();
}

void Lines_window::color_pressed() {
    color_inbox.hide();
    color_ok.hide();
    select_color.show();
}

void Lines_window::change_style(Line_style ls) {
    lines.set_style(ls);
}

void Lines_window::solid_pressed() {
    change_style(Line_style::solid);
    style_pressed();
    redraw();
}

void Lines_window::dot_pressed() {
    change_style(Line_style::dot);
    style_pressed();
    redraw();
}

void Lines_window::select_style_pressed() {
    select_style.hide();
    style_inbox.show();
    style_ok.show();
}

void Lines_window::style_pressed() {
    style_inbox.hide();
    style_ok.hide();
    select_style.show();
}

void Lines_window::style_ok_pressed() {
    Line_style tmp = Line_style::solid;
    tmp = static_cast<Line_style>(style_inbox.get_int());
    change_style(tmp);
    style_pressed();
    redraw();
}

void Lines_window::color_ok_pressed() {
    Color tmp = Color::black;
    tmp = static_cast<Color>(color_inbox.get_int());
    change_color(tmp);
    color_pressed();
    redraw();
}

void Lines_window::quit() {
    hide();
}

void Lines_window::next() {
    int x = next_x.get_int();
    int y = next_y.get_int();

    lines.add(Point{x, y});

    ostringstream ss;
    ss << '(' << x << ',' << y << ')';
    xy_out.put(ss.str());

    redraw();
}