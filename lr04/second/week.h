#pragma once

#include <array>
#include <stdexcept>

#include "day.h"


class Week
{
public:
	enum class day_t
	{
		Mo,
		Tu,
		We,
		Th,
		Fr,
		Sa,
		Su,
		count = 7
	};
private:
	std::array<Day, size_t(day_t::count)> week = {};

public:
	
	friend std::istream& operator>>(std::istream& is, Week& wk);

	size_t unique(day_t day);

	std::string max_count(day_t day);
};