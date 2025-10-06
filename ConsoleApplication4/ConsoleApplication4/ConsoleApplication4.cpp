#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int Ph, Mths, Ch, total, perestanovka, fact_Ph, fact_Mths, fact_Ch, fact_perest;
    Ph = 5;
    Mths = 4;
    Ch = 3;
    total = Ph + Mths + Ch;
    fact_perest = 1;
    int fact_k = 1;
    int fact_n = 1;
    int fact_nk = 1;
    perestanovka = 3;
    for (int i = 1; i <= total; i++) {
        if (i <= Ph) {
            fact_n *= i;
        }
        if (i<=total-Ph) {
            fact_nk *= i;
        }
        fact_k *= i;
    }
    fact_Ph = fact_k / (fact_n * fact_nk);
    cout << "Перестановки для физики " << fact_Ph << "\n";
    fact_k = 1;
    fact_n = 1;
    fact_nk = 1;
    total -= Ph;
    for (int i = 1; i <= total; i++) {
        if (i <= Mths) {
            fact_n *= i;
        }
        if (i <= total - Mths) {
            fact_nk *= i;
        }
        fact_k *= i;
    }
    fact_Mths = fact_k / (fact_n * fact_nk);
    cout << "Перестановки для математики " << fact_Mths << "\n";
    fact_k = 1;
    fact_n = 1;
    fact_nk = 1;
    total -= Mths;
    for (int i = 1; i <= total; i++) {
        if (i <= Ch) {
            fact_n *= i;
        }
        if (i <= total - Ch) {
            fact_nk *= i;
        }
        fact_k *= i;
    }
    fact_Ch = fact_k / (fact_n * fact_nk);
    cout << "Перестановки для химии " << fact_Ch << "\n";
    for (int i = 1; i <= perestanovka; i++) {
        fact_perest *= i;
    }
    int total_pos = fact_Ph * fact_Mths * fact_Ch * fact_perest;
    double total_pos_bits = log2(total_pos);
    double total_pos_8 = total_pos_bits / 8.0;
    cout << total_pos_bits << " информации в битах" << "\n";
    cout << total_pos_8 << " информации в байтах" << "\n";
}