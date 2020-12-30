
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <time.h>
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <windows.h>
#define INF 9999999
#define N 1000
//#define V 5
using namespace std;
FILE* rez;
int V = 0;
int** G;
int* selected;
int no_edge;            
int x;            
int y;           
int term;
 

void memory() {
    printf("Размер матрицы:");
    scanf_s("%d", &V);

    G = (int**)malloc(V * sizeof(int*));

    for (int i = 0; i < V; i++)
    {
        G[i] = (int*)malloc(V * sizeof(int));
    }
}

void matrix_random() {
    srand(time(NULL));

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            G[i][j] = rand() % 20;
        }
    }
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (i == j) {
                G[i][j] = 0;
            }
            G[j][i] = G[i][j];
        }
    }
}

void matrix_vvod() {
   
    for (int i = 0; i < V; i++) 
    {
        for (int j = i+1; j < V; j++)  
        {
            printf("G[%d][%d] = ", i, j);
            scanf_s("%d", &G[i][j]);
        }
    }
    for (int i = 0; i < V; i++)  
    {
        for (int j = 0; j < V; j++)  
        {
            if (i == j) {
                G[i][j] = 0;
            }
            G[j][i] = G[i][j];
        }
    }
}

void matrix_vivod() {
    rez = fopen("Rezultat.txt", "a");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            printf("%2d ", G[i][j]);
            fprintf(rez, "%2d ", G[i][j]);
        }
        printf("\n");
        fprintf(rez, "\n");
    }
    fprintf(rez, "\n");
    fclose(rez);
    printf("\n");
}

void function() {
    matrix_vivod();
    selected = (int*)malloc(V * sizeof(int));
    for (int i = 0; i < V; i++) {
        selected[i] = false;
    }
    no_edge = 0;
    selected[0] = true;
    rez = fopen("Rezultat.txt", "a");
    printf("Ребро : Вес ребра");
    fprintf(rez, "Ребро : Вес ребра");
    printf("\n");
    fprintf(rez, "\n");
    fclose(rez);
    rez = fopen("Rezultat.txt", "a");
    while (no_edge < V - 1) {

        int min = INF;
        x = 0;
        y = 0;

        for (int i = 0; i < V; i++) {
            if (selected[i]) {
                for (int j = 0; j < V; j++) {
                    if (!selected[j] && G[i][j]) { // not in selected and there is an edge
                        if (min > G[i][j]) {
                            min = G[i][j];
                            x = i;
                            y = j;
                        }

                    }
                }
            }
        }
        printf("%d - %d : %d", x, y, G[x][y]);
        fprintf(rez, "%d - %d : %d\n", x, y, G[x][y]);
        printf("\n");
        selected[y] = true;
        no_edge++;
    }
    fclose(rez);
    rez = fopen("Rezultat.txt", "a");
    fprintf(rez, "------------------------------------------------------------------------------------");
    fprintf(rez, "\n");
    fclose(rez);
    free(G);
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Rus");
    system("cls");
    printf("+---------------------------------------------+\n");
    printf("|                     Меню                    |\n");
    printf("+---------------------------------------------+\n");
    printf("+  1 Заполнение массива рандомными числами    +\n");
    printf("+  2 Заполнение массива с клавиатуры          +\n");
    printf("+  3 Результаты работы программы              +\n");
    printf("+  4 Выход                                    +\n");
    printf("+---------------------------------------------+\n");

    scanf_s("%d", &term);

    while (term != 0)
    {

        if (term == 1)
        {
            system("cls");
            memory();
            matrix_random();
            function();
            _getch();
        }

        else if (term == 2)
        {
            system("cls");
            memory();
            matrix_vvod();
            function();
            _getch();
        }
        else if (term == 3)
        {
            system("cls");
            char arr[N];
            rez = fopen("Rezultat.txt", "r");
            while (fgets(arr, N, rez) != NULL)
                printf("%s", arr);
            printf("\n");
            fclose(rez);
            _getch();
        }

        else if (term == 4)
        {
            exit(0);
        }

        else {
            printf("Введите значение от 1-4");
        }
        printf("+---------------------------------------------+\n");
        printf("|                     Меню                    |\n");
        printf("+---------------------------------------------+\n");
        printf("+  1 Заполнение массива рандомными числами    +\n");
        printf("+  2 Заполнение массива с клавиатуры          +\n");
        printf("+  3 Результаты работы программы              +\n");
        printf("+  4 Выход                                    +\n");
        printf("+---------------------------------------------+\n");
        scanf_s("%d", &term);
    }
    return 0;
}