#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

const int TABLE_SIZE = 1000;
class HashTable
{
private:
    vector<int> table[TABLE_SIZE];
    int collisions = 0;

    int hashFunction(int key)
    {
        return key % TABLE_SIZE;
    }

public:
    void insert(int value)
    {
       
        int index = hashFunction(value);
        if (!table[index].empty() && !search(value) )
        {
            collisions++;
        }
        // if(search(value))return;

        // table[index].push_back(value);
    }

    bool search(int value)
    {
        int index = hashFunction(value);
        for (int v : table[index])
        {
            if (v == value)
            {
                return true;
            }
        }
        return false;
    }

    void remove(int value)
    {
        int index = hashFunction(value);
        for (auto it = table[index].begin(); it != table[index].end(); ++it)
        {
            if (*it == value)
            {
                table[index].erase(it);
                return;
            }
        }
    }

    int getCollisions()
    {
        return collisions;
    }

    void clear()//for rehashing
    {
        collisions = 0;
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            table[i].clear();
        }
    }
};

void runExperiment(int numElements)
{
    HashTable hashTable;
    srand(time(0)); 

    for (int i = 0; i < numElements; i++)
    {
        int value = rand(); 
        hashTable.insert(value);
    }

    cout << "Collisions after inserting " << numElements << " elements: " << hashTable.getCollisions() << endl;
}

int main()
{
    int tableSize = 1000;

    int numElements20 = tableSize * 0.2;
    cout << "Experiment with 20% fill:" << endl;
    runExperiment(numElements20);

    int numElements50 = tableSize * 0.5;
    cout << "Experiment with 50% fill:" << endl;
    runExperiment(numElements50);

    int numElements80 = tableSize * 0.8;
    cout << "Experiment with 80% fill:" << endl;
    runExperiment(numElements80);

    return 0;
}
