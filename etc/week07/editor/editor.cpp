#include "editor.h"
#include <algorithm>
#include <iterator>

#include <iostream>

Document::Document() {
    m_lines.push_back(Line{});
}

Text_iterator::Text_iterator(std::list<Line>::iterator line_number,
                             Line::iterator            position)
    : m_line_number(line_number), m_position(position) {}

Text_iterator Document::begin() {
    return Text_iterator(m_lines.begin(), (*m_lines.begin()).begin());
}

Text_iterator Document::end() {
    auto last = m_lines.end();
    --last;
    return Text_iterator(last, (*last).end());
}

char& Text_iterator::operator*() {
    return *m_position;
}

Text_iterator& Text_iterator::operator++() {
    ++m_position;
    if (m_position == (*m_line_number).end()) {
        ++m_line_number;
        m_position = (*m_line_number).begin();
    }

    return *this;
}

bool Text_iterator::operator==(const Text_iterator& rhs) const {
    return (m_line_number == rhs.m_line_number) &&
           (m_position == rhs.m_position);
}

bool Text_iterator::operator!=(const Text_iterator& rhs) const {
    return (!(*this == rhs));
}

bool match(Text_iterator first, Text_iterator last, const std::string str) {
    // Ha valakinek a for ciklus túl sűrű lenne
    // auto str_it  = str.begin();
    // auto text_it = first;
    //
    // while (str_it < str.end() && text_it != last) {
    //     if (*text_it != *str_it)
    //         return false;
    //     else {
    //         ++text_it;
    //         ++str_it;
    //     }
    // }

    for (auto str_it = str.begin(); str_it < str.end() && first != last;
         ++str_it, ++first) {
        if (*first != *str_it)
            return false;
    }

    return true;
}

Text_iterator find_txt(Text_iterator      first,
                       Text_iterator      last,
                       const std::string& str) {
    if (str.size() == 0)
        return last;

    char first_char = str[0];
    while (true) {
        auto p = std::find(first, last, first_char);
        if (p == last || match(p, last, str))
            return p;
        else
            first = ++p;
    }
}

void erase_line(Document& document, int line_number) {
    if (line_number < 0 || document.m_lines.size() - 1 <= line_number)
        return;

    auto p = document.m_lines.begin();
    std::advance(p, line_number);
    document.m_lines.erase(p);
}

std::istream& operator>>(std::istream& i, Document& document) {
    for (char buf; i.get(buf);) {
        /**
         * Az m_lines utolsó sorába, ott is a sor legvégén elhelyezzük
         * a beolvasott karaktert.
         * A .back() metódus az m_lines utolsó elemét adja vissza.
         * szemben a .end()-el, ami az "utolsó utáni" elemet, azaz egy
         * nem létező, szimbolikus elemet.
         */
        document.m_lines.back().push_back(buf);

        if (buf == '\n')
            document.m_lines.push_back(Line{});
    }

    /**
     * Ha az utolsó sor, amibe beolvastunk nem üres,
     * akkor helyezzünk egy üres sort a dokumentum végén.
     * Ha nem így tennénk akkor a következő beolvasást ott folytatná,
     * ahol az előzőt abbahagytuk.
     */
    if (document.m_lines.back().size() != 0)
        document.m_lines.push_back(Line{});

    return i;
}

std::ostream& operator<<(std::ostream& o, Document document) {
    for (auto i : document)
        o << i;
    return o;
}