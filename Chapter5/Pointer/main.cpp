#include <iostream>
#include <random>
using namespace std;

int** alloc2DInt(int rows, int cols) {
    if (rows <= 0 || cols <= 0) return nullptr;

    int** mat = new int*[rows];
    for (int i = 0; i < rows; i++)
        mat[i] = new int[cols];
    return mat;
}

void free2DInt(int **mat, int rows, int cols=0) {
    if (mat != nullptr) {
        for (int i = 0; i < rows; i++)
            delete[] mat[i];
        delete[] mat;
    }
}

void set2DRandom(int **mat, int rows, int cols) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            mat[i][j] = rand()%100;
}

void cout2DInt(int **mat, int rows, int cols) {
    cout << "행의 수: " << rows << " 열의 수: " << cols << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}

int main() {
    // dynamic allocation of memory
    char *str;
    str = new char[1000];
    if (str == nullptr) {
        cout << "Insufficient memory available" << endl;
    }
    else {
        cout << "Allocated 1000 bytes" << endl;
        delete[] str;
        cout << "Memory freed" << endl;
    }

    // for 2D array
    int **mat;
    int rows, cols;
    cout << "행의 크기를 입력하시오: "; cin >> rows;
    cout << "열의 크기를 입력하시오: "; cin >> cols;

    mat = alloc2DInt(rows, cols);
    set2DRandom(mat, rows, cols);
    cout2DInt(mat, rows, cols);
    free2DInt(mat, rows, cols);
    return 0;

}
