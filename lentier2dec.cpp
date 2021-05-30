#include<iostream>
using namespace std;

#include"lentier2dec.h"
#include "lentier.h"

/*
R:Convertir un entier long représenté par un ensemble de chiffre en base 2^32
en une chaîne de caractères composées des chiffres en base 10 de ce même entier
E: 1 entier long (lentier)
S: 1 chaine de caractère (char*)
*/
char* lentier2dec(lentier nombre_base_r)
{
	//Lexique local
	lentier quotient, reste, diviseur;
	lentier* tempo;
	unsigned int position = 10 * nombre_base_r.size + 1; 
	unsigned int j, q2, r2, x;
	char* nombre_base_10, *temp;
	
	//Algo local
	diviseur.size = 1;									//Diviseur 1 000 000 000 pour le lentier
	diviseur.p = new unsigned int[diviseur.size]();
	diviseur.p[0] = 1000000000;

	nombre_base_10 = new char[position]();
	nombre_base_10[position - 1] = '\0';

	tempo = div_lentier(nombre_base_r, diviseur);
	quotient = tempo[0];
	reste = tempo[1];									//premier reste a 9 chiffre décimal
	delete[] tempo;

	q2 = reste.p[0] / 10;										//divsion du premier reste 
	nombre_base_10[position-2] = reste.p[0] % 10 + 48;					//Met le reste à 1 chiffre décimal dans nombre_base_10
	
	
	j = position - 2;
	for (unsigned int i = 0; i < 8 && j > 0; i++)					//Met les autres chiffre du reste a 9 décimal dans nombre_base_10
	{
		nombre_base_10[j-1] = q2 % 10 + 48;
		q2 = q2 / 10;
		j--;
	}
	

	while (!(quotient.size == 1 && quotient.p[0] == 0))			//Continue a diviser quotient pour avoir le reste
	{
		tempo = div_lentier(quotient, diviseur);
		delete[] quotient.p;
		delete[] reste.p;
		quotient = tempo[0];
		reste = tempo[1];
		delete[] tempo;
		
		nombre_base_10[j-1] = reste.p[0] % 10 + 48;		//Continue a diviser reste pour avoir le premire chiffre en décimal
		q2 = reste.p[0] / 10;
		j--;
		
		for (unsigned int i = 0; i < 8 && j > 0; i++)						//Met les autres chiffre du reste a 9 décimal dans nombre_base_10
		{
			nombre_base_10[j-1] = q2 % 10 + 48;
			q2 = q2 / 10;
			j--;
		}
		
	}

	x = 0;
	while (nombre_base_10[x] == 0 || nombre_base_10[x] == '0')		//Compte le nombre de 0 ou \0 avant la chaine de caractère
	{
		x++;
	}

	temp = nombre_base_10;											//Enlève les 0 ou \0 avant la chaine de caractère
	nombre_base_10 = new char[position - x];
	for (unsigned int i = 0; i < position - x; i++)
	{
		nombre_base_10[i] = temp[i + x];
	}

	delete[] quotient.p;
	delete[] reste.p;
	delete[] diviseur.p;
	return nombre_base_10;
}