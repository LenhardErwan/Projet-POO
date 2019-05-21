#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>

typedef unsigned int uint;
//les coordon�e d'un point sont enti�re car il est possible d'avoir des point avec des coordonn�es n�gatives

namespace fm {

class Point {
    static const uint TAILLE = 3;
    int x,y;

	public:
    Point(int _x, int _y);
    Point(const Point &ori);
    Point(std::istream &is);
    ~Point();
    inline uint getTaille() const {return TAILLE;}
    inline int getX() const {return x;}
    inline int getY() const {return y;}
    inline void setX(int _x) {x = _x;}
    inline void setY(int _y) {y = _y;}
    inline void setXY(int _x, int _y) {x=_x; y=_y;}
    friend std::ostream & operator<<(std::ostream &os, const Point & p);
    friend std::istream & operator>>(std::istream &is, Point & p);
};

}//namespace

#endif POINT_HPP