#include <iostream>
#include <cassert>
#include "../src/Rect.hpp"

int main() {
    Rect r1;
    assert(r1.get_left() == 0);
    assert(r1.get_right() == 0);
    assert(r1.get_top() == 0);
    assert(r1.get_bottom() == 0);

    Rect r2(3,2,5,10);
    assert(r2.get_left() == 2);
    assert(r2.get_right() == 3);
    assert(r2.get_top() == 10);
    assert(r2.get_bottom() == 5);

    r1.set_all(1,2,1,2);
    assert(r1.get_left() == 1);
    assert(r1.get_right() == 2);
    assert(r1.get_top() == 2);
    assert(r1.get_bottom() == 1);

    return 0;
}
