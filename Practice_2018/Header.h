/*����������� ���������, ����������� ����� ����� � ����� �� ���������� �����.
���������� ����������� ��������� ������������� � ������������� ����� � ��������� 32-������� ��������� �����. �������:
10 -> ten
121 -> one hundred twenty one
1032 -> one thousand thirty two
11043 -> eleven thousand forty three
1200000 -> one million two hundred thousand*/
#pragma once
#include<iostream>
#include<cstring>
#include<climits>

using std::cout;
using std::cin;
using std::endl;

int number_to_string(long long int number_to_transform);
