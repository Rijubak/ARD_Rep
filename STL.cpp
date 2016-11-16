#include<iostream>
#include<algorithm>

using namespace std;


int main()
{
int arr[6] = {0,24,9,5,678,102};
//vector<int>at ;
sort(arr,arr+4);
for(int i = 0;i<4;i++)
{ cout<<arr[i]<<" "; }
cout<<endl;
//cout<<"Size arr : "<<sizeof(arr)<<endl;
return 0;
}
