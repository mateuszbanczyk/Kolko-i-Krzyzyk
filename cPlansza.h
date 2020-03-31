//---------------------------------------------------------------------------

#ifndef cPlanszaH
#define cPlanszaH
//---------------------------------------------------------------------------
#include "cGracz.h"
//---------------------------------------------------------------------------
enum Pole {
	PUSTE = '-',
	KOLKO = 'O',
	KRZYZYK = 'X'
};
//---------------------------------------------------------------------------
class CPlansza
{
private:
	char plansza[3][3];

public:
	__fastcall CPlansza();
	__fastcall ~CPlansza();
	void Zeruj();
	void Rysuj();

	bool WstawZnak(CGracz *gracz, int y, int x);
	bool SprawdzWygrana(CGracz *gracz);
    
};
//---------------------------------------------------------------------------
#endif
