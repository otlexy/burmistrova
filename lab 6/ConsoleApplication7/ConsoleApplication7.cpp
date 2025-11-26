#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;


bool readMatrixFromFile(const string& filename, vector<vector<int>>& matrix, int size) {
    ifstream file(filename);
    matrix.resize(size, vector<int>(size));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (!(file >> matrix[i][j])) {
                cout << "Ошибка" << endl;
                return false;
            }
        }
    }
    file.close();
    return true;
}


bool isInTargetArea(int i, int j, int n) {
    if (i == j && i < n / 2) {
        return true;
    }
    if (i + j == n - 1 && i > n / 2) {
        return true;
    }
    return false;
}


void printMatrix(const vector<vector<int>>& matrix, int n) {
    cout << "\nМатрица " << n << "x" << n << ":" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (isInTargetArea(i, j, n)) {
                cout << "[" << matrix[i][j] << "]";
            }
            else {
                cout << matrix[i][j];
            }
            cout << "\t";
        }
        cout << endl;
    }
}


double calculateAverageAndWriteToFile(const vector<vector<int>>& matrix, int n) {
    double sum = 0;
    double count = 0;
    vector<int> processedNumbers;

    for (int i = 0; i < n / 2; i++) {
        int value = matrix[i][i];
        processedNumbers.push_back(value);
        if (value % 2 != 0) {
            sum += value;
            count++;
        }
    }

    for (int i = n / 2 + 1; i < n; i++) {
        int value = matrix[i][n - 1 - i];
        processedNumbers.push_back(value);
        if (value % 2 != 0) {
            sum += value;
            count++;
        }
    }

    string outputFilename = "R8.txt";
    ofstream outputFile(outputFilename);
    if (outputFile.is_open()) {
        outputFile << "Обрабатываемые числа из матрицы " << n << "x" << n << ":" << endl;
        outputFile << "Верхняя половина главной диагонали: ";
        for (int i = 0; i < n / 2; i++) {
            outputFile << matrix[i][i];
            if (i < n / 2 - 1) outputFile << ", ";
        }

        outputFile << "\nНижняя половина обратной диагонали: ";
        for (int i = n / 2 + 1; i < n; i++) {
            outputFile << matrix[i][n - 1 - i];
            if (i < n - 1) outputFile << ", ";
        }

        outputFile << "\n\nНечетные числа из обрабатываемой области: ";
        bool hasOddNumbers = false;
        for (int i = 0; i < processedNumbers.size(); i++) {
            int num = processedNumbers[i];
            if (num % 2 != 0) {
                cout << num << " ";
            }
        }

        if (!hasOddNumbers) {
            outputFile << "нечетные числа отсутствуют";
        }

        outputFile << "\n\nСреднее значение нечетных чисел: ";
        if (count > 0) {
            double average = sum / count;
            outputFile << average;
        }
        else {
            outputFile << "не вычислено (нет нечетных чисел)";
        }

        outputFile.close();
    }
    else {
        cout << "Ошибка: не удалось создать файл " << outputFilename << endl;
    }

    if (count == 0) {
        return 0.0;
    }

    return sum / count;
}


void displayAreaElements(const vector<vector<int>>& matrix, int n) {
    cout << "\nЭлементы в указанной области:" << endl;
    cout << "Верхняя половина главной диагонали: ";
    for (int i = 0; i < n / 2; i++) {
        cout << matrix[i][i];
        if (i < n / 2 - 1) cout << ", ";
    }

    cout << "\nНижняя половина обратной диагонали: ";
    for (int i = n / 2 + 1; i < n; i++) {
        cout << matrix[i][n - 1 - i];
        if (i < n - 1) cout << ", ";
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");

    const int FULL_SIZE = 13;
    vector<vector<int>> fullMatrix;
    string filename = "M8.txt";
    int n;
    cout << "Введите размер обрабатываемой части матрицы N: ";
    cout << "\n(нечетное число от 5 до 13, например: 5, 7, 9, 11, 13): ";
    cin >> n;

    if (!readMatrixFromFile(filename, fullMatrix, FULL_SIZE)) {
        cout << "Программа завершена из-за ошибки." << endl;
        return 1;
    }

    printMatrix(fullMatrix, n);

    displayAreaElements(fullMatrix, n);

    double average = calculateAverageAndWriteToFile(fullMatrix, n);

    if (average > 0) {
        cout << "Среднее значение нечетных чисел в указанной области: " << average << endl;
    }
    else {
        cout << "В указанной области нет нечетных чисел для обработки." << endl;
    }

    cin.ignore();
    cin.get();
}