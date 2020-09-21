#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

/*
7.Разработать электронную зачетку студента. 
Получать средний балл для каждого курса. 
Выяснить, на каком курсе студент был отличником и хорошистом
*/

class RecordBook
{
public:
	enum class lesson { inf, math, prog, disk, hist, os, fil, saod, oop, fhys, sprt, bd, count };

	friend std::istream& operator>>(std::istream& is, RecordBook::lesson& les);

private:
	class GradeSemestr
	{
	public:
		typedef std::vector<std::pair<RecordBook::lesson, int>> gradeMas_t;
	private:
		const size_t length;
		gradeMas_t masGrade;

		GradeSemestr(size_t countLesson)
			: length(countLesson) { this->masGrade.resize(this->length); };

	public:
		/*input*/
		friend std::istream& operator>>(std::istream& is, GradeSemestr& course)
		{
			std::pair<RecordBook::lesson, int> tmp;
			for (size_t i = 0; i < course.length; i++)
			{
				is >> tmp.first;
				is >> tmp.second;
				course.masGrade[i] = tmp;
			}
		}

		/*get*/
		size_t getCountGrade(int grade) /*количество оценок*/
		{
			size_t count{};
			for (size_t i = 0; i < this->length; i++)
			{
				if (this->masGrade[i].second == grade)
					count++;
			}
			return count;
		}
		float getAverageGrade() /*средний балл*/
		{
			float sum{};
			for (size_t i = 0; i < this->length; i++)
			{
				sum += this->masGrade[i].second;
			}
			return (sum / this->length);
		}
	};

	typedef std::vector<GradeSemestr*> semestrMas_t;

	std::string firstName;
	std::string lastName;
	std::string specialty;

	const size_t countCourse;
	semestrMas_t semestrMas;

	/*constr / destr*/
	RecordBook(size_t countCourse);
	~RecordBook();

	RecordBook(const RecordBook& rb);
	RecordBook(RecordBook&& rb);

	RecordBook& operator=(const RecordBook& rb);

	/*input*/
	friend std::istream& operator>>(std::istream& is, RecordBook& rb);
};