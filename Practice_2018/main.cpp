#include"Header.h"
int main() {
	//����������� ������� �����������
	setlocale(LC_ALL, "RUS");
	
	//���������� � ��������� ����������, ������� ����� ����������������� � ������
	long long int numb_to_transform = 0;
	
	//������ �� ���� � ���� ����������
	cout << "������� �����: " << endl;
	cin >> numb_to_transform;
	
	//������� �������
	system("cls");

	//�������� ������ ���������� ������
	if (numb_to_transform<INT_MIN || numb_to_transform>INT_MAX) {
		cout << "��������� ����� �� ������������� ��������� �������� 32-������� �����." << endl;
		return 0;
	}

	//����� �������, ������������� ����� � ������
	number_to_string(numb_to_transform);
	cout << endl << endl;
	return 0;
}