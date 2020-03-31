//---------------------------------------------------------------------------

#ifndef MainH
#define MainH

#include "cGracz.h"
#include "cPlansza.h"
//---------------------------------------------------------------------------

	char znak = KRZYZYK;
	CGracz *Krzyzyk;
	CGracz *Kolko;
	CGracz *Aktualny;
	CPlansza *Plansza;

	void Gracz(CGracz *gracz);
	void ZmianaGracza();
	void SprawdzWygrana();
	void Gra();

#endif
