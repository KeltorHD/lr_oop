#include "week.h"

std::istream& operator>>(std::istream& is, Week& wk)
{
	for (size_t i = 0; i < size_t(Week::day_t::count); i++)
	{
		size_t length{};
		is >> length;
		for (size_t j = 0; j < length; j++)
		{
			is >> wk.week[i];
		}
	}
	return is;
}

size_t Week::unique(day_t day)
{
	return this->week[size_t(day)].unique();
}

std::string Week::max_count(day_t day)
{
	return this->week[size_t(day)].max_count();
}
