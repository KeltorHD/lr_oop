#include "program.h"

Program::Program()
{
	std::ifstream ifs;
	ifs.open("data.dt");
	if (ifs.is_open())
	{
		int countAbitur{ -1 };
		ifs >> countAbitur;
		this->abitur.resize(countAbitur);

		std::string name;
		std::string adress;
		int countLesson;
		std::string lesson;
		int score;

		for (int i = 0; i < countAbitur; i++)
		{
			Abiturient* tmp = new Abiturient();

			ifs >> name;
			ifs >> adress;
			tmp->setName(name);
			tmp->setAdress(adress);

			ifs >> countLesson;
			for (int j = 0; j < countLesson; j++)
			{
				ifs >> lesson;
				ifs >> score;
				tmp->addScores({ lesson, score });
			}

			this->abitur[i] = tmp;
		}
	}
	else
	{
		throw "COULD NOT LOAD DATA.DT";
	}
}

Program::~Program()
{
	for (size_t i = 0; i < this->abitur.size(); i++)
	{
		delete this->abitur[i];
	}
}

void Program::run()
{
	/*Задание а: список абитуриентов, имеющих самые высокие баллы по предмету*/

}
