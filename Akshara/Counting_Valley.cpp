#include <bits/stdc++.h>

using namespace std;

// Complete the countingValleys function below.
int CountingValleys(int n , char s[])
{
    int level=0 , ctr=0;
    char ch;
    for(int i=0; i<n;i++)
    {
        ch = s[i];
        if(ch=='U')
        {
            if(level<0 && (level+1)==0)
                    ctr++;
            level++;
        }
        if(ch=='D')
            level--;
    }
    return ctr;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    char s[n];
    getline(cin, s);

    int result = CountingValleys(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
