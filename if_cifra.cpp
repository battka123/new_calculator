#include "header.hpp"

void Pushcifra(std::string &str, size_t &symbol, std::stack<float> &numbers, std::string &buf_chislo) {


    //Добавляем эту цифру в стоку "chislo", которая определит число не из одного символа
    buf_chislo.push_back(str[symbol]);
    // Если следующий символ — не цифра и не точка
    if ((std::find(cifra.begin(), cifra.end(), str[symbol + 1]) == cifra.end()) && (str[symbol + 1] != '.')) {
        // Мы убеждаемся, что это конец числа и добавляем его в стек чисел "numbers"
        numbers.push(float(std::stod(buf_chislo)));
        buf_chislo = "";
    }

}
