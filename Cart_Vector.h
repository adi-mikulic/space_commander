#ifndef CART_VECTOR_H
#define CART_VECTOR_H

#include <iostream>
using namespace std;

class Cart_Vector
{
public:

    Cart_Vector();
    Cart_Vector(double inputx, double inputy);

    double x;
    double y;

    friend ostream& operator<< (ostream& out, const Cart_Vector &v1);
};

Cart_Vector operator* (const Cart_Vector &v1, double d);

Cart_Vector operator/ (const Cart_Vector &v1, double d);

#endif

