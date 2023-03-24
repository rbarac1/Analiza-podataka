#include<Analyzer.h>

Analyzer::Analyzer()
{

}

Analyzer::~Analyzer()
{

}

void Analyzer::Evolume(float a, float b, float c)
{
  sum = 0;

  srand((unsigned)time(NULL));  //seed za nasumične brojeve da ne budu uvijek isti

  for(i=0; i<1000000; i++){
    x = (float)rand()/RAND_MAX * a; //obuhvaćam samo kvadrant gdje su a,b,c>0 jer je svejedno zbog simetrije
    y = (float)rand()/RAND_MAX * b;
    z = (float)rand()/RAND_MAX * c;

    if((x/a)*(x/a)+(y/b)*(y/b)+(z/c)*(z/c)<1){
      sum++;
    }
  }

  V = 8*a*b*c*(float)sum/i; //volumen kvadra bridova 2a, 2b, 2c pomnožen sa brojem nasumičnih brojeva koji upadaju u upisani elipsoid
  
  cout << "Generirano je " << i << " nasumičnih točaka." << endl;

  cout << "MC volumen elipsoida je " << V << endl;
  cout << "Analitički volumen elipsoida je " << 4./3.*3.14159*a*b*c << endl;


}
