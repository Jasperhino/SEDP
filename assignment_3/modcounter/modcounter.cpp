#include <iostream>
#include "modcounter.h"



void ModuloCounter::_set_value(int value) {
    if (value < 0) {

    }
    value = (value - min) % (max - min) + min;
}


std::ostream& operator<<(std::ostream &stream, const ModuloCounter &counter) {
    stream << counter.value << " in [" << counter.min << ", " << counter.max << ")" << std::endl;
    return stream;
}

ModuloCounter ModuloCounter::operator+(int other) {
    ModuloCounter copy = *this;
    copy._set_value(copy.value + other);
    return copy;
}

ModuloCounter ModuloCounter::operator-(int other) {
    ModuloCounter copy = *this;
    copy._set_value(copy.value - other);
    return copy;
}

ModuloCounter ModuloCounter::operator*(int other) {
    ModuloCounter copy = *this;
    copy._set_value(copy.value * other);
    return copy;
}


//preincrement
ModuloCounter& ModuloCounter::operator++() {
    this->value++;
    return *this;
}

//postincrement
ModuloCounter ModuloCounter::operator++(int) {
    ModuloCounter copy = *this;
    operator++();
    return copy;
}

//predecrement
ModuloCounter& ModuloCounter::operator--() {
    this->value--;
    return *this;
}

//postdecrement
ModuloCounter ModuloCounter::operator--(int) {
    ModuloCounter copy = *this;
    operator--();
    return copy;
}


ModuloCounter &ModuloCounter::operator+=(const int other) {
    this->_set_value(this->value + other);
    return *this;
}

ModuloCounter &ModuloCounter::operator-=(const int other) {
    this->_set_value(this->value - other);
    return *this;
}

ModuloCounter &ModuloCounter::operator=(const int v) {
    this->_set_value(v);
    return *this;
}



