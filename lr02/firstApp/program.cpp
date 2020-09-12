#include "program.h"

void Program::a()
{
	/*Задание а: список абитуриентов, имеющих самые высокие баллы по предмету*/
	int choice{ -1 };
	std::cout << "Задание а: список абитуриентов, имеющих самые высокие баллы по предмету. Высокий балл - >=80" << std::endl;
	for (size_t i = 0; i < size_t(Abiturient::lesson::count); i++)
	{
		std::cout << i << ". " << Abiturient::lesson(i) << std::endl;
	}
	std::cout << "Введите номер предмета: ";
	while (choice < 0 || choice > int(Abiturient::lesson::count))
	{
		std::cin >> choice;
		if (choice < 0 || choice > int(Abiturient::lesson::count))
		{
			std::cout << "Ошибка, нет такого предмета, введите еще раз: ";
		}
	}
	
	std::cout << "Список: " << std::endl;
	for (size_t i = 0; i < this->abitur.size(); i++)
	{
		if (this->abitur[i]->getScore(choice) >= 80)
			std::cout << this->abitur[i] << ", баллы: " << this->abitur[i]->getScore(choice) << std::endl;
	}
}

void Program::b()
{
	/*Задание б: список абитуриентов, сумма баллов у которых не меньше заданной*/
	int choice{ -1 };
	std::cout << "Задание б: список абитуриентов, сумма баллов у которых не меньше заданной." << std::endl;
	std::cout << "Введите сумму баллов: ";
	while (choice <= 0)
	{
		std::cin >> choice;
		if (choice <= 0)
		{
			std::cout << "Ошибка, введите еще раз: ";
		}
	}

	std::cout << "Список: " << std::endl;
	for (size_t i = 0; i < this->abitur.size(); i++)
	{
		if (this->abitur[i]->getSumScore() >= choice)
			std::cout << this->abitur[i] << ", сумма: " << this->abitur[i]->getSumScore() << std::endl;
	}
}

void Program::c()
{
	/*Задание в: выбрать N абитуриентов, имеющих самую высокую сумму баллов*/
	int choice{ -1 };
	std::cout << "Задание в: выбрать N абитуриентов, имеющих самую высокую сумму баллов." << std::endl;
	std::cout << "Введите количество абитуриентов: ";
	while (choice <= 0 || choice > this->abitur.size())
	{
		std::cin >> choice;
		if (choice <= 0 || choice > this->abitur.size())
		{
			std::cout << "Ошибка, неизвестное число студентов: ";
		}
	}

	std::vector<Abiturient*> tmp = this->abitur;
	std::sort(tmp.begin(), tmp.end(), 
		[](const Abiturient* ab1, const Abiturient* ab2)
		{
			return (ab1->getSumScore() > ab2->getSumScore()); 
		});

	std::cout << "Список: " << std::endl;
	for (int i = 0; i < choice; i++)
	{
		std::cout << tmp[i] << ", сумма: " << tmp[i]->getSumScore() << std::endl;
	}
}

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
		int score;

		for (int i = 0; i < countAbitur; i++)
		{
			Abiturient* tmp = new Abiturient();

			ifs >> name;
			ifs >> adress;
			tmp->setName(name);
			tmp->setAdress(adress);

			for (int j = 0; j < size_t(Abiturient::lesson::count); j++)
			{
				ifs >> score;
				tmp->addScores(j, score);
				//std::cout << score << " " << name << std::endl;
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
	std::cout << "Список студентов: " << std::endl;
	for (auto& i : this->abitur)
	{
		std::cout << i << std::endl;
	}
	std::cout << std::endl;

	/*Задание а: список абитуриентов, имеющих самые высокие баллы по предмету*/
	a();

	/*Задание б: список абитуриентов, сумма баллов у которых не меньше заданной*/
	b();

	/*Задание в: выбрать N абитуриентов, имеющих самую высокую сумму баллов*/
	c();
}
