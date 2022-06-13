#include <stdio.h>
int divide(int l, int r, int arr[]);
int merge(int l, int r, int arr[]);
int p[200005], arrx[200005], arry[200005], original[200005], arr[200005];
int main(void)
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arrx[i]);
        scanf("%d", &arry[i]);
        original[i] = arry[i];
    }
    // printf("kan\n");
    divide(0, n - 1, arrx);
    int l, r, flag = 0;

    for (int i = 0; i < n; i++)
    {
        p[i] = original[i];
    }

    arrx[n] = 1e9 + 1, arry[n] = 1e9 + 1, p[n] = 1e9 + 1, original[n] = 1e9 + 1;

    for (int i = 0; i < n - 1; i++)
    {
        if (arrx[i] == arrx[i + 1])
        {
            if (flag == 0)
            {
                l = i;
                flag = 1;
            }
            continue;
        }
        else
        {
            if (flag == 1)
            {
                r = i;
                divide(l, r, p);
            }
            flag = 0;
        }
    }
    /*  printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d %d\n", arrx[i], original[i]);
    }
*/
    int count = 0, count1 = 0, county1 = 0, countx1 = 0, f = 1, fl = 1, countx = 0, county = 0;

    for (int i = 0; i < n; i++)
    {
        if (arrx[i] == arrx[i + 1])
        {
            ++countx1;
            if (f == 1)
            {
                ++countx1;
            }

            if (p[i] == p[i + 1])
            {
                //printf("kan\n");
                ++count1;
                if (fl == 1)
                {
                    ++count1;
                    fl = 0;
                }
            }

            /*if (p[i] != p[i + 1] && i == n - 1)
            {
                count += (count1 * (count1 - 1)) / 2;
            }*/

            if (p[i] != p[i + 1])
            {
                fl = 1;
                // printf("d %d\n", count);
                count += (count1 * (count1 - 1)) / 2;
                // printf(" k %d\n", count);
                count1 = 0;
            }

            f = 0;
        }

        else
        {
            count += (count1 * (count1 - 1)) / 2;
            count1 = 0;
            f = 1;
            fl = 1;
            countx += (countx1 * (countx1 - 1)) / 2;
            //count += (count1 * (count1 - 1)) / 2;
            count1 = 0;
            countx1 = 0;
        }
    }

    divide(0, n - 1, arry);
    f = 1;

    for (int i = 0; i < n; i++)
    {
        if (arry[i] == arry[i + 1])
        {
            ++county1;
            if (f == 1)
            {
                ++county1;
            }
            f = 0;
        }
        else
        {
            f = 1;
            county += (county1 * (county1 - 1)) / 2;
            county1 = 0;
        }
    }

    /*for (int i = 0; i < n; i++)
    {
        printf("%d %d\n", arrx[i], p[i]);
    }*/
    //printf("%d\n", count);
    /* count = (count * (count - 1)) / 2;
    countx = (countx * (countx - 1)) / 2;
    county = (county * (county - 1)) / 2;
    */
    printf("%d \n", countx + county - count);
    return 0;
}

//0 based indexing...

int divide(int l, int r, int arr[])
{
    if (l < r)
    {
        int mid = l + (r - l) / 2;
        divide(l, mid, arr);
        divide(mid + 1, r, arr);
        merge(l, r, arr);
    }
    return 0;
}

int merge(int l, int r, int arr[])
{
    int mid = (l + r) / 2;
    int n1 = mid - l + 1, n2 = r - mid;
    int left[n1], right[n2], L[n1], R[n2];

    for (int i = 0; i < n1; i++)
    {
        left[i] = arr[l + i];
        L[i] = original[l + i];
    }
    for (int j = 0; j < n2; j++)
    {
        right[j] = arr[mid + j + 1];
        R[j] = original[mid + j + 1];
    }
    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            original[k] = L[i];
            ++i;
        }
        else
        {
            arr[k] = right[j];
            original[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1)
    {
        arr[k] = left[i];
        original[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2)
    {
        arr[k] = right[j];
        original[k] = R[j];
        ++j;
        ++k;
    }
    return 0;
}
