#pragma once
#include <iostream>
#include <string>

class Pojazd{
    
    ///klasa reprezentująca dowolny pojazd, posiadający rejestrację
    
public:
    /**
     * @brief konstruktor domyślny, ustawiający "BRAKJREJESTRACJI", ponieważ rejestracje wydawane są określonym dokładnie pojazdom
     */ 
    Pojazd() : m_rejestracja("BRAKREJESTRACJI") {}
    virtual ~Pojazd() = default;
    
    /**
     * @brief wirtualna funkcja zwracająca informacje o tym, jakiego typu jest pojazd np. samochod, rower itp.
     * @return napis z nazwą typu pojazdu
     */ 
    virtual std::string getInfo() const = 0;
    
    /**
     * @brief zaprzyjazniona funkcja - operator << umożliwiająca wypisanie informacji o pojeździe na ekran
     * @param ostr - strumien wyjsciowy do ktorego przekazujemy informacje do wypisania
     * @param poj - pojazd o ktorym wypisywane są informacje
     * @return ostr
     */ 
    friend std::ostream& operator<<(std::ostream& ostr, const Pojazd& poj)
    {
        return ostr << poj.getInfo() << " <" << poj.m_rejestracja << ">";
    }
    
protected:
    /**
     * @brief funkcja ustawiajaca rejestracje pojazdu, gdy jest on już zdefiniowany
     * @param rejestracja - rejestracja do ustawienia
     */ 
    void setRej(std::string rejestracja)
    {
        m_rejestracja = rejestracja;
    }
  
private:
    std::string m_rejestracja;
    
};

class PojazdLadowy : virtual public Pojazd{
    
    ///klasa reprezentujaca pojazdy ladowe
};

class PojazdWodny : virtual public Pojazd{

     ///klasa reprezentujaca pojazdy wodne

};

class Motorowka : public PojazdWodny{

    ///klasa reprezentujaca pojazd wodny typu motorówka

public:
    /**
     * @brief konstruktor
     * @param rejestracja - rejestracja pojazdu do ustawienia
     * @param pr - predkosc maksymalna dla tego pojazdu wodnego jakim jest motorowka
     */ 
    Motorowka(const std::string rejestracja, PredkoscMaksymalna pr) : m_maxV(pr)
    {
        setRej(rejestracja);
    }
   
    
    std::string getInfo() const override
    {
        return "Motorowka";
    }
    std::string predkoscMaksymalna() const
    {
        return m_maxV.predkoscMaksymalna();
    }


private:
    PredkoscMaksymalna m_maxV;

};

class Samochod : public PojazdLadowy{
    
    ///klasa reprezentujaca pojazd lądowy typu samochód
    
public:
    /**
     * @brief konstruktor
     * @param rejestracja - rejestracja pojazdu do ustawienia
     * @param pr - predkosc maksymalna dla tego pojazdu lądowego
     */ 
    Samochod(const std::string rejestracja, PredkoscMaksymalna pr) : m_maxV(pr)
    {
        setRej(rejestracja);
    }
    std::string getInfo() const override
    {
        return "Samochod";
    }
    std::string predkoscMaksymalna() const
    {
        return m_maxV.predkoscMaksymalna();
    }


private:
    PredkoscMaksymalna m_maxV;

};

class Rower : public PojazdLadowy {

    ///klasa reprezentujaca pojazd lądowy typu rower
    
public:
    /**
     * @brief konstruktor
     * @param rejestracja - rejestracja pojazdu do ustawienia
     */
    Rower(const std::string rejestracja)
    {
        setRej(rejestracja);
    }
    std::string getInfo() const override
    {
        return "Rower";
    }
    
};

class Amfibia : public Samochod, public Motorowka {

    ///klasa reprezentująca Amfibię. Amfibia jest to pół samochód, pół motorówka, dlatego dziedziczy po klasie Samochód i Motorówka.

public:
/**
     * @brief konstruktor
     * @param rejestracja - rejestracja pojazdu do ustawienia
     * @param lad - predkosc maksymalna na lądzie do ustawienia
     * @param woda - predkosc maksymalna na wodzie do ustawienia
     */
    Amfibia(const std::string rejestracja, PredkoscMaksymalna lad, PredkoscMaksymalna woda) : Samochod(rejestracja, lad), Motorowka(rejestracja, woda)
    {

    }
    std::string getInfo() const override
    {
        return "Amfibia";
    }
    
    /**
     * @brief funkcja zwracająca informację o prędkosci maksymalnej na lądzie
     */ 
    std::string predkoscMaksymalna_Lad()
    {
        return Samochod::predkoscMaksymalna();
    }
    /**
     * @brief funkcja zwracająca informację o prędkosci maksymalnej na wodzie
     */ 
    std::string predkoscMaksymalna_Woda()
    {
        return Motorowka::predkoscMaksymalna();
    }
    
};



