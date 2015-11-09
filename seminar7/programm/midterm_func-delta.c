double delta(unsigned char hours1, unsigned char minutes1, unsigned char seconds1, unsigned char hours2, unsigned char minutes2, unsigned char seconds2)
{
	int s1 = hours1*3600 + minutes1*60 + seconds1;
	int s2 = hours2*3600 + minutes2*60 + seconds2;
	int s = (s2 - s1 + 24*3600) % (24*3600);
	double time_passed = s*1.0/60.0;
	return time_passed;
}
