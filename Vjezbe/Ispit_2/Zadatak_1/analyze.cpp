#include<Analyzer.h>
int main()
{
  Analyzer* analyzer = new Analyzer();
  float a, b, c;
  a = 5;
  b = 4;
  c = 3;
  analyzer->Evolume(a, b, c);
  analyzer->~Analyzer();
  return 0;
}
