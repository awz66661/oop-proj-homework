#include "bird.h"
// We have given you the header file `bird.h`.
// You should read class `Bird` carefully
// and implement the member functions in `bird.cpp`.
// TODO: Please implement the member functions of class `Bird`.
/* Your code here */

Bird::Bird(double _x, double _y, double _vx, double _vy, double _ax, double _ay){
    this->x = _x;
    this->y = _y;
    this->vx = _vx;
    this->vy = _vy;
    this->ax = _ax;
    this->ay = _ay;
}

std::pair<int, int> Bird::get_pos() const{
    std::pair<int,int> temp(round(x),round(y));
    return temp;
}

std::pair<double, double> Bird::get_v() const{
    std::pair<double,double> temp(vx,vy);
    return temp;
}

std::pair<double, double> Bird::get_a() const{
    std::pair<double,double> temp(ax,ay);
    return temp;
}

void Bird::set_pos(int _x, int _y){
    x = _x;
    y = _y;
}

void Bird::set_v(double _vx, double _vy){
    vx = _vx;
    vy = _vy;
}

void Bird::set_a(double _ax, double _ay){
    ax = _ax;
    ay = _ay;
}

void Bird::tick(){
    vx = vx + ax;
    vy = vy + ay;
    double delta_x = vx + 0.5*ax;
    double delta_y = vy + 0.5*ay;
    x = x + delta_x;
    y = y + delta_y;
}




