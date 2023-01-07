#include <iostream>
#include <cmath>
using namespace std;
#define SuccessCode 201
#define NotModified 304
#define DefaultValue -1
#define NotFound 404
class HashTable
{
private:
    int *Table;
    int size = 10;
    int SpaceLeft = size;

public:
    HashTable() // default Constructor
    {
        Table = new int[size];
        Define();
    }
    HashTable(int Size) // Given size Constructor
    {
        Size = abs(Size); // if size is negative
        Table = new int[Size];
        size = Size;
        Define();
    }
    int Search(int KeyValue)
    {
        bool Found = false;
        int hashIndex = hash(KeyValue);
        if (Table[hashIndex] == KeyValue)
        {
            Found = true;
            return hashIndex;
        }
        int i = 0;
        while (Table[hashIndex] != KeyValue && i < size)
        {
            hashIndex = (hashIndex + 1) % size;
            i++;
        }
        if (i == size) // if not present
        {
            Found = false;
            return -1;
        }
    }
    int Insert(int value)
    {
        if (SpaceLeft == 0)
        {
            return NotModified;
        }
        int hashIndex = hash(value); // Calculate the hash index of the key
        // if the slot is empty, then insert the value
        if (Table[hashIndex] == DefaultValue)
        {
            Table[hashIndex] = value;
            SpaceLeft--;
            return SuccessCode;
        }
        // int ActualIndex = hashIndex;
        int i = 0;
        bool Flag = false;
        while (Table[hashIndex] != DefaultValue && i < size)
        { // If the slot at the calculated hash index is not empty

            hashIndex = (hashIndex + 1) % size; // Try the next slot in the Table
            i++;
        }
        if (i != size) // if the slot is present
        {
            Table[hashIndex] = value;
            SpaceLeft--;
            return SuccessCode;
        }
        // if the slot is not present
        return NotModified;
    }
    int Delete(int KeyValue)
    {
        int index = Search(KeyValue);
        if (index == -1)
        {
            return NotFound;
        }
        Table[index] = DefaultValue;
        SpaceLeft++;
        return SuccessCode;
    }
    int Update(int KeyValue, int Value)
    {
        int index = Search(KeyValue);
        if (index == -1)
        {
            return NotFound;
        }
        Table[index] = Value;
        return SuccessCode;
    }
    void Show()
    {
        for (int i = 0; i < size; i++)
        {
            cout << Table[i] << endl;
        }
        cout << "Space left: " << SpaceLeft << endl;
    };
    // Provate Functions work as a Decorators / Helper Functions
private:
    void Define()
    {
        for (int i = 0; i < size; i++)
        {
            Table[i] = DefaultValue;
        }
    }
    int hash(int val)
    {
        return val % size;
    }
};
