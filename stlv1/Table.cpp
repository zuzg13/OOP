#include "Table.h"


void Table :: print() const
{
    std::for_each(m_table.begin(), m_table.end(), [](const Expense& el){el.print();});
}

void Table :: operator+=(const Expense& ex)
{
    m_table.push_back(ex);
    if(m_size == 0)
        m_size = ex.size();
    if(ex.size() < m_size)
        m_size = ex.size();
}

Table& Table :: sort(unsigned int col)
{
    if(col >= m_size)
    {
        std::cout << "Indeks " << col << " nieprawidlowy!" << std::endl;
        return *this;
    }
    else
    {
        using namespace std::placeholders;
        auto flag = std::bind(cmp, _1, _2, col);
        std::sort(m_table.begin(), m_table.end(), flag);
        return *this;

    }
}

Table& Table :: sortByMean()
{
    std::sort(m_table.begin(), m_table.end(),
            [](const Expense& ex1, const Expense& ex2){return ex1.mean()<ex2.mean();});
    return *this;
}

bool cmp(const Expense& ex1, const Expense& ex2, unsigned int indx)
{
    if(ex1[indx]<ex2[indx])
        return true;
    else
        return false;
}

