#include "m_use.h"

int main()
{
	system("chcp 65001>nul");

	std::ifstream ifs("data.txt");
	if (!ifs.is_open())
	{
		std::cout << "Не удалось открыть файл!" << std::endl;
		return 0;
	}

	first(ifs);
	std::cout << std::endl;
	second(ifs);

	return bool(std::cout);
}