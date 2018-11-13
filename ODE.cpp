#include <iostream>
#include <cmath>
using std::cout;

const float  PI_F=3.1415926;

float vel(float h, float n,float vel,float nmenos, float g);
float primerpasovelx(float angulo, float h);
float primerpasovely(float angulo, float h);
float rads(float angulo);
//ecuacion(es):
//x''=-g-c(abs(x'**2)/m)*x'/abs(x')
//igual a -g-abs(x')*x'
//x'_n=x_n+1 - x_n-1/2h=-g-(abs(x_n)*x_n)---n en tiempo
//x_n+1=x'_n(2h)+x_n-1=-g-(abs(x_n)*x_n)(2h)+x_n-1

//ecu final: x_n+1=-g-(abs(x_n)*x_n)(2h)+x_n-1

float posx[50000];
float posy[50000];
float velx[50000];
float vely[50000];
int main()
{
	float g=10.0;
	float c=0.2;
	float m=0.2;
	
	float h=0.00001;
	int pasos=50000;
	//tiempo final=h*pasos
	
	velx[0]=300*cos(rads(45));
	vely[0]=300*sin(rads(45));
	velx[1]=velx[0]+((-0.0-(abs(velx[0])*(velx[0])))*h);
	vely[1]=vely[0]+((-10-(abs(vely[0])*(vely[0])))*h);
	
	posx[0]=0;
	posy[0]=0;
	cout<<velx[0]<<" "<<vely[0]<<" "<<posx[1]<<" "<<posy[1]<<"\n";
	for(int i=2;i<pasos;i++)
		{
		velx[i]=vel(h,velx[i-1],pow(((velx[i-1]*velx[i-1])+(vely[i-1]*vely[i-1])),0.5),velx[i-2],0.0);
		vely[i]=vel(h,vely[i-1],pow(((velx[i-1]*velx[i-1])+(vely[i-1]*vely[i-1])),0.5),vely[i-2],g);
		posx[i-1]=posx[i-2]+(velx[i-2]*h);
		posy[i-1]=posy[i-2]+(vely[i-2]*h);
		cout<<velx[i-1]<<" "<<vely[i-1]<<" "<<posx[i-2]<<" "<<posy[i-2]<<"\n";
		}
		
		
	
	
	
	
	return 0;
}

float vel(float h, float n,float vel, float nmenos, float g)//para x g=0, para y g=10
{//devuelve x_n+1
	return (-1.0*(abs(vel)*n)*2.0*h)+nmenos-(g*h);
}
float primerpasovelx(float angulo, float h)
{
	return h*300*cos(angulo*PI_F/180.0);
}
float primerpasovely(float angulo, float h)
{
	return h*300*sin(angulo*PI_F/180.0);
}

float rads(float angulo)
{
	return (angulo*PI_F)/180.0;
}










