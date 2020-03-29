import numpy as np
import matplotlib.pyplot as plt
import matplotlib.gridspec as gridspec
from scipy.interpolate import interp1d
#from scipy.interpolate import interp1d
import scipy.optimize
import math

plt.style.use('seaborn-whitegrid')
plt.rc('font', family='serif')

fdati = 'collatz.dat'
fdati_orb = 'orbits.dat'

x=np.genfromtxt(fdati,comments="#", usecols=(0), dtype=None, unpack=True,encoding=None)
y=np.genfromtxt(fdati,comments="#", usecols=(1), dtype=None, unpack=True)

x_1 = np.genfromtxt(fdati_orb,comments="#", usecols=(0), dtype=None, unpack=True,encoding=None)
y_1 = np.genfromtxt(fdati_orb,comments="#", usecols=(1), dtype=None, unpack=True)

number = y_1[0]

def spline(input,array,order):  #spline cubica

    spl = interp1d(input,array,kind='cubic')
    ret = spl(input)
    return ret


plt.title("Collatz total stopping time")
plt.plot(x,y,marker='.',color='darkred',linestyle='')
plt.xlabel("number")
plt.ylabel("# iterations")
plt.show()

plt.hist(y,450, color='darkred')
plt.title("Histogram for the iterations")
plt.xlabel("number of iterations")
plt.ylabel("frequency")
plt.show()

plt.plot(x_1,y_1,color='k',linestyle='',marker='.')
plt.plot(x_1,spline(x_1,y_1,3), color='gray')
plt.title("Orbit of "+str(number))
plt.xlabel("Step numbers")
plt.ylabel("Collatz step")
plt.show()
