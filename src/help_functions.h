/*
 * help_functions.h
 *
 *  Created on: Apr 24, 2017
 *      Author: ramiz
 */

#ifndef HELP_FUNCTIONS_H_
#define HELP_FUNCTIONS_H_

#include <cmath>
#include <string>

class HelpFunctions {
public:

  //definition of one over square root of 2*pi:
  const float ONE_OVER_SQRT_2PI;

  //Constructor
  HelpFunctions();

  //definition square:
  float squared(float x);

  /*****************************************************************************
   * normpdf(X,mu,sigma) computes the probability function at values x using the
   * normal distribution with mean mu and standard deviation std. x, mue and
   * sigma must be scalar! The parameter std must be positive.
   * The normal pdf is y=f(x;mu,std)= 1/(sqrt(2pi * square(std)) * e ^ [ -(x−mu)^2 / 2*std^2 ]
  *****************************************************************************/
  float Normpdf(double x, double mu, double std);

  //function to normalize a vector:
  std::vector<float> NormalizeVector(std::vector<float> inputVector);
};




#endif /* HELP_FUNCTIONS_H_ */
