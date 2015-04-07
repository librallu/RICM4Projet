i = 0
while True:
	esp.gpio2_toggle()
	if ( i%16 < 12 ):
		esp.wait(100)
	else:
		esp.wait(500)
	i += 1
