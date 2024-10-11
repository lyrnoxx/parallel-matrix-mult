#include <iostream>
#include <vector>
#include <chrono>
#include <omp.h>

using namespace std;
using namespace std::chrono;

void sequential_matrix_mult(const vector<vector<int>>& a, const vector<vector<int>>& b, vector<vector<int>>& c, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void parallel_matrix_mult(const vector<vector<int>>& a, const vector<vector<int>>& b, vector<vector<int>>& c, int n, int num_threads) {
    #pragma omp parallel for num_threads(num_threads) collapse(2)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    vector<int> sizes = {10, 50, 100, 500};
    vector<int> thread_counts = {1, 2, 4, 8};

    for (int n : sizes) {
        vector<vector<int>> a(n, vector<int>(n, 1));
        vector<vector<int>> b(n, vector<int>(n, 1));

        vector<vector<int>> c_seq(n, vector<int>(n, 0));
        auto start_seq = high_resolution_clock::now();
        sequential_matrix_mult(a, b, c_seq, n);
        auto end_seq = high_resolution_clock::now();
        auto duration_seq = duration_cast<microseconds>(end_seq - start_seq);
        cout << "Time taken (sequential) for " << n << "x" << n << ": " << duration_seq.count() << " microseconds" << endl;

        for (int num_threads : thread_counts) {
            vector<vector<int>> c_par(n, vector<int>(n, 0)); 
            auto start_par = high_resolution_clock::now();
            parallel_matrix_mult(a, b, c_par, n, num_threads);
            auto end_par = high_resolution_clock::now();
            auto duration_par = duration_cast<microseconds>(end_par - start_par);
            cout << "Time taken (parallel) with " << num_threads << " threads for " << n << "x" << n << ": " << duration_par.count() << " microseconds" << endl;
        }

        cout << "--------------------------------------------" << endl;
    }

    return 0;
}
