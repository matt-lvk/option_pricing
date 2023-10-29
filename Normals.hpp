#ifndef NORMALS_H
#define NORMALS_H

#include <Eigen/Dense>

double GetOneGaussianByBoxMuller();

double NormalDensity(double x);

double CumulativeNormal(double x);

double InverseCumulativeNormal(double x);

#endif
