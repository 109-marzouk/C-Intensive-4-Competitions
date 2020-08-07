/****************************
* 1D Arrays - Homework
*****************************/

#include <iostream>
#include <assert.h>
#include <cmath>
#include <vector>
#include<bits/stdc++.h>
#include <algorithm>

using namespace std;

/****************************
* 1. Convert to Int
*****************************/
int convert(string s){
  int r = 0;
  for(int i = (s[0] == '-' ? 1 : 0); i < s.size(); i++){
    assert(isdigit(s[i]));
    r += (s[i]-'0');
    if(i != s.size()-1) r *= 10;
  }
  return s[0] == '-' ? r * -1 : r;
}

/****************************
* 2. Grouping
*****************************/
void grouping(string s){
  cout << s[0];
  for(int i = 1; i < s.size(); i++)
    cout << (s[i] == s[i-1] ? "" : " ") << s[i];
  cout <<endl;
}

/****************************
* 3. Less Than
*****************************/
bool lessThan(string a, string b){
  int x = min(a.size(), b.size());
  for(int i = 0; i < x; i++){
    if(a[i] < b[i]) return true;
  }
  if(a.size() < b.size()) return true;
  return false;
}

/****************************
* 4. Sub Strings
*****************************/
void subStrings(string s){
  if(s.size() == 0) cout<<""<<endl;
  for(int x = 0; x < s.size(); x++){
    for(int i = x; i < s.size(); i++)
      cout << s.substr(x, i-(x-1)) << " ";
    cout <<endl;
  }
}

/****************************
* 5. Add 9999
*****************************/
string add9999(string s){
  string m = "9999";
  if(s.length() < m.length()) swap(s, m);
  int a = 0, b = 0, carry = 0, i = 0;
  do{
    a = s[s.length()-i-1] - '0' + carry;
    b = m[m.length()-i-1] - '0';
    carry = a + b >= 10 ? 1 : 0;
    s.replace(s.length()-i-1, 1, to_string((a+b)%10));
    if(i++ == m.length()-1 && carry == 1 ) m.insert(0, "0");
  }while(carry == 1 || i < m.length());
  return s;
}

/****************************
* 6. Sum Query
*****************************/
int query_v1(int arr[], int start, int end){
  int r = 0;
  for(int i = start; i <= end; i++) r += arr[i];
  return r;
}

int query_v2(int arr[], int start, int end){
  if(start > end) return 0;
  return arr[start] + query_v2(arr, start+1, end);
}

/****************************
* 7. Search for number
*****************************/
bool search(int arr[], int x, int size){
  for(int i = 0; i < size; i++){
    if(arr[i] == x) return true;
  }
  return false;
}

bool bin_search(int arr[], int x, int start, int end){
  if(end >= start){
    if(arr[(start+end)/2] == x) return true;
    if(arr[(start+end)/2] < x)
      return bin_search(arr, x, (start+end)/2+1, end);
    return bin_search(arr, x, start, (start+end)/2+1);
  }
  return false;
}

/****************************
* 8. Find S=2 numbers
*****************************/
// O(N^2) => BF(Brute Force)
bool finds2_v1(int arr[], int t, int size){
  for(int i = 0; i < size; i++){
    for(int x = 0; x < size; x++){
      if(arr[i] + arr[x] == t && arr[i] != arr[x]) return true;
    }
  }
  return false;
}

// O(N.logN)
bool finds2_v2(int arr[], int t, int size){
  for(int i = 0; i < size; i++){
    if(arr[i] != t-arr[i] && bin_search(arr, t-arr[i], 0, size-1)) return true;
  }
  return false;
}

// O(N)
bool finds2_v3(int arr[], int t, int size){
  vector<int> comp;
  for(int i = 0; i < size; i++){
    if(find(comp.begin(), comp.end(), arr[i]) != comp.end())
      return true;
    else comp.push_back(t-arr[i]);
  }
  return false;
}

/****************************
* 9. Big Factorial
*****************************/
void big_fac(int n){
  int d[500], end = 1, carry = 0, product = 0;
  d[0] = 1;
  for(int i = 2; i <= n; i++){
    for(int x = 0; x < end; x++){
      product = d[x] * i + carry;
      d[x] = product % 10;
      carry = product / 10;
    }
    while(carry){
      d[end++] = carry % 10;
      carry /= 10;
    }
  }
  int i = end;
  while(--i) cout << d[i];
  cout << d[0] <<endl;
}

/****************************
* 10. Find Primes
*****************************/
void findPrimes(int n){
  bool d[n];
  fill(d, d+n, 1);
  d[0] = 0;
  for(int i = 2; i <= sqrt(n); i++){
    int j = 2;
    while(i * j <= n) d[i * j++ - 1] = 0;
  }
  for(int x = 0; x < n; x++)
    if(d[x]) cout << x + 1 << " ";
  cout <<endl;
}

/****************************
* 11. Permutation Cycle
*****************************/
void permutationCycles(int arr[], int size){
  bool visited[size];
  int i = size, startCycle = 0, startNode = 0, endNode = arr[0];
  while(i--){
    cout << startNode << " -> " << endNode <<endl;
    visited[startNode] = 1;
    if(endNode != startCycle) startNode = endNode;
    else{
      int x = 1;
      while(x < size && visited[x]) x++;
      startCycle = x;
      startNode = startCycle;
      cout <<endl;
    }
    endNode = arr[startNode];
  }
}

/****************************
* 12. Josephus Problem
* https://www.geeksforgeeks.org/josephus-problem-set-1-a-on-solution/
*****************************/
int josephusProblem(int N, int K){
  if(N == 1) return 1;
  return (josephusProblem(N - 1, K) + K - 1) % N + 1;
}

int main() {

  /****************************
  * 1. Convert to Int (Test)
  *****************************/
  cout << "1. Convert to Int:\n-------------------" <<endl;
  cout << convert("-11") <<endl;
  cout << convert("0") <<endl;
  cout << convert("11") <<endl;
//  cout << convert("0x1") <<endl;

  /****************************
  * 2. Grouping (Test)
  *****************************/
  cout << "2. Grouping:\n-------------------" <<endl;
  grouping("");
  grouping("aa");
  grouping("1122233abhh$$");

  /****************************
  * 3. Less Than (Test)
  *****************************/
  cout << "3. Less Than:\n-------------------" <<endl;
  cout <<showbase<<boolalpha<<lessThan("a", "b") <<endl;
  cout <<showbase<<boolalpha<<lessThan("aaa", "aaab") <<endl;
  cout <<showbase<<boolalpha<<lessThan("aaabb", "aaab") <<endl;
  cout <<showbase<<boolalpha<<lessThan("Mohamed Marzouk", "Mohamed Magdi") <<endl;

  /****************************
  * 4. Sub Strings (Test)
  *****************************/
  cout << "4. Sub Strings:\n-------------------" <<endl;
  subStrings("123a");

  /****************************
  * 5. Add 9999 (Test)
  *****************************/
  cout << "5. Add 9999:\n-------------------" <<endl;
  cout << add9999("123456789123456789123456") <<endl;

  /****************************
  * 6. Sum Query (Test)
  *****************************/
  cout << "6. Sum Query:\n-------------------" <<endl;
  int arr[6] = {2, 0, 1, 4, 3, 5};
  cout << query_v1(arr, 1, 3) <<endl;
  cout << query_v2(arr, 1, 3) <<endl;

  /****************************
  * 7. Search for number (Test)
  *****************************/
  cout << "7. Search for number:\n-------------------" <<endl;
  // array, target, size
  cout << search(arr, 5, 6) <<endl;
  // sorted array, target, start, end
  // we can provide this function with unsorted array then we will
  // sort it inside the function using the built-in fuction "sort()"
  cout << bin_search(arr, 3, 0, 5) <<endl;

  /****************************
  * 8. Find S=2 numbers (Test)
  *****************************/
  cout << "8. Find S=2 numbers:\n-------------------" <<endl;
  cout <<showbase<<boolalpha<<finds2_v1(arr, 3, 6)<<endl;
  cout <<showbase<<boolalpha<<finds2_v2(arr, 10, 6)<<endl;
   cout <<showbase<<boolalpha<<finds2_v2(arr, 3, 6)<<endl;
  cout <<showbase<<boolalpha<<finds2_v2(arr, 10, 6)<<endl;
  cout <<showbase<<boolalpha<<finds2_v3(arr, 3, 6)<<endl;
  cout <<showbase<<boolalpha<<finds2_v3(arr, 10, 6)<<endl;

  /****************************
  * 9. Big Factorial (Test)
  *****************************/
  cout << "9. Big Factorial:\n-------------------" <<endl;
  big_fac(100);

  /****************************
  * 10. Find Primes (Test)
  *****************************/
  cout << "10. Find Primes:\n-------------------" <<endl;
  findPrimes(25);

  /****************************
  * 11. Permutation Cycle (Test)
  *****************************/
  cout << "11. Permutation Cycle:\n-------------------" <<endl;
  permutationCycles(arr, 6);

  /****************************
  * 12. Josephus Problem
  *****************************/
  cout << "12. Josephus Problem:\n-------------------" <<endl;
  cout << josephusProblem(7, 3) <<endl;

}
