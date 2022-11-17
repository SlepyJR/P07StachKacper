#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <iterator>
#include <ctime>
#include <vector>
#include <time.h>
#include <chrono>
#include <fstream>
std::vector <std::vector<int>> algorytm(std::vector<int>&tablica) //Stworzenie funkcji jako wektora algorytm przyjmującego wartości wektora tablica
{
    std::vector<std::pair<int,int>>wyniki;
    int rz = tablica.size();
    for(int i = 0; i <rz; i++) // Pêtla sprawdzaj¹ca wartoœæ ka¿dego indeksu tablicy
	{

	int min_odleglosc = i;
		if (i > (rz - i - 1)) min_odleglosc = rz - i - 1; //Warunek sprawdzaj¹cy maksymaln¹ iloœæ kroków "w lewo i prawo w tablicy"
		if (tablica[i]==2)  // Warunek sprawdzaj¹cy wartoœæ pod indeksem - musi byæ ona równa 2
		{
			int dlugosc = 0;
			while (dlugosc < min_odleglosc && (tablica[i-dlugosc-1] == tablica[i + dlugosc +1])) // Pêtla porównuj¹ca wartoœci w równych odleg³oœciach od i
			{
				dlugosc++;

			if (dlugosc > 0) wyniki.push_back(std::pair<int,int>(i-dlugosc, dlugosc*2+1 )); // Dodawanie wartoœci do wektora wyniki

			}

		}
	}
	std::vector<std::vector<int>> converted;


	for(int i = 0; i < wyniki.size();i++)
	{
	    std::vector<int> zmienna;
		for (int j = 0; j < wyniki[i].second; j++) {
            zmienna.push_back(tablica[wyniki[i].first + j]); //wpisanie do tablicy elementu tablicy wejsciowej + iterator j
        }
        converted.push_back(zmienna);
        std::ofstream output_file("test.txt");
        std::ostream_iterator<int> output_iterator(output_file, "|""\t");
        for ( int i = 0 ; i < converted.size() ; i++ ) // ZAPISYWANIE WYNIKÓW WEKTORA CONVERTED JAKO TABLICY DO PLIKU "test.txt
        {
        copy(converted.at(i).begin(), converted.at(i).end(), output_iterator);
        output_file <<  "\n";
        }

        }

    return converted;


}


int Symetria(int rz)
{

	if(rz <= 0)
	{
		std::cout << "Tablica nie moze miec wartosci mniejszej od 0 lub rownej 0"<<std::endl;
		return 0;
	}
	else{

	srand((unsigned int)time(NULL)); //Funkcja resetuj¹ca losowania liczb za ka¿dym uruchomianiem programu.

//	std::cout << "Wprowadz rozmiar tablicy: " ; // Wprowadzenie rozmiaru losowego ci¹gu liczb
//
//	std::cin >> rz ;

//	cout << rz ;

	std::vector<int> tablica;   // Utworzenie tablicy

	tablica.resize(rz);

	for(int i=0;i<rz;i++)  // Utworzenie pêtli, która kazdemu indeksowi tablicy przypisuje losow¹ wartoœæ od 0 do 2;
	{
		tablica[i] = rand() %3;
	}
	std::vector<std::vector<int> > wyniki; //Wektor przyjmuj¹cy dwie wartoœci typu int o nazwie "wyniki"

	/*for (int i = 0; i < rz; i++)
	{
		std::cout << i<< "," << tablica[i] << "|"; // Pêtla wypisuj¹ca indeksy oraz wartoœci wektora "tablica"

	}*/
    auto begin = std::chrono::high_resolution_clock::now(); // Rozpoczêcie pomiaru czasu dzia³ania algorytmu
    wyniki = algorytm(tablica);
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin); // Wyœwietlanie czasu dzia³ania algorytmu



	for(int i = 0; i < wyniki.size();i++)
	{
		std::cout<< "|";
		for (int j = 0; j < wyniki[i].size(); j++) {
            std::cout << wyniki[i][j]; //Wyœwietlanie wyników w formie przejrzystej tablicy
            std::cout << "|";
        }
        std::cout<<"\n";


	}
	std::cout << "Czas algorytmu:\n";
    std::cout << (" %.3f seconds.\n", elapsed.count() * 1e-9);
	}
}
int main()
{
	int rz;
	std::cout << "Wprowadz zadany rozmiar tablicy z liczbami: \n" <<std::endl;
	std::cin >> rz;
	Symetria(rz);




	return 0;
}
