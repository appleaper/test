#include <iostream>
using namespace std;
#include <vector>

int main()
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(2);
	vector<int>().swap(nums);
}
