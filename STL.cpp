#include<iostream>
#include<algorithm>

using namespace std;


int main()
{
int arr[6] = {0,24,9,5,678,102};
int one[10] = {0,2,1,1,1,1,78,90,1,89};
//vector<int>at ;
sort(arr,arr+6);
for(int i = 0;i<6;i++)
{ cout<<arr[i]<<" "; }
cout<<endl;
cout<<"Loc_9 : "<<(find(arr,arr+6,9) - arr)<<endl;
cout<<"No_1 : "<<count(one,one+8,1)<<endl;
return 0;
}
