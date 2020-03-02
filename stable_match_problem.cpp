/*
Nama    : Alvin
NPM     : 140810180013
Kelas   : A
Tugas   : Stable Matching Problem
*/

#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;
#define N 5

bool pilihPria(int prioritas[2 * N][N], int w, int m, int m1){//mengecek prioritas
    for (int i = 0; i < N; i++)
    {
        if (prioritas[w][i] == m1)
            return true;

        if (prioritas[w][i] == m)
            return false;
    }
} 
void pencocokan(int prioritas[2 * N][N]) {
    int pasanganWanita[N];

    bool priaSingle[N];

    memset(pasanganWanita, -1, sizeof(pasanganWanita));
    memset(priaSingle, false, sizeof(priaSingle));
    int jumlahSingle = N;

    while (jumlahSingle > 0){
        int m;//inisialisasi pasangan pria
        for (m = 0; m < N; m++)
            if (priaSingle[m] == false)
                break;

        for (int i = 0; i < N && priaSingle[m] == false; i++){//pria single memilih pasangan berdasarkan prioritas tertingginya
            int w = prioritas[m][i];

            if (pasanganWanita[w - N] == -1){//jika wanita belum bertunangan
                pasanganWanita[w - N] = m;
                priaSingle[m] = true;
                jumlahSingle--;
            }

            else{
                int m1 = pasanganWanita[w - N];//jika wanita sudah bertunangan

                if (pilihPria(prioritas, w, m, m1) == false){
                    pasanganWanita[w - N] = m;
                    priaSingle[m] = true;
                    priaSingle[m1] = false;
                }
            } 
        }
    }

    cout << " HASIL PASANGAN  \n" << endl;
    string pria;
    string wanita;
    for (int i = 0; i < N; i++){
        if (i < N){
            if (pasanganWanita[i] == 0)
                pria = "Victor";
            if (pasanganWanita[i] == 1)
                pria = "Wyatt";
            if (pasanganWanita[i] == 2)
               pria = "Xavier";
            if (pasanganWanita[i] == 3)
                pria = "Yancey";
            if (pasanganWanita[i] == 4)
                pria = "Zeus";
                
            if (i == 0)
                wanita = "Amy";
            if (i == 1)
                wanita = "Bertha";
            if (i == 2)
               wanita = "Clare";
            if (i == 3)
               wanita = "Diane";
            if (i == 4)
               wanita = "Erika";
        }
        cout  <<pria << "\t&  " << wanita << endl;
    }
}

int main()
{
    int prioritas[2 * N][N] = {{6, 5, 8, 9, 7},{8, 6, 5, 7, 9}, {6, 9, 7, 8, 5},{5, 8, 7, 6, 9}, {6, 8, 5, 9, 7},
                            {4, 0, 1, 3, 2},{2, 1, 3, 0, 4}, {1, 2, 3, 4, 0}, {0, 4, 3, 2, 1}, {3, 1, 4, 2, 0}
							};
    pencocokan(prioritas);

    return 0;
}
 
