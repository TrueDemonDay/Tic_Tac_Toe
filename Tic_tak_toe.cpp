// Tic_tak_toe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//It's simple and direct solution for console

#include <iostream>
#include "AI_Game.h"
using namespace std;

int main()
{
    int A[9];
    bool f = true;
    int a;
    ClearTable(A);
    int b = 0;
    b = ChooseDiff();
    while (f)
    {
        PrintTable(A);
        std::cout << "Make your turn [1-3] [4-6] [7-9]" << endl;
        cin >> a;
        a--;
        if (A[a] == 0)
        {
            A[a] = 1;
            if (IfItDraw(A))
                {
                    PrintTable(A);
                    std::cout << "Draw" << endl;
                    f = false;
                }
            else
            {
                if (CheckVictory(A))
                    {
                        PrintTable(A);
                        std::cout << "You WIN!!!" << endl;
                        f = false;
                    }
                else
                {
                    EnemyTurn(A, b);
                    if (CheckVictory(A))
                        {
                            PrintTable(A);
                            std::cout << "You LOSE!!!" << endl;
                            f = false;
                        }
                }
            }
            
        }
        else
        {
            std::cout << "Wrong turn" << endl;
        }
        if (!f)
            {
                std::cout << "Again??? [1-yes]" << endl;
                cin >> a;
                if (a == 1)
                {
                    b = ChooseDiff();
                    f = true;
                    ClearTable(A);
                }
            }
    }
}
