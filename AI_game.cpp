//AI file

#include <iostream>
#include "AI_Game.h"
#include <fstream>
using namespace std;


void EnemyTurn(int A[], int b) // Choose diffcult
{

    if (b == 1)
        DumbTurn(A);
    if (b == 2)
        SmartTurn(A, 2);
    if (b == 3)
        DumbTurn(A);
}

void DumbTurn(int A[]) //just random turn
{
    while (true)
    {
        int a = rand();
        a = a % 10;
        if (A[a] == 0)
        {
            A[a] = 2;
            return;
        }

    }
}

bool CheckVictory(int A[]) //Check all combination to win
{
    if ((A[0] == A[1]) && (A[0] == A[2]) && !(A[0] == 0)) 
        return 1;
    if ((A[3] == A[4]) && (A[3] == A[5]) && !(A[3] == 0)) 
        return 1;
    if ((A[6] == A[7]) && (A[6] == A[8]) && !(A[6] == 0))
        return 1;

    if ((A[0] == A[3]) && (A[0] == A[6]) && !(A[0] == 0)) 
        return 1;
    if ((A[1] == A[4]) && (A[1] == A[7]) && !(A[1] == 0))
        return 1;
    if ((A[2] == A[5]) && (A[2] == A[8]) && !(A[2] == 0))
        return 1;

    if ((A[0] == A[4]) && (A[0] == A[8]) && !(A[0] == 0)) 
        return 1;
    if ((A[2] == A[4]) && (A[2] == A[6]) && !(A[2] == 0))
        return 1;

    return 0;
}

bool IfItDraw(int A[]) //Check can make turn?
{
    int i = 0;
    while (i<9)
    {
        if (A[i] == 0)
            return false;
        i++;
    }
    return true;
}


void PrintTable(int A[])
{
    int i = 0;
    while (i < 9)
    {
        if (A[i] == 0)
            std::cout << "*";
        if (A[i] == 1)
            std::cout << "X";
        if (A[i] == 2)
            std::cout << "O";
        i++;
        if (!(i % 3))
            std::cout << endl;
        else
            std::cout << "|";
    }
}

void ClearTable(int A[]) //In new game clear array 
{
    int i = 0;
    while (i < 9)
    {
        A[i] = 0;
        i++;
    }
}

bool ChooseBlock(int A[],int i, int j, int g)   //Used in SmartTurn for win move, or don't let player win
{                                               //Checking for a combination
    if ((A[i]==(3-g)) || (A[j]==(3-g)))         //if g=2 then check can AI win? 
    {                                           //if in row not player simvol, check second AI simvol in row
        return false;                           //if all true, place AI simvol in free combo row
    }                                           //if g=1 then check can player win?
    if (A[i] == g)
        {
            A[j] = 2;
            return true;
        }
    if (A[j] == g)
        {
            A[i] = 2;
            return true;
        }
    return false;
}

void SmartTurn(int A[], int g) //Check all combo to win(AI and Player)
{               
    if (A[0] == g)             //---ToDo:Delete all duplicates---
        {
            if (ChooseBlock(A, 1, 2, g))
                return;
            if (ChooseBlock(A, 3, 6, g))
                return;
            if (ChooseBlock(A, 4, 8, g))
                return;
        }

    if (A[1] == g)
        {
            if (ChooseBlock(A, 0, 2, g))
                return;
            if (ChooseBlock(A, 4, 7, g))
                return;
        }

    if (A[2] == g)
        {
            if (ChooseBlock(A, 1, 0, g))
                return;
            if (ChooseBlock(A, 5, 8, g))
                return;
            if (ChooseBlock(A, 4, 6, g))
                return;
        }

    if (A[3] == g)
        {
            if (ChooseBlock(A, 4, 5, g))
                return;
            if (ChooseBlock(A, 0, 6, g))
                return;
        }

    if (A[4] == g)
        {
            if (ChooseBlock(A, 3, 5, g))
                return;
            if (ChooseBlock(A, 1, 7, g))
                return;
            if (ChooseBlock(A, 0, 8, g))
                return;
            if (ChooseBlock(A, 2, 6, g))
                return;
        }

    if (A[5] == g)
        {
            if (ChooseBlock(A, 3, 4, g))
                return; 
            if (ChooseBlock(A, 2, 8, g))
                return;
        }

    if (A[6] == g)
        {
            if (ChooseBlock(A, 7, 8, g))
                return;
            if (ChooseBlock(A, 0, 3, g))
                return;
            if (ChooseBlock(A, 4, 2, g))
                return;
        }

    if (A[7] == g)
        {
            if (ChooseBlock(A, 6, 8, g))
                return;
            if (ChooseBlock(A, 1, 4, g))
                return;
        }

    if (A[8] == g)
        {
            if (ChooseBlock(A, 6, 7, g))
                return;
            if (ChooseBlock(A, 2, 5, g))
                return;
            if (ChooseBlock(A, 0, 4, g))
                return;
        }
    if (g == 1)                         //If can't make win move or player can't make win move, then 
        DumbTurn(A);
    else                                //If can't make win move, then check can player make win move
        SmartTurn(A, g - 1);
}

int ChooseDiff()
{
    int b;
    while (true)
    {
        std::cout << "Choose dificl [1-easy] [2-Hard] [3-SUPER HARD]" << endl;
        cin >> b;
        if ((b == 1) || (b == 2) || (b == 3))
            return b;
        else
            std::cout << "Wrong! Try again!" << endl;
    }
}

void ThinkTurn(int A[])
{
    //---ToDo---
    //if can't do ThinkTurn, do
    SmartTurn(A, 2);
}

void RemeberGame(int A[])
{
    //ToDo
}
