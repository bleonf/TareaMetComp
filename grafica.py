import numpy as np
import matplotlib.pylab as plt

datos=np.genfromtxt("datsODE.txt")
x=datos[:,2]
y=datos[:,3]



plt.plot(x,y)
plt.savefig("grafsODE.pdf")
