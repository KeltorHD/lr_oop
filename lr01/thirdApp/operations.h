#include <iostream>

/*меню заполнения массива*/
void input(std::shared_ptr<int[]>& mas, int length);

/*заполнение руками*/
void inputHand(std::shared_ptr<int[]>& mas, int length);

/*заполнение рандомно*/
void inputRand(std::shared_ptr<int[]>& mas, int length);

/*вывод на экран*/
void outputScreen(const std::shared_ptr<int[]>& mas, int length);