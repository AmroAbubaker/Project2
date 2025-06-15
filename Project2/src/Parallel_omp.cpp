// src/parallel_omp.cpp
#include <iostream>
#include <vector>
#include <omp.h>
#include <chrono>

using namespace std;

int main() {
    int n = 1000;
    int num_threads = 8; 

    vector<vector<int>> A(n, vector<int>(n, 1));
    vector<vector<int>> B(n, vector<int>(n, 2));
    vector<vector<int>> C(n, vector<int>(n, 0));

    omp_set_num_threads(num_threads);

    auto start = chrono::high_resolution_clock::now();

    #pragma omp parallel for
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            C[i][j] = 0;
            for (int k = 0; k < n; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;

    cout << "Time taken by OpenMP multiplication with " << num_threads << " threads: " << elapsed.count() << " seconds.\n";
    cout << "Sample output C[0][0]: " << C[0][0] << endl;

    return 0;
}
