#include "header.hpp"

void Magic(std::stack<std::string> &action, std::stack<float> &numbers, std::stack<int> &buf_prioritet) {
    if (action.top() == "+" && numbers.size() > 1) {
        float a = numbers.top();
        numbers.pop();
        float b = numbers.top();
        numbers.pop();
        numbers.push(a + b);
    } else if (action.top() == "-" && numbers.size() > 1) {
        float a = numbers.top();
        numbers.pop();
        float b = numbers.top();
        numbers.pop();
        numbers.push(b - a);
    } else if (action.top() == "/" && numbers.size() > 1) {
        float a = numbers.top();
        numbers.pop();
        float b = numbers.top();
        numbers.pop();
        numbers.push(b / a);
    } else if (action.top() == "*" && numbers.size() > 1) {
        float a = numbers.top();
        numbers.pop();
        float b = numbers.top();
        numbers.pop();
        numbers.push(a * b);
    } else if (action.top() == "sqrt") {
        float a = numbers.top();
        numbers.pop();
        numbers.push(std::sqrt(a));
    } else if (action.top() == "^" && numbers.size() > 1) {
        float a = numbers.top();
        numbers.pop();
        float b = numbers.top();
        numbers.pop();
        numbers.push(std::pow(b, a));
    } else if (action.top() == "sin") {
        float a = numbers.top();
        numbers.pop();
        numbers.push(std::sin(a));
    } else if (action.top() == "cos") {
        float a = numbers.top();
        numbers.pop();
        numbers.push(std::cos(a));
    } else if (action.top() == "tan") {
        float a = numbers.top();
        numbers.pop();
        numbers.push(std::tan(a));
    } else if (action.top() == "ctg") {
        float a = numbers.top();
        numbers.pop();
        numbers.push(1 / std::tan(a));
    } else if (action.top() == "exp") {
        float a = numbers.top();
        numbers.pop();
        numbers.push(std::exp(a));
    }
    if (action.top() != "(") {
        action.pop();
        buf_prioritet.pop();
    }
}
