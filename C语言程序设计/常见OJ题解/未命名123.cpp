#include <iostream>

struct Vector3
{
    int x,y,z;
};

int main()
{
    //usage of arrow operator//
    long long offset =(long long)&((Vector3 *)a=0)->y;
    std::cout << offset << std::endl;

    return 0;
}