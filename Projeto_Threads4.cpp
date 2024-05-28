#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <thread>

using namespace std;

// Função para gerar uma matriz com valores aleatórios entre -9 e 9
vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = rand() % 19 - 9; // Gera um número entre -9 e 9
        }
    }
    return matrix;
}

// Função para multiplicar uma seção das matrizes usando threads
void multiplyMatricesSection(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& C, int startRow, int endRow) {
    int n = A.size();
    for (int i = startRow; i < endRow; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Função para multiplicar duas matrizes usando várias threads
vector<vector<int>> multiplyMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B, int n) {
    vector<vector<int>> C(n, vector<int>(n, 0));
    int numThreads = 4; // Usando quatro threads
    vector<thread> threads;

    int rowsPerThread = n / numThreads;
    int remainingRows = n % numThreads;
    int currentRow = 0;

    for (int i = 0; i < numThreads; ++i) {
        int startRow = currentRow;
        int endRow = startRow + rowsPerThread + (remainingRows > 0 ? 1 : 0);
        threads.push_back(thread(multiplyMatricesSection, cref(A), cref(B), ref(C), startRow, endRow));
        currentRow = endRow;
        if (remainingRows > 0) remainingRows--;
    }

    for (auto& t : threads) {
        t.join();
    }

    return C;
}

// Função para imprimir uma matriz
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (const auto& val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    srand(time(0)); // Inicializa o gerador de números aleatórios

    cout << "\n\n\nInício do Projeto Threads Matriz A 5 x 5\n\n";

    // Matriz 5x5
    int n = 5;
    auto Z = generateMatrix(n);
    auto Y = generateMatrix(n);
    auto start_time = clock();
    auto A = multiplyMatrices(Z, Y, n);
    auto end_time = clock();
    double execution_time = double(end_time - start_time) / CLOCKS_PER_SEC;

    cout << "Matriz resultante:\n";
    printMatrix(A);
    cout << "Tempo de execução: " << execution_time << " segundos\n\n\n\n";

    cout << "Fim do Projeto\n";

    return 0;
}
