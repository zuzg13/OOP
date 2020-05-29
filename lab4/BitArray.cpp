#include "BitArray.h"

BitArray :: BitArray(int size, bool wart)
{
    msize = size;
    mtab = new unsigned char[(msize/8)+1];
    for(unsigned int i=0;i<(msize/8)+1 ;i++)
    {
        if(wart)
            mtab[i]=0xFF;

        else
            mtab[i]=0x00;
    }
}

BitArray :: ~BitArray()
{
    delete [] mtab;
    msize = 0;
}

void BitArray :: print() const
{
    unsigned int pom = msize;

    for(unsigned int i = 0; i < msize; i++)
    {
        bool bit = (*this)[msize - i - 1];
        pom--;
        std::cout << bit;
        if(pom%8 == 0)
        {
            std::cout << " <-" << pom << " ";
        }

    }
}


BitArray& BitArray :: operator=(const BitArray& b)
{
    if(this != &b)
    {
         delete [] mtab;
         mtab = new unsigned char[ b.msize/8 + 1];
         msize = b.msize;
         std :: memcpy(mtab, b.mtab, b.msize/8 + 1);
    }
    return *this;

}
BitHelper BitArray :: operator[](unsigned int indx)
{
    return BitHelper(mtab + indx/8, indx%8);
}

const BitHelper BitArray :: operator[](unsigned int indx) const
{
    return BitHelper(mtab + indx/8, indx%8);
}
