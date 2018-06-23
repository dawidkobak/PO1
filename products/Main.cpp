// Nazwa pliku wykonywalnego: Products

// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// UWAGA !!!
// Plikow Main.cpp i Product.h nie wolno modyfikowac. 

// Przy wykonaniu zadania nie wolno korzystac z zadnych kontenerow
// biblioteki standardowej.

// Prosze napisac klasy reprezentujace obiekty, ktore mozna sprzedac
// meble i pojazdy. Kazdy taki obiekt ma cene i numer ID oraz
// dodatkowe informacje zalezne od jego typu. Funkcje zwiazane z
// czynnosciami Drive, Fly, Move, Sit jedynie wypisuja tekst na
// ekranie.

// Prosze najpierw sie zastanowic nad hierarchia klas.

// Ostateczny program powinien byc przyjazny dla programisty (miec
// czytelny i dobrze napisany kod). 

// Makefile dolaczony do rozwiazania powinien tworzyc plik wykonywalny
// o nazwie podanej na poczatku tego pliku. Program nalezy kompilowac
// z flagami -Wall -Wextra -pedantic -g.

// Makefile powinien zawierac rowniez cel "clean", ktory usuwa pliki
// obiektowe i plik wykonywalny.

// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani zadnych innych materialow (w tym własnych wczesniej
// przygotowanych plikow oprócz makefile)

// Kody zrodlowe musza znajdowac sie w katalogu do ktorego nikt oprocz
// wlasciciela nie ma praw dostepu.

// Rozwiazanie (czyli dodane pliki, makefile i Main.cpp) nalezy wgrac
// do UPEL: https://upel.agh.edu.pl/wfiis/course/view.php?id=20


#include "Main.h"
#include "Product.h"
#include <iostream>

void PrintPrice (const Product object)
{
    object.Print();
}

int main() 
{
    std::cout<<"===== MillenniumFalcon =====\n";
    Vehicle* millenniumFalcon = new Vehicle (0);
    
    millenniumFalcon->SetPrice(1000);               // 1000 is the new cost of the vehicle
    millenniumFalcon->SetMaxSpeed(200);
    millenniumFalcon->Print();                      // This is a vehicle with max speed of 200
    std::cout<<"----- MillenniumFalcon price -----\n";
    PrintPrice(*millenniumFalcon);                  // Product with ID=0 costs 1000


    std::cout<<"\n===== Hyundai =====\n";
    const int hyundaiPassengers = 4;
    Car* hyundai = new Car (10, hyundaiPassengers);
    
    hyundai->SetPrice (15);   						// The car price will be: 15
    hyundai->SetMaxSpeed(75);

    int passengersIds [] = {007, 999, 123, 888};
    hyundai->SetPassengersIds ((const int*)passengersIds, sizeof(passengersIds)/sizeof(int));
    for (unsigned int i = 0; i < sizeof(passengersIds)/sizeof(int); ++i) passengersIds[i] = 0;

    hyundai->Drive();        						// Driving the car with ID=10
    hyundai->Print();        						// Car with ID=10 has 4 passengers with following IDs: 7, 999, 123, 888. Max speed of the car is 75
    std::cout<<"----- Hyundai price -----\n";
    PrintPrice(*hyundai);    						// Product with ID=10 costs 15


    std::cout<<"\n===== Bombardier =====\n";
    Airplane* bombardier = new Airplane (15);
    
    bombardier->SetPrice (333);    					// The plane price is changed
    bombardier->SetWingspan(42);
    bombardier->Fly();        						// Flying the airplane with ID=15
    bombardier->Print();        					// A vehicle with ID=15 is an airplane with max speed of 100 and wignspan 42
    bombardier->SetMaxSpeed(75);
    bombardier->Print();        					// A vehicle with ID=15 is an airplane with max speed of 75 and wignspan 42


    std::cout<<"----- Bombardier price -----\n";
    PrintPrice(*bombardier);    					// Product with ID=15 costs 333


    std::cout<<"\n===== Array =====\n";
    const Vehicle* transport [] = {bombardier, hyundai, millenniumFalcon};
    for (unsigned int vehicleID = 0; vehicleID < sizeof(transport)/sizeof(Vehicle*); ++vehicleID) {
		transport[vehicleID]->Move();               // ... (see below: Array)
		delete transport[vehicleID];
    }
    

    std::cout<<"\n===== Chair =====\n";
	Furniture chair (211);

    chair.SetPrice(2);
    chair.Sit();            						// You sit down on a chair. Nothing happens.
    chair.Print();        							// This is chair with ID=211
    std::cout<<"----- Chair price -----\n";
    PrintPrice(chair);        						// Product with ID=211 costs 2

    return 0;
}

/* output
===== MillenniumFalcon =====
1000 is the new cost of the vehicle
This is a vehicle with max speed of 200
----- MillenniumFalcon price -----
Product with ID=0 costs 1000

===== Hyundai =====
The car price will be: 15
Driving the car with ID=10
Car with id=10 has 4 passengers with following Ids: 7, 999, 123, 888. Max speed of the car is 75
----- Hyundai price -----
Product with ID=10 costs 15

===== Bombardier =====
The plane price is changed
Flying the airplane with ID=15
A vehicle with ID=15 is an airplane with max speed of 100 and wignspan 42
A vehicle with ID=15 is an airplane with max speed of 75 and wignspan 42
----- Bombardier price -----
Product with ID=15 costs 333

===== Array =====
Flying the airplane with ID=15
Driving the car with ID=10
Moving with speed 200

===== Chair =====
You sit down on a chair. Nothing happens.
This is chair with ID=211
----- Chair price -----
Product with ID=211 costs 2
*/
