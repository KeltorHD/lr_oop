#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

#include "user.h"

class Day
{
private:
	std::vector<User> traffic;

public:

	friend std::istream& operator>>(std::istream& is, Day& d)
	{
		User u;
		is >> u;
		d.traffic.push_back(u);
		return is;
	}

	size_t unique()
	{
		std::sort(this->traffic.begin(), this->traffic.end(),
			[](const User& u1, const User& u2)
			{
				return u1.getName() < u2.getName();
			});
		auto unique
		{ 
			std::unique(this->traffic.begin(), this->traffic.end(),
			[](const User& u1, const User& u2)
				{
				return u1.getName() == u2.getName();
				}) 
		}; /*возвращает указатель на конец вектора*/

		return (unique - this->traffic.begin());
	}

	std::string max_count()
	{
		std::string name_el{};
		size_t max_el{};
		for (size_t i = 0; i < this->traffic.size(); i++)
		{
			std::string name{};
			size_t max{};
			name = this->traffic[i].getName();
			for (size_t j = 0; j < this->traffic.size(); j++)
			{
				if (this->traffic[j].getName() == name)
				{
					max++;
				}
			}
			if (max > max_el)
			{
				max_el = max;
				name_el = name;
			}
		}
		return name_el;
	}
};