#include <iostream>
#include <cassert>
#include "../src/Rect.hpp"

int main() {
    Rect r1(0,1,2,0);
    Rect r2(2,1,2,3);
    Rect r3 = bounding_rect(r1,r2);
    assert(r3.get_left() == 0);
    assert(r3.get_right() == 2);
    assert(r3.get_top() == 3);
    assert(r3.get_bottom() == 0);

    return 0;
}