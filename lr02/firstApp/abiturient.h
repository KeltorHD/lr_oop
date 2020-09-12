#pragma once

#include <string>
#include <array>
#include <iostream>

class Abiturient
{
public:
	enum class lesson
	{
		inf = 0,
		math = 1,
		russ = 2,
		phis = 3,
		count = 4
	};
	typedef std::array<int, int(lesson::count)> score_t;
private:
	std::string name;
	std::string adress;
	score_t scores;

public:
	Abiturient() { this->scores = score_t(); }
	Abiturient(const std::string& name, const std::string& adress, const score_t& scores)
		: name(name), adress(adress), scores(scores) {}

	void setName(const std::string& name) { this->name = name; }
	void setAdress(const std::string& adress) { this->adress = adress; }
	void addScores(size_t lesson, int score) { this->scores[lesson] = score; }

	const std::string& getName() const { return this->name; }
	const std::string& getAdress() const { return this->adress; }
	const score_t& getScores() const { return this->scores; }
	const int& getScore(size_t lesson) const { return this->scores[lesson]; }
	int getSumScore() const;

	friend std::ostream& operator<<(std::ostream& os, const Abiturient& abitur);
	friend std::ostream& operator<<(std::ostream& os, const Abiturient* abitur);

};

std::ostream& operator<<(std::ostream& os, const Abiturient::lesson& lesson);