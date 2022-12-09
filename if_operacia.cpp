#include "header.hpp"

// Создаём приоритетность операций
const std::unordered_map<int, std::vector<std::string> > operators = {{0, {"#"}},
                                                                      {1, {"+",   "-"}},
                                                                      {2, {"*",   "/"}},
                                                                      {3, {"^",   "sqrt"}},
                                                                      {4, {"sin", "cos", "tan", "ctg", "exp"}}};


void Pushoperacia(std::string &str, size_t &symbol, std::stack<std::string> &action, std::stack<float> &numbers,
                  const float &x, std::string &buf_operacia, std::stack<int> &buf_prioritet) {
    //Добавляем этот символ в стоку "operaсia", которая определит операцию не из одного символа
    buf_operacia.push_back(str[symbol]);
    if (buf_operacia == "pi") {
        numbers.push(float(std::acos(-1.0)));
        buf_operacia = "";
    } else if (buf_operacia == "x") {
        numbers.push(x);
        buf_operacia = "";
    } else {
        for (const auto &prioritet: operators) {
            if ((prioritet.second.end() != std::find(prioritet.second.begin(), prioritet.second.end(),
                                                     buf_operacia)) || (buf_operacia == "(") || (buf_operacia == ")")) {
                if ((!buf_prioritet.empty() && !numbers.empty()) &&
                    (((buf_prioritet.top() >= prioritet.first) && (str[symbol] != '(')) || (str[symbol] == ')'))) {
                    if (str[symbol] == ')' || str[symbol] == '#') {
                        while ((!action.empty()) && (action.top() != "(")) {
                            Magic(action, numbers, buf_prioritet);

                        }

                        if (!action.empty()) {
                            if (action.top() == "(") {
                                action.pop();
                            }
                        }
                    } else {
                            Magic(action, numbers, buf_prioritet);
                    }
                }

                if ((str[symbol] != '(') && (str[symbol] != ')') && (str[symbol] != '#')) {
                    buf_prioritet.push(prioritet.first);
                }
                if (str[symbol] != ')') {
                    action.push(buf_operacia);
                }
                buf_operacia = "";
                break;
            }
        }
    }
}
