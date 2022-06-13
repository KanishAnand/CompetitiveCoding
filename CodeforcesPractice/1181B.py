n = input()
no = input()
n = int(n)

if(no[n//2] != '0'):
		ans = int(no[0:n//2]) + int(no[n//2:n+1])
		if(n//2 + 1 < n and no[n//2+1] != '0'):
			b = int(no[0:n//2+1]) + int(no[n//2+1:n])
			ans = min(ans,b)
		if(n//2 + 2 < n and no[n//2+2] != '0'):
			b = int(no[0:n//2+2]) + int(no[n//2+2:n])
			ans = min(ans,b)
		if(n//2 - 1 > 0 and no[n//2-1] != '0'):
			c = int(no[0:n//2-1]) + int(no[n//2-1:n])
			ans = min(ans,c)
		if(n//2 - 2 > 0 and no[n//2-2] != '0'):
			c = int(no[0:n//2-2]) + int(no[n//2-2:n])
			ans = min(ans,c)
		print(ans)
else:
	x = n//2
	y = n//2
	while(no[x] == '0'):
		x -= 1
	while(y < n and no[y] == '0'):
		y += 1
	ans = -1
	if(y < n and no[y] != '0'):
		ans = int(no[0:y]) + int(no[y:n])
	if(x > 0):
		b = int(no[0:x]) + int(no[x:n])
		if(ans != -1):
			ans = min(ans,b)
		else:
			ans = b
	if(x - 1 > 0 and no[x-1] != '0'):
		c = int(no[0:x-1]) + int(no[x-1:n])
		ans = min(ans,c)
	if(x - 2 > 0 and no[x-2] != '0'):
		c = int(no[0:x-2]) + int(no[x-2:n])
		ans = min(ans,c)
	if(y+1 < n and no[y+1] != '0'):
		d = int(no[0:y+1]) + int(no[y+1:n])
		ans = min(ans,d)
	if(y+2 < n and no[y+2] != '0'):
		d = int(no[0:y+2]) + int(no[y+2:n])
		ans = min(ans,d)
	print(ans)



		
