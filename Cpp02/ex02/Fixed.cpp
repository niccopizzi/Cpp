#include "Fixed.hpp"
#include <cmath>

const int Fixed::fractionalBits = 8;

Fixed::Fixed()
{
   // std::cout << "Default constructor called"<<std::endl;
    value = 0;
}

Fixed::Fixed(const int value)
{
    //std::cout << "Int constructor called"<<std::endl;
    this->value = value << fractionalBits;
}

Fixed::Fixed(const float value)
{
    int     new_value;

    new_value = (value * float(1 << fractionalBits));
    this->value = new_value;
   // std::cout << "Float constructor called"<<std::endl;
}

Fixed::Fixed(const Fixed& fixed)
{
   // std::cout << "Copy constructor called"<<std::endl;
    *this = fixed;
}

Fixed& Fixed::operator=(const Fixed& fixed)
{
    //std::cout << "Copy assignment operator called"<<std::endl;
    value = fixed.value;
    return (*this);
}

Fixed::~Fixed()
{
   // std::cout << "Destructor called"<<std::endl;
}

bool    Fixed::operator>(const Fixed& fixed)
{
    return (value > fixed.getRawBits());
}

bool    Fixed::operator<(const Fixed& fixed)
{
    return (value < fixed.getRawBits());
}

bool    Fixed::operator>=(const Fixed& fixed)
{
    return (value >= fixed.getRawBits());
}

bool    Fixed::operator<=(const Fixed& fixed)
{
    return (value <= fixed.getRawBits());
}

bool    Fixed::operator==(const Fixed& fixed)
{
    return (value == fixed.getRawBits());
}

bool    Fixed::operator!=(const Fixed& fixed)
{
    return (value != fixed.getRawBits());
}

Fixed    Fixed::operator+(const Fixed& fixed)
{
    return (Fixed(value + fixed.getRawBits()));
}

Fixed    Fixed::operator-(const Fixed& fixed)
{
    return (Fixed(value - fixed.getRawBits()));
}
    
Fixed    Fixed::operator*(const Fixed& fixed)
{
    return (Fixed((value * fixed.getRawBits()) >> fractionalBits));
}

Fixed   Fixed::operator/(const Fixed& fixed)
{
    return (Fixed((value << fractionalBits) / fixed.getRawBits()));
}

int     Fixed::operator++()
{
    return (this->value +=  std::numeric_limits<float>::epsilon());
}

int     Fixed::operator++(int dummyVar)
{
    Fixed temp = *this;
    this->value += std::numeric_limits<float>::epsilon();
    return (temp.value);
}

int     Fixed::operator--()
{
    return (this->value -= std::numeric_limits<float>::epsilon());
}

int     Fixed::operator--(int dummyVar)
{
    Fixed temp = *this;
    this->value -= std::numeric_limits<float>::epsilon();
    return (temp.value);
}

int Fixed::getRawBits() const
{
    //std::cout << "getRawBits member function called"<<std::endl;
    return (value);
}

void Fixed::setRawBits(int const raw)
{
    value = raw;
}

float Fixed::toFloat(void) const
{
    std::cout << "float value " << (float)value;
    return ((float(value) / float(1 << fractionalBits)));
}

int Fixed::toInt(void) const
{
    return (value /( 1 << fractionalBits));
}


Fixed& Fixed::max(Fixed& fixed1, Fixed& fixed2)
{
    if (fixed1 >= fixed2)
        return (fixed1);
    return (fixed2);
}

/* Fixed& Fixed::max(const Fixed& fixed1, const Fixed& fixed2)
{
    if (fixed1 >= fixed2)
        return (fixed1);
    return (fixed2);
} */
 
Fixed& Fixed::min(Fixed& fixed1, Fixed& fixed2)
{
    if (fixed1 <= fixed2)
        return (fixed1);
    return (fixed2);
}

/* Fixed& Fixed::min(const Fixed& fixed1, const Fixed& fixed2)
{
    if (fixed1 = fixed2)
        return (fixed1);
    return (fixed2);
} */

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    return (os << fixed.toFloat());
}