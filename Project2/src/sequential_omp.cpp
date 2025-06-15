// src/sequential_omp.cpp
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

void multiplyMatricesSequential(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& C) {
    int n = A.size();
    int m = B[0].size();
    int p = B.size();

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int sum = 0;
            for (int k = 0; k < p; ++k) {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }
}

int main() {
    int n = 100;  
    vector<vector<int>> A(n, vector<int>(n, 1));  
    vector<vector<int>> B(n, vector<int>(n, 2));  
    vector<vector<int>> C(n, vector<int>(n, 0));   

    auto start = chrono::high_resolution_clock::now();

    multiplyMatricesSequential(A, B, C);

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;

    cout << "Time taken by sequential multiplication: " << elapsed.count() << " seconds.\n";
    cout << "Sample output C[0][0]: " << C[0][0] << endl;

    return 0;
}
