#ifndef CNN_MATH_H_IN
#define CNN_MATH_H_IN

#include <assert.h>
#include <Eigen/Dense>

namespace cnn_math {
    Eigen::ArrayXd relu(Eigen::ArrayXd x);
    Eigen::ArrayXd tanh(Eigen::ArrayXd x);
}

#endif