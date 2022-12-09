#include "header.hpp"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Use 2 parametrs!";
        return 0;
    }
    std::cout
            << "    \t\t-Instruction-\n"
               "\t-The program works correctly if the correct operations are entered!-\n"
               "\t-Calculator with brackets can:\n"
               "+,-,*,/,^,sqrt,sin,cos,tan,ctg,exp and has numbers: pi, e. -\n";

    std::string str = argv[1]; // считываем введённую строку
    str += "#";

    std::stack<float> numbers;
    std::stack<int> buf_prioritet;
    std::stack<std::string> action;

    std::string buf_chislo;
    std::string buf_operacia;
    float x = 0.0;

    for (char symbol: str) {
        if (symbol == 'x') {
            std::cout << "Enter x: ";
            std::cin >> x;
            break;
        }
    }
    //Перебираю все символы в строке
    for (size_t symbol = 0; symbol != str.size(); symbol++) {
        if ((cifra.end() != std::find(cifra.begin(), cifra.end(), str[symbol])) || (str[symbol] == '.')) {
            Pushcifra(str, symbol, numbers, buf_chislo);
        } else {
            //Если символ — не цифра и не точка
            Pushoperacia(str, symbol, action, numbers, x, buf_operacia, buf_prioritet);
        }

    }
    action.pop(); //Удаляю решётку
    //При неправильном вводе
    if (!buf_operacia.empty() || !buf_chislo.empty() || !action.empty() || numbers.size() != 1) {
        std::cerr << "The expression is entered incorrectly!";
        return 0;
    }
    std::cout << numbers.top();//Вывод ответа
    numbers.pop();
}
