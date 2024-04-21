#include<iostream>

using namespace std;

int L(int idx){return 2*idx+1;}

int R(int idx){return 2*idx+2;}

int P(int idx){return ((idx+1)/2)-1;}

void FixFromBelow (int t[], int ilosc)
{
    int walker = ilosc -1;
    while(walker > 0 && t[walker]>t[P(walker)])
    {
        swap(t[walker], t[P(walker)]);
        walker = P(walker);
    }
}

void Add(int t[], int &ilosc, int p)
{
    t[ilosc] = p;
    ilosc++;
    FixFromBelow(t,ilosc);
}

void FixFromAbove (int t[], int ilosc)
{
    int walker = 0;
    while(true)
    {
        int naj = walker;
        if(R(walker)<ilosc && t[R(walker)]>t[naj])
        {
            naj = R(walker);
        }
        if(L(walker)<ilosc && t[L(walker)]>t[naj])
        {
            naj = L(walker);
        }
        if(naj == walker)
        {
            break;
        }
        else
        {
            swap(t[walker],t[naj]);
            walker = naj;
        }
    }
}

int Pop(int t[], int& ilosc)
{
    ilosc--;
    swap(t[0],t[ilosc]);
    FixFromAbove(t,ilosc);
    return t[ilosc];
}

void HeapSort(int t[], int _size)
{
    int ilosc = 1;
    for(int i = 1; i<_size; i++)
    {
        ilosc ++;
        FixFromBelow(t,ilosc);
    }
    for(int i = 1; i<_size; i++)
    {
        Pop(t,ilosc);
    }
}

/// Merge sort  nlogn           O(n)            stabilny
/// QuickSort   czasami n^2     O(logn)-O(n)    niestabilny
/// HeapSort    nlog            O(1)            niestabilny

int main()
{
    int* tab = new int [300];
    int ilosc = 0;
    for(int i = 0; i<10; i++)
    {
        Add(tab,ilosc,rand()%10);
    }
    for(int i = 0; i<ilosc; i++)
    {
        cout<<tab[i]<<", ";
    }

    cout<<endl<<endl;

    for (int i = 0; i<10; i++)
    {
          cout<<Pop(tab, ilosc)<<endl;
    }

    cout<<endl<<"Funkcja PoP"<<endl;
    for(int i = 0; i<ilosc; i++)
    {
        cout<<tab[i]<<", ";
    }
    cout<<endl<<"Koniec funkcji Pop"<<endl;

    return 0;
}
