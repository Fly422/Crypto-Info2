#include<iostream>
#include"lentier2dec.h"
#include"lentier.h"

using namespace std;

int main()
{
	//Lexique princpal

	//Algo princpal


/* 1e jeu de donn�es */
//d�but copier/coller (dans votre main)
	unsigned int aa[3] = { 1806659176,1021366019,527857808 };
	lentier a;
	a.p = aa;
	a.size = 3;
	char * s = lentier2dec(a);
	cout << s << endl;
	//fin copier/coller
	/*
	R�sultat attendu:
	9737257895872047995341991528
	*/
	//Pensez � la lib�ration m�moire avant de faire un autre test
	delete[]s;
	/************ fin test 1 ***************/

	return 0;
}