#include <stdexcept>
#include <vector>
#include <cmath>
#include <iostream>
#include "gradient_descent.h"

double GradientDescent::compute_cost(std::vector<double> x, std::vector<double> y, double w, double b)
{
    int x_length = x.size();
    int y_length = y.size();

    if (x_length != y_length)
    {
        throw std::invalid_argument("Vector x and y are not in same length!");
        return {};
    }

    double f_wb = 0;
    double cost = 0;
    double total_cost = 0;

    for (int i = 0; i < x_length; i++)
    {
        f_wb = w * x[i] + b;
        cost += pow((f_wb - y[i]), 2);
    }
    total_cost = (double)1 / (double)(2 * x_length) * cost;

    return total_cost;
}

std::vector<double> GradientDescent::compute_gradient(std::vector<double> x, std::vector<double> y, double w, double b)
{
    int x_length = x.size();
    int y_length = y.size();

    if (x_length != y_length)
    {
        throw std::invalid_argument("Vector x and y are not in same length!");
        return {};
    }

    double f_wb = 0;
    double dj_dw_i = 0;
    double dj_db_i = 0;
    double dj_dw = 0;
    double dj_db = 0;
    double cost = 0;

    for (int i = 0; i < x_length; i++)
    {
        f_wb = w * x[i] + b;
        cost = (f_wb - y[i]);
        dj_dw_i += cost * x[i];
        dj_db_i += cost;
    }

    dj_dw = (double)1 / (double)x_length * dj_dw_i;
    dj_db = (double)1 / (double)x_length * dj_db_i;

    return {dj_dw, dj_db};
}

std::vector<double> GradientDescent::gradient_descent(std::vector<double> x, std::vector<double> y, double alpha, double w_initial_value, double b_initial_value, int number_of_iterations){
    std::vector<double> J_history;
    std::vector<std::vector<double>> p_history;
    double w = w_initial_value;
    double b = b_initial_value;

    for(int i=0; i<number_of_iterations; i++){
        std::vector<double> tmp = this->compute_gradient(x, y, w, b);
        w = w - alpha * tmp[0];
        b = b - alpha * tmp[1];

        if( i < 100000 ){
            J_history.push_back(this->compute_cost(x, y, w, b));
            p_history.push_back({w, b});
        }

        if( i % (number_of_iterations/10) == 0){
            std::cout << "Iteration " << i << ": Cost " << J_history.back() << " dj_dw: " << tmp[0] << " dj_dw: " << tmp[1] << " w: " << w << " b:" << b << std::endl;        
        }
    } 

    std::vector<double> result({w, b});
    return result;
}