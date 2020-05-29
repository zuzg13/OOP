#pragma once
#include "Expense.h"


class Table {

public:
    Table() : m_size(0) {}

    void print() const;
    void operator+=(const Expense& ex);

    Table& sort(unsigned int col);
    Table& sortByMean();


private:
    std::vector<Expense> m_table;
    unsigned int m_size;
};

bool cmp(const Expense& ex1, const Expense& ex2, unsigned int indx);



