#include <conio.h>
#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "russian");
	int A, B, C, binary_a, binary_b, binary_c, k, a, b, c, AB;
	char sum, carry;
	A = 139;
	B = 174;
	C = 173;
	binary_a = 0;
	binary_b = 0;
	binary_c = 0;
	a = 0;
	b = 0;
	c = 0;
	k = 0;
	AB = 0;
	while (A > 0) {
		a = A % 2;
		binary_a += a * pow(10, k);
		A /= 2;
		k++;
	}


	k = 0;
	while (B > 0) {
		b = B % 2;
		binary_b += b * pow(10, k);
		B /= 2;
		k++;
	}


	int dec_C = C;
	k = 0;
	while (C > 0) {
		c = C % 2;
		binary_c += c * pow(10, k);
		C /= 2;
		k++;
	}
	cout << "А двоичной системе счисления = " << binary_a << "\n" << "В двоичной системе счисления = " << binary_b << "\n" << "C двоичной системе счисления = " << binary_c << "\n";
	
	
	int i = 1;
	sum = 0;
	carry = 0;
	int a1 = binary_a;
	int b1 = binary_b;
	while (a1 > 0 || b1 > 0 || carry > 0) {
		sum = a1 % 10 + b1 % 10 + carry;
		int current_bit = sum % 2;
		carry = sum / 2;
		AB += current_bit*i;
		i *= 10;
		a1 /= 10;
		b1 /= 10;
	}
	int sum_AB = AB;
	cout << "Сумма А и В в двоичной системе счисления = " << AB << "\n";


	carry = 0;
	int position = 1;
	int binary_Y = 0;
	while (AB > 0 || binary_c > 0) {
		int last_AB = AB % 10;
		int last_C = binary_c % 10;
		int vichet = last_AB - last_C - carry;
		if (vichet < 0) {
			vichet += 2;
			carry = 1;
		}
		else {
			carry = 0;
		}
		binary_Y += vichet * position;
		position *= 10;
		AB /= 10;
		binary_c /= 10;
	}
	cout << "Y в двоичной системе счисления = " << binary_Y << "\n";


	int exponent = 1;
	int dec_Y = 0;
	while (binary_Y > 0) {
		int last_digit = binary_Y % 10;
		dec_Y += last_digit * exponent;
		exponent *= 2;
		binary_Y /= 10;
	}
	cout << "Y в десятичной системе счисления = " << dec_Y << "\n";


	exponent = 1;
	int dec_AB = 0;
	int bin_AB = sum_AB;
	while (bin_AB > 0) {
		int last_digit = bin_AB % 10;
		dec_AB += last_digit * exponent;
		exponent *= 2;
		bin_AB /= 10;
	}
	//cout << dec_AB;


	string AB16 = "";
	string digits16 = "0123456789ABCDEF";
	int temp16 = dec_AB;
	while (temp16 > 0) {
		AB16 = digits16[temp16 % 16] + AB16;
		temp16 /= 16;
	}
	cout << "Сумма А и В в шестнадцатиричной системе счисления = " << AB16 << "\n";

	string AB8 = "";
	string digits8 = "01234567";
	int temp8 = dec_AB;
	while (temp8 > 0) {
		AB8 = digits8[temp8 % 8] + AB8;
		temp8 /= 8;
	}
	cout << "Сумма А и В в восьмеричной системе счисления = " << AB8 << "\n";

}