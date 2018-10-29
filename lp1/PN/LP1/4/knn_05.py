import matplotlib.pyplot as plt
import math
import sys

#using points: is a dictionary of lists of point belonging to region 0 and 1
#using p: the point entered by the user
#using k=3 : as default nearest number of neighbours

#func - clissify the points using euclidean distances
def classify(points,p,k=3):
	dist = []
	for i in points:
		for j in points[i]:
			e_dist = math.sqrt((j[0]-p[0])**2 + (j[1]-p[1])**2)
			dist.append((e_dist,i))
			
	dist = sorted(dist)[:k]
	
	#declaring two regions of points and initialising to zero
	region_1=0
	region_2=0
	
	#dividing points into regions
	for x in dist:
		if x[1]==0:
			region_1 = region_1 + 1
		elif x[1]==1:
			region_2 = region_2 + 1
			
	return 1 if region_1>region_2 else 2
	

#func - main 
def main():
	points_1 = [(1,12),(2,5),(3,6),(3,10),(3.5,8),(2,11),(2,9),(1,7),(1,2)]
	points_2 = [(5,3),(3,2),(1.5,9),(7,2),(6,1),(3.8,1),(5.6,4),(4,2),(2,5)]
	points = {0:[(1,12),(2,5),(3,6),(3,10),(3.5,8),(2,11),(2,9),(1,7),(1,2)],1:[(5,3),(3,2),(1.5,9),(7,2),(6,1),(3.8,1),(5.6,4),(4,2),(2,5)]}
	
	#region 1 points
	X1=[]
	Y1=[]
	for i in points_1:
		X1.append(i[0])
	for j in points_1:
		Y1.append(j[1])
			
	print X1
	print Y1
	
	#region 2 points
	X2=[]
	Y2=[]
	for i in points_2:
		X2.append(i[0])
	for j in points_2:
		Y2.append(j[1])
			
	print X2
	print Y2
	
	#get input from the user
	x=raw_input('Enter the  x coordinate of the point: ')
	y=raw_input('Enter the  y coordinate of the point: ')
	
	#type cast
	x= float(x)
	y= float(y)
	
	p=(x,y)
	k=3 #predefined
	print 'The point',p,'belongs to region:',classify(points,p,k)
	
	#plot points
	plt.scatter(X1,Y1)
	plt.scatter(X2,Y2)
	plt.plot(x,y,'g^')
	plt.show()
	
if __name__ == '__main__':
	main()
