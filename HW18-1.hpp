#ifndef TEMP_HEADER
#define TEMP_HEADER

#include <stdexcept>

class Temperature {
    double temp_in_c;
    void convert_celcius(double temperature, char unit);
public:
    Temperature(double temperature, char unit);
    double AsCelsius() const;
    double AsFahrenheit() const;
    double AsKelvin() const;
    double AsRankine() const;

};

#endif //TEMP_HEADER
