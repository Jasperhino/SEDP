
#include <iostream>
#include <random>
#include <cmath>
#include <limits>
#include <bitset>

#define E_PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062

const double lower_bound = 3.1413;
const double upper_bound = 3.1419;
const int iterations = 10000;


int monteCarlo_float() {
	int tries = 0;
	
	// TODO: approximate Pi and count the tries
    float pi;
    float points_on_circle = 0;
    int streak = 0;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dis(0, 1);

    for (; ; ++tries) {
        float x = dis(gen);
        float y = dis(gen);

        float distance = sqrtf(pow(x, 2) + pow(y, 2));
        if (distance < 1) points_on_circle++;
        pi = points_on_circle / tries * 4;
        if (pi <= upper_bound && pi >= lower_bound) {
            streak++;
            if (streak >= iterations) {
                break;
            }
        } else {
            streak = 0;
        }
    }

	return tries;
}

int monteCarlo_double() {
    int tries = 0;

    // TODO: approximate Pi and count the tries
    double pi;
    double points_on_circle = 0;
    int streak = 0;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0, 1);

    for (; ; ++tries) {
        double x = dis(gen);
        double y = dis(gen);

        double distance = std::sqrt(std::pow(x, 2) + pow(y, 2));
        if (distance < 1) points_on_circle++;
        pi = points_on_circle / tries * 4;
        if (pi <= upper_bound && pi >= lower_bound) {
            streak++;
            if (streak >= iterations) {
                break;
            }
        } else {
            streak = 0;
        }
    }

    return tries;
}

int monteCarlo_long_double() {
	int tries = 0;

	// TODO: approximate Pi and count the tries
    long double pi;
    long double points_on_circle = 0;
    int streak = 0;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<long double> dis(0, 1);

    for (; ; ++tries) {
        long double x = dis(gen);
        long double y = dis(gen);

        long double distance = sqrtl(pow(x, 2) + pow(y, 2));
        if (distance < 1) points_on_circle++;
        pi = points_on_circle / tries * 4;
        if (pi <= upper_bound && pi >= lower_bound) {
            streak++;
            if (streak >= iterations) {
                break;
            }
        } else {
            streak = 0;
        }
    }

	return tries;
}


int main(int argc, char * argv[])
{
    std::cout << "Float Tries: " <<  monteCarlo_float() << std::endl;
	std::cout << "Double Tries: " << monteCarlo_double() << std::endl;
	std::cout << "Long Double Tries: " << monteCarlo_long_double() << std::endl;
	
	// TODO: Provide an exact output using the three data types.
    auto float_precision = std::numeric_limits<float>::max_digits10;
    auto double_precision = std::numeric_limits<double>::max_digits10;
    auto long_double_precision = std::numeric_limits<long double>::max_digits10;

    std::cout << "max digits float " << float_precision << std::endl;
    std::cout << "max digits double " << double_precision << std::endl;
    std::cout << "max digits long double " << long_double_precision << std::endl;

    std::cout.precision(float_precision);
    std::cout << "(in-) Exact Output of float Pi: " << (float) E_PI << " used " << sizeof (float) << " bytes" << std::endl;
    std::cout.precision(double_precision);
    std::cout << "(in-) Exact Output of double Pi: " << (double) E_PI << " used " << sizeof (double) << " bytes" << std::endl;
    std::cout.precision(long_double_precision);
    std::cout << "(in-) Exact Output of long double Pi: " << (long double) E_PI << " used " << sizeof (long double) << " bytes" << std::endl;

    return 0;
}
