#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

void ReadOnegin();

int main ()
    {
    //ReadOnegin ();
    }

void ReadOnegin()
    {
    FILE * text;
    text = fopen ("Evgeniy-Onegin.txt", "r");
    char time[100] = {""};
    for (int i = 0; i<50/*8288*/; i++)
        {
        fgets(time, 100, text);

        }

    fclose (pFile);
    }
