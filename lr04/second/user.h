#pragma once

#include <iostream>
#include <string>

class User
{
private:
	std::string name;
	std::string password;

public:
	User() {};
	User(std::string name, std::string password)
		: name(name), password(password) {}

	const std::string& getName() const { return this->name; }
	const std::string& getPassword() const { return this->password; }

	friend std::istream& operator>>(std::istream& is, User& user) 
	{
		is >> user.name; is >> user.password; return is;
	}
};