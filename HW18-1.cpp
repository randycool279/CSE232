#include "HW18-1.hpp"

Temperature::Temperature(double temperature, char unit) {
    convert_celcius(temperature, unit);
}

void Temperature::convert_celcius(double temperature, char unit) {
    switch (unit) {
        case 'C':
            temp_in_c = temperature;
            break;
        case 'F':
            temp_in_c = (temperature - 32) * 5 / 9;
            break;
        case 'R':
            temp_in_c = (temperature - 491.67) * 5 / 9;
            break;
        case 'K':
            temp_in_c = temperature - 273.15;
            break;
        default:
            throw std::invalid_argument("bad unit");
    }
}

double Temperature::AsCelsius() const {
    return temp_in_c;
}

double Temperature::AsFahrenheit() const {
    return temp_in_c * 9 / 5 + 32;
}

double Temperature::AsKelvin() const {
    return temp_in_c + 273.15;
}

double Temperature::AsRankine() const {
    return (temp_in_c + 273.15) * 9 / 5;
}
