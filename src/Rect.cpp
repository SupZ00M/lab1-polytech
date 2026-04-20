#include <iostream>
#include <cstdlib> 
#include "Rect.hpp"
using namespace std;
//constructors and destructor
Rect::Rect (){
l=0;
//r=0;
//t=0;
b=0;
h=0;
w=0;
cout << "I'm defult constructor [" << this << "]" << endl;
}

Rect::Rect (int X1, int X2, int Y1, int Y2){
if (X1>X2) {
     l=X2;
     //r=X1;
     w=X1-X2;
}
else {
    //r=X2;
    l=X1;
    w=X2-X1;
}
if (Y1>Y2) {
     b=Y2;
     //t=Y1;
     h=Y1-Y2;
}
else {
    //t=Y2;
    b=Y1;
    h=Y2-Y1;
}
cout << "I'm constructor [" << this << "]"  << endl;
}

Rect::Rect (const Rect &rect){
l=rect.l;
//r=rect.r;
//t=rect.t;
b=rect.b;
w=rect.w;
h=rect.h;
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
  //return r;
  return l+w;
}
int Rect::get_bottom(){
  return b;
}
int Rect::get_top(){
  //return t;
  return b+h;
}
int Rect::get_width(){
  //return r-l;
  return w;
}
int Rect::get_height(){
  //return t-b;
  return h;
}
int Rect::get_square(){
  //return (t-b)*(r-l);
  return w*h;
}


void Rect::set_all(int X1, int X2, int Y1, int Y2){
if (X1>X2) {
     l=X2;
     //r=X1;
     w=X1-X2;
}
else {
    //r=X2;
    l=X1;
    w=X2-X1;
}
if (Y1>Y2) {
     b=Y2;
     //t=Y1;
     h=Y1-Y2;
}
else {
    //t=Y2;
    b=Y1;
    h=Y2-Y1;
}
}
void Rect::inflate(int dl, int dr, int dt, int db){
  //set_all(l-dl, r+dr, b-db, t+dt);
  set_all(l-dl, l+w+dr, b-db, b+h+dt);
}

void Rect::inflate(int dw, int dh){
   //set_all(l-dw, r+dw, b-dh, t+dh);
   set_all(l-dw, l+w+dw, b-dh, b+h+dh);
}

void Rect::inflate(int da){
    //set_all( l-da, r+da, b-da, t+da);
    set_all( l-da, l+w+da, b-da, b+h+da);
}

void Rect::move(int dw, int dh){
//set_all(l+dw, r+dw, b+dh, t+dh);
set_all(l+dw, l+w+dw, b+dh, b+h+dh);
}

void Rect::set_height(int height) {
  //set_all(l, r, b+height, b);
  h=height;
}
void Rect::set_width(int width){
  //set_all(l, l+width, t, b);
  w=width;
}

Rect bounding_rect(const Rect &r1, const Rect &r2){
int L=r1.l;
//int R=r1.r;
//int T=r1.t;
int B=r1.b;
int R=r1.l+r1.w;
int T=r1.b+r1.h;
/*if (L>r2.l) {
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
}*/
if (L>r2.l) {
     L=r2.l;
}
if (B>r2.b) {
     B=r2.b;
}
if (R<r2.l+r2.w) {
     R=r2.l+r2.w;
}
if (T<r2.b+r2.h) {
     T=r2.b+r2.h;
}



return Rect(L,R,T,B);
}
void print_rect(const Rect &r){
/*cout << "  __ " << r.t << " __ " << endl;
cout << r.l << "|      |"  << r.r << endl;
cout << "  __ " << r.b << " __ " << endl;*/

cout << "  __ " << r.b+r.h << " __ " << endl;
cout << r.l << "|      |"  << r.l+r.w << endl;
cout << "  __ " << r.b << " __ " << endl;

};