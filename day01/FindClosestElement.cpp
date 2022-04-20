#include <iostream>

using namespace std;
void FindCElement(int a[],int n,int m){
    for (int i = 0; i < m; i++)
    {
        int high = n - 1, low = 0, mid, ans = -1, x;
        scanf("%d",&x);
        while (low<=high)
        {
            mid = low + (high - low) / 2;
            if (a[mid]==x)
            {
                ans=mid;
                break;
            }
            else if (a[mid]<x)
            {
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        if (ans != -1)
        {
            cout << a[ans] << endl;
        }
        else{
            if (high==-1)  ans=low;
            else if (low==n)  ans=high;
            else{
                if (a[low]-x < x - a[high]) ans=low;
                else ans=high;
            }
            cout << a[ans] << endl;
        }

    }
}
int main(int argc, char const *argv[])
{
    int n,m;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> m;
    FindCElement(a,n,m);
    return 0;
}
