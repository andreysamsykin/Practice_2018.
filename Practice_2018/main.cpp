#include"Header.h"
int main() {
	//подключение русской локализации
	setlocale(LC_ALL, "RUS");
	
	//объ€вление и обнуление переменной, котора€ будет преобразовыватьс€ в строку
	long long int numb_to_transform = 0;
	
	//запрос на ввод и ввод переменной
	cout << "¬ведите число: " << endl;
	cin >> numb_to_transform;
	
	//очистка консоли
	system("cls");

	//проверка границ введеннных данных
	if (numb_to_transform<INT_MIN || numb_to_transform>INT_MAX) {
		cout << "¬веденное число не соответствует диапазону значений 32-битного числа." << endl;
		return 0;
	}

	//вызов функции, преобразующей число в строку
	number_to_string(numb_to_transform);
	cout << endl << endl;
	return 0;
}