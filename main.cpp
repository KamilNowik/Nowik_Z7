#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;


struct SAuto
    {
        string marka;
        int rocznik;
        double cena;
    };



int main()
{

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



    ifstream plik("auta.txt");

    for(int i=0; i<n; i++)
    {
        if (plik.eof())
            {
            cout<<endl<<"Podano za malo danych, program musi zostac przerwany :("<< endl;
            return 0;
            }
        plik>>A[i].marka;
        plik>>A[i].rocznik;
        plik>>A[i].cena;

    }



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
    if(ile<1)
    {
        srednia=A[n-1].cena;
    }
    if(ile>0)
    {
        srednia=suma/ile;
    }






    for(int i=0; i<n; i++)
    {
        if (A[i].rocznik==2017 && (A[i].cena>srednia+P))
        {
            A[i].cena=A[i].cena-(A[i].cena*(D*0.01));
        }
    }



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




    for(int i=0;i<n;i++)
    {
        cout<<A[i].marka<< " ";
        cout<<A[i].rocznik<< " ";
        cout<<A[i].cena<< endl;
    }



    return 0;
}
