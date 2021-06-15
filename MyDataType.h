#include <string>
#include <iostream>

#pragma once

struct MyDataType
{
private:
    std::string _name;
    size_t _age;
    std::string _hobby;

public:
    MyDataType() : _name(""), _age(0), _hobby("") { };
    MyDataType(const std::string& n, size_t a, const std::string& h) :
        _name(n),
        _age(a),
        _hobby(h) { };

    bool operator<(const MyDataType& other) { return _name < other._name; };
    bool operator>(const MyDataType& other) { return _name > other._name; };
    bool operator==(const MyDataType& other) { return _name == other._name; };
    bool operator!=(const MyDataType& other) { return _name != other._name; };
    MyDataType& operator=(const MyDataType& other)
    {
        _name = other._name;
        _age = other._age;
        _hobby = other._hobby;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& output, const MyDataType& ob)
    {
        output << "{ " << ob._name << ", " << ob._age << ", " << ob._hobby << " }\n";
        return output;
    }
};
