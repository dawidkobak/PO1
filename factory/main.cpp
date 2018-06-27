/* Task: Wyjatki 
 * Executable file: atest 
 * Description:  
 * Bazwową klasą w zadaniu jest klasa Value, przechowująca nazwę i 
 * wartość liczbową. Powinna ona posiadać głośny konstruktor i destruktor.
 * 
 * Tworzeniem i zarządzaniem wartościami ma zajmować się klasa Factory. 
 * Jeżeli próbuje się stworzyć obiekt spoza wcześniej ustalonego zakresu, 
 * to rzucany jest wyjątek.
 * 
 * Używanie klas biblioteki standardowej (string, vector) jest dozwolone.
 * 
 * Program nalezy kompilowac z flagami -Wall -g, prosze sprawdzic wycieki
 * pamieci.
 */

#include "main.hpp"

void exceptionHandler(){
    try{
        throw;
    } catch (OutOfRange exception) {
        std::cout << "... EXCEPTION!!!" << std::endl;        
        std::cout << "... " << exception << std::endl;                  // Value named: third has value 8.3 which is outside of the allowed range: [1, 8]
        std::cout << "... Clean up factory." << std::endl;
        exception.CleanFactory();              // -> see below -
    }
}

int main() {
        
    try {
        // Zwykłe stworzenie obiektu byłoby zdecydowanie lepsze, 
        // tu używamy new w celach ćwiczeniowych.
        // Odwikłanie stosu pojawi się na kolejnych zajęciach.
        Factory * factory = new Factory(1, 8);                          // Build factory with range [1, 8]
        
        const Value* first = factory->PrepareValue("first", 1.6);       // Manufacturing value 1.6
        first->Print();                                                 // first = 1.6
        first->Print();                                                 // first = 1.6

        const Value* second = factory->PrepareValue("second", 4.5);     // Manufacturing value 4.5
        second->Print();                                                // second = 4.5

        const Value* third = factory->PrepareValue("third", 8.6);       // Manufacturing value 8.6
        third->Print();

        std::cout << "ALL VALUES PREPARED!" << std::endl;

        std::cout << "Clean up factory." << std::endl;
        delete factory;
        
    } catch (...) {
        exceptionHandler();
    }

    std::cout << "Game over." << std::endl;

    return 0;
}

/* Output: 
Build factory with range [1, 8]
Manufacturing value 1.6
first = 1.6
first = 1.6
Manufacturing value 4.5
second = 4.5
Manufacturing value 8.6
... EXCEPTION!!!
... Value named: third has value 8.6 which is outside of the allowed range: [1, 8]
... Clean up factory.
Destroying value 1.6
Destroying value 4.5
Destroying value 8.6
Factory destroyed.
Game over.
*/ 
