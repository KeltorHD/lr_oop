#include <iostream>
#include <fstream>

#include "week.h"

int main()
{
	system("chcp 65001>nul");

	std::ifstream ifs("data.txt");

	if (ifs.is_open())
	{
		Week week;

		ifs >> week;

		for (size_t i = 0; i < size_t(Week::day_t::count); i++)
		{
			std::cout << "Уникальных пользователей в " << i << " дне: " << week.unique(Week::day_t(i)) << std::endl;
		}

		std::cout << "Человек, который заходил на сайт в воскресенье больше всего: " << week.max_count(Week::day_t::Su) << std::endl;
	}
	else
	{
		std::cout << "Не удается открыть файл!" << std::endl;
	}

	return bool(std::cout) && bool(ifs);
}