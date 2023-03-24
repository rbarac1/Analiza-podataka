// C++
#include <iostream>
#include <fstream>

// My own class
#include <Analyzer.h>

using namespace std;

int main()
{
  Analyzer* analyzer = new Analyzer();

  analyzer->Htest();

  delete analyzer;

  return 0;
}
