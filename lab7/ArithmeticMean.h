#include "Mean.h"

class ArithmeticMean : public Mean{
   ///klasa reprezentujaca srednia arytmetyczną
   
public:
    ArithmeticMean() = default;
    
    ///wirtualne funkcje opisane szerzej w klasie-interfejsie
    string print() const override;
    Mean& operator<<(double val) override;
    double result() const override;
    
    /**
     * @brief statyczna funkcja pozwalajaca na utworzenie nowego obiektu tej klasy
     * @return wskaznik do nowoutworzonego obiektu
     */
    static ArithmeticMean* create();

};

string ArithmeticMean::print() const
{
    return "Arithmetic";
}

Mean& ArithmeticMean::operator<<(double val)
{
    m_dzielnik += val;
    m_n += 1;
    return *this;
}


double ArithmeticMean::result() const
{
    if(m_n == 0)
        return 0;
    else
        return m_dzielnik/m_n;
}

ArithmeticMean* ArithmeticMean::create()
{
    ArithmeticMean *a = new ArithmeticMean();
    return a;
}