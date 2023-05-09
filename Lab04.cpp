#include <iostream>
#include <cmath>
#include <iomanip>

double Fn(double x) {
  return -6 * pow(x, 2) + 5 * x + 3;
}

double Integral(double x) {
  return -2 * pow(x, 3) + (5.0 / 2.0) * pow(x, 2) + 3 * x;
}

double EstimateWithTraps(double a, double b, int n) {
  double deltaX = (b - a) / n;
  double sum = 0;
  for (int i = 1; i < n; ++i) {
    double x = a + i * deltaX;
    sum += Fn(x);
  }
  return deltaX  * (Fn(a) / 2 + sum + Fn(b) / 2);
}

int main() {
    double a, b, tolerance;
    int n;
    double actual_value, estimate, diff;

    std::cout << "Lower Range: ";
    std::cin >> a;
    std::cout << "Upper Range: ";
    std::cin >> b;
    std::cout << "Tolerance: ";
    std::cin >> tolerance;
    std::cout << "Initial trapezoid count: ";
    std::cin >> n;

    actual_value = Integral(b) - Integral(a);
    do {
        estimate = EstimateWithTraps(a, b, n);
        diff = std::abs(actual_value - estimate);
        std::cout << "Estimate:" << std::fixed << std::setprecision(4) << estimate
                  << ", Number of Traps:" << n << ", Diff:" << diff << std::endl;
        n *= 2;
    } while (diff > tolerance);

    return 0;
}
