#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

// Функция для подсчета количества ребер
int countEdges(const vector<vector<int>>& adj, int n) {
    int edges = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) { // считаем каждое ребро один раз
            if (adj[i][j] == 1) edges++;
        }
    }
    return edges;
}

// Функция для определения степени графа (максимальная степень вершины)
int graphDegree(const vector<vector<int>>& adj, int n) {
    int maxDegree = 0;
    for (int i = 0; i < n; i++) {
        int degree = 0;
        for (int j = 0; j < n; j++) {
            if (adj[i][j] == 1) degree++;
        }
        if (degree > maxDegree) maxDegree = degree;
    }
    return maxDegree;
}

// Функция для преобразования матрицы смежности в матрицу инцидентности
vector<vector<int>> toIncidenceMatrix(const vector<vector<int>>& adj, int n, int edges) {
    vector<vector<int>> inc(n, vector<int>(edges, 0)); //создание двумерного вектора (матрицы)
    int edgeIndex = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (adj[i][j] == 1) {
                if (i == j) {
                    // петля
                    inc[i][edgeIndex] = 2;
                }
                else {
                    // обычное ребро
                    inc[i][edgeIndex] = 1;
                    inc[j][edgeIndex] = 1;
                }
                edgeIndex++;
            }
        }
    }
    return inc;
}

// Функция для вывода матрицы смежности с выделением связей с заданной вершиной
void printAdjacencyMatrix(const vector<vector<int>>& adj, int n, int vx) {
    cout << "\n=== МАТРИЦА СМЕЖНОСТИ (связи с V" << vx + 1 << " выделены скобками) ===" << endl;
    cout << "    ";
    for (int j = 0; j < n; j++) {
        cout << "V" << j + 1 << " ";
    }
    cout << endl;
    cout << "    ";
    for (int j = 0; j < n; j++) {
        cout << "---";
    }
    cout << endl;

    for (int i = 0; i < n; i++) {
        cout << "V" << i + 1 << " | ";
        for (int j = 0; j < n; j++) {
            // Выделяем скобками связи с вершиной Vx
            if ((i == vx || j == vx) && adj[i][j] == 1) {
                cout << "[" << adj[i][j] << "] ";
            }
            else {
                cout << " " << adj[i][j] << "  ";
            }
        }
        cout << endl;
    }
}

// Функция для вывода матрицы инцидентности
void printIncidenceMatrix(const vector<vector<int>>& inc, int n, int edges) {
    cout << "\n=== МАТРИЦА ИНЦИДЕНТНОСТИ ===" << endl;
    cout << "    ";
    for (int e = 0; e < edges; e++) {
        cout << char('a' + e) << "  ";
    }
    cout << endl;
    cout << "    ";
    for (int e = 0; e < edges; e++) {
        cout << "---";
    }
    cout << endl;

    for (int i = 0; i < n; i++) {
        cout << "V" << i + 1 << " | ";
        for (int e = 0; e < edges; e++) {
            cout << " " << inc[i][e] << "  ";
        }
        cout << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    // ========== 1. Чтение данных из файла ==========
    ifstream file("graph.txt");
    if (!file) {
        cout << "ОШИБКА: Файл graph.txt не найден!" << endl;
        cout << "Создайте файл graph.txt с матрицей смежности." << endl;
        system("pause");
        return 1;
    }

    int n; // количество вершин
    file >> n;

    // Создаем и заполняем матрицу смежности
    vector<vector<int>> adj(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            file >> adj[i][j];
        }
    }
    file.close();

    // ========== 2. Вывод исходной матрицы ==========
    cout << "\n========================================" << endl;
    cout << "      ЛАБОРАТОРНАЯ РАБОТА" << endl;
    cout << "   Матричное представление графа" << endl;
    cout << "========================================" << endl;

    // ========== 3. Подсчет количества ребер и степени графа ==========
    int edges = countEdges(adj, n);
    int degree = graphDegree(adj, n);

    cout << "\n--- ОСНОВНЫЕ ХАРАКТЕРИСТИКИ ГРАФА ---" << endl;
    cout << " Количество вершин: " << n << endl;
    cout << " Количество ребер: " << edges << endl;
    cout << " Степень графа: " << degree << endl;

    // ========== 4. Преобразование в матрицу инцидентности ==========
    vector<vector<int>> inc = toIncidenceMatrix(adj, n, edges);
    printIncidenceMatrix(inc, n, edges);

    // ========== 5. Поиск смежных вершин ==========
    int vx;
    cout << "\n--- ПОИСК СМЕЖНЫХ ВЕРШИН ---" << endl;
    cout << "Введите номер вершины Vx (1-" << n << "): ";
    cin >> vx;
    vx--; // перевод в индекс массива

    if (vx >= 0 && vx < n) {
        // Поиск смежных вершин
        cout << "\nВершины, смежные с V" << vx + 1 << ": ";
        bool found = false;

        for (int j = 0; j < n; j++) {
            if (adj[vx][j] == 1) {
                cout << "V" << j + 1 << " ";
                found = true;
            }
        }

        if (!found) {
            cout << "нет смежных вершин";
        }
        cout << endl;

        // Вывод матрицы смежности с выделением
        printAdjacencyMatrix(adj, n, vx);

        // Вывод результата
        cout << "\n=== РЕЗУЛЬТАТ РЕШЕНИЯ ===" << endl;
        cout << " Задача: Напечатать все вершины, смежные вершине V" << vx + 1 << endl;
        cout << " Результат: ";
        if (found) {
            cout << "Найдены смежные вершины: ";
            for (int j = 0; j < n; j++) {
                if (adj[vx][j] == 1) {
                    cout << "V" << j + 1 << " ";
                }
            }
        }
        else {
            cout << "У вершины V" << vx + 1 << " нет смежных вершин";
        }
        cout << endl;

    }
    else {
        cout << "\nОШИБКА: Неверный номер вершины! (должен быть от 1 до " << n << ")" << endl;
    }

    cout << "\n========================================" << endl;
    system("pause");
    return 0;
}