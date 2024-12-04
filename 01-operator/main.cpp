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
        cout << x << ", " << y << endl;
    }

    Point operator+(Point arg) const
    {
        Point a;
        
        a.x = x + arg.x;
        a.y = y + arg.y;

        return a;
    }

    const Point& operator++() // 전위 연산자
    {
        ++x;
        ++y;

        return *this;
    }

    const Point operator++(int) // 후위 연산자
    {
        Point pt(x, y);
        ++x;
        ++y;

        return pt;
    }
};

int main()
{
    Point p1(2, 3), p2(5, 5);
    Point ret;

    ret = p1 + p2;
    ret.Print();

    ret = p1.operator+(p2);
    ret.Print();

    ret = ++p1;
    ret.Print();
    
    ret = p2++;
    ret.Print();
    p2.Print();

    return 0;
}