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
    color_menu({x_max() - 150, 40}, 150, 40, Menu::vertical, "color"),
    color_button({x_max() - 150, 40}, 150, 40, "Colors",
                 [](Address, Address pw) {
                     reference_to<Lines_window>(pw).color_pressed();
                 }),
    style_menu({x_max() - 300, 40}, 150, 40, Menu::vertical, "Style"),
    style_button({x_max() - 300, 40}, 150, 40, "Styles",
                 [](Address, Address pw) {
                     reference_to<Lines_window>(pw).style_pressed();
                 }),
    in_style({x_max() - 150, y_max() - 80}, 150, 40, "Style:"),
    input_style({x_max() - 150, y_max() - 40}, 150, 40, "OK",
                [](Address, Address pw) {
                    reference_to<Lines_window>(pw).capture_style();
                }) {
    attach(next_button);
    attach(quit_button);
    attach(next_x);
    attach(next_y);
    attach(xy_out);
    attach(lines);
    color_menu.attach(new Button({0, 0}, 0, 0, "Red", [](Address, Address pw) {
        reference_to<Lines_window>(pw).red_pressed();
    }));

    color_menu.attach(new Button({0, 0}, 0, 0, "Blue", [](Address, Address pw) {
        reference_to<Lines_window>(pw).blue_pressed();
    }));

    color_menu.attach(
        new Button({0, 0}, 0, 0, "Black", [](Address, Address pw) {
            reference_to<Lines_window>(pw).black_pressed();
        }));
    attach(color_button);
    attach(color_menu);
    color_menu.hide();

    style_menu.attach(
        new Button({0, 0}, 0, 0, "Solid", [](Address, Address pw) {
            reference_to<Lines_window>(pw).solid_pressed();
        }));

    style_menu.attach(new Button({0, 0}, 0, 0, "Dot", [](Address, Address pw) {
        reference_to<Lines_window>(pw).dot_pressed();
    }));

    attach(style_menu);
    style_menu.hide();
    attach(style_button);

    attach(in_style);
    attach(input_style);
}

void Lines_window::red_pressed() {
    change_color(Color::red);
    hide_color();
    redraw();
}
void Lines_window::blue_pressed() {
    change_color(Color::blue);
    hide_color();
    redraw();
}
void Lines_window::black_pressed() {
    change_color(Color::black);
    hide_color();
    redraw();
}
void Lines_window::change_color(Color c) {
    lines.set_color(c);
}

void Lines_window::color_pressed() {
    color_button.hide();
    color_menu.show();
}

void Lines_window::hide_color() {
    color_menu.hide();
    color_button.show();
}

void Lines_window::dot_pressed() {
    change_style(Line_style::dot);
    hide_style();
    redraw();
}

void Lines_window::solid_pressed() {
    change_style(Line_style::solid);
    hide_style();
    redraw();
}

void Lines_window::change_style(Line_style ls) {
    lines.set_style(ls);
}

void Lines_window::style_pressed() {
    style_button.hide();
    style_menu.show();
}

void Lines_window::hide_style() {
    style_menu.hide();
    style_button.show();
}

void Lines_window::capture_style() {
    Line_style tmp(Line_style::solid);
    switch (in_style.get_int()) {
        case 0: {
            tmp = Line_style::solid;
            break;
        }
        case 1: {
            tmp = Line_style::dash;
            break;
        }
        case 2: {
            tmp = Line_style::dot;
            break;
        }
        case 3: {
            tmp = Line_style::dashdot;
            break;
        }
        case 4: {
            tmp = Line_style::dashdotdot;
            break;
        }
        default: {
            std::cerr << "Nem jó ez így\n";
            break;
        }
    }

    change_style(tmp);
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