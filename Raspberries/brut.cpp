#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Function to calculate the product of an array
long long calculateProduct(const vector<int>& a) {
    long long product = 1;
    for (int num : a) {
        product *= num;
    }
    return product;
}

int minOperationsToMakeProductDivisible(vector<int>& a, int k) {
    int n = a.size();
    long long product = calculateProduct(a);
    int minOperations = INT_MAX;

    // Try all possible combinations of operations
    for (int i = 0; i < (1 << n); i++) {
        vector<int> modifiedArray = a;
        int operations = 0;

        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                while (modifiedArray[j] % k != 0) {
                    modifiedArray[j]++;
                    operations++;
                }
            }
        }

        if (calculateProduct(modifiedArray) % k == 0) {
            minOperations = min(minOperations, operations);
        }
    }

    return (minOperations == INT_MAX) ? -1 : minOperations;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int result = minOperationsToMakeProductDivisible(a, k);

    if (result == -1) {
        cout << "-1\n";
    } else {
        cout << result << endl;
    }

    return 0;
}
