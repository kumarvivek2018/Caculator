#include <iostream>
#include "calc.h"
#include "stddef.h"
#include <cmath>

Calc::Calc(int values):storedExpressions(new std::string[values]), stored(0) {}

Calc::Calc(const Calc &rhs) {
    if(storedExpressions != nullptr)
        storedExpressions = new std::string[rhs.stored];
}

Calc::~Calc() {
    delete[] storedExpressions;
    storedExpressions = nullptr;
    stored = 0;
}

const Calc& Calc::operator=(const Calc &rhs) {
    if(this != rhs) {
        Calc temp(rhs);
        std:swap(storedExpressions, temp.storedExpressions);
        std::swap(stored, temp.stored);
    } 

    return *this;
}

double Calc::process(std::string userInput, double preValue) {
    //First cleanse
    std::string cleansedString = "";

    for(size_t i = 0; i < userInput.size(); ++i) {
        if(!(userInput[i] == '=' or userInput[i] == ' ' or userInput[i] == '(' or userInput[i] == ')'))
            cleansedString += userInput[i];
    }

    double value = std::stod(cleansedString.substr(1));

    switch (cleansedString[0]) {
    case '^':
        return pow(preValue, value);
    
    case '*':
        return preValue * value;
    
    case '/':
        if(value == 0)
            std::exit(0);
        
        return preValue / value;
    
    case '+':
        return preValue + value;

    case '-':
        return preValue - value;
    
    default:
        std::cout << "ERROR: Must start with operator" << std::endl;
        break;
    }

    return -1e7;
}

void Calc::print() {
    std::cout << "You have " << stored << " expressions stored:\n";

    for(size_t i = 0; i < stored; ++i) {
        std::cout << "Expression " << i + 1 << " result is: ";
        std::cout << storedExpressions[i] << std::endl;
    }
}

void Calc::setStored(size_t newStored) {
    stored = newStored;
}

size_t Calc::getStored() {
    return stored;
}