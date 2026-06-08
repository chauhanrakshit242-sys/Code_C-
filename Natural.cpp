#include<iostream>
using namespace std;
int sum_n(int n)
{
    if(n<=0)
    return 0;
    return sum_n(n-1)+n;
}
int main()
{
    int n;
    cout<<"Enetr the number";
    cin>>n;
    int sum=sum_n(n);
    cout<<"Sum of N Natural Number"<<sum;
    return 0;
}