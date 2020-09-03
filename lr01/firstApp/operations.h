#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>

/*меню заполнения массива*/
void input(int* mas, int length);

/*заполнение руками*/
void inputHand(int* mas, int length);

/*заполнение рандомно*/
void inputRand(int* mas, int length);

/*заполнение из файла*/
void inputFile(int* mas, int length, std::string& str);

/*задание 15. Удалить самую длинную последовательность подряд идущих положительных элементов*/
void individual(int*& mas, int& length);

/*меню вывода массива*/
void output(int* mas, int length);

/*вывод на экран*/
void outputScreen(int* mas, int length);

/*вывод в файл*/
void outputFile(int* mas, int length, std::string& str);

#endif // !OPERATIONS_H