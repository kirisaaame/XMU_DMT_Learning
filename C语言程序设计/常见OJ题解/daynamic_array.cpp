#include <iostream>
#include <vector>
struct Vertex
{
    float x,y,z;

    Vertex(float x, float y,float z) :x(x),y(y),z(z) 
    {
        std::cout << "Copied!" << '\n';
    }

};
std::ostream& operator<<(std::ostream& stream, const Vertex& vertex)
{
    stream << vertex.x << ", " << vertex.y << ", " << vertex.z;
    return stream;
}
int main()
{
    /*different from standard array,dynamic array has changable length*/

    //initialize
    std::vector<int> v(10);//<-initial size
    //avoid copy vector class
    std::vector <Vertex> vertices;
    vertices.push_back(Vertex(1,2,3));
    vertices.push_back(Vertex(4,5,6));
    //this is differnet when you create a vector of object:
    std::vector<Vertex> vertices1(3);
    //object donot have default construct function, compile error
    std::vector<Vertex> vertices2;
    vertices2.reserve(3);
    //can be compiled
    

    //when create a dynamic object vector, use emplace_back
    vertices2.emplace_back(Vertex{1,2,3});//only porvide arguments to constructor

    return 0;
}