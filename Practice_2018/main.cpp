#include"Header.h"
int main(){
	setlocale(LC_ALL, "RUS");
	static char *units[] = { "","one ","two ","three ","four ","five ","six ","seven ","eight ","nine " };
	static char *ten_to_nineteen[] = { "ten ", "eleven ", "twelve ", "thirteen ", "fourteen ", "fifteen ", "sixteen ","seventeen ","eighteen ","nineteen " };
	static char *tens[] = { "","","twenty ","thirty ","forty ","fifty ", "sixty ", "seventy ", "eighty ", "ninety " };
	static char *hundreds[] = { "","one hundred ","two hundreds ","three hundreds ","four hundreds ","five hundreds ","six hundreds ","seven hundreds ","eight hundreds ","nine hundreds " };
	static char *thouthands_miilions_bullions[] = {"", "thousand ","million ","billion " };
	short buf0 = 0, buf1 = 0, buf2 = 0, i = 0, buf3 = 0;
	char resu[100], resu1[100][100];
	resu1[0][0] = NULL, resu1[1][0] = NULL, resu1[2][0] = NULL, resu1[3][0] = NULL;
	int numb_to_transform = 0;
	cout << "¬ведите число: " << endl;
		cin >> numb_to_transform;
		if (numb_to_transform<INT_MIN || numb_to_transform>INT_MAX) {
			cout << "¬веденное число не соответствует диапазону значений 32-битного числа." << endl;
			return 0;
		}
		system("cls");
		cout << "“рансформированное число:" << endl << endl;
		cout << numb_to_transform << " => ";
		if (numb_to_transform< 0){
			cout << "minus ";
			numb_to_transform = numb_to_transform* (-1);
		}
		if (numb_to_transform == 0){
			cout << "zero";
		}
		for (i = 0; numb_to_transform > 0; i++){
			buf3 = numb_to_transform;
			if (numb_to_transform % 100 < 10 || numb_to_transform % 100 > 19){
				buf3 = numb_to_transform % 10;									
				buf0 = buf3;
				numb_to_transform /= 10;
				buf3 = numb_to_transform % 10;
				buf1 = buf3; 
				numb_to_transform /= 10;
				buf3 = numb_to_transform % 10;
				buf2 = buf3;
				numb_to_transform /= 10;
				strcpy_s(resu, hundreds[buf2]); 
				strcat_s(resu, tens[buf1]);    
				strcat_s(resu, units[buf0]);  
				strcpy_s(resu1[i], resu);}   
					else{
						buf3 = numb_to_transform % 100;
						buf0 = buf3 - 10;
						numb_to_transform /= 100;
						buf3 = numb_to_transform % 10;
						buf1 = buf3;
						numb_to_transform /= 10;
						strcpy_s(resu, hundreds[buf1]);				
						strcat_s(resu, ten_to_nineteen[buf0]);	   
						strcpy_s(resu1[i], resu);}                
		}
		for (i; i >= 0; i--){	
			if (resu1[i][0] == NULL){}
				else{
					cout<< resu1[i]<< thouthands_miilions_bullions[i];
				}
		}
		
		cout << endl << endl;
		return 0;
}