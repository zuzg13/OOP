#include "MaszynaStanow.h"


MaszynaStanow :: ~MaszynaStanow()
{
    for(unsigned int i=0; i<mlistastanow.size(); ++i)
    {
        delete mlistastanow[i];
    }
}

MaszynaStanow & MaszynaStanow :: operator+= (Stan *st)
{
    st->set(this);
    mlistastanow.push_back(st);
    return *this;
}

Stan& MaszynaStanow :: operator()()
{
    return *mlistastanow[mcurelement];
}

void MaszynaStanow :: start()
{
    std::cout << "Rozpoczynamy dzialanie maszyny stanow!" << std::endl;
    mcurelement = 0;
}

void MaszynaStanow :: operator++()
{
    if(mcurelement<mlistastanow.size()-1)
    {
        ++mcurelement;
    }
}
void MaszynaStanow :: operator--()
{
    if(mcurelement>0)
    {
        --mcurelement;
    }
}

void MaszynaStanow :: print(std::ostream & ostr) const
{
    for(unsigned int i=0; i<mlistastanow.size(); ++i)
    {
        if(i==mcurelement)
        {
            std::cout << ">" << mlistastanow[i]->nazwa() << "< ";
        }
        else
        {
            std::cout << mlistastanow[i]->nazwa() << " ";
        }
    }
}

void MaszynaStanow :: podsumowanie() const
{
    for(unsigned int i=0; i<mlistastanow.size(); ++i)
    {
        mlistastanow[i]->podsumowanie();
    }
}