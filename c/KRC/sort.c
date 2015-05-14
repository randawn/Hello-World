
/* shellsort: sort v[0] ... v[n-1] into increasing order
 * 1959 by D. L. Shell
 * in early stage, far-apart elements are compared,
 * rather than adjacent ones as in simpler interchange sorts.
 * This tends to elliminate large amounts of disorder quickly,
 * so later stages have less work to do.
 * the interval between compared elements is gradully decreased to one,
 * at which point the sort effectively becomes an adjacent interchange method
 */
void shellsort(int v[], int n)
{
}

/* qsort: sort v[left] ... v[right] into increasing order
 * 1962 by C. A. R. Hoare
 * One elements is chosen and the others are partitioned into two subsets--
 * those less than the partition elements and those greater than or equal to it.
 * The same process is then applied recursively to the two subsets.
 * when a subsets has fewer than two elements,
 * it doesn't need any sorting. this stops the recursion.
 */
void qsort(int v[], int left, int right)
{
}


