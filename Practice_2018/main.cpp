#include"Header.h"
int main() {
	setlocale(LC_ALL, "RUS");
	//создание нескольких массивов, которые хранят в себе единицы, дестки, сотни , тысячи, миллионы, миллиарды
	static char *units[] = { "","one ","two ","three ","four ","five ","six ","seven ","eight ","nine " };
	static char *ten_to_nineteen[] = { "ten ", "eleven ", "twelve ", "thirteen ", "fourteen ", "fifteen ", "sixteen ","seventeen ","eighteen ","nineteen " };
	static char *tens[] = { "","","twenty ","thirty ","forty ","fifty ", "sixty ", "seventy ", "eighty ", "ninety " };
	static char *hundreds[] = { "","one hundred ","two hundreds ","three hundreds ","four hundreds ","five hundreds ","six hundreds ","seven hundreds ","eight hundreds ","nine hundreds " };
	static char *thouthands_miilions_bullions[] = { "", "thousand ","million ","billion " };

	//создание переменных-"буферов обмена".
	short buf0 = 0, buf1 = 0, buf2 = 0, i = 0, buf3 = 0;
	//создание массивов, в которые будут записываться промежуточный и конечный результат 
	char resu[100], resu1[100][100];
	//очистка элементов от мусора
	resu1[0][0] = NULL, resu1[1][0] = NULL, resu1[2][0] = NULL, resu1[3][0] = NULL;

	//объявление и обнуление переменной, которая будет преобразовываться в строку
	int numb_to_transform = 0;
	//запрос на ввод и ввод переменной
	cout << "Введите число: " << endl;
	cin >> numb_to_transform;

	//проверка границ введеннных данных
	if (numb_to_transform<INT_MIN || numb_to_transform>INT_MAX) {
		cout << "Введенное число не соответствует диапазону значений 32-битного числа." << endl;
		return 0;
	}
	//очистка консоли
	system("cls");
	//вывод трансформированного числа
	cout << "Трансформированное число:" << endl << endl;
	cout << numb_to_transform << " => ";

	//проверка числа на отрицательность
	if (numb_to_transform< 0) {
		cout << "minus ";
		numb_to_transform = numb_to_transform* (-1);
	}
	//проверка числа на нулевое значение
	if (numb_to_transform == 0) {
		cout << "zero";
	}


	for (i = 0; numb_to_transform > 0; i++) {
		buf3 = numb_to_transform;
		if (numb_to_transform % 100 < 10 || numb_to_transform % 100 > 19) {   //проверка числа на наличие значений от 10 до 19
			buf3 = numb_to_transform % 10;									// если нет, определяем каждую цифру в числе
			buf0 = buf3;
			numb_to_transform /= 10;
			buf3 = numb_to_transform % 10;
			buf1 = buf3;
			numb_to_transform /= 10;
			buf3 = numb_to_transform % 10;
			buf2 = buf3;
			numb_to_transform /= 10;
			strcpy_s(resu, hundreds[buf2]); //копирование в строку названия сотен  
			strcat_s(resu, tens[buf1]);    //добавляем десятки
			strcat_s(resu, units[buf0]);  //добавляем единицы
			strcpy_s(resu1[i], resu);    //сохраняем в массив
		}   
		else {// если да, определяем две цифры как один элемент массива. так же вычисляем и сотни
			buf3 = numb_to_transform % 100;
			buf0 = buf3 - 10;
			numb_to_transform /= 100;
			buf3 = numb_to_transform % 10;
			buf1 = buf3;
			numb_to_transform /= 10;
			strcpy_s(resu, hundreds[buf1]);				//копирование в строку названия сотен  
			strcat_s(resu, ten_to_nineteen[buf0]);	   //добавляем к строке результата
			strcpy_s(resu1[i], resu);				  //сохраняем
		}                
	}

	for (i; i >= 0; i--) {
		//вывод, если значение ненулевое		
		if (resu1[i][0] == NULL) {}
		else {
			cout << resu1[i] << thouthands_miilions_bullions[i];
		}
	}

	cout << endl << endl;
	return 0;
}