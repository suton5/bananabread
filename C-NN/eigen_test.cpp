#include <iostream>
#include <Eigen/Dense>
 
int main()
{
  Eigen::VectorXd m(4);
  m(0) = 1;
  m(1) = 2;
  m(2) = 3;
  m(3) = 4;
  std::cout << m << std::endl;

  Eigen::Map<Eigen::MatrixXd> m2(m.data(), 2,2);
  std::cout << m2.transpose() << std::endl;

  Eigen::VectorXd n(2);
  n(0) = 1;
  n(1) = 2;
  std::cout << m2.transpose()*n << std::endl;
  std::cout << m2*n << std::endl;
}