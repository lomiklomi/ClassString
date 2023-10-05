#pragma once

class IString {
private:
	char* str;
public:
	IString();

	IString(const char* val);

	// Copy Constructor
	IString(const IString& source);

	// Move Constructor
	IString(IString&& source) noexcept;

	~IString() { delete str; }

	void Print();

	char* GetStr();

	// Swap strings function
	void swp(IString& rhs);

	friend IString operator+(
		const IString& lhs,
		const IString& rhs);

	IString& operator=(
		const IString& rhs);

	IString& operator+=(const IString& rhs);

};