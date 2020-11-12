
#include <iostream>
#include <list>
#include <fstream>
#include <string>

#include "graph.h"

using namespace std;

void Graph::LoadMatrix(const string &FileName)
{
    list<int> listInt;
    ifstream inf(FileName);
    int intTemp;

    int Count = 0;
    if (!inf)
    {
        cout << "파일 개방 실패" << endl;
        return;
    }
    int i = 0, j = 0;
    while (!inf.eof()) {

        inf >> intTemp;
        if (Count == 0)
        {
            Size = intTemp;
            Matrix = new int* [intTemp];
            for (int i = 0; i < intTemp; ++i)
            {
                Matrix[i] = new int[intTemp];
               (Matrix[i], 0, sizeof(int) * intTemp);
            }
            Count++;
        }
        else
        {

            Matrix[i][j] = intTemp;
            j++;
            if (j >= Size)
            {
                i++, j = 0;
            }
        }
        listInt.push_back(intTemp);
    }
}

void Graph::PrintMatrix()
{
    for (int i = 0; i < Size; i++)
    {

        for (int j = 0; j < Size; j++)
        {
            cout << Matrix[i][j] << "\t";
        }
        cout << endl;
    }
}
