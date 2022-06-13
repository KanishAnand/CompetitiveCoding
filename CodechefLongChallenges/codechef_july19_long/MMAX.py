t = int(input())
while t > 0:
	t -= 1
	n = int(input())
	k = int(input())
	k = k % n
	p = n-k
	if p > k:
		print(2*k)
	elif p == k:
		print(2*k-1)
	else:
		print(2*p)

