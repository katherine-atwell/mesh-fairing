#include "Triangle.h"

using namespace std;

//triangle constructor, populates vertices based on the input arguments
Triangle::Triangle(Eigen::Vector3d firstVertex, Eigen::Vector3d secondVertex, Eigen::Vector3d thirdVertex) {
  vertex1 = firstVertex;
  vertex2 = secondVertex;
  vertex3 = thirdVertex;
}

//overloaded operator (for debugging purposes)
ostream& operator<<(ostream& os, const Triangle& triangle) {
  os << triangle.vertex1 << "\n";
  os << triangle.vertex2 << "\n";
  os << triangle.vertex3 << "\n";
  return os;
}

