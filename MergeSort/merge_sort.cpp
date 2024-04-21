///merge sort
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

//2 posortowane tablice
///sortowanie stabilne

void Merge(int *tab, int start, int mid, int stop)
{
    int a;
    a= stop-start+1;
    int* tmp=new int[a];
    for (int i=0; i<a; i++)
    {
        tmp[i]=tab[i+start];
    }
    int i=0;
    int j=mid-start;
    for (int z=start; z<=stop; z++)
    {

        if(i>=mid-start)
        {
            tab[z]=tmp[j];
            j++;
            continue;
        }
        if(j>(a-1))
        {
            tab[z]=tmp[i];
            i++;
            continue;
        }
        if(tmp[i]<=tmp[j])
        {
            tab[z]=tmp[i];
            i++;
            continue;
        }
        else
        {
            tab[z]=tmp[j];
            j++;
        }
    }
    /* LUB
for (int z=start; z<=stop; z++)
{
    if((i>=mid-start)||(j<a && tmp[j]<tmp[i]))
        tab[z]=tmp[j++];
    else
        tab[z]=tmp[i++];
    */
}

void MergeSortR(int tab[],int start, int stop)
{
    if(stop<=start)
    {
        return;
    }
    int mid=(start+stop+1)/2; ///+1 bo mid rozpoczyna prawa tablice -> bez tego na koncu tworzy sie tablica pusta i tablica 2 elementowa zamiast dwie po 1 elemencie
    MergeSortR(tab,start,mid-1);
    MergeSortR(tab,mid,stop);
    Merge(tab, start, mid, stop);
}

int main()
{
//    int tab[10] = {1,3,5,7,9,2,2,4,6,6};
//
//    Merge(tab, 0, 5, 9);
//    for(int i=0; i<10;i++)
//    {
//        cout<<tab[i]<<", ";
//    }
    int tab[100];
    for(int i=0; i<100; i++)
    {
        tab[i]=rand()% 300;
    }
    MergeSortR(tab,0,99);
    for(int i=0; i<100; i++)
    {
        cout<<tab[i]<<" ";
    }
    return 0;
}
