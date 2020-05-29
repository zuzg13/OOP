#include "InfoSmartPtr.h"


InfoSmartPtr& InfoSmartPtr :: operator=(const InfoSmartPtr& ptr2)
{
    del();
    copy(ptr2);
    return *this;

}


void InfoSmartPtr :: copy(const InfoSmartPtr& isp)
{
    mptr = isp.getPtr();
    m_counter = isp.getCounterPtr();
    (*m_counter)++;
}
void InfoSmartPtr :: del()
{
    if(*m_counter == 1)
    {
        delete mptr;
        delete m_counter;
    }
    else
    {
        (*m_counter)--;
    }
}