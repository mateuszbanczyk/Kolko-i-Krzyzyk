//---------------------------------------------------------------------------

#ifndef cGraczH
#define cGraczH
//---------------------------------------------------------------------------
class CGracz
{
private:
	int wygrane;
    char znak;

public:
	__fastcall CGracz(char z);
	__fastcall ~CGracz();
    void PodbijIloscWygranych(int i);
	int PobierzIloscWygranych();
	char PobierzZnak();

};
//---------------------------------------------------------------------------
#endif
