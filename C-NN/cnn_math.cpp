#include <assert.h>
#include <Eigen/Dense>

namespace cnn_math {
    Eigen::ArrayXd relu(Eigen::ArrayXd x) {
        return x.max(Eigen::ArrayXd::Zero(x.size()));
    }
    
    Eigen::ArrayXd tanh(Eigen::ArrayXd x) {
        return x.tanh();
    }
}