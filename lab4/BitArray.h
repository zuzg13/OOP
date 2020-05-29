#include <iostream>
#include <cstring>
#include "BitHelper.h"


class BitArray {

public:
    /**
     * @brief Construct new object
     * @param size - size of bit array
     * @param wart - value to set
     */
    BitArray(int size, bool wart=false);
    ~BitArray();

    /**
     * @brief print bit array
     */
    void print() const;
    /**
     * @brief overloaded operator=, copy one object to another
     * @param b - BitArray object to copy
     * @return new version of this
     */
    BitArray& operator=(const BitArray& b);
    /**
     * @brief overloaded operator[], gives access to single bit
     * @param indx  - index of bit
     * @return value of bit
     */
    BitHelper operator[](unsigned int indx);
    const BitHelper operator[](unsigned int indx) const;


private:
    unsigned int msize;
    unsigned char *mtab;

};

