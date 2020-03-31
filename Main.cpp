//---------------------------------------------------------------------------

#pragma hdrstop

#include <iostream>
#include <string>
#include <Windows.h>

#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

using namespace std;
//---------------------------------------------------------------------------
int  main ()
{
    Plansza = new CPlansza();
	Krzyzyk = new CGracz(KRZYZYK);
	Kolko = new CGracz(KOLKO);
	Aktualny = Krzyzyk;

	Gra();
	return 0;
}
void Gra()
{
	cout << "Witaj w grze Kolko i Krzyzyk!" << endl;
	cout << "Pola sa numerowane od 1 do 9" << endl;
	cout << "Gracz " << Krzyzyk->PobierzZnak() << " rozpoczyna!" << endl;

//	Zeruj(); juz sie zeruje w konstruktorze CPlansza
	while (true)
	{
		Plansza->Rysuj();
		Gracz(Aktualny);
		ZmianaGracza();
		SprawdzWygrana();
	}
}
//---------------------------------------------------------------------------
void Gracz(CGracz *gracz)
{
	int position, x, y;

	while(cin >> position)
	{
		switch (position)
		{
			case 1: y = 0; x = 0; break;
			case 2: y = 0; x = 1; break;
			case 3: y = 0; x = 2; break;
			case 4: y = 1; x = 0; break;
			case 5: y = 1; x = 1; break;
			case 6: y = 1; x = 2; break;
			case 7: y = 2; x = 0; break;
			case 8: y = 2; x = 1; break;
			case 9: y = 2; x = 2; break;
			default:
				std::cout << "Sprobuj jeszcze raz!\a\n";
				continue;
		}

		if (Plansza->WstawZnak(gracz, y, x))
            break;
	}

	system("cls");
}
//---------------------------------------------------------------------------
void ZmianaGracza()
{
	(Aktualny == Krzyzyk) ? Aktualny = Kolko : Aktualny = Krzyzyk;

	cout << "Kolej gracza " << Aktualny->PobierzZnak() << endl << endl;
}
//---------------------------------------------------------------------------
void SprawdzWygrana()
{
	Plansza->SprawdzWygrana(Krzyzyk);
	Plansza->SprawdzWygrana(Kolko);

}
//---------------------------------------------------------------------------

