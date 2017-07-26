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
#include <cassert>
#include "classifier.h"

/**
 * Initializes GNB
 */
GNB::GNB() {

}

GNB::~GNB() {}

void GNB::train(vector<vector<double>> data, vector<string> labels)
{

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

  //----------
  ///Group Data
  //-----------

  cout << "-------------Grouping data" << endl;
  //from data, group classes data into different vectors:
  //so total vectors of type vector<vector<double>>: left_vector, keep_vector, right_vector
  //make a new vector of type: vector<vector<vector<double>>>: values
  vector<vector<vector<double> > > grouped_classes_data = GroupClassesData(data, labels);

  int total = 0;
  for (int i = 0; i < grouped_classes_data.size() ; ++i) {
    cout << "Class " << possible_labels[i] << " has observations: " << grouped_classes_data[i].size() << endl;
    total += grouped_classes_data[i].size();
  }

  std::cout << "Total of all grouped obs: " << total << endl;
  assert(total == data.size());
  cout << "------------Data grouping complete" << endl;

  //----------
  // Calculate mean
  //-----------

  //----------
  //sum values
  //-----------
  //for each class
  // for each observation
  //  for each feature out of total features
  //    sum_value[class][feature] += values[class][obs][feature]

  //for each class
  //  for each sum_value
  //    mean_value[i] = sum_value[i]/values[class][i].size()
  cout << "-----------Calculating mean" << endl;
  vector<vector<double> > mean = CalculateMean(grouped_classes_data);

  //verify size classes count in mean vector
  assert(mean.size() == possible_labels.size());
  //verify size of features vector in mean vector
  assert(mean[0].size() == grouped_classes_data[0][0].size());
  cout << "----------Mean Calculated with classes count " << mean.size() << " and features vector size " << mean[0].size() << endl;

  for (int clas = 0; clas < mean.size(); ++clas) {
    cout << "Mean values for " << possible_labels[clas] << " are: ";
    for (int feature = 0; feature < mean[clas].size(); ++feature) {
      cout << mean[clas][feature] << ", ";
    }
    cout << endl;
  }

  //---------------------
  //Calculate Variance
  //-------------------

  //for each class
  // for each observation
  //  for each feature out of total features
  //    squared_sum_value[class][feature] += pow( (values[class][obs][feature] - mean_value[class][feature]), 2)


  //for each class
  // for each feature
  //    variance[class][feature] = squared_sum_value[class][feature]/values[class][i].size()

  cout << "-----------Calculating Variance" << endl;
  vector<vector<double> > variance = CalculateVariance(grouped_classes_data, mean);

  //verify size classes count in variance vector
  assert(variance.size() == possible_labels.size());
  //verify size of features vector in variance vector
  assert(variance[0].size() == grouped_classes_data[0][0].size());
  cout << "----------Variance Calculated with classes count " << variance.size() << " and features vector size " << variance[0].size() << endl;

  for (int clas = 0; clas < variance.size(); ++clas) {
    cout << "Variance values for " << possible_labels[clas] << " are: ";
    for (int feature = 0; feature < variance[clas].size(); ++feature) {
      cout << variance[clas][feature] << ", ";
    }
    cout << endl;
  }

}

vector<vector<double> > GNB::CalculateMean(const vector<vector<vector<double> > > &data) {
  //extract different counts
  int classes_count = data.size();
  int features_count = data[0][0].size();

  //create a vector to hold sum of observations for each feature, required for mean
  vector<vector<double> > sums;
  //create a vector of just zeros of size same as features vector
  vector<double> zeros_vector;
  //initialize zeros vector with zeros and make its size same as features vector
  zeros_vector.resize(features_count, 0.0);

  //initialize the sum vectors classes array part
  sums.resize(classes_count, zeros_vector);

  //go through all class --> observations --> features
  //and sum each feature for each class for all observations
  for (int clas = 0; clas < classes_count; ++clas) {
    for (int obs = 0; obs < data[clas].size(); ++obs) {
      for (int feature = 0; feature < data[clas][obs].size(); ++feature) {
        sums[clas][feature] += data[clas][obs][feature];
      }
    }
  }

  //now divide sum of features by total observations to get mean
  vector<vector<double> > means;
  means.resize(possible_labels.size(), zeros_vector);
  for(int clas = 0; clas < sums.size(); ++clas) {
    for (int feature = 0; feature < sums[clas].size(); ++feature) {
      //divide sum of each feature by number of observations of that feature
      means[clas][feature] = (double)sums[clas][feature] / (double)data[clas].size();
    }
  }

  return means;
}

vector<vector<double> > GNB::CalculateVariance(const vector<vector<vector<double> > > &data,
                                               const vector<vector<double > > & mean) {
  //extract different counts
  int classes_count = data.size();
  int features_count = data[0][0].size();

  //create a vector to hold sum of observations for each feature, required for mean
  vector<vector<double> > sum_of_squred_diffs_from_mean;
  //create a vector of just zeros of size same as features vector
  vector<double> zeros_vector;
  //initialize zeros vector with zeros and make its size same as features vector
  zeros_vector.resize(features_count, 0.0);

  //initialize the sum vectors classes array part
  sum_of_squred_diffs_from_mean.resize(classes_count, zeros_vector);

  //go through all class --> observations --> features
  //and sum each feature for each class for all observations
  for (int clas = 0; clas < classes_count; ++clas) {
    for (int obs = 0; obs < data[clas].size(); ++obs) {
      for (int feature = 0; feature < data[clas][obs].size(); ++feature) {
        sum_of_squred_diffs_from_mean[clas][feature] += pow((data[clas][obs][feature] - mean[clas][feature]), 2);
      }
    }
  }

  //now divide sum of features by total observations to get mean
  vector<vector<double> > means;
  means.resize(possible_labels.size(), zeros_vector);
  for(int clas = 0; clas < sum_of_squred_diffs_from_mean.size(); ++clas) {
    for (int feature = 0; feature < sum_of_squred_diffs_from_mean[clas].size(); ++feature) {
      //divide sum of each feature by number of observations of that feature
      means[clas][feature] = (double)sum_of_squred_diffs_from_mean[clas][feature] / (double)data[clas].size();
    }
  }

  return means;
}


int GNB::IndexOfClass(const string & class_label) {
  for (int i = 0; i < possible_labels.size(); ++i) {
    if (this->possible_labels[i] == class_label) {
      return i;
    }
  }

  return -1;
}

vector<vector<vector<double> > > GNB::GroupClassesData(vector<vector<double> > data, vector<string> labels) {
  //create a big vector to contain grouped data for all possible_labels
  vector<vector<vector<double> > > class_observations;

  //resize class_observations vector to have same size as number of classes
  class_observations.resize(possible_labels.size());

  //first lets loop over all the observations we have
  for (int i = 0; i < data.size(); ++i) {
    //get the class index based on corresponding label
    int class_label = this->IndexOfClass(labels[i]);
    class_observations[class_label].push_back(data[i]);
  }

  return class_observations;
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
