#include "Fixed.hpp"

class Point
{
private:
    Fixed   const x;
    Fixed   const y;

public:

    Point();
    Point(const float n1, const float n2);
    Point(const Point& point);
    Point& operator=(const Point& point);

    const Fixed&   getX() const ;
    const Fixed&  getY() const;

    ~Point();
};
