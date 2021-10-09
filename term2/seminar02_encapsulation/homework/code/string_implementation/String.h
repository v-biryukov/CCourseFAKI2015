#pragma once
#include <iostream>

struct String {
private:
	size_t size;
	char* data;
	
public:
	String();
	String(char a);
	String(const char* str);
	
	String(const String& s);
	String(size_t n, char a);

	String& operator=(const String& right);
	String operator+(const String& right);
	String& operator+=(const String& right);

	bool operator==(const String& right) const;
	bool operator!=(const String& right) const;
	bool operator>(const String& right) const;
	bool operator<=(const String& right) const;
	bool operator<(const String& right) const;
	bool operator>=(const String& right) const;

	char& operator[](size_t id);
	char& at(size_t id);

	size_t get_size() const;
	const char* c_str() const;

	~String();
};

std::ostream& operator<<(std::ostream& left, const String& right);
