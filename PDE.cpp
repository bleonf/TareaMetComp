#include <iostream>
#include <cmath>
using std::cout;
const float  PI_F=3.1415926;
float pos[51][51];//para cada borde con una interseccion en todo el centro de la varilla
float posfuturo[51][51];
float futuro(float fut, float v,  float xmenos, float xmas,float x, float ymenos,float ymas, float dt);



int main()
{
float d=10;//diametro o 10 cuadrados
float cp=820.0;//C_p
float k=1.62;//conductividad termica
float p=2.71;//densidad
float v=0.0001;//coeficiente de difusion,constante
float T=100.0;//temperatura=cte
float dt=0.5;
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
		else
			{
			pos[i][j]=10;
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
			pos[i][j]=10.0;
			}
		}
	}
/////////////////////////////////////////////////////////////////////////////////////
///////codigo para 10000 pasos de la condicion 1
for(int k=0;k<10000;k++)
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
				//posfuturo[i][j]=pos[i][j]+2;
				posfuturo[i][j]=futuro(pos[i][j],v,pos[i-1][j],pos[i+1][j],pos[i][j],pos[i][j-1],pos[i][j+1],dt);
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
	if (k==100 or k==1500)//imprime 2 pasos intermedios
	{
		for (int l=0;l<51;l++)
		{
			for (int m=0;m<51;m++)
			{
			cout<<posfuturo[l][m]<<" ";
			}
		cout<<"\n";
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
for (int i=0;i<51;i++)
	{
	for (int j=0;j<51;j++)
		{
		if (pow((pow((i-26),2)+pow((j-26),2)),0.5)<=10)//condicion de circulo alrededor del centro (26,26)
			{
			pos[i][j]=T;
			}
		else
			{
			pos[i][j]=10;
			}
		}
	}
//para cada paso ya no se fijan los bordes en 10 grados pero la varilla si se pone a 100 grados siempre
for(int k=0;k<10000;k++)
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
				//futuro(posfuturo[i][j],v,pos[i-1][j],pos[i+1][j],pos[i][j],pos[i][j-1],pos[i][j+1],dt);
				posfuturo[i][j]=futuro(pos[i][j],v,pos[i-1][j],pos[i+1][j],pos[i][j],pos[i][j-1],pos[i][j+1],dt);
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
	if (k==100 or k==1500)//imprime dos pasos intermedios
	{
		for (int l=0;l<51;l++)
		{
			for (int m=0;m<51;m++)
			{
			cout<<posfuturo[l][m]<<" ";
			}
		cout<<"\n";
		}
	}

	}//acaba recorrido sobre k

for (int l=0;l<51;l++)//imprime ultimo paso
	{
	for (int m=0;m<51;m++)
		{
		cout<<posfuturo[l][m]<<" ";
		}
	cout<<"\n";
	}

/////////Se imprime el final despues de k pasos


	
///////condicion 3
////////////////////fronteras periodicas

for (int i=0;i<51;i++)
	{
	for (int j=0;j<51;j++)
		{
		if (pow((pow((i-26),2)+pow((j-26),2)),0.5)<=10)//condicion de circulo alrededor del centro (26,26)
			{
			pos[i][j]=T;
			}
		else
			{
			pos[i][j]=10;//asumimos que todo el resto empieza en 10 grados
			}
		}
	}
for(int k=0;k<10000;k++)
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
			if ((i==0 or i==50) or (j==0 or j==50))//condicion periodica
				{
				pos[i][j]=sin(((k % 200)/200.0)*6.28)*25.0;//frontera sinusoidal, frec 200 pasos(100 segundos) de amplitud 25.0
				posfuturo[i][j]=sin((((k+1) % 200)/200.0)*6.28)*25.0;//frontera sinusoidal, frec 200 pasos(100 segundos) de amplitud 25.0
				}
			if((i!=0 and i!=50) and (j!=0 and j!=50))
				{					
				//futuro(posfuturo[i][j],v,pos[i-1][j],pos[i+1][j],pos[i][j],pos[i][j-1],pos[i][j+1],dt);
				posfuturo[i][j]=futuro(pos[i][j],v,pos[i-1][j],pos[i+1][j],pos[i][j],pos[i][j-1],pos[i][j+1],dt);
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
	if (k==100 or k==1500)//imprime dos pasos intermedios
	{
		for (int l=0;l<51;l++)
		{
			for (int m=0;m<51;m++)
			{
			cout<<posfuturo[l][m]<<" ";
			}
		cout<<"\n";
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

return 0;
}

float futuro(float fut, float v, float xmenos, float xmas,float x, float ymenos,float ymas, float dt)
{
return x+((v*dt*(xmas-(2*x)+xmenos+ymas-(2*x)+ymenos)));
//return fut+1;
}

	

//xmas, posicion al lado
//xmenos, al otro lado
//ymas, arriba
//ymenos, abajo
//x es el punto
//v constante
//fut, es el proximo valor de T para el punto
























