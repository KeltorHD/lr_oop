#include "program.h"

int main()
{
	system("chcp 65001>nul");

	Program p;
	p.run();

	/*std::ifstream ifs("data.txt");
	std::string tmp;
	while (std::getline(ifs,tmp))
	{
		std::cout << tmp << std::endl;
	}*/


	return bool(std::cout);
}