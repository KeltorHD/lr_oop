#pragma once

#include <iostream>
#include <fstream>
#include <string>

class Student
{
public:
	Student() = default;

	/*get*/
	size_t get_course() const;
	const std::string& get_fio() const;
	const std::string& get_spetiality() const;

	bool operator==(const Student& st);

	friend std::ostream& operator<<(std::ostream& os, const Student& st);
	friend std::istream& operator>>(std::istream& is, Student& st);

	/*
	сравнение студентов
	1 - по фио
	2 - по специальности
	3 - по курсу
	*/
	friend bool less(const Student& st1, const Student& st2, size_t i);

private:
	std::string fio;
	std::string spetiality;
	size_t course;
};