#include <iostream>

class Fixed
{
private:
    int              value;
    static const int fractionalBits;
public:

    Fixed();
    Fixed(const Fixed& fixed);
    Fixed& operator=(const Fixed& fixed);
    ~Fixed();

    int     getRawBits(void) const;
    void    setRawBits(int const raw);
};
