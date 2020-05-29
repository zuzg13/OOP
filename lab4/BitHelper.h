#include <iostream>

class BitHelper{

public:
    /**
     * @brief Construct new object
     * @param bit - pointer to bit
     * @param indx - index of this bit in array
     */
    BitHelper(unsigned char *bit, unsigned int indx): mbit(bit), mindx(indx) {}

    /**
     * @brief overloaded operator=, changes value of bit
     * @param wart - new value
     * @return new version of bit
     */
    BitHelper& operator=(bool wart)
    {
        if(wart)
        {
            *mbit = *mbit | 1 << mindx;
        }
        else
        {
            *mbit = *mbit & ~(1 << mindx);
        }
        return *this;
    }
    /**
     * Overloaded operator bool()
     * @return value of bit
     */
    operator bool() const
    {
        return static_cast<bool>(*mbit & (1 << mindx));
    }

private:
    unsigned char * mbit;
    int mindx;
};


