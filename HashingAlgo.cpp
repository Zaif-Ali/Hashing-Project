#include <iostream>
#include "FunctionControllers.h"
#include <fstream>
#include <string>
main()
{
    HashTable NADRA(10); // initialize Object of hash table
    // Read CNIC from .txt file and add it to the hash table
    int word;
    ifstream file("Data.txt");
    if (file.is_open())
    {
        while (!file.eof())
        {
            file >> word;
            AddCNIC(NADRA, word);
        }
        file.close();
    }
    else
    {
        cout << "Unable to open file." << endl;
    }
    ShowAllData(NADRA);
    // SearchCNIC(NADRA, 11111);
    // UpdateCNIC(NADRA, 11111 , 22222);
    // DeleteCNIC(NADRA, 22222);
}