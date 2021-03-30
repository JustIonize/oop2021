#include<iostream>
#include<cmath>
#include<vector>
#include<iomanip>

using namespace std;

//����� ������ � ����������� �������������

//��� ������� ������ �������������� ������������ ���� �������� ��������� ����������
// (a + b) mod c = a mod c/2 + b mod c/2
// � 
// (a * b) mod c = a mod c/2 * b mod c/2,			���� a mod c/2 + b mod c/2 > c/2
// (a * b) mod c = a mod c/2 * b mod c/2 + c/2,		���� a mod c/2 + b mod c/2 > c/2

//������ �������� ������� � ���, ��� ��� ���������  � � b, ��� � � b < c
//������������ ����� ���� ������ � � ���������� ����� ����������� �� ���������� �������

unsigned long long int hm = 9223372036854775808;			//����������� �� ������ ����������� �� 2


unsigned long long int Combine(int n, int l) {				//���������� ������������� ����������� (���������� ���������)
	vector<unsigned long long int> c;

	for (int i = 0; i <= l + 1; i++) {
		c.push_back(0);
	}

	c[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = min(i, l); j > 0; j--)

			c[j] = c[j] % hm + c[j - 1] % hm;
	}
	return c[l];
}

int main() {
	int p, k;
	cin >> p >> k;
	if (k * (p - 1) + 1 > 4444) {
		cout << -1;
		return 0;
	}
	int K = 2 * k - 1;
	int n = k * (p - 1) + K;

	unsigned long long int integral = 0;
	long double Integral = 0;

	for (int i = 0; i < k; i++) {
		unsigned long long int multiply = 0;
		if ((Combine(n - (i * p), K) % hm + Combine(2 * k, i) % hm) < hm) {
			multiply = (Combine(n - (i * p), K) % hm) * (Combine(2 * k, i) % hm) % hm + hm;
		}
		else {
			multiply = (Combine(n - (i * p), K) % hm) * (Combine(2 * k, i) % hm) % hm;
		}
		integral = integral + (int)pow(-1, i) * (multiply % hm);
	}

	//��� ���������� ���� �������� �������, ������� ������������� � ����� �������.pdf

	//��� ���� ������� ����, ��� ���������� �������� ��������� ������ ����� ������� ��������,
	//������ ��� ������ ��������� ����� ������ � ������ ������
	
	//������� ������ �� ������ ������� ��������� ����������, ����
	// (a * b) mod c = a mod sqrt(c) * b mod sqrt(c) + n * sqrt(c)
	//��� sqrt(c) - ���������� ������ �� �
	//� ����� ������ a mod sqrt(c) � b mod sqrt(c) �� ����� ��������� sqrt(c)
	//� ��� ��������� �� ������������ �� ����� ��������� �, ��� ���� 
	//�� ����� ����������� ������������ ����������
	 
	//��� �������� ����� k (1/2 ����������� ����� ���������� ���������) 
	//����� �������� ��������� 2 �������, ����� ��������� ����� ����������
	//�� ����� 500 ��

	cout << integral;

	return 0;
}