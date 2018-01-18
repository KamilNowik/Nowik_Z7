#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

const int n=30;
const double P=10000, D=25;
double srednia;

struct SAuto
    {
        string marka;
        int rocznik;
        double cena;
    };

SAuto A[n];

void wczytywanie()
{
    ifstream plik("auta.txt");

    for(int i=0; i<n; i++)
    {
        if (plik.eof())
            {
            cout<<endl<<"Podano za malo danych, program musi zostac przerwany :("<< endl;
            return;
            }
        plik>>A[i].marka;
        plik>>A[i].rocznik;
        plik>>A[i].cena;

    }
}

void liczenie_sredniej()
{
    double suma=0;
    int ile=0;

    for(int i=0; i<n; i++)
    {
        if(A[i].rocznik>2013 && A[i].marka[0]==A[n-1].marka[0])
        {
            ile++;
            suma+=A[i].cena;
        }
    }
    srednia=suma/ile;
}


void rabat()
{
    for(int i=0; i<n; i++)
    {
        if (A[i].rocznik==2017 && (A[i].cena>srednia+P))
        {
            A[i].cena=A[i].cena-(A[i].cena*(D*0.01));
        }
    }
}

void zamiana_najstarszego ()
{
    SAuto schowek_rekordowy;
    int najstarszy=0;
    for(int i=1; i<n; i++)
    {
        if(A[i].rocznik<A[najstarszy].rocznik)
        {
                najstarszy=i;
        }
    }
    schowek_rekordowy=A[najstarszy];
    A[najstarszy]=A[0];
    A[0]=schowek_rekordowy;
}

void drukowanie_tablicy()
{
    for(int i=0;i<n;i++)
    {
        cout<<A[i].marka<< " ";
        cout<<A[i].rocznik<< " ";
        cout<<A[i].cena<< endl;
    }
}


int main()
{
    wczytywanie();

    liczenie_sredniej();

    rabat();

    zamiana_najstarszego();

    drukowanie_tablicy();

    return 0;
}
