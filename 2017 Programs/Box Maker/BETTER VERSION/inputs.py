def inputs():
    #INPUTS
    length = float(input('Enter length of box: '))
    width = float(input('Enter width of box: '))
    height = float(input('Enter height of box: '))
    thickness = float(input('Enter thickness of material: '))
    basetenons = int(input('Enter number of tenons on base: '))
    cornertenons = int(input('Enter number of tenons on corner: '))
    offset = float(input('Enter offset between joints: '))
    viewbox = input('Enter a viewbox(200,300): ').split()
    #JOINTS
    basejoint = basetenons + 2
    cornerjoint = cornertenons + 2
    #NEW LENGTHS
    l = length/basejoint
    w = width/basejoint
    h = height/cornerjoint
    #VIEWBOX
    X = float(viewbox[0])
    Y = float(viewbox[1])
    VX = X/2
    VY = Y/2
    #COORDINATES
    #BASE
    BX = VX - width/2
    BY = VY + length/2
    #UP
    UX = BX
    UY = BY + 10
    #DOWN
    DX = BX
    DY = BY - length - 10
    #LEFT
    LX = BX - 10
    LY = BY
    #RIGHT
    RX = BX + width + 10
    RY = BY
    return(drawer(basejoint,cornerjoint,l,w,h,VX,VY,BX,BY,UX,UY,DX,DY,LX,LY,RX,RY))





    
    
