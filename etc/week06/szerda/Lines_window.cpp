#include "Lines_window.h"
#include "GUI.h"
#include "Graph.h"
#include <cstdio>
#include <string>

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
    color_button({x_max() - 150, 40}, 150, 40, "Select color",
                 [](Address, Address pw) {
                     reference_to<Lines_window>(pw).color_button_pressed();
                 }),
    style_menu({x_max() - 300, 40}, 150, 40, Menu::vertical, "Styles"),
    style_button({x_max() - 300, 40}, 150, 40, "Select style",
                 [](Address, Address pw) {
                     reference_to<Lines_window>(pw).style_button_pressed();
                 }),
    color_inbox({x_max() - 150, 40}, 150, 40, ""),
    ok_color({x_max() - 150, 80}, 150, 40, "OK",
             [](Address, Address pw) {
                 reference_to<Lines_window>(pw).ok_color_pressed();
             }),
    style_inbox({x_max() - 300, 40}, 150, 40, ""),
    ok_style({x_max() - 300, 80}, 150, 40, "OK", [](Address, Address pw) {
        reference_to<Lines_window>(pw).ok_style_pressed();
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
    attach(color_button);

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
    attach(style_button);

    attach(color_inbox);
    attach(ok_color);

    color_inbox.hide();
    ok_color.hide();

    attach(style_inbox);
    attach(ok_style);

    style_inbox.hide();
    ok_style.hide();
}

void Lines_window::change_color(Color c) {
    lines.set_color(c);
}

void Lines_window::red_pressed() {
    change_color(Color::red);
    color_menu_pressed();
    redraw();
}

void Lines_window::blue_pressed() {
    change_color(Color::blue);
    color_menu_pressed();
    redraw();
}

void Lines_window::black_pressed() {
    change_color(Color::black);
    color_menu_pressed();
    redraw();
}

void Lines_window::color_button_pressed() {
    color_button.hide();
    color_inbox.show();
    ok_color.show();
}

void Lines_window::color_menu_pressed() {
    color_button.show();
    color_inbox.hide();
    ok_color.hide();
}

void Lines_window::solid_pressed() {
    change_style(Line_style::solid);
    style_menu_pressed();
    redraw();
}

void Lines_window::dot_pressed() {
    change_style(Line_style::dot);
    style_menu_pressed();
    redraw();
}

void Lines_window::change_style(Line_style ls) {
    lines.set_style(ls);
}

void Lines_window::style_button_pressed() {
    style_button.hide();
    style_inbox.show();
    ok_style.show();
}

void Lines_window::style_menu_pressed() {
    style_button.show();
    style_inbox.hide();
    ok_style.hide();
}

void Lines_window::ok_color_pressed() {
    Color       tmp{Color::black};
    std::string content = color_inbox.get_string();

    if (content.length() != 1 && content.length() != 2) {
        std::cerr << "Unknown color";
    } else {
        switch (content[0]) {
            case 'd': {
                switch (content[1]) {
                    case 'r': {
                        tmp = Color::dark_red;
                        break;
                    }
                    case 'g': {
                        tmp = Color::dark_green;
                        break;
                    }
                    case 'b': {
                        tmp = Color::dark_blue;
                        break;
                    }
                    case 'c': {
                        tmp = Color::dark_cyan;
                        break;
                    }
                    case 'y': {
                        tmp = Color::dark_yellow;
                        break;
                    }
                    case 'm': {
                        tmp = Color::dark_magenta;
                        break;
                    }
                    default: {
                        std::cerr << "Unknown color";
                        break;
                    }
                }

                break;
            }
            case 'r': {
                tmp = Color::red;
                break;
            }
            case 'g': {
                tmp = Color::green;
                break;
            }
            case 'b': {
                tmp = Color::blue;
                break;
            }
            case 'c': {
                tmp = Color::cyan;
                break;
            }
            case 'y': {
                tmp = Color::yellow;
                break;
            }
            case 'm': {
                tmp = Color::magenta;
                break;
            }
            case 'w': {
                tmp = Color::white;
                break;
            }
            case 'k': {
                tmp = Color::black;
                break;
            }
            default: {
                std::cerr << "Unknown color";
            }
        }
    }

    change_color(tmp);
    color_menu_pressed();
    redraw();
}

void Lines_window::ok_style_pressed() {
    Line_style  tmp{Line_style::solid};
    std::string content = style_inbox.get_string();

    switch (content.length()) {
        case 1: {
            switch (content[0]) {
                case 's': {
                    tmp = Line_style::solid;
                    break;
                }
                case 'd': {
                    tmp = Line_style::dash;
                    break;
                }
                case 'p': {
                    tmp = Line_style::dot;
                    break;
                }
                default: {
                    std::cerr << "Unknown style";
                    break;
                }
            }
            break;
        }
        case 2: {
            if (content == "dd")
                tmp = Line_style::dashdot;

            break;
        }

        case 3: {
            if (content == "ddd") {
                tmp = Line_style::dashdotdot;
            }
            break;
        }
        default: {
            std::cerr << "Unknown style";
        }
    }

    change_style(tmp);
    style_menu_pressed();
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