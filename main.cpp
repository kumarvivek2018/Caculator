#include <iostream>
#include "calc.h"

int main() {
    int sentinal = 0;

    do {
        std::cout << "\nPlease enter the number of expressions you would like to store: " << std::endl;
        int values;
        std::cin >> values;

        if(values < 1)
            std::cout << "ERROR: Number of stored expressions must be positve" << std::endl;
        else {
            Calc calc1 = Calc(values);

            for(size_t i = 0; i < values; ++i) {
                double answer = 0;
                bool shouldContinue = true;

                while(shouldContinue) {
                    std::string userString;

                    std::cout << "\nPlease enter your expression (Enter 'STOP' to halt this input stream): \n" << " = "
                              << answer << " + ... " << std::endl;
                    std::cin >> userString;

                    if(userString == "STOP") {
                        calc1.storedExpressions[calc1.getStored()] = std::to_string(answer);
                        shouldContinue = false;
                        break;
                    }

                    answer = calc1.process(userString, answer);
                    std::cout << userString << "= " << answer;
                }

                calc1.setStored(calc1.getStored() + 1);
            }

            calc1.print();
            std::cout << "Presss 1 to continue with another calculater, any other value to quit" << std::endl;
            std::cin >> sentinal;
        }
    } while(sentinal == 1);

    return 0;
}