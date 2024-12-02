#include <iostream>
#include <fstream>
#include "StringBinaryTree.h"
using namespace std;

void processChoice(int choice, StringBinaryTree& tree);

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
        // Display the menu
        cout << "\nMenu Options:\n";
        cout << "1. Add a code\n";
        cout << "2. Delete a code\n";
        cout << "3. Search for a code\n";
        cout << "4. Modify a code\n";
        cout << "5. Display all codes in-order\n";
        cout << "6. Display all codes pre-order\n";
        cout << "7. Display all codes post-order\n";
        cout << "8. Exit\n";

        // Process the choice
        cout << "\nEnter your choice: ";
        cin >> choice;
        cin.ignore(1000, '\n');

        processChoice(choice, tree);
    } while (choice != 8);

    return 0;
}

void processChoice(int choice, StringBinaryTree& tree)
{

}
