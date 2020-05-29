#include "Stan.h"

ZbieranieDanych :: ZbieranieDanych(string mail)
{
    adres=mail;
}
const char* ZbieranieDanych ::nazwa() const
{
    return "ZbieranieDanych";
}
void ZbieranieDanych :: podsumowanie() const
{
    std::cout << " * Adres email: \'" << adres << "\'" << std::endl;
}
void ZbieranieDanych :: operator()()
{
    adres = "Nowak@mail.com";
    std::cout << "Prosze podac dana: Adres email = ?, podano \'" <<adres<<"\'" << std::endl;
}

void Podsumowanie :: podsumowanie() const
{

}
const char* Podsumowanie :: nazwa() const
{
    return "Podsumowanie";
}
void Podsumowanie :: operator()()
{
    ms->podsumowanie();
}