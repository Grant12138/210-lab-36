#include <iostream>
#include <fstream>
#include "StringBinaryTree.h"
using namespace std;

int main() {
    StringBinaryTree tree;

    try
    {
        ifstream fin("codes.txt");
        if (!fin.good())
            throw "I/O error";
    }
    catch(const char* e)
    {
        cout << e << "\n";
    }

    string code;
    while (getline(fin, code))
        tree.insertNode(code);
    fin.close();

    int choice;
    do
    {
        cout << "\nMenu Options:\n";
        cout << "1. Add a code\n";
        cout << "2. Delete a code\n";
        cout << "3. Search for a code\n";
        cout << "4. Modify a code\n";
        cout << "5. Display all codes"
    }

    return 0;
}