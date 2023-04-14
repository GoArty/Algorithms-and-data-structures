long fib(long* fib_numbers, unsigned long nel)
{
    long max_index_fib;
    for (long i = 0, fib_under = 1, fib_after = 1, fib_middle; fib_after < nel && i < nel; i++) {
        fib_middle = fib_after, fib_after = fib_under + fib_after, fib_under = fib_middle, fib_numbers[i] = fib_under;
        if (nel < fib_numbers[i]) {
            max_index_fib = i - 1;
            return max_index_fib;
        }
            max_index_fib = i - 1;
    }
    return max_index_fib;
}

void shellsort(unsigned long nel, int (*compare)(unsigned long, unsigned long), void (*swap)(unsigned long, unsigned long))
{
    if (nel < 2)
        return;
    long fib_numbers[nel];
    for (long i = 0; i < nel; i++)
        fib_numbers[i] = 0;
    long max_index_fib = fib(fib_numbers, nel);
    for (; max_index_fib < nel && max_index_fib > -1; max_index_fib--)
    {
        long step = fib_numbers[max_index_fib];
        for (long i = 0; i < nel; i++)
            for (long j = i - step; j > -1 && j + step < nel; j -= step)
                if (compare(j, j + step) > 0)
                    swap(j, j + step);
    }

}
