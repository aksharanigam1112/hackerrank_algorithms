#include <bits/stdc++.h>

using namespace std;

struct page
{
    int left=0 , right=0;
};

int pageCount(int n, int p)
{
    if(p>=0 && p<=n){
    int pages = (int)(1 +  ceil((n)/2));
    int i=2 , k=1 , r ,d,ctr=0 ;
    struct page arr[pages];
    arr[0].right = 1;
    
    if(n%2==0)
    {
        while(k<pages && i<n)
        {
            arr[k].left = i++;
            arr[k].right = i++;
            k++;
        }
        arr[k].left = i;
    }
    else
    {
        while(k<pages && i<n)
        {
            arr[k].left = i++;
            arr[k].right = i++;
            k++;
        }
    }

    if(p<=(n/2))
    {
        k=0;
        while(k<pages)
        {
           if(p%2==0 && p==arr[k].left)
                    return ctr;
            if(p%2!=0 && p==arr[k].right)
                    return ctr;
            k++;
            ctr++;
        }
    }
    if(p>(n/2))
    {
        k = pages-1;
        while(k>=0)
        {
            if(p%2==0 && p==arr[k].left)
                return ctr;
            if(p%2!=0 && p==arr[k].right)
                return ctr;
            k--;
            ctr++;
        }
     }
    }
    return -999;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int p;
    cin >> p;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = pageCount(n, p);
    if(result != -999)
        fout << result << "\n";

    fout.close();

    return 0;
}
