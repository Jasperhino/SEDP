class ModuloCounter {
public:
    //constructors
    ModuloCounter(int min, int max) : min(min), max(max), value(0), initial_value(0) {}
    ModuloCounter(int min, int max, int val) : min(min), max(max), initial_value(val) {
        set_value(val);
    }

    //copy constructor
    ModuloCounter(ModuloCounter& source) = default;

    //move constructor
    ModuloCounter(ModuloCounter&& source) = default;


    //type conversions
    operator int() const { return value; }

    //operators
    //copy assignment operator
    ModuloCounter& operator=(ModuloCounter const& other) {
        value = other.value;
        initial_value = other.value;
        return *this;
    };

    ModuloCounter& operator=(int v);

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


    void set_value(int value);
    int get_initial_value() const { return initial_value; };

protected:
    int initial_value;
    int value;
    const int min;
    const int max;
};