#include "Farma.h"
#include <algorithm>

void Farma :: dodaj(std::unique_ptr<Zwierz> zw)
{
    std::shared_ptr<Zwierz> sh = std::move(zw);
    m_zwierzaki.push_back(std::move(sh));
}

void Farma :: wypisz(const std::string& str) const
{
    std :: cout << " -- " << str << " -- " << std::endl;

    std::for_each(m_zwierzaki.begin(), m_zwierzaki.end(), [](const std::shared_ptr<Zwierz> el)
    {
        el->opisz();
    });
}

int Farma :: zliczImie(const std::string& imie) const
{   
    int liczba=0;
    for(const auto& el : m_zwierzaki)
    {
        if(el->imie() == imie)
            liczba++;
    }
    return liczba;
}

void Farma :: statystykaImion() const
{
    std :: vector <std::pair<std::string, int>> imiona;
    
    for(const auto &el : m_zwierzaki)
    {   
        bool flag = false;
        for(auto &im : imiona)
        {
            if(el->imie() == im.first)
            {
                flag = true;
                break;
            }
        }
        if(flag==false)
        {   
            int pom = zliczImie(el->imie());
            imiona.push_back(std :: make_pair(el->imie(), pom));
        }
    }
    
    
    std::sort(imiona.begin(), imiona.end());
    
    
    std::for_each(imiona.begin(), imiona.end(), [](const std::pair<std::string, int> para)
    {
        std::cout << para.first << ": "<< para.second << std :: endl;
    });
    
    
}

std::vector<Owca*> Farma :: wyprowadzOwce()
{
    std::vector<Owca*> stado;
    for(auto &el: m_zwierzaki)
    {
        if(Owca* owieczka = dynamic_cast<Owca*>(&(*el)))
            stado.push_back(owieczka);
    }
    return stado;
    
}



