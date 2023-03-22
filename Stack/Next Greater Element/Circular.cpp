#include "temp.h"
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> nums(n);
	for (int i = 0; i < n; ++i)
		cin >> nums[i];

	vector<int> ans(n, -1);
	stack<int> s;

	for (int i = nums.size()-1; i >= 0; --i)
	{
		if(i != nums.size()-1 && nums[i+1] > nums[i])
		{
			s.push(nums[i+1]);
			ans[i] = nums[i+1];
		}

		else
		{
			while(!s.empty() && s.top() <= nums[i])
            	s.pop();

            if(s.empty())
            {
            	int a = 0;
                for (int j = 0; j < i; ++j)
				{
					if(nums[j] > nums[i])
					{
						s.push(nums[j]);
						ans[i] = nums[j];
						a = 1;
						break;
					}
				}

				if(!a)
					ans[i] = -1;
            }

            else
                ans[i] = s.top();
		}
	
	}
	
	for(auto it : ans)
		cout << it << " ";
	
}
