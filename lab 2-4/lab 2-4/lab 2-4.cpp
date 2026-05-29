#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <limits>

using namespace std;

// ======================= ЗАДАНИЕ 1 =======================
// Функция для вычисления значения y(x) согласно варианту 8
double calculateY(double x) {
    if (x > 3.5) {
        // y = 0.2 * sin(x) * lg(x)   (lg - десятичный логарифм)
        return 0.2 * sin(x) * log10(x);
    }
    else {
        // y = cos^2(x) / 0.2
        return pow(cos(x), 2) / 0.2;
    }
}

void zadanie1() {
    cout << "\n---------- ЗАДАНИЕ 1 ----------" << endl;
    cout << "Таблица значений функции (вариант 8)" << endl;
    cout << "Функция: y = 0.2*sin(x)*lg(x) при x>3.5, иначе y = cos^2(x)/0.2" << endl;
    cout << "Диапазон: x [2, 5], шаг h = 0.25" << endl;
    cout << "----------------------------------------" << endl;
            
    double x_start = 2.0;
    double x_end = 5.0;
    double step = 0.25;

    vector<double> values;

    cout << setw(10) << "x" << " | " << setw(20) << "y(x)" << endl;
    cout << "----------------------------------------" << endl;

    cout << fixed << setprecision(4);

    double current_x = x_start;
    while (current_x <= x_end + 1e-9) {
        double y_value = calculateY(current_x);
        values.push_back(y_value);

        cout << setw(10) << current_x << " | " << setw(20) << setprecision(8) << y_value << endl;
        cout << setprecision(4);

        current_x += step;
    }

    if (!values.empty()) {
        double sum = 0.0;
        for (double val : values) {
            sum += val;
        }
        double average = sum / values.size();

        cout << "========================================" << endl;
        cout << "Среднее значение функции на промежутке ["
            << x_start << ", " << x_end << "]:" << endl;
        cout << "y_среднее = " << fixed << setprecision(8) << average << endl;
    }

    cout << "========================================\n" << endl;
}

// ======================= ЗАДАНИЕ 2 =======================
void findShortestAndLongestWord(const string& sentence) {
    cout << "\n========== ЗАДАНИЕ 2 ==========" << endl;
    cout << "Исходное предложение: \"" << sentence << "\"" << endl;

    if (sentence.empty()) {
        cout << "Ошибка: Пустая строка!" << endl;
        return;
    }

    stringstream ss(sentence);
    string word;
    vector<string> words;


    while (ss >> word) {
        while (!word.empty() && ispunct(word.front())) {
            word.erase(word.begin());
        }
        while (!word.empty() && ispunct(word.back())) {
            word.pop_back();
        }

        if (!word.empty()) {
            words.push_back(word);
        }
    }

    if (words.empty()) {
        cout << "В предложении нет слов!" << endl;
        return;
    }

    // Поиск самого короткого и самого длинного слова
    auto shortestIt = words.begin();
    auto longestIt = words.begin();

    for (auto it = words.begin(); it != words.end(); ++it) {
        if (it->length() < shortestIt->length()) {
            shortestIt = it;
        }
        if (it->length() > longestIt->length()) {
            longestIt = it;
        }
    }

    cout << "\nРезультаты:" << endl;
    cout << "Самое короткое слово: \"" << *shortestIt << "\" (длина: " << shortestIt->length() << ")" << endl;
    cout << "Самое длинное слово: \"" << *longestIt << "\" (длина: " << longestIt->length() << ")" << endl;

    // Дополнительно выводим все слова для наглядности (опционально)
    cout << "\nВсе слова в предложении:" << endl;
    for (const auto& w : words) {
        cout << "  \"" << w << "\" - " << w.length() << " симв." << endl;
    }
    cout << "========================================\n" << endl;
}

// ======================= ЗАДАНИЕ 3 =======================
struct Point {
    double x, y;

    Point(double x = 0, double y = 0) : x(x), y(y) {}

    void input(const string& name) {
        cout << "Введите координаты точки " << name << " (x y): ";
        cin >> x >> y;
    }

    void output(const string& name) const {
        cout << name << "(" << x << ", " << y << ")";
    }
};

double triangleArea(const Point& a, const Point& b, const Point& c) {
    // Площадь = |(x1(y2 - y3) + x2(y3 - y1) + x3(y1 - y2))| / 2
    return fabs((a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y)) / 2.0);
}

bool isPointInsideTriangle(const Point& p, const Point& a, const Point& b, const Point& c) {
    double areaABC = triangleArea(a, b, c);
    double areaPAB = triangleArea(p, a, b);
    double areaPBC = triangleArea(p, b, c);
    double areaPCA = triangleArea(p, c, a);

    return fabs(areaABC - (areaPAB + areaPBC + areaPCA)) < 1e-9;
}

void zadanie3() {
    cout << "\n========== ЗАДАНИЕ 3 ==========" << endl;
    cout << "Нахождение площадей треугольников, образованных точкой внутри треугольника" << endl;
    cout << "========================================" << endl;

    Point A, B, C, P;

    cout << "Введите координаты вершин треугольника:" << endl;
    A.input("A");
    B.input("B");
    C.input("C");

    cout << "\nВведите координаты точки внутри треугольника:" << endl;
    P.input("P");

    cout << "\nВведённые данные:" << endl;
    A.output("A"); cout << ", ";
    B.output("B"); cout << ", ";
    C.output("C"); cout << endl;
    P.output("P"); cout << endl;

    double areaABC = triangleArea(A, B, C);
    cout << "\nПлощадь исходного треугольника ABC: " << fixed << setprecision(6) << areaABC << endl;

    if (!isPointInsideTriangle(P, A, B, C)) {
        cout << "\nВНИМАНИЕ: Точка P находится НЕ внутри треугольника!" << endl;
        cout << "Площади будут вычислены, но они не будут корректно разбивать треугольник." << endl;
    }
    else {
        cout << "Точка P находится внутри треугольника." << endl;
    }

    double areaPAB = triangleArea(P, A, B);
    double areaPBC = triangleArea(P, B, C);
    double areaPCA = triangleArea(P, C, A);
    double sumAreas = areaPAB + areaPBC + areaPCA;

    cout << "\n========== РЕЗУЛЬТАТЫ ==========" << endl;
    cout << "Площадь треугольника PAB: " << fixed << setprecision(6) << areaPAB << endl;
    cout << "Площадь треугольника PBC: " << setprecision(6) << areaPBC << endl;
    cout << "Площадь треугольника PCA: " << setprecision(6) << areaPCA << endl;
    cout << "----------------------------------------" << endl;
    cout << "Сумма площадей трёх треугольников: " << setprecision(6) << sumAreas << endl;
    cout << "Площадь исходного треугольника ABC: " << setprecision(6) << areaABC << endl;

    if (fabs(sumAreas - areaABC) < 1e-6) {
        cout << "\n✓ Проверка пройдена: сумма площадей равна площади исходного треугольника!" << endl;
    }
    else {
        cout << "\n✗ Внимание: сумма площадей отличается от площади исходного треугольника" << endl;
        cout << "  Разница: " << fabs(sumAreas - areaABC) << endl;
    }

    cout << "========================================\n" << endl;
}

// ======================= ГЛАВНОЕ МЕНЮ =======================
void showMenu() {
    cout << "\n╔════════════════════════════════════╗" << endl;
    cout << "║         ВЫБОР ЗАДАНИЯ              ║" << endl;
    cout << "╠════════════════════════════════════╣" << endl;
    cout << "║  1 - Задание 1 (Таблица функции)   ║" << endl;
    cout << "║  2 - Задание 2 (Поиск слов)        ║" << endl;
    cout << "║  3 - Задание 3 (Площади треугольников) ║" << endl;
    cout << "║  0 - Выход                         ║" << endl;
    cout << "╚════════════════════════════════════╝" << endl;
    cout << "Ваш выбор: ";
}

int main() {
    setlocale(LC_ALL, "Russian");

    int choice;

    do {
        showMenu();
        cin >> choice;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
        case 1:
            zadanie1();
            break;
        case 2: {
            // Задание 2 с тестовым предложением
            string sentence;
            cout << "\nВведите предложение (или нажмите Enter для тестового): ";
            getline(cin, sentence);

            if (sentence.empty()) {
                // Тестовое предложение
                sentence = "В заданном предложении найти самое короткое и самое длинное слово";
                cout << "Используется тестовое предложение." << endl;
            }

            findShortestAndLongestWord(sentence);
            break;
        }
        case 3:
            zadanie3();
            break;
        case 0:
            cout << "\nПрограмма завершена. До свидания!" << endl;
            break;
        default:
            cout << "\nОшибка: Неверный выбор! Пожалуйста, введите 1, 2, 3 или 0.\n" << endl;
            break;
        }

        if (choice != 0) {
            cout << "\nНажмите Enter для продолжения...";
            cin.get();
        }

    } while (choice != 0);

    return 0;
}