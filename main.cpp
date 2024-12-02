/***************************************************************************
* COMSC-210 | Lab 36 | Grant Luo
* Editor: CLion
* Compiler: Apple clang version 16.0.0
*/
#include <iostream>
#include <fstream>
#include "StringBinaryTree.h"
using namespace std;

void processChoice(int choice, StringBinaryTree& tree);
void print_id(string const& lab_desc);

int main() {

    print_id("")
    StringBinaryTree tree;

    try
    {
        ifstream fin("codes.txt");
        if (!fin.good())
            throw "I/O error";
        string code;
        while (getline(fin, code))
            tree.insertNode(code);
        fin.close();
    }
    catch(const char* e)
    {
        cout << e << "\n";
    }

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
    string code;
    string newCode;

    switch (choice)
    {
        case 1:
        {
            cout << "Enter the code to add: ";
            getline(cin, code);
            tree.insertNode(code);
            cout << "Code added.\n";
            break;
        }
        case 2:
        {
            cout << "Enter the code to delete: ";
            getline(cin, code);
            if (tree.searchNode(code))
            {
                tree.remove(code);
                cout << "Code deleted.\n";
            }
            else
                cout << "Code not found.\n";
            break;
        }
        case 3:
        {
            cout << "Enter the code to search for: ";
            getline(cin, code);
            if (tree.searchNode(code))
                cout << "Code found.\n";
            else
                cout << "Code not found.\n";
            break;
        }
        case 4:
        {
            cout << "Enter the code to modify: ";
            getline(cin, code);
            if (tree.searchNode(code))
            {
                cout << "Enter a new code: ";
                getline(cin, newCode);
                tree.insertNode(newCode);
                cout << "Code modified.\n";
            }
            else
                cout << "Code not found.\n";
            break;
        }
        case 5:
        {
            cout << "Displaying codes in-order:\n";
            tree.displayInOrder();
            break;
        }
        case 6:
        {
            cout << "Displaying codes pre-order:\n";
            tree.displayPreOrder();
            break;
        }
        case 7:
        {
            cout << "Displaying codes post-order:\n";
            tree.displayPostOrder();
            break;
        }
        case 8:
        {
            cout << "Exiting the program...\n";
            break;
        }
        default:
            cout << "Invalid choice. Please try again.\n";
    }
}

void print_id(string const& lab_desc)
{
    cout << "\nCOMSC210 | Grant Luo | " << lab_desc << "\n";
    cout << "Editor: CLion\n";
    cout << "Compiler: Apple clang version 16.0.0\n";
    cout << "File: " << __FILE__ << "\n";
    cout << "Compiled: " << __DATE__ << " at " << __TIME__ << "\n\n";
}
