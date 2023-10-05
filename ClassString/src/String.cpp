#include <IString.h>
#include <cstdio>
#include <string.h>

IString& IString::operator=(
    const IString& rhs)
{
    if (this == &rhs)
        return *this;
    delete[] str;
    str = new char[strlen(rhs.str) + 1];
    strcpy_s(str, strlen(rhs.str) + 1, rhs.str);
    return *this;
}

IString operator+(const IString& lhs,
                  const IString& rhs)
{
    size_t length = strlen(lhs.str)
                  + strlen(rhs.str);

    char* buff = new char[length + 1];

    strcpy_s(buff, length + 1, lhs.str);
    strcat_s(buff, length + 1, rhs.str);
    buff[length] = '\0';

    IString temp { buff };

    delete[] buff;

    return temp;
}

IString& IString::operator+=(const IString& rhs)
{
    *this = *this + rhs;
    return *this;
}

void IString::Print() {
    printf(str);
    printf("\n");
}

char* IString::GetStr() {
    return str;
}

// Swapping string
void IString::swp(IString& rhs)
{
    IString temp{ rhs };
    rhs = *this;
    *this = temp;
}

IString::IString()
	: str { nullptr } {
	str = new char[1];
	str[0] = '\0';
}

IString::IString(const char* val) {
    if (val == nullptr) {
        str = new char[1];
        str[0] = '\0';
    }
    else {
        str = new char[strlen(val) + 1];

        strcpy_s(str, strlen(val) + 1, val);
        str[strlen(val)] = '\0';

        // printf("Created: ");
        // printf(str);
        // printf("\n");
    }
}

// Copy Constructor
IString::IString(const IString& source)
{
    str = new char[strlen(source.str) + 1];
    strcpy_s(str, strlen(source.str) + 1, source.str);
    str[strlen(source.str)] = '\0';

    // printf("Copied ");
    // printf(str);
    // printf("\n");
}

// Move Constructor
IString::IString(IString&& source) noexcept 
    : str(source.str)
{
    // printf(source.str);
    // printf(" is Moved!\n");
    source.str = nullptr;
}