/* W zadaniu nalezy skonstruowac logiczna hierarchie klas na podstawie
 * ponizszego programu. 
 * 
 * Prosze nie implementowac pol w klasach bazowych jezeli nie sa one tam
 * wymagane (na podstawie ponizszego kodu).
 * 
 * Jezeli ktos chce, to uzywanie biblioteki standardowej jest dozwolone 
 * bez ograniczen. 
 * 
 * Zadanie nalezy wykonywac w parach. Obie osoby z pary maja wgrac 
 * rozwiazanie na UPEL.
*/

#include <iostream>
#include "Pojazdy.h"

void sprawdzWskaznik(const void* p) {
	if ( p == 0 )
		std::cout << "null ptr" << std::endl;
	else
		std::cout << "ok ptr" << std::endl;
}

void wypiszRodzaj(const Pojazd* poj) {
	if ( poj )
		std::cout << "Typ pojazdu: " << poj->rodzaj() << std::endl;
	else
		std::cout << "Pojazd nierozpoznany." << std::endl;
}

int main() 
{
	Samochod * ss = new Samochod( PredkoscMaksymalna(140) );
	sprawdzWskaznik(dynamic_cast<PojazdLadowy*>(ss));
	wypiszRodzaj(ss);

	Motorowka * mm = new Motorowka( PredkoscMaksymalna(50) );
	sprawdzWskaznik(dynamic_cast<const PojazdLadowy*>(mm));
	wypiszRodzaj(mm);

	Rower rr = Rower();
	sprawdzWskaznik(dynamic_cast<const PojazdLadowy*>(&rr));
	wypiszRodzaj(&rr);

	std::cout << "--------" << std::endl;

	PojazdLadowy * a =  new Amfibia( PredkoscMaksymalna(80), PredkoscMaksymalna(40) );
	const Motorowka * m = dynamic_cast<Motorowka*>(a);
	const Samochod * s = dynamic_cast<Samochod*>(a);  
	const Rower * r = dynamic_cast<Rower*>(a);  
	sprawdzWskaznik(m);
	wypiszRodzaj(m);
	sprawdzWskaznik(s);
	wypiszRodzaj(s);
	sprawdzWskaznik(r);
	wypiszRodzaj(r);

	std::cout << "Na ladzie: v_max = " << s->predkoscMaksymalna() << std::endl;
	std::cout << "W wodzie: v_max = " << m->predkoscMaksymalna() << std::endl;

	delete ss;
	delete mm;
	delete a;

}

/* wynik
ok ptr
Typ pojazdu: Samochod
null ptr
Typ pojazdu: Motorowka
ok ptr
Typ pojazdu: Rower
--------
ok ptr
Typ pojazdu: Amfibia
ok ptr
Typ pojazdu: Amfibia
null ptr
Pojazd nierozpoznany.
Na ladzie: v_max = 80km/h
W wodzie: v_max = 40km/h
*/
