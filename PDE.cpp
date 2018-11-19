#include <iostream>
#include <cmath>
using std::cout;

float pos[51][51];//para cada borde con una interseccion en todo el centro de la varilla
float posfuturo[51][51];
void futuro(float fut, float v,  float xmenos, float xmas,float x, float ymenos,float ymas, float dt);



int main()
{
float d=10;//diametro o 10 cuadrados
float cp=820.0;//C_p
float k=1.62;//conductividad termica
float p=2.71;//densidad
float v=k/(cp*p);//coeficiente de difusion,constante
float T=100.0;//temperatura=cte
float dt=0.001;
float dx=1.0;
float dy=1.0;//iguales a 1 porque ada posicion es de un centimetro


//condicion que utilizaremos ya que la varilla se mantiene a 100 grados
for (int i=0;i<51;i++)
	{
	for (int j=0;j<51;j++)
		{
		if (pow((pow((i-26),2)+pow((j-26),2)),0.5)<=10)//condicion de circulo alrededor del centro (26,26)
			{
			pos[i][j]=T;
			}
		}
	}
//codigo para imprimir todo el array
//for (int i=0;i<51;i++)
//
//	{
//	for (int j=0;j<51;j++)
//		{
//		cout<<pos[i][j]<<" ";
//		}
//	cout<<"\n";
//	}


////////////////////bordes a 10 grados
/////////////////////////////////////////////////////////////////////////////////////
for (int i=0;i<51;i++)
	{
	for (int j=0;j<51;j++)
		{
		if ((i==0 or i==50) or (j==0 or j==50))
			{
			pos[i][j]=10.0;
			}
		if((i!=0 and i!=50) and (j!=0 and j!=50))
			{
			pos[i][j]=0.0;
			}
		}
	}
/////////////////////////////////////////////////////////////////////////////////////
///////codigo para 1000 pasos de la condicion 1
for(int k=0;k<2;k++)
	{
	for (int i=0;i<51;i++)//hace el cambio de posiciones reiterando las condiciones de frontera y de la varilla
		{
		for (int j=0;j<51;j++)
			{
			if (pow((pow((i-26),2)+pow((j-26),2)),0.5)<=10)//condicion de circulo alrededor del centro (26,26)
				{
				pos[i][j]=T;
				posfuturo[i][j]=T;
				}
			if ((i==0 or i==50) or (j==0 or j==50))//condicion de 10C en los bordes
				{
				pos[i][j]=10.0;
				posfuturo[i][j]=10.0;
				}
			if((i!=0 and i!=50) and (j!=0 and j!=50))//hace paso
				{
				futuro(posfuturo[i][j],v,pos[i-1][j],pos[i+1][j],pos[i][j],pos[i][j-1],pos[i][j+1],dt);
				}
			
			}
		} 
	
	for (int i=0;i<51;i++)//recurrencia devuelve posicion para el siguiente paso
		{
		for (int j=0;j<51;j++)
			{
			if ((i==0 or i==50) or (j==0 or j==50))
				{
				pos[i][j]=posfuturo[i][j];
				}
			if((i!=0 or i!=50) or (j!=0 or j!=50))
				{
				pos[i][j]=posfuturo[i][j];
				}
			}
		}
	}//Acaba los pasos que recorre k)
for (int i=0;i<51;i++)//imprime el ultimo paso
	{
	for (int j=0;j<51;j++)
		{
		cout<<posfuturo[i][j]<<" ";
		}
	cout<<"\n";
	}

//////////////////////////////////////////////////////////Acaba codigo para condicion 1 imprimiendo el array despues de los pasos de k

///////condicion 2
////////////////////bordes abiertos
//para cada paso ya no se fijan los bordes en 10 grados pero la varilla si se pone a 100 grados siempre
for(int k=0;k<1000;k++)
	{

	for (int i=0;i<51;i++)
		for (int i=0;i<51;i++)
		{
		for (int j=0;j<51;j++)
			{
			if (pow((pow((i-26),2)+pow((j-26),2)),0.5)<=10)//condicion de circulo alrededor del centro (26,26)	
				{
				pos[i][j]=T;
				}
			if((i!=0 and i!=50) and (j!=0 and j!=50))
				{					
				futuro(posfuturo[i][j],v,pos[i-1][j],pos[i+1][j],pos[i][j],pos[i][j-1],pos[i][j+1],dt);
				}
				//cout<<pos[i][j]<<" ";
			}
			//cout<<"\n";
		} 
	
	for (int i=0;i<51;i++)//recurrencia devuelve posicion para el siguiente paso
		{
		for (int j=0;j<51;j++)
			{
			if ((i==0 or i==50) or (j==0 or j==50))
				{
				pos[i][j]=posfuturo[i][j];
				}
			if((i!=0 or i!=50) or (j!=0 or j!=50))
				{
				pos[i][j]=posfuturo[i][j];
				}
			}
		}
	}//acaba recorrido sobre k

for (int i=0;i<51;i++)//imprime ultimo paso
	{
	for (int j=0;j<51;j++)
		{
		cout<<posfuturo[i][j]<<" ";
		}
	cout<<"\n";
	}

/////////Se imprime el final despues de k pasos


	
///////condicion 3
////////////////////fronteras periodicas

//for (int i=0;i<51;i++)
//	{
//	for (int j=0;j<51;j++)
//		{
//		if ((i==0 or i==50) and (j==00 or j==50) )//condicion de circulo alrededor del centro (26,26)
//			{
//			pos[i][j]=10.0;
//			}
//		}
//	}


return 0;
}

void futuro(float fut, float v, float xmenos, float xmas,float x, float ymenos,float ymas, float dt)
{
fut=((v*(xmas-(2*x)+xmenos+ymas-(2*x)+ymenos))*dt);
}

	

//xmas, posicion al lado
//xmenos, al otro lado
//ymas, arriba
//ymenos, abajo
//x es el punto
//v constante
//fut, es el proximo valor de T para el punto
























