unsigned long peak(unsigned long nel, int (*less)(unsigned long i, unsigned long j))
{
	for(unsigned long k=2;k<nel;k++)
	{
		if(less(k,k-1))
		{
			return k-1;
		}
	}
	return nel-1;
}
