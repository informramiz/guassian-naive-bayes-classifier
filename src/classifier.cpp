/*
 * classifier.cpp
 *
 *  Created on: Jul 26, 2017
 *      Author: ramiz
 */

#include <iostream>
#include <sstream>
#include <fstream>
#include <math.h>
#include <vector>
#include "classifier.h"

/**
 * Initializes GNB
 */
GNB::GNB() {

}

GNB::~GNB() {}

void GNB::train(vector<vector<double>> data, vector<string> labels)
{

  //from data, group classes data into different vectors:
  //so total vectors of type vector<vector<double>>: left_vector, keep_vector, right_vector

  //make a new vector of type: vector<vector<vector<double>>>: values

  //----------
  //sum values
  //-----------

  //for each class
  // for each observation
  //  for each feature out of total features
  //    sum_value[class][feature] += values[class][obs][feature]


  //----------
  // Calculate mean
  //-----------

  //for each class
  //  for each sum_value
  //    mean_value[i] = sum_value[i]/values[class][i].size()

  //for each class
  // for each observation
  //  for each feature out of total features
  //    squared_sum_value[class][feature] += pow( (values[class][obs][feature] - mean_value[class][feature]), 2)


  //for each class
  // for each feature
  //    variance[class][feature] = squared_sum_value[class][feature]/values[class][i].size()

  /*
    Trains the classifier with N data points and labels.

    INPUTS
    data - array of N observations
      - Each observation is a tuple with 4 values: s, d,
        s_dot and d_dot.
      - Example : [
          [3.5, 0.1, 5.9, -0.02],
          [8.0, -0.3, 3.0, 2.2],
          ...
        ]

    labels - array of N labels
      - Each label is one of "left", "keep", or "right".
   */
}

string GNB::predict(vector<double>)
{
  /*
    Once trained, this method is called and expected to return
    a predicted behavior for the given observation.

    INPUTS

    observation - a 4 tuple with s, d, s_dot, d_dot.
      - Example: [3.5, 0.1, 8.5, -0.2]

    OUTPUT

    A label representing the best guess of the classifier. Can
    be one of "left", "keep" or "right".
    """
    # TODO - complete this
   */

  return this->possible_labels[1];

}
