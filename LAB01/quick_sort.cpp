#include <bits/stdc++.h>
using namespace std;

// Function to generate a random number between 's' and 'e'
int random(int s, int e) {
    return (rand() % (e - s + 1)) + s;
}

// Function to partition the vector based on a pivot
int partition(vector<int> &arr, int s, int e) {
    int x = arr[e];  // Choose the last element as the pivot
    int i = s - 1;
    int j;
    for (j = s; j < e; j++) {
        if (arr[j] <= x) {
            i = i + 1;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[e]);  // Place the pivot in its correct position
    return i + 1;  // Return the index of the pivot
}

// Function to randomly choose a pivot and partition the vector
int randomized_partition(vector<int> &arr, int s, int e) {
    int i = random(s, e);
    swap(arr[i], arr[e]);  // Swap the randomly chosen pivot with the last element
    return partition(arr, s, e);
}

// Function to perform quick_sort recursively
void quick_sort(vector<int> &arr, int s, int e) {
    if (s < e) {
        int p = randomized_partition(arr, s, e);  // Partition the vector and get the pivot index
        quick_sort(arr, s, p - 1);  // Sort the elements before the pivot
        quick_sort(arr, p + 1, e);  // Sort the elements after the pivot
    }
}

int main() {
    vector<int> arr {7, 94, 163, 53, 196, 121, 72, 218, 5, 207, 152, 130, 61, 83, 229, 174, 94, 112, 185, 103};
    quick_sort(arr, 0, arr.size() - 1);  // Sort the vector using quick_sort
    for (auto c: arr) {
        cout << c << " ";  // Print the sorted elements
    }
    cout << endl;
    return 0;
}