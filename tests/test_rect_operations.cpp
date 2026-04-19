#include <iostream>
#include <cassert>
#include "../src/Rect.hpp"

int main() {
    Rect r1;
    r1.inflate(2);
    assert(r1.get_left() == -2);
    assert(r1.get_right() == 2);
    assert(r1.get_top() == 2);
    assert(r1.get_bottom() == -2);
    r1.inflate(2,-3);
    assert(r1.get_left() == -4);
    assert(r1.get_right() == 4);
    assert(r1.get_top() == 1);
    assert(r1.get_bottom() == -1);
    r1.inflate(-4,0,0,-1);
    assert(r1.get_left() == 0);
    assert(r1.get_right() == 4);
    assert(r1.get_top() == 1);
    assert(r1.get_bottom() == 0);
    r1.move(-4);
    assert(r1.get_left() == -4);
    assert(r1.get_right() == 0);
    assert(r1.get_top() == 1);
    assert(r1.get_bottom() == 0);
    r1.move(0,-1);
    assert(r1.get_left() == -4);
    assert(r1.get_right() == 0);
    assert(r1.get_top() == 0);
    assert(r1.get_bottom() == -1);


    

    return 0;
}