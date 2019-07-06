#pragma once

#include "unordered_map"
/*
4.1.1 Creating the Widgets

The label string must be in static storage such as a string constant because FLTK does
not make a copy of it - it just uses the pointer.

*/

class StringPrison
{
public:
	const char* intern(std::string s)
	{
		//std::cout << "s: " << s << std::endl;
		return (m_map[s] = s).c_str();

	}

	static StringPrison& get_string_prison()
	{
		return string_prison;
	}
private:
	std::unordered_map<std::string, std::string> m_map;
	//std::unordered_set<std::string> m_set;

	static StringPrison string_prison;
};

inline
const char* intern(std::string s)
{
	return StringPrison::get_string_prison().intern(s);
}

//extern StringPrison 