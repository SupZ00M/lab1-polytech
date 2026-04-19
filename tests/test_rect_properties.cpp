#include <iostream>
#include <cassert>
#include "../src/Rect.hpp"

int main() {
    Rect r1;
    r1.set_width(1);
    r1.set_height(2);
    assert(r1.get_left() == 0);
    assert(r1.get_right() == 1);
    assert(r1.get_top() == 2);
    assert(r1.get_bottom() == 0);
    assert(r1.get_width() == 1);
    assert(r1.get_height() == 2);
    assert(r1.get_square() == 2);
    

    return 0;
}