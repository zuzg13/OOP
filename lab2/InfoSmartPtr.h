#include <iostream>
#include "InfoClass.h"

class InfoSmartPtr {

public:
    InfoSmartPtr(InfoClass *ptr) : mptr(ptr)
    {
        m_counter = new unsigned int;
        *m_counter = 1;
    }
    InfoSmartPtr(const InfoSmartPtr& p)
    {
        copy(p);
    }
    ~InfoSmartPtr()
    {
        del();
    }

    InfoClass* operator -> () const {return this->getPtr();}
    InfoClass& operator *() const {return *mptr;}
    InfoClass& operator *()  {return *mptr;}
    InfoSmartPtr& operator=(const InfoSmartPtr& ptr2);

    
private:
    void copy(const InfoSmartPtr& isp);
    void del();
    InfoClass* getPtr() { return mptr; }
    InfoClass* getPtr() const { return mptr; }
    unsigned int* getCounterPtr() { return m_counter; }
    unsigned int* getCounterPtr() const { return m_counter; }
    InfoClass *mptr;
    unsigned int * m_counter;

};


