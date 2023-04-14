unsigned long binsearch(unsigned long nel, int (*compare)(unsigned long i))
{
    for (unsigned long left_elem = 0, right_elem = nel - 1, mid_elem; left_elem <= right_elem;) {
        mid_elem = (left_elem + right_elem) / 2;
        if (compare(mid_elem) < 0)
            left_elem = mid_elem + 1;
        else if (compare(mid_elem) > 0)
            right_elem = mid_elem - 1;
        else if (compare(mid_elem) == 0)
            return mid_elem;
    }

    return nel;
}
