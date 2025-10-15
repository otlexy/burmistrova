#include <iostream>
#include <cmath>
#include <stdio.h>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    const int n = 12;
    int Array[n] {12,59,43,-83,6,1134,12299,5555,64,102,1084,13};
    int max = 0;
    int index = -1;
    int k = 0;
    int sum = 0;


    for (int i = 0; i < size(Array); i++) {
        int l = abs(Array[i]);
        bool have3 = false;
        while (l > 0) {
            if (l % 10 == 3) {
                have3 = true;
                break;
            }
            l /= 10;
        }
        if (have3 == true) {
            if (index == -1 || Array[i] > max) {
                max = Array[i];
                index = i;
            }
        }
        if (Array[i] % 2 == 1) {
            sum += Array[i];
        }
    }


    if (index != -1) {
        cout << "Наибольший элемент с цифрой 3: " << max << ", позиция: " << index + 1 << endl;
    }
    else {
        cout << "Элементов с цифрой 3 не найдено" << endl;
    }



    cout << sum << "\n";
    bool even = false;
    for (int i = 0; sum > 0; i++) {
        if (sum % 10 == 2) {
            even = true;
        }
        else {
            even = false;
            break;
        }
        sum /= 10;
    }
    if (even == true) {
        cout << "Число состоит только из четных цифр" << "\n";
    }
    else {
        cout << "Число состоит не только из четных цифр" << "\n";
    }
    


    string sum_obrat;
    string temp;
    temp = to_string(sum);
    sum_obrat = temp;
    sum_obrat[0] = temp[temp.size() - 1];
    sum_obrat[sum_obrat.size() - 1] = temp[0];
    cout << sum_obrat;
}