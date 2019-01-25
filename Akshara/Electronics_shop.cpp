#include <algorithm>
#include <iostream>
using namespace std;
int getMoneySpent(int n, int *keyboards, int m, int *drives, int b) 
{
  int value, max = -1;
  for (int i = n - 1; i >= 0; i--) 
  {
    for (int j = m - 1; j >= 0; j--) 
    {
      value = (*(keyboards + i) + *(drives + j));
      if (value <= b) 
      {
        if (value > max) 
        {
          max = value;
        }
      }
    }
  }
  return max;
}

int main() {
  int n, m, b;
  int k[n], usb[m];
  cin >> b >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> k[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> usb[i];
  }

  sort(k, k + n);
  sort(usb, usb + m);

  int ans = getMoneySpent(n, k, m, usb, b);
  cout << ans;
  return 0;
}
