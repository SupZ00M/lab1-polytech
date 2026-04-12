#include <iostream>
using namespace std;
class Rect
{
private:

int x,y;
int a,b;

public:
Rect (){
x=0;
y=0;
a=0;
b=0;
cout << "I'm defult constructor [" << this << "]" << endl;
}

Rect (int X, int Y, int A, int B){
x=X;
y=Y;
a=A;
b=B;
cout << "I'm constructor [" << this << "]"  << endl;
}

Rect (Rect &rect){
x=rect.x;
y=rect.y;
a=rect.a;
b=rect.b;
cout << "I'm copy constructor [" << this << "]" << endl;
}

~Rect (){
cout << "I'm destructor [" << this << "]" << endl;
}

};