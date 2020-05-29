#pragma once

class AttColor{
    ///klasa reprezentująca wybraną opcję koloru wydruku
public:
    
    /**
     * @brief typ wyliczniowy umożliwiąjący reprezentację kolorów
     **/
    enum Attribute
    {
        WHITE = 0,
        GRAY = 1,
        RED = 2,
        MAGENTA = 3,
        GREEN = 4,
        BLACK = 5,
        YELLOW = 6,
        BLUE = 7,
        CYAN = 8
    };
    /**
     * @brief prosty konstruktor
     * @param atr - kolor który ma być ustawiony jako opcja
     **/
    AttColor(AttColor::Attribute atr) : m_atr(atr) {}
    /**
     * @brief funkcja zwracająca aktualnie ustawiony kolor
     * @return aktualnie usatwiony kolor
     **/
    AttColor::Attribute getColor() const
    {
        return m_atr;
    }
    /**
     * @brief funkcja ustawiająca na nowo kolor
     * @param atr - ustawiany kolor
     */
    void setColor(AttColor::Attribute atr)
    {
        m_atr = atr;
    }
   
private:
    AttColor::Attribute m_atr;
};

class AttFormat{
    ///klasa reprezentująca wybraną opcję formatowania
public:
    /**
     * @brief typ wyliczniowy umożliwiający reprezentację formatowania
     **/
    enum Attribute
    {
        NORMAL = 0,
        BOLD = 1,
        UNDERLINED = 2,
        DIM = 3
    };
    
    /**
     * @brief prosty konstruktor
     * @param atr - format który ma być ustawiony jako opcja
     **/
    AttFormat(AttFormat::Attribute atr) : m_atr(atr) {}
    
    
    /**
     * @brief funkcja zwracająca aktualnie ustawioną opcje formatowania
     * @return aktualnie usatwiona opcja formatowania
     **/
    AttFormat::Attribute getFormat() const
    {
        return m_atr;
    }
    /**
     * @brief funkcja ustawiająca na nowo opcje formatowania
     * @param atr - ustawiana opcja formatowania
     */
    void setFormat(AttFormat::Attribute atr)
    {
        m_atr = atr;
    }
   
private:
    AttFormat::Attribute m_atr;
};