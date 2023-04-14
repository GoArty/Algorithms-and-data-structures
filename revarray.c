#include <stdio.h>
void revarray(void *base, size_t nel, size_t width) 
{
  for(size_t low = 0, high = nel - 1; low < nel/2; low++, high--)
    for(size_t i = 0; i < width; i++) 
	{
      char sup_elem = *((char*)base + width*low + i);
      *((char*)base + width*low + i) = *((char*)base + width*high + i);
      *((char*)base + width*high + i) = sup_elem;
    }
}
