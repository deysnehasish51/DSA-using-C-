#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    unordered_map<string, string> hashTable;
 
    hashTable["name"] = "Alice";
    hashTable["age"] = "25";
    hashTable["city"] = "New York";

    cout << "Name: " << hashTable["name"] << endl;
    cout << "Age: " << hashTable["age"] << endl;
    cout << "City: " << hashTable["city"] << endl;

    return 0;
}