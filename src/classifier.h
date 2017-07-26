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

};

#endif /* CLASSIFIER_H_ */
