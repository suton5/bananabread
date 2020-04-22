#include <assert.h>
#include <Eigen/Dense>

Eigen::ArrayXd relu(Eigen::ArrayXd x) {
    return x.max(Eigen::ArrayXd::Zero(x.size()));
}