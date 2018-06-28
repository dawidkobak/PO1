#include "Calc_error.h"
#include <vector>

// z rozwiązania janasa

void Calc_error::handler()
{
	try
	{
    	throw;
    } 
    catch (std::runtime_error * exception)
    {            
        std::cout << " Zlapano wyjatek:" << std::endl;
        while(exception)
        {
            std::cout << " -- z powodu: " << exception->what();
            
            Calc_error* err = dynamic_cast<Calc_error*> (exception);
            if(err) 
            {
                std::cout << ", [plik = " << err->plik << ", linia = " << err->linia << "]" << std::endl;
                exception = err->error;
                delete err;
            } 
            else 
            {
                std::cout << std::endl;
                delete exception;
                exception = nullptr;
            }
        }
    }
}