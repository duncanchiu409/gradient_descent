#ifndef GRADIENTDESCENTH
#define GRADIENTDESCENTH

#include <vector>

class GradientDescent{
    public:
        double compute_cost(std::vector<double> x, std::vector<double> y, double w, double b);
        std::vector<double> compute_gradient(std::vector<double> x, std::vector<double> y, double w, double b);
        std::vector<double> gradient_descent(std::vector<double> x, std::vector<double> y, double w_initial_value, double b_initial_value, int number_of_iterations);
};

#endif