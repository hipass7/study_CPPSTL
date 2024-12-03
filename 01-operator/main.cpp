#include <iostream>
using namespace std;

class Point
{
    int x;
    int y;
public:
    Point (int _x = 0, int _y = 0) : x(_x), y(_y) {}

    void Print() const
    {
        cout << x << ',' << y << endl;
    }

    Point operator+(Point arg)
    {
        Point a;
        cout << "operator+() 함수 호출" << endl;
        
        a.x = x + arg.x;
        a.y = y + arg.y;
    }
};

int main()
{
    Point p1(2, 3), p2(5, 5);
    Point ret;

    ret = p1 + p2;

    return 0;
}