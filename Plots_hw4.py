import numpy as np
import matplotlib.pylab as plt
from mpl_toolkits import mplot3d

datos=np.genfromtxt("datsODE.txt",skip_footer=153)
x=datos[:,2]
y=datos[:,3]
t=datos[:,4]

datos2=np.genfromtxt("datsODE.txt",skip_header=39992,skip_footer=102)
print datos2

datos3=np.genfromtxt("datsODE.txt",skip_header=(39992+51),skip_footer=51)
print datos3

datos4=np.genfromtxt("datsODE.txt",skip_header=(39992+102))
print datos4



xx=np.linspace(0,50,51)
yy=np.linspace(0,50,51)
X, Y = np.meshgrid(xx, yy)

ode=plt.figure()
plt.plot(x,y)
plt.ylabel("posicion y")
plt.xlabel("posicion x")
ode.savefig("grafsODE.pdf")

ode2=plt.figure()
plt.plot(t,x)
plt.ylabel("distancia en x")
plt.xlabel("tiempo (s)")
ode2.savefig("grafsODE2.pdf")




fig = plt.figure()
ax2 = plt.axes(projection='3d')
ax2.plot_surface(X, Y, datos2, rstride=1, cstride=1,
                cmap='viridis', edgecolor='blue')
ax2.set_xlabel('x (cm)')
ax2.set_ylabel('y (cm)')
ax2.set_zlabel('temperatura(C)');
fig.savefig("3d2.pdf")

fig2 = plt.figure()
ax3 = plt.axes(projection='3d')
ax3.plot_surface(X, Y, datos3, rstride=1, cstride=1,
                cmap='viridis', edgecolor='black')
ax3.set_xlabel('x')
ax3.set_ylabel('y')
ax3.set_zlabel('temperatura(C)');
fig2.savefig("3d3.pdf")

fig3 = plt.figure()
ax4 = plt.axes(projection='3d')
ax4.plot_surface(X, Y, datos3, rstride=1, cstride=1,
                cmap='viridis', edgecolor='green')
ax4.set_xlabel('x')
ax4.set_ylabel('y')
ax4.set_zlabel('temperatura(C)');
fig2.savefig("3d4.pdf")

