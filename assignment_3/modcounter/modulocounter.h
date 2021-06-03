class ModuloCounter {
public:
    //constructors
    ModuloCounter(int min, int max) : min(min), max(max), value(min) {}
    ModuloCounter(int min, int max, int val) : min(min), max(max) {
        _set_value(val);
    }

    //copy constructor
    ModuloCounter(ModuloCounter& source) = default;

    //move constructor
    ModuloCounter(ModuloCounter&& source) = default;


    //type conversions
    operator int() const { return value; }

    //operators
    //copy assignment operator
    ModuloCounter& operator=(ModuloCounter const& other) = default;

    ModuloCounter& operator=(const int v);

    friend std::ostream& operator<< (std::ostream& stream, const ModuloCounter& counter);

    //arithmetics
    ModuloCounter operator+(int other);
    ModuloCounter operator-(int other);
    ModuloCounter operator*(int other);

    //
    ModuloCounter& operator++();
    ModuloCounter operator++(int);
    ModuloCounter& operator--();
    ModuloCounter operator--(int);


    ModuloCounter& operator+=(int other);
    ModuloCounter& operator-=(int other);


    void _set_value(int value);

protected:
    int value;
    int min;
    int max;
};