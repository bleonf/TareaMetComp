import numpy as np
import matplotlib.pylab as plt
from mpl_toolkits import mplot3d

datos=np.genfromtxt("datsODE.txt",skip_footer=459,usecols=(0,1,2,3,4))
x=datos[:,2]
y=datos[:,3]
t=datos[:,4]

datos2=np.genfromtxt("datsODE.txt",skip_header=39992,skip_footer=408)


datos3=np.genfromtxt("datsODE.txt",skip_header=(39992+51),skip_footer=357)


datos4=np.genfromtxt("datsODE.txt",skip_header=(39992+102),skip_footer=306)


datos5=np.genfromtxt("datsODE.txt",skip_header=(39992+153),skip_footer=255)


datos6=np.genfromtxt("datsODE.txt",skip_header=(39992+204),skip_footer=204)


datos7=np.genfromtxt("datsODE.txt",skip_header=(39992+255),skip_footer=153)


datos8=np.genfromtxt("datsODE.txt",skip_header=(39992+306),skip_footer=102)


datos9=np.genfromtxt("datsODE.txt",skip_header=(39992+357),skip_footer=51)


datos10=np.genfromtxt("datsODE.txt",skip_header=(39992+408))






xx=np.linspace(0,50,51)
yy=np.linspace(0,50,51)
X, Y = np.meshgrid(xx, yy)

ode=plt.figure()
plt.plot(x[0:4999],y[0:4999],c="red")
plt.plot(x[4999:9998],y[4999:9998],c="blue")
plt.plot(x[9998:14997],y[9998:14997],c="black")
plt.plot(x[14997:19996],y[14997:19996],c="green")
plt.plot(x[19996:24995],y[19996:24995],c="yellow")
plt.plot(x[25995:29994],y[25995:29994],c="brown")
plt.plt(x[29994:34993],y[29994:34993],c="orange")
plt.plot(x[34993:39992],y[34993:39992],c="purple")

plt.ylabel("posicion y")
plt.xlabel("posicion x")
ode.savefig("grafsODE.pdf")
ode.show()

ode2=plt.figure()
plt.plot(t[0:4999],x[0:4999],c="red")
plt.plot(t[4999:9998],x[4999:9998],c="blue")
plt.plot(t[9998:14997],x[9998:14997],c="black")
plt.plot(t[14997:19996],x[14997:19996],c="green")
plt.plot(t[19996:24995],x[19996:24995],c="yellow")
plt.plot(t[25995:29994],x[25995:29994],c="brown")
plt.plot(t[29994:34993],x[29994:34993],c="orange")
plt.plot(t[34993:39992],x[34993:39992],c="purple")
plt.ylabel("distancia en x")
plt.xlabel("tiempo (s)")
ode2.savefig("grafsODE2.pdf")



###################
fig = plt.figure()
ax2 = plt.axes(projection='3d')
ax2.plot_surface(X, Y, datos4, rstride=1, cstride=1,
                cmap='viridis', edgecolor='blue')
ax2.set_xlabel('x (cm)')
ax2.set_ylabel('y (cm)')
ax2.set_zlabel('temperatura(C)');
fig.savefig("3d2.pdf")
#######################
fig2 = plt.figure()
ax3 = plt.axes(projection='3d')
ax3.plot_surface(X, Y, datos2, rstride=1, cstride=1,
                cmap='viridis', edgecolor='blue')
ax3.set_xlabel('x')
ax3.set_ylabel('y')
ax3.set_zlabel('temperatura(C)');
fig2.savefig("3d3.pdf")
########################
fig3 = plt.figure()
ax4 = plt.axes(projection='3d')
ax4.plot_surface(X, Y, datos3, rstride=1, cstride=1,
                cmap='viridis', edgecolor='blue')
ax4.set_xlabel('x')
ax4.set_ylabel('y')
ax4.set_zlabel('temperatura(C)');
fig3.savefig("3d4.pdf")
########################
fig4 = plt.figure()
ax5 = plt.axes(projection='3d')
ax5.plot_surface(X, Y, datos7, rstride=1, cstride=1,
                cmap='viridis', edgecolor='black')
ax5.set_xlabel('x')
ax5.set_ylabel('y')
ax5.set_zlabel('temperatura(C)');
fig4.savefig("3d5.pdf")
########################
fig5 = plt.figure()
ax6 = plt.axes(projection='3d')
ax6.plot_surface(X, Y, datos5, rstride=1, cstride=1,
                cmap='viridis', edgecolor='black')
ax6.set_xlabel('x')
ax6.set_ylabel('y')
ax6.set_zlabel('temperatura(C)');
fig5.savefig("3d6.pdf")
########################
fig6 = plt.figure()
ax7 = plt.axes(projection='3d')
ax7.plot_surface(X, Y, datos6, rstride=1, cstride=1,
                cmap='viridis', edgecolor='black')
ax7.set_xlabel('x')
ax7.set_ylabel('y')
ax7.set_zlabel('temperatura(C)');
fig6.savefig("3d7.pdf")
########################
fig7 = plt.figure()
ax8 = plt.axes(projection='3d')
ax8.plot_surface(X, Y, datos10, rstride=1, cstride=1,
                cmap='viridis', edgecolor='red')
ax8.set_xlabel('x')
ax8.set_ylabel('y')
ax8.set_zlabel('temperatura(C)');
fig7.savefig("3d8.pdf")
########################
fig8 = plt.figure()
ax9 = plt.axes(projection='3d')
ax9.plot_surface(X, Y, datos8, rstride=1, cstride=1,
                cmap='viridis', edgecolor='red')
ax9.set_xlabel('x')
ax9.set_ylabel('y')
ax9.set_zlabel('temperatura(C)');
fig8.savefig("3d9.pdf")
########################
fig9 = plt.figure()
ax10 = plt.axes(projection='3d')
ax10.plot_surface(X, Y, datos9, rstride=1, cstride=1,
               cmap='viridis', edgecolor='red')
ax10.set_xlabel('x')
ax10.set_ylabel('y')
ax10.set_zlabel('temperatura(C)');
fig9.savefig("3d10.pdf")

