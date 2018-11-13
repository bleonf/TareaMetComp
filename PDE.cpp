#include <iostream>
using std::cout;


//varilla de 0.5*0.5
int main()
{
float d=0.1;//diametro
float cp=820.0;//C_p
float k=1.62;//conductividad termica
float p=2.71;//densidad
float v=k/(cp*p);//coeficiente de difusion
float T=100;//temperatura=cte

return 0;
}
