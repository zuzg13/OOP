#pragma once
#include "Functions.h"


class SecureCalc {

public:
    static void run(const Function& f, double val)
    {
        std :: cout << "--- Calculation: " << f.getName() << "(" << val << ")" << std :: endl;
        try
        {
            std :: cout << "==> result: " << f.calc(val) << std :: endl;
        }
        catch (std::domain_error e_domain)
        {
            std::cout << "failed: " << e_domain.what() << std::endl;
        }
        catch (...)
        {
            std::cout << "failed: unknown exception\n";
        }
    }



};


