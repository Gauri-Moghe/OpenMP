#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <chrono>
#include <omp.h>

void choleskyDecomposition(const std::vector<std::vector<double>>& A, std::vector<std::vector<double>>& L, int N) {
    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            double sum = 0;

            if (j == i) {
                for (int k = 0; k < j; k++) {
                    sum += pow(L[j][k], 2);
                }
                L[j][j] = sqrt(A[j][j] - sum);
            } else {
                for (int k = 0; k < j; k++) {
                    sum += L[i][k] * L[j][k];
                }
                L[i][j] = (A[i][j] - sum) / L[j][j];
            }
        }
    }
}

int main() {
    int N = 1200;
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    std::vector<std::vector<double>> A(N, std::vector<double>(N, 0.0));
    omp_set_num_threads(14);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = static_cast<double>(rand()) / RAND_MAX;
        }
    }

    std::vector<std::vector<double>> L(N, std::vector<double>(N, 0.0));

    auto start = std::chrono::high_resolution_clock::now();

    choleskyDecomposition(A, L, N);

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start);

    std::cout << "\nRunning Time: " << duration.count() << " seconds" << std::endl;

    return 0;
}
