import math
import sys
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

eaee=0.0
cnt=0
for i in range(n):
	if refx[i]==0 and x[i]==0 and refy[i]==0 and y[i]==0:
		cnt+=1
		continue
	sqrt = float( ((refx[i]-x[i])*(refx[i]-x[i])) + (refy[i]-y[i])*(refy[i]-y[i]) )
	sqrt = sqrt**(0.5)
	eaee += sqrt
if cnt!=n:
	eaee/=(n-cnt);
print cnt
print eaee

"""
mx=0.0
my=0.0
mrx=0.0
mry=0.0

for i in range(n):
	mx+=x[i]
	my+=y[i]
	mrx+=refx[i];
	mry+=refy[i];

mx=float(mx/n);
my=float(my/n);
mrx=float(mrx/n);
mry=float(mry/n);

n1=0.0
for i in range(n):
	sqrt = float( (refx[i]-mrx)*(refx[i]-mrx) + (refy[i]-mry)*(refy[i]-mry) )
	sqrt = sqrt**(0.5)
	n1 += sqrt

n2=0.0
for i in range(n):
	sqrt = float( (x[i]-mx)*(x[i]-mx) + (y[i]-my)*(y[i]-my) )
	sqrt = sqrt**(0.5)
	n2 += sqrt

eaee=0.0
for i in range(n):

	sq = float( ( (refx[i]-mrx)/n1 - (x[i]-mx)/n2 )*( (refx[i]-mrx)/n1 - (x[i]-mx)/n2 ) + ( (refy[i]-mry)/n1 - (y[i]-my)/n2 )*( (refy[i]-mry)/n1 - (y[i]-my)/n2 )  )
	sq = sq**(0.5)
	eaee += sqrt

print eaee
"""

"""

eaee=0.0
for i in range(n):
	sqrt = float( ((refx[i]-x[i])*(refx[i]-x[i])) + (refy[i]-y[i])*(refy[i]-y[i]) )
	sqrt = sqrt**(0.5)
	eaee += sqrt
eaee/=n;
print eaee
"""
