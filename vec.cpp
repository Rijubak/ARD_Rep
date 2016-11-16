#include<iostream>
#include<vector>

using namespace std;


int main()
{
vector<int>v;
//v[0] = 20;         CAN'T JUST Initialize, pls push_back() first .
v.push_back(10);
v.push_back(12);
v.push_back(23);
v[0] = 40;
for(int i =0;i<v.size();i++)
cout<<"v["<<i<<"] : "<<v[i]<<" ";
cout<<endl;
return 0;
}
