
#include <iostream>
#include <list>
#include <fstream>
#include <string>


using namespace std;
class Graph
{
public:
	void LoadMatrix(const string& FileName);
		
	void PrintMatrix();

	int GetSize() { return Size; }
public:


	int** Matrix;

	int Size = 0;
};

