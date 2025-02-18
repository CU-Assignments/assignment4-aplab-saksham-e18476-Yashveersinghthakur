#include <iostream>
#include <vector>

using namespace std;

vector<int> beautifulArray(int n) {
    vector<int> res = {1};  // Start with base case
    while (res.size() < n) {
        vector<int> temp;
        for (int num : res) {
            if (2 * num - 1 <= n) temp.push_back(2 * num - 1); // Odd numbers
        }
        for (int num : res) {
            if (2 * num <= n) temp.push_back(2 * num); // Even numbers
        }
        res = temp;
    }
    return res;
}

// Helper function to print an array
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter value of n: ";
    cin >> n;

    vector<int> beautiful = beautifulArray(n);
    cout << "Beautiful Array for n = " << n << ": ";
    printArray(beautiful);

    return 0;
}
