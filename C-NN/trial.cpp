#include <iostream>
#include <assert.h>
#include <unordered_map>
#include <Eigen/Dense>
#include <variant>
#include <string>
// #include "cnn_math.h"
// #include "cnn.h"

// using value_type = std::variant<int, std::function<double(double)>>;

// std::unordered_map<std::string, value_type> arch = {
//     {"num_hidden", 1},
//     {"width", 10},
//     {"input_dim", 1},
//     {"output_dim", 1},
//     {"activation_fn", relu}
// };

Eigen::ArrayXd relu(Eigen::ArrayXd x) {
    return x.max(Eigen::ArrayXd::Zero(x.size()));
}

int main() {
    Eigen::ArrayXd a = Eigen::ArrayXd::Random(10);
    a(0) = -1;
    std::cout << "a:" << a << std::endl;
    std::cout << "\nrelu(a):"<< relu(a) << std::endl;
    Eigen::Map<Eigen::ArrayXd,3,5,Eigen::InnerStride<1> > a2(a.data(), 3);
    std::cout << "\na[3:5]:"<< a2 << std::endl;
    

    return 0; 
}