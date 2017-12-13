#ifndef CART_POINT_H
#define CART_POINT_H

#include <iostream>
#include "Cart_Vector.h"
using namespace std;

class Cart_Point
{
public:

    Cart_Point();
    Cart_Point(double inputx, double inputy);

    double x;
    double y;

    friend ostream& operator<< (ostream& out, const Cart_Point &p1);
};

double cart_distance(Cart_Point &p1, Cart_Point &p2);

Cart_Point operator+ (const Cart_Point &p1, const Cart_Vector &v1);

Cart_Vector operator- (const Cart_Point &p1, const Cart_Point &p2);

#endif

