#pragma once

#include <iostream>
#include <string>

using std::string;

class Mean{
    ///abstrakcyjna klasa-interfejs reprezentująca średnią
    
public:
    ///prosty konstruktor, który ustawia początkowe wartości na zero
    Mean() : m_dzielnik(0), m_n(0) {}
    virtual ~Mean() = default;
    
    ///funkcja wirtualna zwracająca string z rodzajem średniej np. "Arithmetic"
    virtual string print() const = 0;
    /**
     * @brief wirtualny, przeciazony operator<< umozliwiajacy dodanie nowej wartosci do obliczanej sredniej
     * @param val - dodawana wartość
     * @return referencje do obiektu, do którego dodaliśmy wartość
     */
    virtual Mean& operator<<(double val) = 0;
    /**
     * @brief wirtualna funkcja zwracająca obliczoną średnią danego typu
     * @return odpowiednia średnia dla wczytanych wartosci lub 0 gdy nie bylo wczytanych wartosci
     */
    virtual double result() const = 0;
    ///funkcja umożliwiająca wyzerowanie wczytywanych wartości, dzieki czemu mozna rozpoczac obliczanie nowej sredniej 
    void reset();
    
    /**
     * @brief zaprzyjazniona funkcja umozliwiajaca wyswietlanie informacji o rodzaju sredniej
     * @param ostr - strumien do ktorego przekazywany jest tekst z informacja
     * @param m - obiekt o ktorym informacje wyswietlamy
     * @return strumien wyjsciowy z wczytanym tekstem
     */
    friend std::ostream& operator<<(std::ostream& ostr, const Mean& m);
    /**@brief przeciazony operator<< dla przypadku, gdy probujemy dodac nowe wartosci do obiektu który jest niemodyfikowalny (const)
     * Funkcja wyswietli odpowiedni komunikat o błedzie
     * @param m  - obiekt do którego chcemy wczytać wartości
     * @val - wartosc do wczytania
     * @return referencja na obiekt, do którego chcielismy wczytac wartosci
     */
    friend const Mean& operator<<(const Mean& m, double val);


protected:
    double m_dzielnik;
    int m_n;
    
};


void Mean :: reset()
{  
    m_dzielnik = 0;
    m_n = 0;
}

std::ostream& operator<<(std::ostream& ostr, const Mean& m)
{
    ostr << m.print();
    return ostr;
}

const Mean& operator<<(const Mean& m, double val)
{
    std ::  cout << "ERROR: cannot add value " <<  val <<  " to const " << m.print() << " Mean" <<  std :: endl;
    return m;
}


