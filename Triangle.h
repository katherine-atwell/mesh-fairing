#ifndef SCENE_H
#define SCENE_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <Eigen/Dense>
#include <Eigen/Core>
#include <Eigen/LU>

using namespace std;

class Triangle {
  public:
  Triangle(Eigen::Vector3d firstVertex, Eigen::Vector3d secondVertex, Eigen::Vector3d thirdVertex);
  friend ostream& operator<<(ostream& os, const Triangle& triangle);
  private:
  Eigen::Vector3d vertex1;
  Eigen::Vector3d vertex2;
  Eigen::Vector3d vertex3;
};

#endif