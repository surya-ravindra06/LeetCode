#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    vector<int> ngt(n, -1);
    stack<int> s;
    for (int i = v.size() - 2; i >= 0; i--)
    {
        if(v[i] < v[i+1])
        {
            s.push(v[i+1]);
            ngt[i] = v[i+1];
        }   

        else
        {
            while(!s.empty() && s.top() <= v[i])
                s.pop();

            if(s.empty())
                ngt[i] = -1;
            else
                ngt[i] = s.top(); 
        }
        
    }
    
    for(auto i : ngt)
        cout << i << " ";
}
