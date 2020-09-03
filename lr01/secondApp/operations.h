#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <vector>

/*меню заполнения массива*/
void input(std::vector<int>& mas);

/*заполнение руками*/
void inputHand(std::vector<int>& mas);

/*заполнение рандомно*/
void inputRand(std::vector<int>& mas);

/*заполнение из файла*/
void inputFile(std::vector<int>& mas, std::string& str);

/*задание 15. Удалить самую длинную последовательность подряд идущих положительных элементов*/
void individual(std::vector<int>& mas);

/*меню вывода массива*/
void output(std::vector<int>& mas);

/*вывод на экран*/
void outputScreen(std::vector<int>& mas);

/*вывод в файл*/
void outputFile(std::vector<int>& mas, std::string& str);

#endif // !OPERATIONS_H