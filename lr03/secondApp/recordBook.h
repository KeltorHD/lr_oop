#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

/*
7.Разработать электронную зачетку студента. 
Получать средний балл для каждого курса. 
Выяснить, на каком курсе студент был отличником и хорошистом
*/

class RecordBook
{
public:
	enum class lesson { inf, math, prog, disk, hist, os, fil, saod, oop, fhys, sprt, bd, count };

	friend std::ostream& operator<<(std::ostream& os, RecordBook::lesson& les);
	friend std::istream& operator>>(std::istream& is, RecordBook::lesson& les);

private:
	class GradeSemestr
	{
	private:
		typedef std::vector<std::pair<RecordBook::lesson, int>> gradeMas_t;
		const size_t length;
		gradeMas_t masGrade;

	public:
		GradeSemestr(size_t countLesson)
			: length(countLesson) { this->masGrade.resize(this->length); };

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
			return is;
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
			return (this->getSumGrade() / static_cast<float>(this->length));
		}
		size_t getSumGrade()
		{
			float sum{};
			for (size_t i = 0; i < this->length; i++)
			{
				sum += this->masGrade[i].second;
			}
			return sum;
		}
		size_t getCountLessons() { return this->length; }

		/*print*/
		void printGrade()
		{
			for (size_t i = 0; i < this->length; i++)
			{
				std::cout << this->masGrade[i].first << ": " << this->masGrade[i].second << std::endl;
			}
		}
	};

	typedef std::vector<GradeSemestr*> semestrMas_t;

	std::string firstName;
	std::string lastName;
	std::string specialty;

	size_t countSemestr;
	semestrMas_t semestrMas;

public:
	/*constr / destr*/
	RecordBook(size_t countSemestr);
	~RecordBook();

	RecordBook(const RecordBook& rb);
	RecordBook(RecordBook&& rb) noexcept;

	RecordBook& operator=(const RecordBook& rb);
	RecordBook& operator=(RecordBook&& rb) noexcept;

	/*input*/
	friend std::istream& operator>>(std::istream& is, RecordBook& rb);

	/*get*/
	std::string getInfo() const;
	float getAverageCourse(size_t course) const; /*курс с нулевого*/
	size_t getCountCourse() const { return this->countSemestr / 2; }
	size_t getCountGrade(size_t course, int grade) const; /*количество оценок*/
	
	void printGrage(size_t semestr) const; /*семестр с нулевого*/
};