import numpy as np
import matplotlib.pylab as plt
from mpl_toolkits import mplot3d

datos=np.genfromtxt("datsODE.txt",skip_footer=102)
x=datos[:,2]
y=datos[:,3]

datos2=np.genfromtxt("datsODE.txt",skip_header=39992,skip_footer=51)
#print datos2

datos3=np.genfromtxt("datsODE.txt",skip_header=(39992+51))
#print datos3

xx=np.linspace(0,50,51)
yy=np.linspace(0,50,51)
X, Y = np.meshgrid(xx, yy)


plt.plot(x,y)
plt.ylabel("posicion y")
plt.xlabel("posicion x")
plt.savefig("grafsODE.pdf")


fig = plt.figure()
ax2 = plt.axes(projection='3d')
ax2.contour3D(X,Y,datos2)
ax2.set_xlabel('x')
ax2.set_ylabel('y')
ax2.set_zlabel('temperatura(C)');
fig.savefig("3d2.pdf")

fig2 = plt.figure()
ax3 = plt.axes(projection='3d')
ax3.contour3D(X,Y,datos3)
ax3.set_xlabel('x')
ax3.set_ylabel('y')
ax3.set_zlabel('temperatura(C)');
fig2.savefig("3d3.pdf")

