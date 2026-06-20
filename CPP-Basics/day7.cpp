#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int size = 15;

    for(int y = size; y >= -size; y--)
    {
        for (int x = -size; x <= size; x++)
        {
            double normalized_x = (double)x / (size * 0.7);
            double normalized_y = (double)y / (size * 0.6);

            double expression = pow(normalized_x * normalized_x + normalized_y * normalized_y - 1, 3) - normalized_x * normalized_x * pow(normalized_y , 3);

            if(expression <= 0.0)
            {
                cout<<"*"<<endl;

            }
            else
            {
                cout<<""<<endl;
            }

        }
    }
    return 0;

}