#pragma once

#include "Attributes.h"
#include "MyPrintable.h"

class MyLine : public AttColor, public MyPrintable {
    ///klasa reprezentująca linię do wydrukowania, złożoną z powstarzającego się znaku np. *
    
public:
    /**
     * @brief prosty konstruktor ustawiający odpowiednie parametry i inicjalizujący obiekt klasy AttColor
     * @param znak - znak do ustawienia
     * @param length - długosc linii do wydrukowania
     * @param o - kolor wydruku
     */
    MyLine(char znak, unsigned int length, AttColor::Attribute o) : AttColor(o), m_znak(znak), m_length(length) {}
    
    /**
     * @brief funkcja ustawiająca nową długosć linii
     * @param length - nowa dlugosc
     */
    void setLength(unsigned int length);
    /**
     * @brief funkcja ustawiająca nowy znak
     * @param znak - nowy znak
     */
    void setChar(char znak);
    
    ///metody dziedziczone z klasy MyPrintable - opis w pliku "MyPrintable.h"
    /**
     *@brief zwraca tekst przygotowany do wydruku, tzn. "mnoży" znak linii razy jej długość i zwraca gotowy string
     */
    std::string rawString() const override;
    unsigned int getLength() const override;

private:
    char m_znak;
    unsigned int m_length;
    
};


void MyLine :: setLength(unsigned int length)
{
    m_length = length;
}

void MyLine :: setChar(char znak)
{
    m_znak = znak;
}
    
std::string MyLine :: rawString() const
{
    return std::string(m_length, m_znak);
}

unsigned int MyLine :: getLength() const
{
    return m_length;
}