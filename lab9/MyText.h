#pragma once

#include "Attributes.h"
#include "MyPrintable.h"

class MyText : public AttColor, public AttFormat, public MyPrintable{
    ///klasa reprezentująca tekst do wydrukowania
    
public:
/**
     * @brief prosty konstruktor ustawiający odpowiednie parametry i inicjalizujący obiekty klasy AttColor i AttFormat
     * @param text - tekst do wydrukowania
     * @param option - ustawiana opcja formatowania tekstu
     * @param color - kolor wydruku
     */
    MyText(const std::string text, AttFormat::Attribute option, AttColor::Attribute color) : AttColor(color), AttFormat(option), m_text(text) {}
    
    /**
     * @brief funkcja ustawiająca nowy tekst
     * @param text - nowy tekst
     */
    void setText(const std::string& text);
    
    ///metody dziedziczone z klasy MyPrintable - opis w pliku "MyPrintable.h"
    /**
     *@brief zwraca tekst przygotowany do wydruku, w tym przypadku po prostu wczytany tekst
     */
    std::string rawString() const override;
    unsigned int getLength() const override;

private:
    std::string m_text;
    
};

void MyText :: setText(const std::string& text)
{
    m_text = text;
}
    
std::string MyText :: rawString() const
{
    return m_text;
}

unsigned int MyText :: getLength() const
{
    return m_text.length();
}