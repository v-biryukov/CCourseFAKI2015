int revers(int x)
{
	int res;
	if (x / 10 == 0)
	{
		return x;
	}
	else
	{
		int ndigits = floor (log10 (abs (x))) + 1;
		res = (x % 10) * pow(10, ndigits-1) + revers(x / 10);
		return res;
	}
}