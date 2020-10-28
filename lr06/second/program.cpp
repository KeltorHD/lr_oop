#include "program.h"

void Program::run()
{
	std::list<Student> l1{};

	std::ifstream ifs("data.txt");
	if (!ifs.is_open())
	{
		throw "Не удается открыть файл!";
	}

	/*ввод в первый список из файла*/
	size_t length{};
	std::string tmp_s{};
	std::getline(ifs, tmp_s);
	length = std::stoi(tmp_s);
	for (size_t i = 0; i < length; i++) 
	{
		Student tmp{};
		ifs >> tmp;
		l1.push_back(tmp);
	}

	/*Просмотр первого списка*/
	std::cout << "Первый список: " << std::endl;
	for (auto& i : l1)
	{
		std::cout << i << std::endl;
	}

	/*Создание списка и заполнение данными того же типа, что и первый список*/
	std::list<Student> l2{};
	std::getline(ifs, tmp_s);
	length = std::stoi(tmp_s);
	for (size_t i = 0; i < length; i++)
	{
		Student tmp{};
		ifs >> tmp;
		l2.push_back(tmp);
	}

	/*Изменить первый контейнер, удалив из него n элементов после заданного 
	и добавив затем в него все элементы из второго контейнера*/
	int n{}; /*сколько нужно удалить*/
	int after{}; /*после какого элемента*/
	std::cout << "Сколько элементов нужно удалить в первом списке? ";
	std::cin >> n;
	std::cout << "После какого элемента удалять? ";
	std::cin >> after;
	while (n > l1.size() || n + after > l1.size() || n < 0 || after < 0)
	{
		std::cout << "Выход за границы" << std::endl;
		std::cout << "Сколько элементов нужно удалить в первом списке? ";
		std::cin >> n;
		std::cout << "После какого элемента удалять? ";
		std::cin >> after;
	}
	int counter = 0;
	l1.erase(
		std::remove_if( std::begin(l1), std::end(l1), [&counter, after, n](const auto& p) 
			{
				bool result = counter >= after && counter < after + n;
				counter++;
				return result;
			}
		), std::end(l1));

	for (auto& i : l2)
	{
		l1.push_back(i);
	}

	/*Просмотреть первый и второй контейнеры*/
	std::cout << "Первый список: " << std::endl;
	for (auto& i : l1)
	{
		std::cout << i << std::endl;
	}
	std::cout << "Второй список: " << std::endl;
	for (auto& i : l2)
	{
		std::cout << i << std::endl;
	}

	/*Отсортировать первый и второй контейнеры по возрастанию элементов.  
	Условие сортировки (по какому пункту производится сортировка) задает пользователь*/
	int choice{};
	std::cout << "По чему сортировать контейнеры? (1-фио,2-специальность,3-курс) ";
	std::cin >> choice;
	while (choice < 1 || choice > 3)
	{
		std::cout << "Неправильный выбор!" << std::endl;
		std::cout << "По чему сортировать контейнеры? (1-фио,2-специальность,3-курс) ";
		std::cin >> choice;
	}
	l1.sort([choice](const auto& s1, const auto& s2)
		{
			return less(s1, s2, choice);
		});
	l2.sort([choice](const auto& s1, const auto& s2)
		{
			return less(s1, s2, choice);
		});

	/*Просмотреть первый и второй контейнеры*/
	std::cout << "Первый список: " << std::endl;
	for (auto& i : l1)
	{
		std::cout << i << std::endl;
	}
	std::cout << "Второй список: " << std::endl;
	for (auto& i : l2)
	{
		std::cout << i << std::endl;
	}

	/*Получить третий контейнер путем слияния первых двух*/
	std::list<Student> l3{ l1 };
	for (auto& i : l2)
	{
		l3.push_back(i);
	}

	/*Просмотреть третий контейнер*/
	std::cout << "Третий список: " << std::endl;
	for (auto& i : l3)
	{
		std::cout << i << std::endl;
	}

	/*
	Подсчитать, сколько элементов, удовлетворяющих заданному условию, содержит третий контейнер (второкурсник) 
	*/
	size_t count{};
	for (auto& i : l3)
	{
		if (i.get_course() == 2)
			count++;
	}
	std::cout << "Второкурсников во втором списке: " << count << std::endl;
}
