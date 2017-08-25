#include "String.h"
#include <iostream>
#include <memory>
#include <algorithm>
#include <utility>
#include <cstring>

String::String(const char *cstr)
{
	auto data = copyStr(cstr, cstr + strlen(cstr));
	elements = data.first;
	first_new = cap = data.second;
}

String::String(const String &str)
{
	std::cout << "copy: ";
	for(auto i = str.begin(); i < str.end(); ++i)
		std::cout << *i << " ";
	std::cout << std::endl;
	auto data = copyStr(str.begin(), str.end());
	elements = data.first;
	first_new = cap = data.second;
}

String::String(String &&s) noexcept: elements(s.elements), first_new(s.first_new), cap(s.cap)
{
	s.elements = s.first_new = s.cap = nullptr;
}

String &String::operator=(String &&s) noexcept
{
	std::cout << "move contructor" << std::endl;
	if(&s != this)
	{
		free();
		elements = s.elements;
		first_new = s.first_new;
		cap = s.cap;
		s.elements = s.first_new = s.cap = nullptr;
	}
	return *this;
}

String &String::operator=(const String &str)
{
	if(&str != this)
	{
		free();
		auto data = copyStr(str.begin(), str.end());
		elements = data.first;
		first_new = cap = data.second;
	}
	return *this;
}

void String::push_back(char c)
{
	checkCapacity();
	alloc.construct(first_new++, c);
}

void String::free()
{
	if(elements != nullptr)
	{
		std::for_each(elements, first_new, [this](char &c){alloc.destroy(&c);});
		alloc.deallocate(elements, capacity());
	}
}

void String::reallocate()
{
	size_t newSize = capacity() > 0? capacity() * 2: 1;
	auto newHead = alloc.allocate(newSize);
	auto cursor = newHead;
	std::for_each(elements, first_new, [this, &cursor](char &c){alloc.construct(cursor++, std::move(c));});
}

std::pair<char *, char *> String::copyStr(const char *left, const char *right)
{
	auto newHead = alloc.allocate(right - left);
	return {newHead, std::uninitialized_copy(left, right, newHead)};
}


