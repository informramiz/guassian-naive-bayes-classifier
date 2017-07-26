# guassian-naive-bayes-classifier
A Gaussian Naive Bayes classifier to predict the behavior of vehicles on a 3 lane highway (with lanes of 4 meter width)

Implement a Gaussian Naive Bayes classifier to predict the behavior of vehicles on a highway. In the image below you can see the behaviors you'll be looking for on a 3 lane highway (with lanes of 4 meter width). The dots represent the d (y axis) and s (x axis) coordinates of vehicles as they either...

change lanes left (shown in blue)
keep lane (shown in black)
or change lanes right (shown in red)
Your job is to write a classifier that can predict which of these three maneuvers a vehicle is engaged in given a single coordinate (sampled from the trajectories shown below).

Each coordinate contains 4 pieces of information:

s
d
​s_dot (change in s)
d_dot (change in d)
​​ 
You also know the lane width is 4 meters (this might be helpful in engineering features for your algorithm).
