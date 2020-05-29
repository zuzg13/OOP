#include "Mean.h"

class HarmonicMean : public Mean{
    
public:
    HarmonicMean() = default;
    
    ///wirtualne funkcje opisane szerzej w klasie-interfejsie
    string print() const override;
    Mean& operator <<(double val) override;
    double result() const override;
    
    /**
     * @brief statyczna funkcja pozwalajaca na utworzenie nowego obiektu tej klasy
     * @return wskaznik do nowoutworzonego obiektu
     */
    static HarmonicMean* create();

};

string HarmonicMean::print() const
{
    return "Harmonic";
}

Mean& HarmonicMean::operator<<(double val)
{
    m_dzielnik += 1./val;
    m_n += 1;
    return *this;
}

double HarmonicMean::result() const
{
    if(m_n==0)
        return 0;
    else
        return m_n/m_dzielnik;
}

HarmonicMean* HarmonicMean::create()
{
    HarmonicMean *h = new HarmonicMean();
    return h;
}



