#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Funcao para gerar uma matriz com valores aleatorios entre -9 e 9
vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = rand() % 19 - 9; // Gera um n�mero entre -9 e 9
        }
    }
    return matrix;
}

// Funcao para multiplicar duas matrizes
vector<vector<int>> multiplyMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B, int n) {
    vector<vector<int>> C(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
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

    cout << "\n\n\nInicio do Projeto Threads Matriz A 5 x 5\n\n";

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
    cout << "Tempo de execucao: " << execution_time << " segundos\n\n\n\n";

    cout << "Inicio do Projeto Threads Matriz B 100 x 100\n\n";

    // Matriz 100x100
    n = 100;
    auto W = generateMatrix(n);
    auto X = generateMatrix(n);
    start_time = clock();
    auto B = multiplyMatrices(W, X, n);
    end_time = clock();
    execution_time = double(end_time - start_time) / CLOCKS_PER_SEC;

    cout << "Tempo de execucao: " << execution_time << " segundos\n\n\n\n";

    cout << "Inicio do Projeto Threads Matriz C 1000 x 1000\n\n";

    // Matriz 1000x1000
    n = 1000;
    auto U = generateMatrix(n);
    auto V = generateMatrix(n);
    start_time = clock();
    auto C = multiplyMatrices(U, V, n);
    end_time = clock();
    execution_time = double(end_time - start_time) / CLOCKS_PER_SEC;

    cout << "Tempo de execucao: " << execution_time << " segundos\n\n\n\n";

    cout << "Inicio do Projeto Threads Matriz D 2000 x 2000\n\n";

    // Matriz 2000x2000
    n = 2000;
    auto S = generateMatrix(n);
    auto T = generateMatrix(n);
    start_time = clock();
    auto D = multiplyMatrices(S, T, n);
    end_time = clock();
    execution_time = double(end_time - start_time) / CLOCKS_PER_SEC;

    cout << "Tempo de execucao: " << execution_time << " segundos\n\n\n\n";

    cout << "Inicio do Projeto Threads Matriz E 3000 x 3000\n\n";

    // Matriz 3000x3000
    n = 3000;
    auto Q = generateMatrix(n);
    auto R = generateMatrix(n);
    start_time = clock();
    auto E = multiplyMatrices(Q, R, n);
    end_time = clock();
    execution_time = double(end_time - start_time) / CLOCKS_PER_SEC;

    cout << "Tempo de execucao: " << execution_time << " segundos\n\n\n\n";
    cout << "Fim do Projeto\n";

    return 0;
}
