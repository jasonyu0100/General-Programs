#!!!!!!!!!!!!!!
import svgwrite
dwg = svgwrite.Drawing('BOX.svg', size=('600mm', '450mm'), viewBox=('0 0 600 450'))
rlines = dwg.add(dwg.g(stroke='red',stroke_width = 1))#STROKEWIDTH 0.01
#!!!!!!!!!!!!!!

#TEMPORARY INPUTS WHEN DOING ACTUAL THING USE inputs.
width = 100
length = 150
height = 80
thickness = 3
basetenons = 1
cornertenons = 1
offset = 0
viewbox = ('600','450')
basejoint = basetenons + 2
cornerjoint = cornertenons + 2
l = length/basejoint
w = width/basejoint
h = height/cornerjoint
X = 600
Y = 450
VX = X/2
VY = Y/2
BX = VX - width/2
BY = VY - length/2
UX = BX
UY = BY - 10
DX = BX
DY = BY + length + 10
LX = BX - 10
LY = BY
RX = BX + width + 10
RY = BY
def base(w,BY,BX,thickness):
    for i in range(basejoint):
        if (i+1)%2 == 0:
            
        rlines.add(dwg.line(start=(BX,BY),end=(BX+w,BY)))
        rlines.add(dwg.line(start=(BX+w,BY),end=(BX+w,BY+thickness)))
        BX = BX + w
base(w,BY,BX,thickness)
dwg.save()
    

