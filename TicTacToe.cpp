/******************************************************************************


NIESAMOWITY PROJEKT PRZEDSTAWIAJĄCY PRACE NA TABLICACH DWUWYMIAROWYCH.
POTEM TO BĘDZIE KÓŁKO I KRZYŻYK
POZDRAWIAM MEMEK 10.05.19

DATA: 14.05.19 21.:23
PRACE NAD PROGRAMEM "KÓŁKO I KRZYŻYK" ZOSTAŁY UKOŃCZONE
POZOSTAJE ZADZWONIC DO NASA
MOŻE BĘDE ULEPSZAŁ
POZDRAWIAM

*******************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <conio.h>

using namespace std;

void napelnij(char[3][9]);
void wypisz(char[3][9]);
void ustaw(char[3][9]);
void ruch(char[3][9], int*, int*, int*,int,char);
bool sprawdz(char[3][9]);
bool koniec(int,char);


int main()
{
	char tab[3][9];
	int pozycjaX = 4;
	int pozycjaY = 1;
	int player = 1;

	int tempX = 4;
	int tempY = 1;

	int *wsk_pozycjaX = &pozycjaX;
	int *wsk_pozycjaY = &pozycjaY;
	int *wsk_player = &player;

	int znakint = 0;
	unsigned char znak='x';

	while (true)
	{
		pozycjaX = 4;
		pozycjaY = 1;
		player = 1;

		tempX = 4;
		tempY = 1;

		znakint = 0;

		napelnij(tab);
		ustaw(tab);
		wypisz(tab);

		while (true)
		{
			cout << "                8"<<endl;
			cout << "Uzyj klawiszy 4 x 6 do poruszania i enter by zatwierdzic ruch."<<endl;
			cout << "                2"<<endl;
			cout << "Gracz: " << player << endl;
			ruch(tab, wsk_pozycjaX, wsk_pozycjaY, wsk_player, znakint, znak);
			wypisz(tab);
			if (sprawdz(tab))
				break;

			/*cout << "X: "<< pozycjaX << endl;
			cout << "Y: " << pozycjaY << endl;*/
		}
		if (!koniec(znakint, znak))
			break;
		else
			system("cls");

	}
	return 0;
	
}

void napelnij(char tab[3][9])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			//tab[i][j] = 'o';
			if (j == 0 || j == 3 || j == 6)
				tab[i][j] = '(';
			if (j == 2 || j == 5 || j == 8)
				tab[i][j] = ')';
			if (j == 1 || j == 4 || j == 7)
				tab[i][j] = ' ';

		}
	}

}

void wypisz(char tab[3][9])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << tab[i][j];
		}
		cout << endl;
	}
}

void ustaw(char tab[3][9]) 
{
	tab[1][3] = '[';
	tab[1][5] = ']';
}

bool sprawdz(char tab[3][9])
{
	//  Gracz 2 - X  ///////////////////////////////////////////////////////////////

	if (tab[2][1] == 'O' && tab[2][4] == 'O' && tab[2][7] == 'O') // dol
	{
		system("cls");
		cout << "Wygrywa gracz 1." << endl;
		return true;
	}

	if (tab[2][7] == 'O' && tab[1][7] == 'O' && tab[0][7] == 'O') // prawo
	{
		system("cls");
		cout << "Wygrywa gracz 1." << endl;
		return true;
	}
	if (tab[0][1] == 'O' && tab[0][4] == 'O' && tab[0][7] == 'O') //gora
	{
		system("cls");
		cout << "Wygrywa gracz 1." << endl;
		return true;
	}
	if (tab[2][1] == 'O' && tab[1][1] == 'O' && tab[0][1] == 'O') // lewo
	{
		system("cls");
		cout << "Wygrywa gracz 1." << endl;
		return true;
	}
	if (tab[0][4] == 'O' && tab[1][4] == 'O' && tab[2][4] == 'O') // srodek pion
	{
		system("cls");
		cout << "Wygrywa gracz 1." << endl;
		return true;
	}
	if (tab[1][1] == 'O' && tab[1][4] == 'O' && tab[1][7] == 'O') // srodek poziom
	{
		system("cls");
		cout << "Wygrywa gracz 1." << endl;
		return true;
	}
	if (tab[0][1] == 'O' && tab[1][4] == 'O' && tab[2][7] == 'O') // skos w prawo
	{
		system("cls");
		cout << "Wygrywa gracz 1." << endl;
		return true;
	}
	if (tab[0][7] == 'O' && tab[1][4] == 'O' && tab[2][1] == 'O') // skos w lewo
	{
		system("cls");
		cout << "Wygrywa gracz 1." << endl;
		return true;
	}

	//  Gracz 2 - X  ///////////////////////////////////////////////////////////////

	if (tab[2][1] == 'X' && tab[2][4] == 'X' && tab[2][7] == 'X') // dol
	{
		system("cls");
		cout << "Wygrywa gracz 2." << endl;
		return true;
	}

	if (tab[2][7] == 'X' && tab[1][7] == 'X' && tab[0][7] == 'X') // prawo
	{
		system("cls");
		cout << "Wygrywa gracz 2." << endl;
		return true;
	}
	if (tab[0][1] == 'X' && tab[0][4] == 'X' && tab[0][7] == 'X') //gora
	{
		system("cls");
		cout << "Wygrywa gracz 2." << endl;
		return true;
	}
	if (tab[2][1] == 'X' && tab[1][1] == 'X' && tab[0][1] == 'X') // lewo
	{
		system("cls");
		cout << "Wygrywa gracz 2." << endl;
		return true;
	}
	if (tab[0][4] == 'X' && tab[1][4] == 'X' && tab[2][4] == 'X') // srodek pion
	{
		system("cls");
		cout << "Wygrywa gracz 2." << endl;
		return true;
	}
	if (tab[1][1] == 'X' && tab[1][4] == 'X' && tab[1][7] == 'X') // srodek poziom
	{
		system("cls");
		cout << "Wygrywa gracz 2." << endl;
		return true;
	}
	if (tab[0][1] == 'X' && tab[1][4] == 'X' && tab[2][7] == 'X') // skos w prawo
	{
		system("cls");
		cout << "Wygrywa gracz 2." << endl;
		return true;
	}
	if (tab[0][7] == 'X' && tab[1][4] == 'X' && tab[2][1] == 'X') // skos w lewo
	{
		system("cls");
		cout << "Wygrywa gracz 2." << endl;
		return true;
	}

	//  Remis  ///////////////////////////////////////////////////////////////

	if (tab[0][1] != ' ' && tab[0][4] != ' ' && tab[0][7] != ' ' &&
		tab[1][1] != ' ' && tab[1][4] != ' ' && tab[2][7] != ' ' &&
		tab[2][1] != ' ' && tab[2][4] != ' ' && tab[2][7] != ' ')
	{
		system("cls");
		cout << "Remis." << endl;
		return true;
	}

	return false;
}

void ruch(char tab[3][9], int *pozycjaX, int *pozycjaY,int *player, int znakint, char znak)
{

	// funkcja ruch korzysta z _getch(). Dzieki temu mamy mozliwosc grania w kolko i krzyzyk
	// bez zatwierdzania przesuniecia enterem. Ostateczny ruch potwierdzamy klikacjac enter.
	
znak = _getch();
znakint = (int)znak;

	switch (znakint)
		{
			case 52: // lewo
				system("cls");
				if (*pozycjaX == 1)
					break;
				else
				{
					tab[*pozycjaY][*pozycjaX - 4] = '[';
					tab[*pozycjaY][*pozycjaX - 2] = ']';
					tab[*pozycjaY][*pozycjaX - 1] = '(';
					tab[*pozycjaY][*pozycjaX + 1] = ')';
					*pozycjaX = *pozycjaX - 3;
				}
			break;

			case 53: // dol
				system("cls");
				if (*pozycjaY == 2)
					break;
				else
				{
					tab[*pozycjaY + 1][*pozycjaX - 1] = '[';
					tab[*pozycjaY + 1][*pozycjaX + 1] = ']';
					tab[*pozycjaY][*pozycjaX - 1] = '(';
					tab[*pozycjaY][*pozycjaX + 1] = ')';
					++* pozycjaY;
				}
			break;

			case 54: // prawo
				system("cls");
				if (*pozycjaX == 7)
					break;
				else
				{
					tab[*pozycjaY][*pozycjaX + 4] = ']';
					tab[*pozycjaY][*pozycjaX + 2] = '[';
					tab[*pozycjaY][*pozycjaX + 1] = ')';
					tab[*pozycjaY][*pozycjaX - 1] = '(';
					*pozycjaX = *pozycjaX + 3;
				}
			break;

			case 56: //gora
				system("cls");
				if (*pozycjaY == 0)
					break;
				else
				{
					tab[*pozycjaY - 1][*pozycjaX - 1] = '[';
					tab[*pozycjaY - 1][*pozycjaX + 1] = ']';
					tab[*pozycjaY][*pozycjaX - 1] = '(';
					tab[*pozycjaY][*pozycjaX + 1] = ')';
					--* pozycjaY;
				}
			break;

			case 13: //enter
				system("cls");

				if (tab[*pozycjaY][*pozycjaX] != ' ')
					break;
				else
				{
					if (*player == 1)
						tab[*pozycjaY][*pozycjaX] = 'O';
					else
						tab[*pozycjaY][*pozycjaX] = 'X';

					if (*player == 1)
						* player = 2;
					else
						*player = 1;
				}
			break;
			default:
				system("cls");
				break;

		}
	


}

bool koniec(int znakint,char znak)
{
	cout << "Dzieki za gre." << endl;
	cout << "Nacisnij ENTER aby zagrac jeszcze raz." << endl;
	cout << "Nacisnij ESC aby wyjsc." << endl;

	znak = _getch();
	znakint = (int)znak;

	switch (znakint)
	{
	case 27:
		return false;
	case 13:
		return true;
	default:
		system("cls");		
	}
}




