daysInMonth = {1:31,
               2:28,
               3:31,
               4:30,
               5:31,
               6:30,
               7:31,
               8:31,
               9:30,
               10:31,
               11:30,
               12:31}

doomsday = (4,4)

def doomsday(anchor,day,month,year):
    leapYear = leapYear(year)
    if leapYear:
        daysInMonth[2] += 1

    
    return

def getDifferenceInDays(day,month):
    pass

def getDifference(difference)
"""
Taking in difference between dates as a variable
Returns how many days after it is
"""
    return date % 7
    


def leapYear(year):
    """
Leap year calculator
    """
    if year % 4 == 0:
        if year % 400 == 0:
            return True
        elif year % 100 == 0:
            return False
        else:
            return True
    else:
        return False
        
    
    
