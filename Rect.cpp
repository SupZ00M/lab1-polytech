#include <iostream>
#include <cstdlib> 
#include "Rect.hpp"
using namespace std;
//constructors and destructor
Rect::Rect (){
l=0;
r=0;
t=0;
b=0;
cout << "I'm defult constructor [" << this << "]" << endl;
}

Rect::Rect (int X1, int X2, int Y1, int Y2){
if (X1>X2) {
     l=X2;
     r=X1;
}
else {
    r=X2;
    l=X1;
}
if (Y1>Y2) {
     b=Y2;
     t=Y1;
}
else {
    t=Y2;
    b=Y1;
}
cout << "I'm constructor [" << this << "]"  << endl;
}

Rect::Rect (const Rect &rect){
l=rect.l;
r=rect.r;
t=rect.t;
b=rect.b;
cout << "I'm copy constructor [" << this << "]" << endl;
}

Rect::~Rect (){
cout << "I'm destructor [" << this << "]" << endl;
}


//methods
int Rect::get_left(){
  return l;
}
int Rect::get_right(){
  return r;
}
int Rect::get_bottom(){
  return b;
}
int Rect::get_top(){
  return t;
}
int Rect::get_width(){
  return r-l;
}
int Rect::get_height(){
  return t-b;
}
int Rect::get_square(){
  return (t-b)*(r-l);
}


void Rect::set_all(int X1, int X2, int Y1, int Y2){
if (X1>X2) {
     l=X2;
     r=X1;
}
else {
    r=X2;
    l=X1;
}
if (Y1>Y2) {
     b=Y2;
     t=Y1;
}
else {
    t=Y2;
    b=Y1;
}
}
void Rect::inflate(int dl, int dr, int dt, int db){
  set_all(l-dl, r+dr, b-db, t+dt);
}

void Rect::inflate(int dw, int dh){
   set_all(l-dw, r+dw, b-dh, t+dh);
}

void Rect::inflate(int da){
    set_all( l-da, r+da, b-da, t+da);
}

void Rect::move(int dw, int dh){
set_all(l+dw, r+dw, b+dh, t+dh);
}

void Rect::set_height(int height) {
  set_all(l, r, b+height, b);
}
void Rect::set_width(int width){
  set_all(l, l+width, t, b);
}

Rect bounding_rect(const Rect &r1, const Rect &r2){
int L=r1.l;
int R=r1.r;
int T=r1.t;
int B=r1.b;
if (L>r2.l) {
     L=r2.l;
}
if (B>r2.b) {
     B=r2.b;
}
if (R<r2.r) {
     R=r2.r;
}
if (T<r2.t) {
     T=r2.t;
}
return Rect(L,R,T,B);
}
void print_rect(const Rect &r){
cout << "  __ " << r.t << " __ " << endl;
cout << r.l << "|      |"  << r.r << endl;
cout << "  __ " << r.b << " __ " << endl;
};