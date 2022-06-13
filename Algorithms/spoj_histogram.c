#include <stdio.h>
#include <stdlib.h>
typedef long long int lli;
lli push(lli value);
lli pop();
struct node
{
    lli val;
    struct node *nextnode;
};

struct node *head = NULL;

int main(void)
{
    lli n;
    while (1)
    {
        scanf("%lld", &n);

        if (n == 0)
        {
            return 0;
        }

        lli arr[n + 5], l[n + 5];
        for (lli i = 0; i < n; i++)
        {
            scanf("%lld", &arr[i]);
        }
        head = NULL;
        push(0);
        l[0] = 0;
        for (lli i = 1; i < n; i++)
        {
            if (arr[i] > arr[i - 1])
            {
                push(i);
                l[i] = i;
            }
            else
            {
                lli p = head->val;
                while (head != NULL)
                {
                    if (arr[i] <= arr[head->val])
                    {
                        p = head->val;
                        pop();
                    }
                    else
                    {
                        break;
                    }
                }
                l[i] = p;
                push(l[i]);
            }
        }

        lli r[n + 5];
        head = NULL;
        push(n - 1);
        r[n - 1] = n - 1;

        for (lli i = n - 2; i >= 0; i--)
        {
            if (arr[i] > arr[i + 1])
            {
                push(i);
                r[i] = i;
            }
            else
            {
                lli p = head->val;
                while (head != NULL)
                {
                    if (arr[i] <= arr[head->val])
                    {
                        p = head->val;
                        pop();
                    }
                    else
                    {
                        break;
                    }
                }

                r[i] = p;
                push(r[i]);
            }
        }

        lli max = 0, ans;
        for (lli i = 0; i < n; i++)
        {
            ans = (r[i] - l[i] + 1) * arr[i];
            if (ans > max)
            {
                max = ans;
            }
        }
        printf("%lld\n", max);
    }
    return 0;
}

lli pop()
{
    struct node *nodes = (struct node *)malloc(sizeof(struct node));
    nodes = head;
    head = nodes->nextnode;
}

lli push(lli value)
{
    struct node *nodes = (struct node *)malloc(sizeof(struct node));
    nodes->val = value;
    nodes->nextnode = head;
    head = nodes;
}
