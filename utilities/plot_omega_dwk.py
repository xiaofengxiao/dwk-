#!/usr/bin/env python


from sys import argv

if (len(argv)<2):
	print('The default data file is omega_dwk.out')
	filename='omega_dwk.out'
else:
	filename=argv[1]

print 'read file', filename
omegadwkfile	=open(filename)
omegadwk	=omegadwkfile.readlines()
num	=len(omegadwk)	
import numpy

returnMat = numpy.zeros((num,4))
index	=	0
for line in omegadwk:
	line	=	line.strip()
	linelist=	line.split()
	returnMat[index,:]	=linelist[0:4]
	index	+=1
#print returnMat
	
import matplotlib.pyplot as plt
import matplotlib
from matplotlib.pyplot import rc, figure, axes, plot, xlabel, ylabel, title,\
	grid, savefig, show

omegar	=	returnMat[:,0]
omegai	=	returnMat[:,1]
dwkr	=	returnMat[:,2]
dwki	=	returnMat[:,3]

plt.plot(omegar,dwkr)
plt.show()

