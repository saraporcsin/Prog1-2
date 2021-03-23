#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>
#include "editor.h"

int main() {
    Document d;
    // Ez már nagyon opcionális
    // TODO Debuggolni
    // A bugok gratis
    std::string buffer;
    while (true) {
        std::cin >> buffer;

        if (buffer.size() == 2 && buffer[0] == ':')
            switch (buffer[1]) {
                case 'a': {
                    std::cin >> d;
                    break;
                }
                case 'p': {
                    std::cout << d;
                    break;
                }
                case 'd': {
                    int line_num;
                    std::cin >> line_num;
                    erase_line(d, line_num);
                    break;
                }
                case 'f': {
                    std::string exp;
                    std::getline(std::cin, exp);
                    auto it = find_txt(d.begin(), d.end(), exp);

                    if (it == d.end())
                        std::cout << "Not Found!\n";
                    else {
                        for (; it != d.end() && *it != '\n'; ++it)
                            std::cout << *it;
                    }
                    break;
                }
                case 'x': {
                    std::exit(0);
                }
                default: {
                    std::cerr << "Invalid operation!\n\n"
                              << "Help:\n\n"
                              << "\t:a (append)\n"
                              << "\t:p (print)\n"
                              << "\t:d line_num (delete)\n"
                              << "\t:f text (find)\n"
                              << "\t:x (exit)\n";
                    break;
                }
            }
    }
    return 0;
}