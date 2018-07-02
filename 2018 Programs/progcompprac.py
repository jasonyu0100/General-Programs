def function(day,month,year):
	#day
	value = day
	while len(value) > 1 and int(value) % 11 != 0:
		value = str(sum(map(int,value)))
	value1 = value


	value = month
	while len(value) > 1 and int(value) % 11 != 0:
		value = str(sum(map(int,value)))
	
	value2 = value
	value = year
	while len(value) > 1:
		value = str(sum(map(int,value)))
		if int(value) % 11 == 0:
			break

	value3 = value

	total = sum(map(int,[value1,value2,value3]))
	if total % 11 == 0:
		return total
	else:
		value = str(total)
		while len(value) > 1:
			value = str(sum(map(int,value)))
		return value

print(function("30","12","1989"))