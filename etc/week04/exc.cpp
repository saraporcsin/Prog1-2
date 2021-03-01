#include "Graph.h"
#include "Point.h"
#include "Simple_window.h"
#include <FL/fl_draw.H>
#include <string>

class BinaryTree : public Shape {
public:
    BinaryTree(Point root, int levels = 1, int sparse_x = 35,
               int sparse_y = 100, int radius = 12,
               Line_style line_style = Line_style::solid)
      : m_levels(levels), m_sparse_x(sparse_x), m_sparse_y(sparse_y),
        m_radius(radius), m_line_style(line_style) {

        for (int i = 0; i < m_levels; ++i) {
            for (int j = 0; j < static_cast<int>(pow(2, i)); ++j) {

                int center_x = root.x - ((pow(2, i) - 1) / 2 - j) *
                                            pow(2, levels - i) * sparse_x;
                int center_y = root.y + i * sparse_y;

                add(Point{center_x, center_y});
            }
        }
        set_fill_color(Color::black);
    }
    ~BinaryTree(){};

    void draw_lines() const override {
        draw_edges();
        draw_nodes();
    }

    int levels() const {
        return m_levels;
    }

    void set_levels(int levels) {
        m_levels = levels;
    }

    int sparse_x() const {
        return m_sparse_x;
    }

    void set_sparse_x(int sparse_x) {
        m_sparse_x = sparse_x;
    }

    int sparse_y() const {
        return m_sparse_y;
    }

    void set_sparse_y(int sparse_y) {
        m_sparse_y = sparse_y;
    }

    int radius() const {
        return m_radius;
    }

    void set_radius(int radius) {
        m_radius = radius;
    }

    Line_style line_style() const {
        return m_line_style;
    }

    void set_line_style(Line_style line_style) {
        m_line_style = line_style;
    }

private:
    void draw_edges() const {
        if (color().visibility()) {
            fl_color(color().as_int());
            fl_line_style(m_line_style.style(), m_line_style.width());

            for (int i = 0; i < number_of_points() / 2; ++i) {
                fl_line(point(i).x, point(i).y, point(2 * i + 1).x,
                        point(2 * i + 1).y);
                fl_line(point(i).x, point(i).y, point(2 * i + 2).x,
                        point(2 * i + 2).y);
            }
            fl_line_style(0);
        }
    }
    virtual void draw_nodes() const {
        if (color().visibility()) {
            fl_color(color().as_int());

            for (int i = 0; i < number_of_points(); ++i)
                fl_arc(point(i).x - m_radius, point(i).y - m_radius,
                       m_radius * 2, m_radius * 2, 0, 360);
        }

        if (fill_color().visibility()) {
            fl_color(fill_color().as_int());
            for (int i = 0; i < number_of_points(); ++i) {
                fl_pie(point(i).x - m_radius, point(i).y - m_radius,
                       m_radius * 2, m_radius * 2, 0, 360);
            }
            fl_color(color().as_int());
        }
    }

private:
    int                m_levels;
    int                m_sparse_x;
    int                m_sparse_y;
    int                m_radius;
    Line_style         m_line_style;
    Vector_ref<Line>   m_edges;
    Vector_ref<Circle> m_circles;
};

class BinaryTree_Triangle : public BinaryTree {
    using BinaryTree::BinaryTree;

private:
    void draw_nodes() const override {
        if (color().visibility()) {
            fl_color(color().as_int());

            for (int i = 0; i < number_of_points(); ++i)
                fl_rect(point(i).x - radius(), point(i).y - radius(),
                        2 * radius(), 2 * radius());
        }

        if (fill_color().visibility()) {
            fl_color(fill_color().as_int());
            for (int i = 0; i < number_of_points(); ++i) {
                fl_rectf(point(i).x - radius(), point(i).y - radius(),
                         2 * radius(), 2 * radius());
            }
            fl_color(color().as_int());
        }
    }
};

int main(int argc, char **argv) {

    int level = std::stoi(argv[1]);

    Simple_window win{{0, 0}, 1920, 1080, "pain"};

    BinaryTree_Triangle c({300, 300}, level);
    c.set_line_style(Line_style::dot);
    Mark m1{{300, 300}, '.'};

    win.attach(c);
    win.attach(m1);

    win.wait_for_button();
}