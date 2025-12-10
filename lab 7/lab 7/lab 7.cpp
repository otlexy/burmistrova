#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    // Читаем матрицу из файла
    ifstream file("graph.txt");
    if (!file) {
        cout << "Файл graph.txt не найден!" << endl;
        return 1;
    }

    int versh; // количество вершин
    file >> versh;

    // Создаем и читаем матрицу смежности
    vector<vector<int>> adj(versh, vector<int>(versh));
    for (int i = 0; i < versh; i++) {
        for (int j = 0; j < versh; j++) {
            file >> adj[i][j];
        }
    }
    file.close();

    // Выводим матрицу смежности
    cout << "=== МАТРИЦА СМЕЖНОСТИ ===" << endl;
    for (int i = 0; i < versh; i++) {
        cout << "В" << i + 1 << ": ";
        for (int j = 0; j < versh; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    // 1. Подсчет количества ребер
    int rebra = 0;
    for (int i = 0; i < versh; i++) {
        for (int j = i; j < versh; j++) { // начинаем с i чтобы не считать дважды
            if (adj[i][j] == 1) rebra++;
        }
    }
    cout << "Количество ребер: " << rebra << endl;

    // 2. Степень графа (максимальная степень вершины)
    int max_degree = 0;
    for (int i = 0; i < versh; i++) {
        int degree = 0;
        for (int j = 0; j < versh; j++) {
            if (adj[i][j] == 1) degree++;
        }
        if (degree > max_degree) max_degree = degree;
    }
    cout << "Степень графа: " << max_degree << endl << endl;

    // 3. Преобразование в матрицу инцидентности
    cout << "=== МАТРИЦА ИНЦИДЕНТНОСТИ ===" << endl;

    // Создаем матрицу инцидентности
    vector<vector<int>> inc(versh, vector<int>(rebra, 0));

    int rebra_num = 0;
    // Заполняем матрицу инцидентности
    for (int i = 0; i < versh; i++) {
        for (int j = i; j < versh; j++) {
            if (adj[i][j] == 1) {
                if (i == j) { // петля
                    inc[i][rebra_num] = 2;
                }
                else { // обычное ребро
                    inc[i][rebra_num] = 1;
                    inc[j][rebra_num] = 1;
                }
                rebra_num++;
            }
        }
    }

    // Выводим заголовок с буквами ребер
    cout << "   ";
    for (int e = 0; e < rebra; e++) {
        cout << char('a' + e) << " ";
    }
    cout << endl;

    // Выводим саму матрицу
    for (int i = 0; i < versh; i++) {
        cout << "В" << i + 1 << ": ";
        for (int e = 0; e < rebra; e++) {
            cout << inc[i][e] << " ";
        }
        cout << endl;
    }
    cout << endl;

    // 4. Поиск смежных вершин
    int vx;
    cout << "Введите номер вершины Vx (1-" << versh << "): ";
    cin >> vx;
    vx--; // переводим в индекс массива (с 0)

    if (vx >= 0 && vx < versh) {
        cout << "Вершины, смежные с V" << vx + 1 << ": ";
        bool found = false;

        for (int j = 0; j < versh; j++) {
            if (adj[vx][j] == 1) {
                cout << "V" << j + 1 << " ";
                found = true;
            }
        }

        if (!found) cout << "нет смежных вершин";
        cout << endl;

        // Выделяем связи с вершиной Vx в матрице смежности
        cout << endl << "Матрица смежности (связи с V" << vx + 1 << " выделены):" << endl;
        for (int i = 0; i < versh; i++) {
            cout << "В" << i + 1 << ": ";
            for (int j = 0; j < versh; j++) {
                if ((i == vx && adj[i][j] == 1) || (j == vx && adj[i][j] == 1)) {
                    cout << "[" << adj[i][j] << "] ";
                }
                else {
                    cout << " " << adj[i][j] << "  ";
                }
            }
            cout << endl;
        }
    }
    else {
        cout << "Неверный номер вершины!" << endl;
    }

    return 0;
}