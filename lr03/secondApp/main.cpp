#include "program.h"

int main()
{
	system("chcp 65001>nul"); /*кодировка unicode*/

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