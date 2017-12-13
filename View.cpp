#include <iostream>
#include "View.h"

using namespace std;

View::View()
{
    size = 11;
    scale = 2;

    Cart_Point origin(); //is this how? shouldn't defualt constructor work for cart_point?
}

bool View::get_subscripts(int &ix, int &iy, Cart_Point location)
{
    ix = (location.x - origin.x) / scale; //might not work
    iy = (location.y - origin.y) / scale; //truncate fractional part?
    
    if ((ix < size) && (iy < size)) //less than equal to?
    {
        return true;
    }
    else
    {
        cout << "An object is outside the display" << endl;

        return false;
    }
}

void View::clear()
{
    int i;
    for (i = 0; i < size; i++)
    {
        int j;
        for (j = 0; j < size; j++)
        {
            grid[i][j][0] = '.';
            grid[i][j][1] = ' ';
        }
    }
}

void View::plot(Game_Object * ptr)
{
   bool check = false;
   int ix, iy;

   check = get_subscripts(ix, iy, ptr->get_location()); //sufficeint for checking subscripts?

   if (check)
   {
        if (grid[ix][iy][0] == '.')
        {      
            ptr->drawself(grid[ix][iy]);
        }
        else
        {
            grid[ix][iy][0] = '*';
            grid[ix][iy][1] = ' ';
        }   
   }
}

void View::draw()
{
    int i;
    for (i = size - 1; i >= 0; i--)
    {
        int j;
        for (j = 0; j < size; j++)
        {
            if ((j == 0) && ((i % 2) == 0))
            {
                int temp;
                temp = 2 * i;

                if (temp < 10)
                {
                    cout << temp << " ";
                }
                else
                {
                    cout << temp;
                }
            }
             
            if ((j == 0) && ((i % 2) == 1))
            {
                cout << "  ";
            } 

            cout << grid[j][i][0] << grid[j][i][1];

            if (j == size - 1)
            {   
                cout << "\n";
            }

        }
    }

    cout << "  ";

    for (i = 0; i < size; i++)
    {
        if (i % 2 == 0)
        {
            int temp2;
            temp2 = i * 2;

            if (temp2 < 10)
            {
                cout << temp2 << " ";
            }
            else
            {
                cout << temp2;
            }
        }
        else //might not work here, need an else if or just an if
        {
            cout << "  ";
        }
    }

    cout << "\n";

}






