int dicho(int *t, int n, int x) {
	int a,b,mid;
	a = 0;  
	b = n;
	while(a <= b) {
		mid = (b+a)/2;
		if (t[mid] == x)return 1;
		if (t[mid] < x)a = mid + 1;
		else b = mid - 1;
	}
return 0;}
