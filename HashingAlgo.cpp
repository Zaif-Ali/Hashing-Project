#include <iostream>
#include <cmath>
#include "FunctionControllers.h"

main()
{
    HashTable NADRA(10);
    int arr[] = {11111, 223233, 322432532, 4364387, 5786323, 63698294, 7742874, 834343249, 93143232, 102252441, 153541, 267628, 289829};
    int size = sizeof(arr) / sizeof(arr[0]);
    AddCNIC(NADRA, arr, size);
    AddCNIC(NADRA, 43);
    ShowAllData(NADRA);
    cout << endl;
    SearchCNIC(NADRA, 21111);
    DeleteCNIC(NADRA, 223233);
    ShowAllData(NADRA);
    cout << endl;
    NADRA.Update(11111, 222221);
    ShowAllData(NADRA);
}