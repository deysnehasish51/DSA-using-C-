#include <iostream>
#include <list>

using namespace std;

class HashTable {
private:
    static const int TABLE_SIZE = 10;
    int table[TABLE_SIZE];

public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            table[i] = -1;
        }
    }

    int hash(int data) {
        return data % TABLE_SIZE;
    }

    void insert_linear_probing(int  data) {
        int index = hash( data);
        int original_index = index;
        while (table[index] != -1) {
            index = (index + 1) % TABLE_SIZE; 
            if (index == original_index) {
            
                cout << "Hash table is full. Unable to insert " <<  data << endl;
                return;
            }
        }
        table[index] =  data;
    }

    void insert_quadratic_probing(int data) {
        int index = hash( data);
        int original_index = index;
        int i = 1;
        while (table[index] != -1) {
            index = (original_index + i * i) % TABLE_SIZE; 
            ++i;
            if (index == original_index) {
                cout << "Hash table is full. Unable to insert " <<  data << endl;
                return;
            }
        }
        table[index] =  data;
    }

    void print() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (table[i] != -1) {
                cout << table[i] << " ";
            }
        }
    }
};

int main() {
    HashTable linearProbingHashTable;
    HashTable quadraticProbingHashTable;

    linearProbingHashTable.insert_linear_probing(10);
    linearProbingHashTable.insert_linear_probing(20);
    linearProbingHashTable.insert_linear_probing(30);
    linearProbingHashTable.insert_linear_probing(40);
    linearProbingHashTable.insert_linear_probing(15); 

    cout << "Elements inserted using linear probing: ";
    linearProbingHashTable.print();
    cout << endl;

    quadraticProbingHashTable.insert_quadratic_probing(10);
    quadraticProbingHashTable.insert_quadratic_probing(20);
    quadraticProbingHashTable.insert_quadratic_probing(30);
    quadraticProbingHashTable.insert_quadratic_probing(40);
    quadraticProbingHashTable.insert_quadratic_probing(15); 

    cout << "Elements inserted using quadratic probing: ";
    quadraticProbingHashTable.print();
    cout << endl;

    return 0;
}