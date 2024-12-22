#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// Function to partition the array and return the pivot index
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Function to perform quicksort using a stack
void iterativeQuicksort(vector<int>& arr, int low, int high) {
    stack<pair<int, int>> stk;
    stk.push(make_pair(low, high));

    while (!stk.empty()) {
        low = stk.top().first;
        high = stk.top().second;
        stk.pop();

        if (low < high) {
            int pivot = partition(arr, low, high);

            // Push subarrays onto the stack
            stk.push(make_pair(low, pivot - 1));
            stk.push(make_pair(pivot + 1, high));
        }
    }
}

// Function to print the elements of the array
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {5, 3, 8, 6, 2, 7, 1, 4};
    cout << "Original array: ";
    printArray(arr);

    iterativeQuicksort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}