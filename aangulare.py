import math
import sys
import numpy as np
file_refx='/home/sahithi_rvs/sem5/honors/optical_flow/OpticalFlowCode/uknowitsfinal/alpha_beta_profile/trash/flowx.txt'
file_refy='/home/sahithi_rvs/sem5/honors/optical_flow/OpticalFlowCode/uknowitsfinal/alpha_beta_profile/trash/flowy.txt'
file_x='/home/sahithi_rvs/sem5/honors/optical_flow/OpticalFlowCode/uknowitsfinal/alpha_beta_profile/trash/pre_flowx.txt'
file_y='/home/sahithi_rvs/sem5/honors/optical_flow/OpticalFlowCode/uknowitsfinal/alpha_beta_profile/trash/pre_flowy.txt'

if len(sys.argv) == 5:
	file_refx=sys.argv[1]
	file_refy=sys.argv[2]
	file_x=sys.argv[3]
	file_y=sys.argv[4]

refx = [float(line.rstrip('\n')) for line in open(file_refx)]
refy = [float(line.rstrip('\n')) for line in open(file_refy)]
x = [float(line.rstrip('\n')) for line in open(file_x)]
y = [float(line.rstrip('\n')) for line in open(file_y)]

n = len(refx)
print n
print len(x)
eaae=0.0
cnt=0
for i in range(n):
	denom = float( 1+ refx[i]*refx[i] + refy[i]*refy[i] )*float( 1+ x[i]*x[i] + y[i]*y[i] )
	if refx[i]==0 and x[i]==0 and refy[i]==0 and y[i]==0:
		cnt+=1
		continue
	ac = float(1+ refx[i]*x[i] + refy[i]*y[i]  )/float( denom**(0.5) )
	if ac>1.000000 or ac < -1.00000000:
		pass
	else:
		eaae += abs( math.acos(ac)  )
	#print denom
	#print ac
print cnt
if n!=cnt:
	eaae/=(n-cnt);
print eaae
"""
def unit_vector(vector):
    
    a=np.linalg.norm(vector)
    if a > 0
    return vector / np.linalg.norm(vector)


for i in range(n):
	v1 = (refx[i], refy[i])
	v2 = (x[i], y[i])
	v1_u = unit_vector(v1)
	v2_u = unit_vector(v2)
	theta = np.arccos(np.clip(np.dot(v1_u, v2_u), -1.0, 1.0))
	eaae += abs(theta)
eaae/=n;
print eaae
"""
