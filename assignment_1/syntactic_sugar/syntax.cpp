
#include <iostream>
#include <cassert>
#include <utility>
#include <vector>
#include <sstream>

// TODO: Start of solution
// You may edit / add anything from here to satisfy the interfaces and behaviors expected by the execution code below

// Start Generator section
struct Object {
public:
    Object(float value, bool count);

    ~Object();

    operator float() const { return m_value; }

    float m_value;
};

struct Converter {
    float m_value;
    Converter(float value) : m_value(value) {}

    operator float() const { return float(m_value); }

    operator Object() const { return Object{m_value, true}; }
};

struct Generator {
    static size_t objectInstanceCount;

    auto operator()() {
        return Converter(rand());
    }
};

// Start accounting Section
struct Currency {
    unsigned long long int cents;
};

Currency operator "" _euro(unsigned long long euro) {
    return Currency { euro * 100};
}

Currency operator "" _cent(unsigned long long cent) {
    return Currency {cent};
}

Currency operator "" _cents(unsigned long long cents) {
    return Currency {cents};
}

Currency operator && (const Currency &first, const Currency &second) {
    return Currency{first.cents + second.cents};
}

Currency operator , (const Currency &first, const Currency &second) {
    return Currency{first.cents + second.cents};
}

namespace Bills {
    const auto Five = Currency{500};
    const auto Ten = Currency{1000};
    const auto Twenty = Currency{2000};
    const auto Fifty = Currency{5000};
}

struct Account {
    Currency balance;
    Account() : balance(0_euro) {}
    Account(const Currency &c): balance(c) {}
};

void operator >>(Currency const &currency, Account &account) {
    account.balance.cents += currency.cents;
}

Currency operator >>(Account &account, Currency const &currency) {
    account.balance.cents -= currency.cents;
    return currency;
}

void operator <<(Currency const &balance, Account &account) {
    account.balance.cents -= account.balance.cents + balance.cents;
}

Currency operator <<(Account &account, Currency const & currency) {
    account.balance.cents += currency.cents;
    return currency;
}

bool operator ==(Currency const &currency, unsigned long long value) {
    return currency.cents == value;
}

std::ostream& operator <<(std::ostream &ostream, Account const &account) {
    unsigned long long int euros = account.balance.cents / 100;
    unsigned long long int cents = account.balance.cents - euros * 100;
    ostream << "Account with balance " << euros << " euros, " << cents << "cents";
    return ostream;
}

//Start Matrix Section


struct Selector{
    std::vector<int> indices;
    Selector(std::vector<int> indices) : indices(std::move(indices)) {};
};

struct MX {};

struct MY {
    Selector operator == (const MX &mx) {
        std::vector<int> vec = {0, 4, 8, 12};
        return Selector(vec);
    }

    Selector operator > (const MX &mx) {
        std::vector<int> vec = {4, 8, 9, 12, 13, 14};
        return Selector(vec);
    }

    Selector operator < (const MX &mx) {
        std::vector<int> vec = {1, 2, 3, 6, 7, 10, 11, 12};
        return Selector(vec);
    }

    Selector operator == (int i) {
        const std::vector<int> vec = {0, 1, 2, 3};
        return Selector{vec};
    }
};


struct NX {
    int index;
    explicit NX(unsigned long long i) : index(i){}
};

struct NY {
    int index;
    explicit NY(unsigned long long i) : index(i){}
};

NX operator "" _x (unsigned long long i) {
    return NX{i};
}

NY operator "" _y (unsigned long long i) {
    return NY{i};
}

Selector operator , (NY ny, NX nx) {
    std::vector<int> indices = {4 * nx.index + ny.index};
    return Selector{indices};
}

Selector operator , (NX nx, NY ny) {
    std::vector<int> indices = {4 * nx.index + ny.index};
    return Selector{indices};
}

struct Matrix;

struct MatrixView {
    Matrix& matrix;
    std::vector<int>& indices;
    MatrixView(std::vector<int>& indices, Matrix& m) : indices(indices), matrix(m) {}
    MatrixView& operator= (float f);
};

struct Matrix {
    Matrix() : m_f() {}

    Matrix(std::initializer_list<float> initializer) {
        assert(initializer.size() == (sizeof (m_f) / sizeof(*m_f)));
        std::copy(initializer.begin(), initializer.end(), m_f);
    }

    float m_f[16]{};

    MX x;
    MY y;

    MatrixView operator [] (Selector s) {
        return MatrixView{s.indices, *this};
    }
};

bool operator == (const Matrix& a, const Matrix& b) {
    return std::equal(a.m_f, a.m_f+16, b.m_f);
};

MatrixView& MatrixView::operator= (const float f) {
    for (auto const i : indices) {
        matrix.m_f[i] = f;
    }
    return *this;
}


// End of solution
// Do not edit the source code below!

// Generator::objectInstanceCount must be incremented on object creation and shall never be manipulated otherwise
Object::Object(float value, bool count) : m_value(value) { if (count) Generator::objectInstanceCount++; }

Object::~Object() {}

size_t Generator::objectInstanceCount = 0;

void generator() {
    Generator gen;
    std::vector<float> floats;
    std::vector<Object> objects;

    assert(objects.size() == Generator::objectInstanceCount);

    for (auto i = 0; i < 500; ++i) {
        if (i % 7 == 0) {
            floats.emplace_back(gen());
        } else if (i % 5 == 0) {
            objects.emplace_back(gen());
        } else {
            std::cout << gen() << std::endl;
        }
    }

    assert(objects.size() == Generator::objectInstanceCount);
}

void accounting() {
    Account a{200_euro and 34_cents};
    Account b{300_euro and 1_cent};

    b >> (100_euro, 32_cents) >> a;

    assert(a.balance == 30066);
    assert(b.balance == 19969);

    b << Bills::Fifty << a;

    assert(a.balance == 25066);
    assert(b.balance == 24969);

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;

    std::stringstream stream_a;
    stream_a << a;
    std::stringstream stream_b;
    stream_b << b;
    assert(stream_a.str() == "Account with balance 250 euro, 66 cents");
    assert(stream_b.str() == "Account with balance 249 euro, 69 cents");
}

void matrix() {
    Matrix m;

    Matrix m1 = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    assert(m == m1);

    m[m.y == m.x] = 1.0f;

    Matrix m2 = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
    assert(m == m2);

    m[m.y > m.x] = 3.0f;

    Matrix m3 = {1, 0, 0, 0, 3, 1, 0, 0, 3, 3, 1, 0, 3, 3, 3, 1};
    assert(m == m3);

    m[m.y < m.x] = 4.0f;

    Matrix m4 = {1, 4, 4, 4, 3, 1, 4, 4, 3, 3, 1, 4, 3, 3, 3, 1};
    assert(m == m4);

    m[3_y, 2_x] = 12.0f;

    Matrix m5 = {1, 4, 4, 4, 3, 1, 4, 4, 3, 3, 1, 4, 3, 3, 12, 1};
    assert(m == m5);

    m[3_x, 2_y] = 42.0f;

    Matrix m6 = {1, 4, 4, 4, 3, 1, 4, 4, 3, 3, 1, 42, 3, 3, 12, 1};
    assert(m == m6);

    m[m.y == 0] = 2.0f;

    Matrix m7 = {2, 2, 2, 2, 3, 1, 4, 4, 3, 3, 1, 42, 3, 3, 12, 1};
    assert(m == m7);
}

int main(int argc, char *argv[]) {
    generator();
    accounting();
    matrix();

    return 0;
}
