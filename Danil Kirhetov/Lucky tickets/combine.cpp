#include<iostream>
#include<cmath>
#include<vector>
#include<iomanip>

using namespace std;

//����� ������ � ����������� �������������

//��� ������� ������ �������������� �������� ��������� ����������
// (a + b) mod c = (a mod c + b mod c) mod c
// (a * b) mod c = (a mod c * b mod c) mod c
//������ �������� ������� � ���, ��� ��� ��������� � ��� ������������ � � b, ��� � � b < c
//������������ � ����� ����� ���� ������ � � ���������� ����� ����������� �� ���������� �������


long double mod = 18446744073709551616.0;					//����������� �� ������


long double Combine(int n, int l) {							//���������� ������������ ������������ (���������)
	vector<long double> C;

	for (int i = 0; i <= l+1; i++) {
		C.push_back(0);
	}

	C[0] = 1; 
	for (int i = 1; i <= n; i++) {
		for (int j = min(i, l); j > 0; j--)
			C[j] = fmodl(fmodl(C[j], mod) + fmodl(C[j - 1], mod), mod);
	}
	return C[l];
}

int main() {
	
	int p, k;
	cin >> p >> k;
	
	int K = 2 * k - 1;
	int n = k * (p - 1) + K;

	long double Integral = 0;

	for (int i = 0; i < k; i++) {
		Integral = fmodl(Integral + pow(-1, i) * fmodl(fmodl(Combine(n - (i * p), K), mod) * fmodl(Combine(2 * k, i), mod), mod), mod);
	}

	//��� ���������� ���� �������� �������, ������� ������������� � ����� �������.pdf

	//��� ���� ������� ����, � ������ �������� �������� �������� ������
	//��� �������� ����� k (1/2 ����������� ����� ���������� ���������) 
	//����� �������� ��������� 2 �������, ����� ��������� ����� ����������
    //�� ����� 500 ��

	cout << setprecision(45) << Integral << endl;

	return 0;
}