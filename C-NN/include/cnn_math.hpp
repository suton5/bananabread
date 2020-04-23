#ifndef CNN_MATH_H_IN
#define CNN_MATH_H_IN

#include <assert.h>
#include <Eigen/Dense>

namespace cnn_math {
    Eigen::MatrixXd relu(Eigen::MatrixXd x);
    Eigen::MatrixXd tanh(Eigen::MatrixXd x);
}

#endif