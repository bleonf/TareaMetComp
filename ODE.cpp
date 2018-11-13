#include <iostream>
#include <cmath>
using std::cout;

const float  PI_F=3.1415926;

float vel(float h, float n,float nmenos, float g);
float primerpasovelx(float angulo, float h);
float primerpasovely(float angulo, float h);
float rads(float angulo);
//ecuacion(es):
//x''=-g-c(abs(x'**2)/m)*x'/abs(x')
//igual a -g-abs(x')*x'
//x'_n=x_n+1 - x_n-1/2h=-g-(abs(x_n)*x_n)---n en tiempo
//x_n+1=x'_n(2h)+x_n-1=-g-(abs(x_n)*x_n)(2h)+x_n-1

//ecu final: x_n+1=-g-(abs(x_n)*x_n)(2h)+x_n-1

float posx[100];
float posy[100];
float velx[100];
float vely[100];
int main()
{
	float g=10.0;
	float c=0.2;
	float m=0.2;
	
	float h=0.01;
	int pasos=100;
	//tiempo final=h*pasos
	
	velx[0]=300*cos(rads(45));
	vely[0]=300*sin(rads(45));
	velx[1]=velx[0]+(-0.0-(abs(velx[0])*(velx[0])))*h;
	vely[1]=vely[0]+(-10-(abs(vely[0])*(vely[0])))*h;
	
	posx[0]=0;
	posy[0]=0;
	
	for(int i=2;i<pasos;i++)
		{
		velx[i]=vel(h,velx[i-1],velx[i-2],0.0);
		vely[i]=vel(h,vely[i-1],vely[i-2],g);
		posx[i-1]=posx[i-2]+velx[i-1];
		posy[i-1]=posy[i-2]+vely[i-1];
		//cout<<velx[i-1]<<" "<<vely[i-1]<<" "<<posx[i]<<" "<<posy[i]<<"\n";
		}
		cout<<velx[1]<<"\n";
		cout<<vely[1];
	
	
	
	
	return 0;
}

float vel(float h, float n,float nmenos, float g)//para x g=0, para y g=10
{//devuelve x_n+1
	return (-1.0*(abs(n)*n)*2.0*h)+nmenos-g;
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










