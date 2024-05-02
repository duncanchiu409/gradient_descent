#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "gradient_descent.h"

TEST_CASE("TEST COMPUTE GRADIENT METHOD"){
    GradientDescent* test = new GradientDescent();
    std::vector result = test->compute_gradient({1,2}, {300,500}, 0.1, 0.1);
    std::vector expected_result({-649.6, -399.75});
    for(int i=0; i<2; i++){
        CHECK(result[i] == expected_result[i]);
    }
}