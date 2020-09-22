#include "program.h"

void Program::a()
{
	
}

Program::Program()
{
	std::ifstream ifs;
	ifs.open("data.txt");
	if (ifs.is_open())
	{
		int countBook{ -1 };
		int countSemestr{ -1 };
		ifs >> countBook;
		ifs >> countSemestr;

		for (int i = 0; i < countBook; i++)
		{
			RecordBook* tmp = new RecordBook(countSemestr);

			ifs >> *tmp;

			this->rbMas.push_back(tmp);
		}
	}
	else
	{
		throw "COULD NOT LOAD DATA.EXE";
	}
}

Program::~Program()
{
	for (auto& i:this->rbMas)
	{
		delete i;
	}
}

void Program::run()
{
	std::cout << "Список студентов: " << std::endl;
	for (auto& i : this->rbMas)
	{
		std::cout << i->getInfo() << std::endl;
	}
	std::cout << std::endl;
}
