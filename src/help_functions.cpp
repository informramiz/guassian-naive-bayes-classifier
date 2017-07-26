/*
 * help_functions.cpp
 *
 *  Created on: Apr 24, 2017
 *      Author: ramiz
 */

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "help_functions.h"

HelpFunctions::HelpFunctions()
  : ONE_OVER_SQRT_2PI(1/sqrt(2*M_PI)) {

}

//definition square:
float HelpFunctions::squared(float x) {
  return x*x;
}

/*****************************************************************************
 * normpdf(X,mu,sigma) computes the probability function at values x using the
 * normal distribution with mean mu and standard deviation std. x, mue and
 * sigma must be scalar! The parameter std must be positive.
 * The normal pdf is y=f(x;mu,std)= 1/(std*sqrt(2pi)) e[ -(x−mu)^2 / 2*std^2 ]
 *****************************************************************************/
float HelpFunctions::Normpdf(double x, double mu, double std) {
  return (ONE_OVER_SQRT_2PI/std)*exp(-0.5*squared((x-mu)/std));
}

//function to normalize a vector:
std::vector<float> HelpFunctions::NormalizeVector(std::vector<float> inputVector){

  //declare sum:
  float sum = 0.0f;

  //declare and resize output vector:
  std::vector<float> outputVector ;
  outputVector.resize(inputVector.size());

  //estimate the sum:
  for (unsigned int i = 0; i < inputVector.size(); ++i) {
    sum += inputVector[i];
  }

  //normalize with sum:
  for (unsigned int i = 0; i < inputVector.size(); ++i) {
    outputVector[i] = inputVector[i]/sum ;
  }

  //return normalized vector:
  return outputVector ;
}




