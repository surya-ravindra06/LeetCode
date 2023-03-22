#include "temp.h"
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> nums(n);
	for (int i = 0; i < n; ++i)
		cin >> nums[i];

	vector<int> nge(n, -1);
	stack<int> st;

	for (int i = (nums.size())-1; i >= 0; --i)
	{
		while (!st.empty() && st.top() <= nums[i]) 
          st.pop();

      	if(!st.empty())
      		nge[i] = st.top();
        
        st.push(nums[i]);
	}

	for(auto v : nge)
		cout << v << " ";
}
