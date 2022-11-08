#include <bits/stdc++.h>
using namespace std;

vector<set<int>> seg;

set<int> merge(set<int> &a1, set<int> &a2)
{
  set<int> res;
  for(auto i: a1)
  {
      res.insert(i);
  }
  for(auto i: a2)
  {
      res.insert(i);
  }
  return res;
}

void buildST(int l, int r, int t, vector<int> &input)
{
  if (l == r)
  {
      seg[t].insert(input[l]);
      return;
  }
  int mid = (l + r)>>1;
  
  buildST(l, mid, 2*t, input);
  buildST(mid+1, r, 2*t+1, input);
  seg[t] = merge(seg[2*t], seg[2*t+1]);
}
 
set<int> queryHelper(int i, int j, int l, int r, int t){
  if (l >= i && r <= j)
      return seg[t];

  if (r<i || l>j)
      return set<int>();

  int mid = (l + r)>>1;
  
  set<int> left = queryHelper(i, j, l, mid, 2*t);
  set<int> right = queryHelper(i, j, mid+1, r, 2*t+1);
  return merge(left, right);
}

int query(int l, int r, int n)
{
  return queryHelper(l, r, 0, n - 1, 1).size();
}
 
int main()
{
  vector<int> arr{1, 1, 2, 1, 3};
  int n = arr.size();

  seg.clear();
  seg.resize(4 * n);

  buildST(0, n - 1, 1, arr);
  
  for(int i=0; i<4*n; i++){
	cout << "seg " << i << "\n";
	for(auto j: seg[i]){
	  cout << j << " ";
	}
	cout <<"\n\n";
  }
  cout << query(2, 2, n) << endl;
}
