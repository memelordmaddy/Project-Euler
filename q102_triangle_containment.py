# take 1000 line of 3 points per line, and determine how many triangles contain the origin
f = open('triangles.txt', 'r')
count=0
for line in f:
    points = [int(x) for x in line.strip().split(',')]
    a=(points[0],points[1])
    b=(points[2],points[3])
    c=(points[4],points[5])
    if a[0]*b[1]-a[1]*b[0]==0 or b[0]*c[1]-b[1]*c[0]==0 or c[0]*a[1]-c[1]*a[0]==0:
        continue
    no_intersections=0
    if (a[0]*b[1]-b[0]*a[1])*(b[1]-a[1])>0 and max(a[1],b[1])>0 and min(a[1],b[1])<0:
        no_intersections+=1
    if (b[0]*c[1]-c[0]*b[1])*(c[1]-b[1])>0 and max(b[1],c[1])>0 and min(b[1],c[1])<0:
        no_intersections+=1
    if (c[0]*a[1]-a[0]*c[1])*(a[1]-c[1])>0 and max(c[1],a[1])>0 and min(c[1],a[1])<0:
        no_intersections+=1
    if(no_intersections%2==1):
        count+=1
print(count)
