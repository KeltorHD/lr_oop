#pragma once

#include <string>
#include <vector>
#include <iostream>

typedef std::pair<std::string, uint8_t> scoreUnit;
typedef std::vector<scoreUnit> scoreMas;

class Abiturient
{
private:
	std::string name;
	std::string adress;
	scoreMas scores;

public:
	Abiturient() {};
	Abiturient(const std::string& name, const std::string& adress, const scoreMas& scores)
		: name(name), adress(adress), scores(scores) {};

	void setName(const std::string& name) { this->name = name; };
	void setAdress(const std::string& adress) { this->adress = adress; };
	void addScores(const scoreUnit& score) { this->scores.push_back(score); };

	const std::string& getName() const { return this->name; }
	const std::string& getAdress() const { return this->adress; }
	const scoreMas& getScores() const { return this->scores; }

	friend std::ostream& operator<<(std::ostream& os, const Abiturient& abitur);

};

