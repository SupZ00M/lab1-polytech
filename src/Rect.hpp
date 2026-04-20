#include <iostream>
#include <cstdlib> 
using namespace std;
class Rect
{
private:

//int l,r;
//int t,b;
int l,b;
int w,h;

public:
//constructors and destructor
Rect();
Rect(int l,int r,int t,int b);
Rect(const Rect &rect );
~Rect();


int get_left();
int get_right();
int get_bottom();
int get_top();
int get_width();
int get_height();
int get_square();

void set_all(int X1, int X2, int Y1, int Y2);

void inflate(int dl, int dr, int dt, int db);

void inflate(int dw, int dh);

void inflate(int da);

void move(int dw, int dh=0);

void set_height(int height);
void set_width(int width);
friend Rect bounding_rect(const Rect &r1, const Rect &r2);
friend void print_rect(const Rect &r);
};
Rect bounding_rect(const Rect &r1, const Rect &r2);
void print_rect(const Rect &r);