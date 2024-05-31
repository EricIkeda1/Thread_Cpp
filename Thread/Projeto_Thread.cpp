#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

using namespace std;

// Funcao para gerar uma matriz com valores aleatorios entre -9 e 9
vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = rand() % 19 - 9; // Gera um número entre -9 e 9
        }
    }
    return matrix;
}

// Funcao para multiplicar duas matrizes (funcao para ser executada em cada thread)
void multiplyMatricesBlock(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& C,
                           int startRow, int endRow, int n) {
    for (int i = startRow; i < endRow; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Funcao para imprimir uma matriz
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (const auto& val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    srand(time(0)); // Inicializa o gerador de numeros aleatorios

    // Matrizes e tamanhos
    vector<int> sizes = {5, 100, 1000, 2000, 3000};

    // Loop sobre os tamanhos das matrizes
    for (size_t i = 0; i < sizes.size(); ++i) {
        int n = sizes[i];
        auto A = generateMatrix(n);
        auto B = generateMatrix(n);

        cout << "Inicio do Projeto Threads Matriz " << char('A' + i) << " " << n << " x " << n << "\n\n";

        auto start_time = chrono::high_resolution_clock::now();

        vector<vector<int>> C(n, vector<int>(n, 0));
        int num_threads = 12; // Numero de threads
        vector<thread> threads;
        int block_size = n / num_threads;
        for (int j = 0; j < num_threads; ++j) {
            int startRow = j * block_size;
            int endRow = (j == num_threads - 1) ? n : startRow + block_size;
            threads.emplace_back(multiplyMatricesBlock, ref(A), ref(B), ref(C), startRow, endRow, n);
        }
        for (auto& t : threads) {
            t.join();
        }

        auto end_time = chrono::high_resolution_clock::now();
        double execution_time = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count() / 1000.0;

        cout << "Matriz resultante:\n";
        if (n <= 10) {  
            printMatrix(C);
        } else {
        }
        cout << "Tempo de execucao: " << execution_time << " segundos\n\n";
    }

    cout << "Fim do Projeto\n";

    return 0;
}
