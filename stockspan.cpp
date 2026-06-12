#include<iostream>
#include<stack>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>prices(n);
    for (int i = 0; i < n; i++)
    {
        cin>>prices[i];
    }
    stack<int>s;
    for (int i = 0; i < n; i++)
    {
        while(!s.empty() && prices[i]>=prices[s.top()])s.pop();

        if(s.empty())cout<<i+1<<" ";
        else cout<<i-s.top()<<" ";

        s.push(i);
    }
    
    return 0;
}