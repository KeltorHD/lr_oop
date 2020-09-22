#include "program.h"

void Program::a()
{
	
}

void Program::five(RecordBook* rb)
{
	bool isFive{ false };
	std::vector<int> courses;
	for (size_t i = 0; i < rb->getCountCourse(); i++)
	{
		if (rb->getAverageCourse(i) == 5.f)
		{
			isFive = true;
			courses.push_back(i);
		}
	}

	if (isFive)
	{
		std::cout << "Отличник на курсе(ах): ";
		for (size_t i = 0; i < courses.size() - 1; i++)
		{
			std::cout << courses[i] + 1 << ", ";
		}
		std::cout << courses[courses.size() - 1] + 1 << std::endl;
	}
	else
	{
		std::cout << "В отличниках замечен не был" << std::endl;
	}
}

void Program::four_five(RecordBook* rb)
{
	bool isFour_five{ false };
	std::vector<int> courses;
	for (size_t i = 0; i < rb->getCountCourse(); i++)
	{
		if (rb->getAverageCourse(i) != 5.f && !rb->getCountGrade(i, 3))
		{
			isFour_five = true;
			courses.push_back(i);
		}
	}

	if (isFour_five)
	{
		std::cout << "Хорошист на курсе(ах): ";
		for (size_t i = 0; i < courses.size() - 1; i++)
		{
			std::cout << courses[i] + 1 << ", ";
		}
		std::cout << courses[courses.size() - 1] + 1 << std::endl;
	}
	else
	{
		std::cout << "В хорошистах замечен не был" << std::endl;
	}
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
		/*Средняя оценка по курсам: */
		for (size_t j = 0; j < i->getCountCourse(); j++)
		{
			std::cout << "Курс: " << j + 1 << ", средняя оценка: " << i->getAverageCourse(j) << std::endl;
		}
		/*Какие курсы на 5:*/
		five(i);
		/*Какие курсы на 4-5:*/
		four_five(i);
	}
	std::cout << std::endl;
}
