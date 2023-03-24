#include<Analyzer.h>
int main()
{
  Analyzer* analyzer = new Analyzer();
  float a, b, c;
  a = 7,1;
  b = 5,4;
  c = 3.01;
  analyzer->Evolume(a, b, c);
  analyzer->~Analyzer();
  return 0;
}
