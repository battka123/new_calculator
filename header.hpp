#ifndef NEW_CALCULATOR_HEADER_HPP
#define NEW_CALCULATOR_HEADER_HPP

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>


// Создам массив всех цифр, чтобы сверять со следующим значением элемента строки
const std::vector<char> cifra = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

void Pushcifra(std::string &str, size_t &symbol, std::stack<float> &numbers, std::string &buf_chislo);

void Pushoperacia(std::string &str, size_t &symbol, std::stack<std::string> &action, std::stack<float> &numbers,
                  const float &x, std::string &buf_operacia, std::stack<int> &buf_prioritet);

void Magic(std::stack<std::string> &action, std::stack<float> &numbers, std::stack<int> &buf_prioritet);

#endif //NEW_CALCULATOR_HEADER_HPP
