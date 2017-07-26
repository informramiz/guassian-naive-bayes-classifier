/*
 * classifier.h
 *
 *  Created on: Jul 26, 2017
 *      Author: ramiz
 */

#ifndef CLASSIFIER_H_
#define CLASSIFIER_H_

#include <iostream>
#include <sstream>
#include <fstream>
#include <math.h>
#include <vector>
#include "help_functions.h"

using namespace std;

class GNB {
public:

  vector<string> possible_labels = {"left","keep","right"};


  /**
   * Constructor
   */
  GNB();

  /**
   * Destructor
   */
  virtual ~GNB();

  void train(vector<vector<double> > data, vector<string>  labels);

  string predict(vector<double>);
  /**
   * Groups the observations based on classes
   */
  vector<vector<vector<double> > > GroupClassesData(vector<vector<double> >, vector<string> labels);

  /**
   * Given string label of class returns the index of class
   */
  int IndexOfClass(const string & class_label);

  /**
   * Calculates mean for all features independently, of all classes, based on all observations
   */
  vector<vector<double> > CalculateMean(const vector<vector<vector<double> > > &data);

  /**
   * Calculates variance for all features independently, of all classes, based on all observations
   */
  vector<vector<double> > CalculateVariance(const vector<vector<vector<double> > > &data,
                                                 const vector<vector<double> > & mean);

  /**
   * Calculates standard deviation from passed variance
   */
  vector<vector<double> > CalculateStandardDeviation(const vector<vector<double> > & variance);

private:
  vector<vector<double> > mean_;
  vector<vector<double> > variance_;
  vector<vector<double> > std_;
  HelpFunctions help_functions_;

};

#endif /* CLASSIFIER_H_ */
