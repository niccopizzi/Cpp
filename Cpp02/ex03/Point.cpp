#include "Point.hpp"

Point::Point() : x(0), y(0)
{
}

Point::Point(const float n1, const float n2) : x(n1), y(n2)
{
}

Point::~Point()
{
    std::cout << "Point destructor called\n";
}

Point::Point(const Point& point) : x(point.x.getRawBits()), y(point.y.getRawBits())
{

}

Point& Point::operator=(const Point& point) = delete;

const Fixed&  Point::getX() const
{   
    return (x);
}

const Fixed&  Point::getY() const
{   
    return (y);
}