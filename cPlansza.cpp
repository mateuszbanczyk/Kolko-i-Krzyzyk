//---------------------------------------------------------------------------

#pragma hdrstop

#include <iostream>
#include <string>
#include <Windows.h>
#include "cPlansza.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

using namespace std;
//---------------------------------------------------------------------------
CPlansza::CPlansza()
{
	this->Zeruj();
}
//---------------------------------------------------------------------------
void CPlansza::Zeruj()
{
	for (int i = 0; i <= 2; i++)
	{
		for (int j = 0; j <= 2; j++)
			plansza[i][j] = PUSTE;
	}
}
//---------------------------------------------------------------------------
void CPlansza::Rysuj()
{
	for (int i = 0; i <= 2; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			cout << ' ' << plansza[i][j];
		}
        cout << endl << endl;
	}
}
//---------------------------------------------------------------------------
bool CPlansza::WstawZnak(CGracz *gracz, int y, int x)
{
	if (plansza[y][x] == PUSTE)
	{
		plansza[y][x] = gracz->PobierzZnak();
        return true;
	}
	else
	{
		std::cout << "To pole jest zajete!\a";
		Sleep(500);
	}

}
//---------------------------------------------------------------------------
bool CPlansza::SprawdzWygrana(CGracz *gracz)
{
	char znak;
	znak = gracz->PobierzZnak();


	if ((plansza[0][0] == znak && plansza[0][1] == znak && plansza[0][2] == znak) ||
		(plansza[0][0] == znak && plansza[1][0] == znak && plansza[2][0] == znak) ||
		(plansza[1][0] == znak && plansza[1][1] == znak && plansza[1][2] == znak) ||
		(plansza[2][0] == znak && plansza[2][1] == znak && plansza[2][2] == znak) ||
		(plansza[0][1] == znak && plansza[1][1] == znak && plansza[2][1] == znak) ||
		(plansza[0][0] == znak && plansza[1][1] == znak && plansza[2][2] == znak) ||
		(plansza[2][0] == znak && plansza[1][1] == znak && plansza[0][2] == znak) ||
		(plansza[0][2] == znak && plansza[1][2] == znak && plansza[2][2] == znak))
	{
		this->Rysuj();
		cout << "\nwygral gracz " << gracz->PobierzZnak() << "!" << endl;
		gracz->PodbijIloscWygranych(1);
		cout << "\nGracz " << gracz->PobierzZnak() << " wygral " << gracz->PobierzIloscWygranych() << " razy" << endl;

		string s;
		cout << "\nAby kontynuowac gre wpisz dowolny znak, aby zakonczyc wpisz 0..." << endl;
		cin >> s;
		if (s == "0")
		{
			exit(0);
		}
		else
		{
			system("cls");
			cout << "Kolej gracza " << gracz->PobierzZnak() << endl << endl;
			this->Zeruj();
		}
	}


	//Remis
	if (plansza[0][0] != PUSTE && plansza[0][1] != PUSTE && plansza[0][2] != PUSTE &&
		plansza[1][0] != PUSTE && plansza[1][1] != PUSTE && plansza[1][2] != PUSTE &&
		plansza[2][0] != PUSTE && plansza[2][1] != PUSTE && plansza[2][2] != PUSTE)
	{
		this->Rysuj();
		cout << "\nREMIS!!!" << endl;

		string s;
		cout << "\nAby kontynuowac gre wpisz dowolny znak, aby zakonczyc wpisz 0..." << endl;
		cin >> s;
		if (s == "0")
		{
			exit(0);
		}
		else
		{
			system("cls");
			cout << "Kolej gracza " << gracz->PobierzZnak() << endl << endl;
			this->Zeruj();
		}
	}
}
//---------------------------------------------------------------------------
