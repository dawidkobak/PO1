// Nazwa pliku wykonywalnego: zoo.exe

// Celem zadania jest napisanie kontenera do zarzadzania zoo. W naszym 
// zoo znajduje sie cztery gatunki zwierzet: Lion, Cow, Sheep, Parrot;
// kazde z nich ma swoj wiek oraz swoj charakterystyczny glos. Dodatkowo
// kazda Papuga ma swoje wlasne imie, ktore stale powtarza. 

// Wszystkie zwierzeta powinny zostac umieszczone w swoich wybiegach,
// a w zadnym wybiegu nie moze byc wiecej niz jedno zwierze. Wybiegami
// zarzadza klasa Zoo, ktora powinna obsugiwac umieszczanie i wyciaganie
// zwierzat z wybiegow, przesuniecie zwierzat tak aby zajmowaly kolejne 
// wybiegi od poczatku i zmiana rozmiaru Zoo.

// Prosze zadbac o brak wycieków pamięci i zastanowic sie nad
// hierarchia klass.

// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// UWAGA !!!
// Pliku Main.cpp nie wolno modyfikowac. 

// Przy wykonaniu zadania nie wolno korzystac z zadnych kontenerow
// biblioteki standardowej.

// Prosze najpierw sie zastanowic nad hierarchia i kompozycja klas.

// Ostateczny program powinien byc przyjazny dla programisty (miec
// czytelny i dobrze napisany kod). 

// Makefile dolaczony do rozwiazania powinien tworzyc plik wykonywalny
// o nazwie podanej na poczatku tego pliku. Program nalezy kompilowac
// z flagami -Wall -Wextra -pedantic -g.

// Makefile powinien zawierac rowniez cel "clean", ktory usuwa pliki
// obiektowe i plik wykonywalny.

// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani zadnych innych materialow (w tym własnych wczesniej
// przygotowanych plikow oprócz makefile).

// Kody zrodlowe musza znajdowac sie w katalogu do ktorego nikt oprocz
// wlasciciela nie ma praw dostepu.

// Rozwiazanie (czyli dodane pliki, makefile i Main.cpp) nalezy wgrac
// do UPEL: https://upel.agh.edu.pl/wfiis/course/view.php?id=20

#include "Main.h"

#include <iostream>

using namespace std;

int main() 
{   
    cout << "\n===== Animals =====\n" << endl;
    
    Lion leon(10);                          // Animal with age 10, Lion
    Parrot aga(2, "Aga");                   // Animal with age 2, Parrot: Aga
    Parrot domis(3, "Domis");               // Animal with age 2, Parrot: Domis
    Animal * mucka = new Cow(15);           // Animal with age 15, Cow
    
    const Animal * animals[4] = {&leon, mucka, &aga, &domis};
    for(int i = 0; i<4; ++i){
        animals[i]->saySomething();         // Lion: Aghr!
                                            // Cow: Muuu...
                                            // Parrot: Aga. Aga!
                                            // Parrot: Domis. Domis!
    }
    delete mucka;                           // Bye Cow
    
   
    cout << "\n===== Empty zoo =====\n" << endl;
    Zoo cracow("Cracow", 10);
    cracow.print();                         // Zoo: Cracow
                                            // Enclosure 0: empty (... x10, see below)


    cout << "\n===== Some animals =====\n" << endl;

    Animal * miki = new Lion(5);            // Animal with age 5, Lion
    Cow * krasula = new Cow(5);             // Animal with age 5, Cow
    Parrot * iga = new Parrot(3, "Iga");    // Animal with age 2, Parrot: Iga
    
    cracow.insert(3, miki);
    cracow.insert(8, krasula);
    Animal * ani = cracow.insert(7, iga);
    if( ani ){
        delete ani;
    }
    
    cracow.print();                         // Zoo: Cracow
                                            // Enclosure 0: empty
                                            // Enclosure 1: empty
                                            // Enclosure 2: empty
                                            // Enclosure 3: Animal with age 5, Lion
                                            // Enclosure 4: empty
                                            // Enclosure 5: empty
                                            // Enclosure 6: empty
                                            // Enclosure 7: Animal with age 2, Parrot: Iga
                                            // Enclosure 8: Animal with age 5, Cow
                                            // Enclosure 9: empty
    
    cout << "\n===== Insert sheep =====\n" << endl;

    
    for(int i=1; i<11; i++){
        Animal * ani = cracow.insert(new Sheep(i)); // Animal with age 1, Sheep
                                                    // Animal with age 2, Sheep
        if ( ani ){                                 //            (... x7, see below)
            delete ani;                             // Animal with age 8, Sheep
        }                                           // Bye Sheep
    }                                               // Animal with age 9, Sheep
                                                    // Bye Sheep
                                                    // Animal with age 10, Sheep
                                                    // Bye Sheep
    
    
    cracow.print();                         // Zoo: Cracow
                                            // Enclosure 0: Animal with age 1, Sheep
                                            // Enclosure 1: Animal with age 2, Sheep
                                            // Enclosure 2: Animal with age 3, Sheep
                                            // Enclosure 3: Animal with age 5, Lion
                                            // Enclosure 4: Animal with age 4, Sheep
                                            // Enclosure 5: Animal with age 5, Sheep
                                            // Enclosure 6: Animal with age 6, Sheep
                                            // Enclosure 7: Animal with age 2, Parrot: Iga
                                            // Enclosure 8: Animal with age 5, Cow
                                            // Enclosure 9: Animal with age 7, Sheep
    
    cout << "\n===== Resize zoo =====\n" << endl;
    cracow.reorganize(5);                   // There is more than 5 animals in zoo, resize imposible
    
    cout << "\n===== Remove animals =====\n" << endl;
    for(int i = 2; i<5; ++i){
        Animal * ani = cracow.remove(i);
        delete ani;                         // Bye Sheep
                                            // Bye Lion
                                            // Bye Sheep
    }
    cracow.print();                         // Zoo: Cracow
                                            // Enclosure 0: Animal with age 1, Sheep
                                            // Enclosure 1: Animal with age 2, Sheep
                                            // Enclosure 2: empty
                                            // Enclosure 3: empty
                                            // Enclosure 4: empty
                                            // Enclosure 5: Animal with age 5, Sheep
                                            // Enclosure 6: Animal with age 6, Sheep
                                            // Enclosure 7: Animal with age 2, Parrot: Iga
                                            // Enclosure 8: Animal with age 5, Cow
                                            // Enclosure 9: Animal with age 7, Sheep
    
    cout << "\n===== Resize zoo - other approach =====\n" << endl;
    const int numOfAnimals = cracow.numOfAnimals();
    cracow.reorganize(numOfAnimals);        // Cracow zoo: new size = 8
    cracow.print();                         // Zoo: Cracow
                                            // Enclosure 0: Animal with age 1, Sheep
                                            // Enclosure 1: Animal with age 2, Sheep
                                            // Enclosure 2: Animal with age 5, Sheep
                                            // Enclosure 3: Animal with age 6, Sheep
                                            // Enclosure 4: Animal with age 6, Sheep
                                            // Enclosure 5: Animal with age 2, Parrot: Iga
                                            // Enclosure 6: Animal with age 5, Cow
                                            // Enclosure 7: Animal with age 7, Sheep     
                                            
    cracow.reorganize(numOfAnimals+2);      // Cracow zoo: new size = 10
    cracow.print();                         // Zoo: Cracow
                                            // Enclosure 0: Animal with age 1, Sheep
                                            // Enclosure 1: Animal with age 1, Sheep
                                            // Enclosure 2: Animal with age 2, Sheep
                                            // Enclosure 3: Animal with age 5, Sheep
                                            // Enclosure 4: Animal with age 6, Sheep
                                            // Enclosure 5: Animal with age 2, Parrot: Iga
                                            // Enclosure 6: Animal with age 5, Cow
                                            // Enclosure 7: Animal with age 7, Sheep                                                
                                            // Enclosure 8: empty                                                
                                            // Enclosure 9: empty                                                
                                                                                       
                                            
    cout << "\n===== Default cleanup =====\n" << endl;
    
    return 0;
}
                                            // Bye Sheep
                                            // Bye Sheep
                                            // Bye Sheep
                                            // Bye Sheep
                                            // Bye Sheep
                                            // Bye Parrot
                                            // Bye Cow
                                            // Bye Sheep
                                            // Cracow zoo - closed 
                                            // Bye Parrot
                                            // Bye Parrot
                                            // Bye Lion


/* output

===== Animals =====

Animal with age 10, Lion
Animal with age 2, Parrot : Aga
Animal with age 3, Parrot : Domis
Animal with age 15, Cow
Lion: Aghr!
Cow: Muuu...
Parrot: Aga. Aga!
Parrot: Domis. Domis!
Bye Cow

===== Empty zoo =====

Zoo: Cracow
Enclosure 0 : empty
Enclosure 1 : empty
Enclosure 2 : empty
Enclosure 3 : empty
Enclosure 4 : empty
Enclosure 5 : empty
Enclosure 6 : empty
Enclosure 7 : empty
Enclosure 8 : empty
Enclosure 9 : empty

===== Some animals =====

Animal with age 5, Lion
Animal with age 5, Cow
Animal with age 3, Parrot : Iga
Zoo: Cracow
Enclosure 0 : empty
Enclosure 1 : empty
Enclosure 2 : empty
Enclosure 3 : Animal with age 5, Lion
Enclosure 4 : empty
Enclosure 5 : empty
Enclosure 6 : empty
Enclosure 7 : Animal with age 3, Parrot : Iga
Enclosure 8 : Animal with age 5, Cow
Enclosure 9 : empty

===== Insert sheep =====

Animal with age 1, Sheep
Animal with age 2, Sheep
Animal with age 3, Sheep
Animal with age 4, Sheep
Animal with age 5, Sheep
Animal with age 6, Sheep
Animal with age 7, Sheep
Animal with age 8, Sheep
Bye Sheep
Animal with age 9, Sheep
Bye Sheep
Animal with age 10, Sheep
Bye Sheep
Zoo: Cracow
Enclosure 0 : Animal with age 1, Sheep
Enclosure 1 : Animal with age 2, Sheep
Enclosure 2 : Animal with age 3, Sheep
Enclosure 3 : Animal with age 5, Lion
Enclosure 4 : Animal with age 4, Sheep
Enclosure 5 : Animal with age 5, Sheep
Enclosure 6 : Animal with age 6, Sheep
Enclosure 7 : Animal with age 3, Parrot : Iga
Enclosure 8 : Animal with age 5, Cow
Enclosure 9 : Animal with age 7, Sheep

===== Resize zoo =====

There is more than 5 animals in zoo, resize imposible

===== Remove animals =====

Bye Sheep
Bye Lion
Bye Sheep
Zoo: Cracow
Enclosure 0 : Animal with age 1, Sheep
Enclosure 1 : Animal with age 2, Sheep
Enclosure 2 : empty
Enclosure 3 : empty
Enclosure 4 : empty
Enclosure 5 : Animal with age 5, Sheep
Enclosure 6 : Animal with age 6, Sheep
Enclosure 7 : Animal with age 3, Parrot : Iga
Enclosure 8 : Animal with age 5, Cow
Enclosure 9 : Animal with age 7, Sheep

===== Resize zoo - other approach =====

Cracow zoo: new size = 7
Zoo: Cracow
Enclosure 0 : Animal with age 1, Sheep
Enclosure 1 : Animal with age 2, Sheep
Enclosure 2 : Animal with age 5, Sheep
Enclosure 3 : Animal with age 6, Sheep
Enclosure 4 : Animal with age 3, Parrot : Iga
Enclosure 5 : Animal with age 5, Cow
Enclosure 6 : Animal with age 7, Sheep
Cracow zoo: new size = 9
Zoo: Cracow
Enclosure 0 : Animal with age 1, Sheep
Enclosure 1 : Animal with age 2, Sheep
Enclosure 2 : Animal with age 5, Sheep
Enclosure 3 : Animal with age 6, Sheep
Enclosure 4 : Animal with age 3, Parrot : Iga
Enclosure 5 : Animal with age 5, Cow
Enclosure 6 : Animal with age 7, Sheep
Enclosure 7 : empty
Enclosure 8 : empty

===== Default cleanup =====

Bye Sheep
Bye Sheep
Bye Sheep
Bye Sheep
Bye Parrot
Bye Cow
Bye Sheep
Cracow zoo - closed
Bye Parrot
Bye Parrot
Bye Lion

*/
