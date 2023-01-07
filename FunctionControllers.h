#include <iostream>
#include "Hashing.h"
int AddCNIC(HashTable &TableName, int value)
{
    int response = TableName.Insert(value);
    return response;
}
int AddCNIC(HashTable &TableName, int *arr, int SizedValue)
{
    for (int i = 0; i < SizedValue; i++)
    {
        int response = TableName.Insert(arr[i]);
        if (response == NotModified)
        {
            cout << "Only " << i << " entries are modified out of " << SizedValue << " - " << SizedValue - i << " entries are left" << endl;
            break;
        }
    }
}
int SearchCNIC(HashTable &TableName, int Key)
{
    cout << TableName.Search(Key);
}
void ShowAllData(HashTable &TableName)
{
    TableName.Show();
}
void DeleteCNIC(HashTable &TableName, int Key)
{
    if (TableName.Delete(Key) == 404)
    {
        cout << "Error in deleting" << endl;
    }
    else
    {
        cout << "Deleted" << endl;
    }
}
void UpdateCNIC(HashTable &TableName, int Key, int Value)
{
    if (TableName.Update(Key, Value) == NotFound)
    {
        cout << "Not Found" << endl;
    }
    else
    {
        cout << "Updated" << endl;
    }
}
