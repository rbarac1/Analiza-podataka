//C++ libraries
#include <vector>
#include <time.h>
#include <iostream>

using namespace std;

class Analyzer
{
  public:
    Analyzer();
    ~Analyzer();
    void Evolume(float a, float b, float c);

  private:
    float x, y, z, V;
    int i, sum;
};
