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

    bool operator==(const Point& arg) const
    {
        return x == arg.x && y == arg.y ? true : false;
    }

    int GetX() const { return x; }
    int GetY() const { return y; }
};

const bool operator!=(const Point& arg1, const Point& arg2)
{
    return arg1.GetX() != arg2.GetX() || arg1.GetY() != arg2.GetY() ? true : false;
}

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

    if (p1 == p2)
    {
        // do nothing
    }
    else
    {
        cout << "p1 != p2" << endl;
    }

    if (p1 != p2)
    {
        cout << "p1 != p2" << endl;
    }

    if (operator!=(p1, p2))
    {
        cout << "p1 != p2" << endl;
    }

    return 0;
}