#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <vector>
#include <sstream>
#include <stdio.h>

using namespace std;

// Функция для переворачивания слова
string reverseWord(const string& word) {
    string reversed;
    for (int i = word.length() - 1; i >= 0; i--) {
        reversed += word[i];
    }
    return reversed;
}

// Упрощенная функция обработки строки
string processString(const string& input) {
    string longestWord = "";
    int maxLength = 0;
    string currentWord = "";
    int length = input.length();

    for (int i = 0; i < length; i++) {
        char c = input[i];

        // Добавляем только буквы и цифры
        if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
            currentWord += c;
        }
        else {
            // Проверяем накопленное слово (оно гарантировано состоит только из букв/цифр)
            if (currentWord.length() > maxLength) {
                maxLength = currentWord.length();
                longestWord = currentWord;
            }
            currentWord = "";
        }
    }

    // Проверяем последнее слово
    if (currentWord.length() > maxLength) {
        longestWord = currentWord;
    }

    return longestWord.length() > 0 ? reverseWord(longestWord) : "";
}

int main() {
    setlocale(LC_ALL, "Russian");
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    if (!inputFile.is_open()) {
        cout << "Ошибка открытия входного файла!" << endl;
        return 1;
    }

    if (!outputFile.is_open()) {
        cout << "Ошибка открытия выходного файла!" << endl;
        return 1;
    }

    string line;

    if (getline(inputFile, line)) {
        cout << "Исходная строка: " << line << endl;
        string result = processString(line);

        if (!result.empty()) {
            outputFile << result;
            cout << "Самое длинное слово (только цифры и буквы) в перевернутом виде: " << result << endl;
        }
        else {
            outputFile << "Подходящих слов не найдено";
            cout << "Подходящих слов не найдено" << endl;
        }
    }
    else {
        cout << "Файл пуст!" << endl;
        outputFile << "Файл пуст!";
    }

    inputFile.close();
    outputFile.close();
    return 0;
}