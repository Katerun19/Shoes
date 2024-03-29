#include <iostream>
using namespace std;

int main() /*В обувном магазине продается обувь разного размера.Известно, 
		   что одну пару обуви можно надеть на другую, если она хотя бы на три размера больше.
		   В магазин пришел покупатель.Требуется определить, какое наибольшее количество пар обуви сможет предложить ему продавец так,
		   чтобы он смог надеть их все одновременно.
		   Входные данные: Сначала вводится размер ноги покупателя(обувь меньшего размера он надеть не сможет),
		   затем количество пар обуви в магазине и размер каждой пары.Размер — натуральное число, не превосходящее 100,
		   количество пар обуви в магазине не превосходит 1000. Выходные данные: Выведите единственное число — максимальное количество пар обуви.*/
{
	int Size, All, M = 0, n = 0, k = 0;
	cin >> Size >> All;
	int *SizeShoes = new int [All];
	for (int i = 0; i < All; i++)
	{
		cin >> SizeShoes[i];
	}
	for (int j = 0; j < All; j++) { //j – начиная с какого номера ищем наименьший
		int num_min = j; //номер минимального элемента
		for (int i = j; i < All; i++) { //ищем только в еще не упорядоченной части
			if (SizeShoes[i] < SizeShoes[num_min]) { num_min = i; }
		}
		int temp;
		temp = SizeShoes[j];
		SizeShoes[j] = SizeShoes[num_min];
		SizeShoes[num_min] = temp;
	}
	for (int i = 0; i < All; i++)
	{
		if (SizeShoes[i] >= Size) { M++; }
		else { M = M; }		
	}
	if (M == 0) { cout << M; }
	if (M != 0) 
	{	
		int start = 0;
		for (int j = 0; j < All; j++)
		{
			if (SizeShoes[j] >= Size) { start = j; k++; break; }
		}
		int Sizeshoes = SizeShoes[start];
		for (int j = start + 1; j < All; j++)
		{
			if (SizeShoes[j] >= Sizeshoes)
			{
				if (SizeShoes[j] - Sizeshoes >= 3) { n++; Sizeshoes = SizeShoes[j]; }
			}
		}
		cout << n + k;
	}
	delete[] SizeShoes;
    return 0;
}

