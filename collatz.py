import matplotlib.pyplot as plt
import scipy.optimize as op
import emcee
import corner
import numpy as np

plt.style.use('seaborn-whitegrid')
plt.rc('font', family='serif')

fdati = 'collatz.dat'

x=np.genfromtxt(fdati,comments="#", usecols=(0), dtype=None, unpack=True,encoding=None)
y=np.genfromtxt(fdati,comments="#", usecols=(1), dtype=None, unpack=True)

plt.title("Iterations for Collatz orbits")
plt.plot(x,y,marker='.',color='darkred',linestyle='')
plt.xlabel("number")
plt.ylabel("# iterations")
plt.show()
