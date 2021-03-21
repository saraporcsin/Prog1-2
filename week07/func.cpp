/**
 * @file func.cpp
 * @author gojoGS (barthazoli00@gmail.com)
 * @brief
 * @version 0.1
 * @date 2021-03-18
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <algorithm>
#include <cctype>
#include <ostream>
#include <string>
#include <iostream>
#include <vector>
#include <cmath>

struct Point {
    double abs_distance() {
        return std::sqrt(m_x * m_x + m_y * m_y);
    }
    int m_x;
    int m_y;
};

bool operator<(Point lhs, Point rhs) {
    return lhs.abs_distance() < rhs.abs_distance();
}

Point operator+(const Point& a, const Point& b) {
    return Point{a.m_x + b.m_x, a.m_y + b.m_y};
}

std::ostream& operator<<(std::ostream& o, Point p) {
    o << '{' << p.m_x << ", " << p.m_y << '}';
    return o;
}

int main() {

    // std::string       name{"Don@ld Duck"};
    // const std::string banned{"[]{}\\/'\"^@"};

    // /**
    //  * @brief Checks if any char of name can be found in banned.
    //  *
    //  */
    // if (std::any_of(name.begin(), name.end(), [&banned](char c) {
    //         return banned.find(c) != std::string::npos;
    //     }))
    //     std::cerr << "Forbidden character in name" << '\n';
    // else
    //     std::cerr << "Seems OK to me" << '\n';

    // std::string quiet{"hallod?"};

    // std::transform(quiet.begin(), quiet.end(), quiet.begin(),
    //                [](char c) { return std::toupper(c); });

    // std::cerr << quiet << '\n';

    // std::vector<int> vec(1000, 0);
    // std::transform(vec.begin(), vec.end(), vec.rbegin(), [](auto elem) {
    //     static int id = 0;
    //     return id++;
    // });

    // std::for_each(vec.begin(), vec.end(),
    //               [](auto elem) { std::cerr << elem << ' '; });

    // std::vector<Point> vec{{0, 0}, {0, 1}, {2, 2}, {1, 1}, {1, 0}};

    // std::for_each(vec.begin(), vec.end(),
    //               [](auto elem) { std::cerr << elem << ' '; });

    // std::sort(vec.begin(), vec.end(),
    //           [](auto lhs, auto rhs) { return lhs < rhs; });

    // std::cerr << "" << '\n';

    // std::for_each(vec.begin(), vec.end(),
    //               [](auto elem) { std::cerr << elem << ' '; });

    return 0;
}