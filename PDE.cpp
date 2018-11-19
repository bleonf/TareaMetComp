#include <iostream>
using std::cout;

float pos[51][51];//para cada borde con una interseccion en todo el centro de la varilla

//varilla de 0.5*0.5
int main()
{
float d=0.1;//diametro o 10 cuadrados
float cp=820.0;//C_p
float k=1.62;//conductividad termica
float p=2.71;//densidad
float v=k/(cp*p);//coeficiente de difusion
float T=100.0;//temperatura=cte


//condicion que utilizaremos ya que la varilla se mantiene a 100 grados
for (int i=0;i<51;i++)
	{
	for (int j=0;j<51;j++)
		{
		if (pow((pow((i-26),2)+pow((j-26),2)),0.5)<10)
			{
			pos[i][j]=T;
			}
		}
	}

return 0;
}
