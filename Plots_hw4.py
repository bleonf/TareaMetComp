import numpy as np
import matplotlib.pylab as plt

datos=np.genfromtxt("datsODE.txt",skip_footer=51)
x=datos[:,2]
y=datos[:,3]

datos2=np.genfromtxt("datsODE.txt",skip_header=39992)
print datos2



plt.plot(x,y)
plt.ylabel("posicion y")
plt.xlabel("posicon x")
plt.savefig("grafsODE.pdf")
