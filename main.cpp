#include "io.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <Eigen/Dense>
#include <Eigen/Core>
#include <Eigen/LU>
#include cmath

using namespace std;
using namespace Eigen;
int main(int argc, char* argv[]) {
  
  //exits program if correct number of args is not provided
  if (argc != 5) {
    cout << "Please try again, making sure to type ./proj4 input.obj output.obj stepsize niterations";
    return 0;
  }
  
  //sets up vertices and triangles to be populated by .obj file
  char * fileName = argv[1];
	vector<Eigen::Vector3d> vertices;
	vector<Tri> triangles;
	vector<Eigen::Vector3d> laplacians;
  vector<double> m;
 
  //exits program if inputfile.obj cannot be read
  if (!readObjFile(fileName, vertices, triangles)) {
    cout << "Invalid file, please try again" << endl;
    return 0;
  }
  
  int stepsize = stoi(argv[3]);
  int niterations = stoi(argv[4]);
  
  //loops through, updating each vector position based on the laplacians generated for niterations
  for (int i=0; i < niterations; i++) {
    
    //sets m and laplacian values to 0 for each vertex
    for (int v=0; v < (int) vertices.size(); v++) {
      Vector3d new_laplacian(0,0,0);
      laplacians.push_back(new_laplacian);
      m.push_back(0);
    }
    
    //updates laplacian and m values for the vertices that make up in each triangle
    for (int t=0; t < (int) triangles.size(); t++) {
      laplacians[(triangles[t])[0]] += vertices[(triangles[t])[1]] + vertices[(triangles[t])[2]];
      m[(triangles[t])[0]] += 2;
      laplacians[(triangles[t])[1]] += vertices[(triangles[t])[0]] + vertices[(triangles[t])[2]];
      m[(triangles[t])[1]] += 2;
      laplacians[(triangles[t])[2]] += vertices[(triangles[t])[0]] + vertices[(triangles[t])[1]];
      m[(triangles[t])[2]] += 2;
    }
    
    //updates vertex positions based on laplacian values
    for(int v=0; v < (int) vertices.size(); v++) {
      if (m[v]!=0)
        laplacians[v] /= m[v];
      vertices[v] += stepsize * (laplacians[v] - vertices[v]); 
    }
    
    //resets laplacian and m vectors
    laplacians.clear();
    m.clear();
  }
  
  //writes updated vertex positions to new obj file
  writeObjFile(argv[2], vertices, triangles); 
}