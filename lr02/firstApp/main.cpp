#include "program.h"

#include <iostream>

int main()
{
	system("chcp 65001"); /*кодировка unicode*/
	bool isErr{ false };
	try
	{
		Program program;

		program.run();
	}
	catch (const char* er)
	{
		std::cerr << er << std::endl;
		isErr = true;
	}

	return isErr;
}