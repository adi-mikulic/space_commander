#include <iostream>
#include <cmath>
#include "Cart_Point.h"
using namespace std;

Cart_Point::Cart_Point()
{
    x = 0.0;
    y = 0.0;
}

Cart_Point::Cart_Point(double inputx, double inputy)
{
    x = inputx;
    y = inputy;
}

double cart_distance(Cart_Point &p1, Cart_Point &p2)
{
    double x = (p2.x - p1.x) * (p2.x - p1.x);
    double y = (p2.y - p1.y) * (p2.y - p1.y);

    return sqrt(x + y);
}

ostream& operator<< (ostream& out, const Cart_Point &p1)
{
    cout << "(" << p1.x << "," << p1.y << ")";
}

Cart_Point operator+ (const Cart_Point &p1, const Cart_Vector &v1)
{
    double x = p1.x + v1.x;
    double y = p1.y + v1.y;

    return Cart_Point(x,y);
}

Cart_Vector operator- (const Cart_Point &p1, const Cart_Point &p2)
{

    double x = p1.x - p2.x;
    double y = p1.y - p2.y;

    return Cart_Vector(x,y);
}