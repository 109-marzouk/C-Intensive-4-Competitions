// By: Mohamed Marzouk
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
void magicSquare(int n){
  int arr[n][n];

  memset(arr, 0, sizeof(arr)); // set all items' value to ZERO

  int x = n - 1, y = n / 2;

  for(int i = 1; i <= n*n;){
    if(y == -1 && x == n){
      y = 0;
      x = n - 2;
    }
    else{
      if(y < 0) y = n - 1;
      if(x == n) x = 0;
    }
    if(arr[y][x]){
      x -= 2;
      y++;
      continue;
    }
    else arr[y][x] = i++;

    x++; y--;
  }
  cout << "The Magic Square " << n <<" * " << n << ":" <<endl;
  cout << "M(" << n << ") = " << n*(n*n+1)/2 <<endl;
  for(int x = 0; x < n; x++){
    for(int y = 0; y < n; y++) cout << arr[x][y] << " ";
    cout<<endl;
  }
}
int main() {
  int n = 3;
  while(true){
    cout << "Enter N = ";
    cin >> n;
    while(n <= 2){
      cout << "N must be greater than 2, plz ente it again = ";
      cin >> n;
    }
    magicSquare(n);
  }
}
