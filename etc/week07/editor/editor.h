#ifndef __EDITOR_H__
#define __EDITOR_H__

#include <istream>
#include <list>
#include <ostream>
#include <string>
#include <vector>

using Line = std::vector<char>;

/**
 * Előre deklaráljuk a Text_iterator osztályt,
 * hogy a Document-ben tudjunk rá hivatkozni.
 */
class Text_iterator;

struct Document {
    std::list<Line> m_lines;
    Document();

    Text_iterator begin();
    Text_iterator end();
};

class Text_iterator {
public:
    typedef std::forward_iterator_tag iterator_category;
    typedef char                      value_type;
    typedef size_t                    difference_type;
    typedef char*                     pointer;
    typedef char&                     reference;

public:
    Text_iterator(std::list<Line>::iterator line_number,
                  Line::iterator            position);

    char&          operator*();
    Text_iterator& operator++();
    bool           operator==(const Text_iterator& rhs) const;
    bool           operator!=(const Text_iterator& rhs) const;

private:
    std::list<Line>::iterator m_line_number;
    Line::iterator            m_position;
};

bool match(Text_iterator first, Text_iterator last, const std::string str);

Text_iterator find_txt(Text_iterator      first,
                       Text_iterator      last,
                       const std::string& str);

void erase_line(Document& document, int n);

std::istream& operator>>(std::istream& i, Document& document);

// Ezzel letudtuk a void print(Document& d) függvényt
std::ostream& operator<<(std::ostream& o, Document document);

#endif  // __EDITOR_H__