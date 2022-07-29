#include "bird.h"

#include <cmath>

const double g = 0.1;
const double v_tap_up = -1;
const double v_tap_left = -1;
const double a_tap_left = 0.1;
const double v_tap_right = 1;
const double a_tap_right = -0.1;

Bird::Bird(double x, double y, double vx, double vy, double ax, double ay)
    : x(x), y(y), vx(vx), vy(vy), ax(ax), ay(ay) {}

std::pair<int, int> Bird::get_pos() const {
    return std::make_pair((int)std::round(x), (int)std::round(y));
}
std::pair<double, double> Bird::get_v() const { return std::make_pair(vx, vy); }
std::pair<double, double> Bird::get_a() const { return std::make_pair(ax, ay); }
void Bird::set_pos(int _x, int _y) {
    x = _x;
    y = _y;
}

void Bird::set_v(double _vx, double _vy) {
    vx = _vx;
    vy = _vy;
}

void Bird::set_a(double _ax, double _ay) {
    ax = _ax;
    ay = _ay;
}

void Bird::draw(Display& display) const {
    // TODO: draw the bird on the display
    // hint: you should check if the bird is inside the display
    /* Your code here */
    int limit_x = display.get_cols() - 1;
    int limit_y = display.get_rows() - 1;
    if(this->x <= limit_x && this->x >=0 && this->y <= limit_y && this->y >= 0){
        display.put_string(this->x,this->y,"@");
    }
}

bool Bird::is_inside(int x, int y) const {
    // TODO: check if position (x, y) is inside bird
    /* Your code here */
    if (x >= this->x && x <= this->x + 0 && y >= this->y &&
        y <= this->y + 0) {
        return true;
    }
    return false;
}

void Bird::tick(int key) {
    // TODO: update the bird's properties according to key input
    /* Your code here */
    if(key == ' '){
        this->set_v(vx,v_tap_up*1.0);
    }else if(key == 'z'){
        this->set_v(v_tap_left,vy);
    }else if(key == 'x'){
        this->set_v(v_tap_right,vy);
    }
    if(vx > 0){
        this->set_a(a_tap_right,g);
        if(vx + a_tap_right < 0){
            this->set_a(0.0,g);
        }
    }else if(vx < 0){
        this->set_a(a_tap_left,g);
        if(vx + a_tap_left > 0){
            this->set_a(0.0,g);
        }
    }else{
        this->set_a(0.0,g);
    }
    vx = vx + ax;
    vy = vy + ay;
    double delta_x = vx + 0.5*ax;
    double delta_y = vy + 0.5*ay;
    x = x + delta_x;
    y = y + delta_y;
}

bool Bird::detect_collide(Object& obj) {
    // TODO: detect collision with the specified object
    /* Your code here */
    // if(obj.is_inside(this->x,this->y)){
    //     this->valid = false;
    //     return true;
    // }
    // return false;

    for (int i = 0; i < 1; i++) {
        for (int j = 0; j < 1; j++) {
            if (obj.is_inside(this->x + i, this->y + j)) {
                valid = false;
                return true;
            }
        }
    }
    return false;
}