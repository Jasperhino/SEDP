#include <iostream>
#include "modulocounter.h"



void ModuloCounter::set_value(int v) {
    value = (v - min) % (max - min) + min;
}


std::ostream& operator<<(std::ostream &stream, const ModuloCounter &counter) {
    stream << counter.value << " in [" << counter.min << ", " << counter.max << ")";
    return stream;
}

ModuloCounter ModuloCounter::operator+(int other) {
    ModuloCounter copy = *this;
    copy.set_value(copy.value + other);
    return copy;
}

ModuloCounter ModuloCounter::operator-(int other) {
    ModuloCounter copy = *this;
    copy.set_value(copy.value - other);
    return copy;
}

ModuloCounter ModuloCounter::operator*(int other) {
    ModuloCounter copy = *this;
    copy.set_value(copy.value * other);
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
    this->set_value(this->value + other);
    return *this;
}

ModuloCounter &ModuloCounter::operator-=(const int other) {
    this->set_value(this->value - other);
    return *this;
}

ModuloCounter &ModuloCounter::operator=(const int v) {
    this->set_value(v);
    return *this;
}



