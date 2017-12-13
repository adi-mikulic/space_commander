#include <iostream>
#include "Cart_Vector.h"
using namespace std;

Cart_Vector::Cart_Vector()
{
    x = 0.0;
    y = 0.0;
}

Cart_Vector::Cart_Vector(double inputx, double inputy)
{
    x = inputx;
    y = inputy;
}

Cart_Vector operator* (const Cart_Vector &v1, double d)
{
    double x = v1.x * d;
    double y = v1.y * d;

    return Cart_Vector(x,y);
}

Cart_Vector operator/ (const Cart_Vector &v1, double d)
{

    double x;
    double y;

    if (d == 0)
    {
        x = v1.x;
        y = v1.y;
    }

    else
    {
        x = v1.x / d;
        y = v1.y / d;
    }

    return Cart_Vector(x,y);
}

ostream& operator<< (ostream& out, const Cart_Vector &v1)
{
    cout << "<" << v1.x << "," << v1.y << ">";
}
