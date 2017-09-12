#include <stdio.h>
#include <iostream>
#include <string>
#include <cstdlib>

#define N 366

using namespace std;

void ReadOnegin(string Onegin[], int j);
int StrSr (const void * s1, const void * s2);

int main ()
    {
    setlocale( LC_ALL,"Russian" );
    string Onegin[14][N];
    for (int i = 0; i < 14; i++)
        {
        ReadOnegin (Onegin[i], i);
        }
    for (int j = 0; j < 14; j++)
        {
        qsort (Onegin[j], N, sizeof(string), StrSr);
        }
    for (int i = 0; i < 14; i++)
        {
        for (int j = 0; j < N; j++)
            {
            printf ("%s", Onegin[i][j].c_str());
            }
        }
    }

void ReadOnegin(string Onegin[], int j)
    {
    FILE * text;
    text = fopen ("Evgeniy-Onegin.txt", "r");
    char time[100] = {""};
    for (int k = 0; k < j; k++)
            {
            fgets (time, 100, text);
            }
    for (int i = 0; i<N; i++)
        {
        fgets (time, 100, text);
        Onegin[i] = time;
        for (int k = 0; k < 13; k++)
            {
            fgets (time, 100, text);
            }
        }
    fclose (text);
    }

int StrSr (const void * s1, const void * s2)
    {
    string* str1 = (string*)s1;
    string* str2 = (string*)s2;
    int sz1 = str1->size(), sz2 = str2->size();
    int cod1, cod2;

    if (sz1 == 0 || sz1 == 1) return -1;
    if (sz2 == 0 || sz2 == 1) return  1;
    if((sz1 == 0 || sz1 == 1) && (sz2 == 0 || sz2 == 1)) return 0;

    for (int i = sz1 - 1, j = sz2 - 1;;)
        {
        while (i < sz1 || i < 0)
            {
            if (i >= sz1 || i < 0) return -1;
            if (str1->at(i) < -64 || str1->at(i) > -1) i--;
            else break;
            }
        while (j < sz2 || j < 0)
            {
            if (j >= sz2 || j < 0) return 1;
            if (str2->at(j) < -64 || str2->at(j) > -1) j--;
            else break;
            }

        if (i >= sz1 || i < 0) return -1;
        if (j >= sz2 || j < 0) return 1;

        if (str1->at(i) >= -32) cod1 = str1->at(i);
        else cod1 = str1->at(i) + 32;

        if (str2->at(j) >= -32) cod2 = str2->at(j);
        else cod2 = str2->at(j) + 32;

        if (cod1 >  cod2) return  1;
        if (cod1 <  cod2) return -1;
        if (cod1 == cod2)
            {
            i--, j--;
            }
        }
    }
