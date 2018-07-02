import svgwrite
width = float(input('Enter width of box: '))
length = float(input('Enter length of box: '))
height = float(input('Enter height of box: '))
thickness = float(input('Enter thickness of material: '))
finger = int(input('Enter number of protruding finger joints: '))
corner = int(input('Enter number of protruding corner finger joints: '))
offset = float(input('Enter the offset of the joint: '))
laser = float(input('Enter the stroke width: '))
offset = offset+0.02
cornerjoint = corner*2 + 1
joint = finger*2 + 1
a = 0
z = 0

dwg = svgwrite.Drawing(filename='test.svg')
dwg = svgwrite.Drawing('myDrawing.svg', size=('600mm', '450mm'), viewBox=('0 0 600 450'))
rlines = dwg.add(dwg.g(stroke='red',stroke_width = laser))

def base():
    x = 300-width/2
    y = 225-length/2
    for i in range(joint):
        if (i+1)%2 == 0:
            z = thickness
            a = -offset
        else:
            z = 0
            a = offset
        if i == 0:
            rlines.add(dwg.line(start=(x, y+z), end=(x+width/joint+a, y+z)))
            rlines.add(dwg.line(start=(x, y+length-z), end=(x+width/joint+a, y+length-z)))
        elif i == joint-1:
            rlines.add(dwg.line(start=(x-a, y+z), end=(x+width/joint, y+z)))
            rlines.add(dwg.line(start=(x-a, y+length-z), end=(x+width/joint, y+length-z)))
        else:
            rlines.add(dwg.line(start=(x-a, y+z), end=(x+width/joint+a, y+z)))
            rlines.add(dwg.line(start=(x-a, y+length-z), end=(x+width/joint+a, y+length-z)))
        if i != joint-1:
            rlines.add(dwg.line(start=(x+width/joint+a, y), end=(x+width/joint+a,y+thickness)))
            rlines.add(dwg.line(start=(x+width/joint+a, y+length), end=(x+width/joint+a,y+length-thickness)))
        else:
            z = 0
        x = x + width/joint
    a = 0
    z = 0
    x = 300-width/2
    y = 225-length/2
    for i in range(joint):
        if (i+1)%2 == 0:
            z = thickness
            a = offset
        else:
            z = 0
            a = -offset
        if i == 0:
            rlines.add(dwg.line(start=(x+z,y), end=(x+z, y+length/joint-a)))
            rlines.add(dwg.line(start=(x+width-z, y), end=(x+width-z, y+length/joint-a)))
        elif i == joint-1:
            rlines.add(dwg.line(start=(x+z,y+a), end=(x+z, y+length/joint)))
            rlines.add(dwg.line(start=(x+width-z, y+a), end=(x+width-z, y+length/joint)))
        else:
            rlines.add(dwg.line(start=(x+z,y+a), end=(x+z, y+length/joint-a)))
            rlines.add(dwg.line(start=(x+width-z, y+a), end=(x+width-z, y+length/joint-a)))
        if (i+1)%2 == 0:
            z = 0
        if i != joint-1:
            rlines.add(dwg.line(start=(x, y+length/joint-a), end=(x+thickness,y+length/joint-a)))
            rlines.add(dwg.line(start=(x+width, y+length/joint-a), end=(x+width-thickness,y+length/joint-a)))
        else:
            z = 0
        y = y + length/joint
base()

def sideright():
    x = 310 + width/2
    y = 225 - length/2 + thickness
    for i in range(cornerjoint):
        z = 0
        if (i+1)%2==0:
            z = thickness
        rlines.add(dwg.line(start=(x+thickness,y-z), end=(x+height/cornerjoint+thickness,y-z)))
        if i != (cornerjoint-1):
            rlines.add(dwg.line(start=(x+height/cornerjoint+thickness,y),end=(x+height/cornerjoint+thickness,y-thickness)))
        rlines.add(dwg.line(start=(x+thickness,y+length+z-2*thickness), end=(x+height/cornerjoint+thickness,y+length+z-2*thickness)))
        if i != (cornerjoint-1):
            rlines.add(dwg.line(start=(x+height/cornerjoint+thickness,y+length-2*thickness),end=(x+height/cornerjoint+thickness,y+length-thickness)))
        x = x + height/cornerjoint
    x = 310 + width/2
    rlines.add(dwg.line(start=(x+thickness+height,y),end=(x+thickness+height,y+length-2*thickness)))
    for i in range(joint):
        if i == 0:
            rlines.add(dwg.line(start=(x+thickness,y),end=(x+thickness,y+length/joint-thickness)))
        elif i == (joint-1):
            rlines.add(dwg.line(start=(x+thickness,y-thickness),end=(x+thickness,y+length/joint-2*thickness)))
        else:
            if (i+1)%2 == 1:
                rlines.add(dwg.line(start=(x+thickness,y-thickness),end=(x+thickness,y+length/joint-thickness)))
            else:
                rlines.add(dwg.line(start=(x,y-thickness),end=(x,y+length/joint-thickness)))
        if i != 0:
            rlines.add(dwg.line(start=(x,y-thickness),end=(x+thickness,y-thickness)))           
        y = y + length/joint
sideright()

def sideleft():
    x = 290 - width/2
    y = 225 - length/2 + thickness
    for i in range(cornerjoint):
        z = 0
        if (i+1)%2==0:
            z = thickness
        rlines.add(dwg.line(start=(x-thickness,y-z), end=(x-height/cornerjoint-thickness,y-z)))
        if i != (cornerjoint-1):
            rlines.add(dwg.line(start=(x-height/cornerjoint-thickness,y),end=(x-height/cornerjoint-thickness,y-thickness)))
        rlines.add(dwg.line(start=(x-thickness,y+length+z-2*thickness), end=(x-height/cornerjoint-thickness,y+length+z-2*thickness)))
        if i != (cornerjoint-1):
            rlines.add(dwg.line(start=(x-height/cornerjoint-thickness,y+length-2*thickness),end=(x-height/cornerjoint-thickness,y+length+thickness-2*thickness)))
        x = x - height/cornerjoint
    x = 290 - width/2
    rlines.add(dwg.line(start=(x-thickness-height,y),end=(x-thickness-height,y+length-2*thickness)))
    for i in range(joint):
        if i == 0:
            rlines.add(dwg.line(start=(x-thickness,y),end=(x-thickness,y+length/joint-thickness)))
        elif i == (joint-1):
            rlines.add(dwg.line(start=(x-thickness,y-thickness),end=(x-thickness,y+length/joint-2*thickness)))
        else:
            if (i+1)%2 == 1:
                rlines.add(dwg.line(start=(x-thickness,y-thickness),end=(x-thickness,y+length/joint-thickness)))
            else:
                rlines.add(dwg.line(start=(x,y-thickness),end=(x,y+length/joint-thickness)))
        if i != 0:
            rlines.add(dwg.line(start=(x-thickness,y-thickness),end=(x,y-thickness)))           
        y = y + length/joint
sideleft()

def sideup():
    x = 300 - width/2 
    y = 215 - length/2
    for i in range(cornerjoint):
        z = 0
        if (i+1)%2==0:
            z = thickness
        rlines.add(dwg.line(start=(x+z,y-thickness),end=(x+z,y-height/cornerjoint-thickness)))
        rlines.add(dwg.line(start=(x,y-height/cornerjoint-thickness),end=(x+thickness,y-height/cornerjoint-thickness)))
        rlines.add(dwg.line(start=(x+width-z,y-thickness),end=(x+width-z,y-height/cornerjoint-thickness)))
        rlines.add(dwg.line(start=(x+width,y-height/cornerjoint-thickness),end=(x+width-thickness,y-height/cornerjoint-thickness)))
        y = y - height/cornerjoint
    y = 215 - length/2
    rlines.add(dwg.line(start=(x,y-height-thickness), end=(x+width,y-height-thickness)))
    for i in range(joint):
        z = 0
        if (i+1)%2 == 1:
            z = thickness
        rlines.add(dwg.line(start=(x,y-z),end=(x+width/joint,y-z)))
        if i != 0:
            rlines.add(dwg.line(start=(x,y),end=(x,y-thickness)))
        x = x + width/joint
sideup()

def sidedown():
    x = 300 - width/2
    y = 235 + length/2
    for i in range(cornerjoint):
        z = 0
        if (i+1)%2==0:
            z = thickness
        rlines.add(dwg.line(start=(x+z,y+thickness),end=(x+z,y+height/cornerjoint+thickness)))
        rlines.add(dwg.line(start=(x,y+height/cornerjoint+thickness),end=(x+thickness,y+height/cornerjoint+thickness)))
        rlines.add(dwg.line(start=(x+width-z,y+thickness),end=(x+width-z,y+height/cornerjoint+thickness)))
        rlines.add(dwg.line(start=(x+width,y+height/cornerjoint+thickness),end=(x+width-thickness,y+height/cornerjoint+thickness)))
        y = y + height/cornerjoint
    y = 235 + length/2
    rlines.add(dwg.line(start=(x+width,y+height+thickness), end=(x,y+height+thickness)))
    for i in range(joint):
        z = 0
        if (i+1)%2 == 1:
            z = thickness
        rlines.add(dwg.line(start=(x,y+z),end=(x+width/joint,y+z)))
        if i != 0:
            rlines.add(dwg.line(start=(x,y),end=(x,y+thickness)))
        x = x + width/joint
sidedown()
dwg.save()
