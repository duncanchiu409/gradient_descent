#include <stdexcept>
#include <vector>
#include <cmath>

class GradientDescent{
    double compute_cost(std::vector<double> x, std::vector<double> y, double w, double b){
        int x_length = x.size();
        int y_length = y.size();

        if(x_length != y_length){
            throw std::invalid_argument("Vector x and y are not in same length!");
            return {};
        }

        double f_wb = 0;
        double cost = 0;
        double total_cost = 0;
        for(int i=0; i<x_length; i++){
            f_wb = w * x[i] + b;
            cost += pow((f_wb - y[i]), 2);
        }
        total_cost = 1 / (2 * x_length) * cost;

        return total_cost;
    }
};