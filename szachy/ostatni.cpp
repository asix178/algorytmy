#include<iostream>
#include<cmath>

using namespace std;

int tab[8];
int k[64];
int w[64];
int P[8] = {-1,1,2,2,1,-1,-2,-2};
int Q[8] = {2,2,1,-1,-2,-2,1,-1};
int licznik = 0;

bool Szachuje(int ktory){
    for(int i = 0; i<ktory; i++){
        if(tab[ktory] == tab[i]){
            return true;
        }
        if(abs(ktory - i) == abs(tab[ktory] - tab[i])){
            return true;
        }
    }
    return false;
}

void PostawHetmana(int ktorego){
    if(ktorego == 8){
        cout<<"licznik: "<<++licznik<<"     ";
        for (int i = 0; i<8; i++){
            cout<<tab[i]<<" ";
        }
        cout<<endl;
        return;
    }
    for (int i = 0; i<8; i++){
        tab[ktorego]=i;
        if(Szachuje(ktorego) == false){
             PostawHetmana(ktorego+1);
        }
    }

}

bool Koliduje(int ktory){
    if(k[ktory]>7 || k[ktory]<0 || w[ktory]>7 || w[ktory]<0){
        return true;
    }
    for(int i = 0; i<ktory; i++){
        if(w[i] == w[ktory] && k[i] == k[ktory]){
            return true;
        }
    }
    return false;
}

void PostawSkoczka(int ktory){
    cout<<ktory<<"-";
    if(ktory == 64){
        cout<<"licznik: "<<++licznik<<"     ";
        for (int i = 0; i<64; i++){
            cout<<"["<<k[i]<<", "<<w[i]<<"]";
        }
        cout<<endl;
        return;
    }
    for(int i = 0; i<8; i++){
        k[ktory] = k[ktory - 1] + P[i];
        w[ktory] = w[ktory - 1] + Q[i];
        if(!Koliduje(ktory)){
            PostawSkoczka(ktory + 1);
        }
    }

}

int main(){
    //PostawHetmana(0);
    k[0] = 0;
    w[0] = 0;
    PostawSkoczka(1);
    cout<<"koniec";
    return 0;
}
