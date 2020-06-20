#include <string>

class Calc {
public:
    Calc(int val);
    Calc(const Calc &rhs);
    ~Calc();
    const Calc & operator=(const Calc &rhs);
    double process(std::string userInput, double preValue);
    void print();
    std::string* storedExpressions;
    void setStored(size_t newStored);
    size_t getStored();

private:
    size_t stored;
};