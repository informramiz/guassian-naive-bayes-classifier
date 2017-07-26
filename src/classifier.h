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

};

#endif /* CLASSIFIER_H_ */
