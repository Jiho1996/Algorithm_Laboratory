
#include <iostream>
#include <string>
#include "graph.h"

using namespace std;

int main(void) {
    Graph g;

    string filename;
    getltine(cin, filename);

    g.LoadMatrix(filename);
    g.PrintMatrix();

    return 0;
}