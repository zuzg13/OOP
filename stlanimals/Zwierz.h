#pragma once
#include <string>


class Zwierz{
    
    //klasa reprezentujaca zwierze mieszkajace na farmie
    
public:
    /**
     * @brief konstruktor ustawiajacy imie zwierzecia
     * @param name - imie do ustawienia
     */ 
    explicit Zwierz(const std::string &imie) : m_imie(imie) {}
    virtual ~Zwierz() = default;
    
    /**@brief funkcja zwracajaca imie zwierzecia
     * @param imie
     */ 
    std::string imie() const 
    {
        return m_imie;
    }
    /**
     * @brief wirtualna funkcja wypisujaca informacje o zwierzeciu, 
     */
    virtual void opisz() const = 0;
    
private:
    std::string m_imie;
    
};

class Owca : public Zwierz {
    
public:
    /**
     * @brief konstruktor ustawiwajacy imie zwierzecia i dla owcy(i tylko owcy) 
     * ustawia flage informujaca czy owca jest ostrzyzona (domyslnie false)
     * @param name - imie do ustawienia
     */ 
    Owca(const std::string& name) : Zwierz(name), czyOstrzyzona(false) {}
    /**
     * @brief - glosny destruktor informujacy ze zwierze wrocilo do zagrody
     */ 
    ~Owca()
    {
        std :: cout << "Owca " << imie() << " wrocila do zagrody" << std :: endl;
    }
    
 
    void opisz() const override
    {
        std :: cout << "Owca " << imie() << " - " << stan() << std :: endl;
    }
    
    /**
     * @brief funkcja zwracajaca odpowiednia informacje o tym czy 
     * owca jest ostrzyzona
     */ 
    std :: string stan() const
    {
        if(czyOstrzyzona)
            return "ostrzyzona";
        else
            return "nieostrzyzona";
    }
    /**
     * @brief funkcja strzygaca owca, ustawia flage ostrzyzenia na true
     */ 
    void ostrzyz()
    {
        czyOstrzyzona = true;
    }
    

private:
    bool czyOstrzyzona;
    
};


class Krowa : public Zwierz {
    
public:
    /**
     * @brief konstruktor ustawiwajacy imie zwierzecia  
     * @param name - imie do ustawienia
     */ 
    Krowa(const std::string& name) : Zwierz(name) {}
    /**
     * @brief - glosny destruktor informujacy ze zwierze wrocilo do obory
     */
    ~Krowa()
    {
        std :: cout << "Krowa " << imie() << " wrocila do obory" << std :: endl;
    }
    
    void opisz() const override
    {
        std :: cout << "Krowa " << imie() << std :: endl;
    }

};

class Kon : public Zwierz {
    
public:
    /**
     * @brief konstruktor ustawiwajacy imie zwierzecia  
     * @param name - imie do ustawienia
     */
    Kon(const std::string& name) : Zwierz(name) {}
    /**
     * @brief - glosny destruktor informujacy ze zwierze wrocilo do stajni
     */
    ~Kon()
    {
        std :: cout << "Kon " << imie() << " wrocil do stajni" << std :: endl;
    }
    
    void opisz() const override
    {
        std :: cout << "Kon " << imie() << std :: endl;
    }

};


