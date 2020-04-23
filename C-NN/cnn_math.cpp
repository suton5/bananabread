#include <assert.h>
#include <Eigen/Dense>
#include <cmath>
#include <Eigen/Core>

namespace cnn_math {

    double relu_element(double x) {
            return std::max(0.0, x);
    }

    double tanh_element(double x) {
            return std::tanh(x);
    }

    Eigen::MatrixXd relu(Eigen::MatrixXd x) {
        return x.unaryExpr([](double x){return std::max(0.0, x);});
    }
    
    Eigen::MatrixXd tanh(Eigen::MatrixXd x) {
        return x.unaryExpr([](double x){return std::tanh(x);});
    }
}