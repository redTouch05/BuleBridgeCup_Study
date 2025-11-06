#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<unordered_map>
//#include<bits/stdc++.h>
using namespace std;
//int main()
//{
//	int i, j;
//	for (i = 1; i < 30; i++)
//	{
//		for (j = 1; j < 30; j++)
//		{
//			if ((i * j) == 6 * (i + j) && (abs(i - j) <= 8) && (i != j))
//			{
//				/*cout << "i: " << i << " j: " << j << endl;*/
//				int ans = (i < j ? i : j);
//				cout << ans << endl;
//				return 0;
//			}
//		}
//	}
//
//	return 0;
//}


//int main()
//{
//	int i;
//	string str;
//	for (i = 1; i <= 2020; i++)
//	{
//		str.append(to_string(i));
//	}
//	int count = 0;
//
//	count = std::count(str.begin(), str.end(), '2');
//
//	cout << count << endl;
//	return 0;
//}


////动态规划
//int count(int num)
//{
//	if (num < 0)
//	{
//		cout << "请输入大于0的数!" << endl;
//		return -1;
//	}
//  //f(n)=f(n-1)+f(n-2)
//  //f(1)=1 f(2)=2
//	if (num == 1)
//	{
//		return 1;
//	}
//	if (num == 2)
//	{
//		return 2;
//	}
//	return count(num - 1) + count(num - 2);
//}
//
//
//
//int main()
//{
//	cout << count(20) << endl;
//	return 0;
//}


//归并排序



//阶段2 合并
//int merge_count(vector<int> &nums, int left, int mid, int right)
//{
//   //1.创建一个临时数组
//   vector<int> temp(right - left + 1);
//   int i = left;//左子数组index
//   int j = mid + 1;//右子数组index
//   int posPair = 0;
//   int k = 0;//临时数组index
//   while (i <= mid && j <= right)
//   {
//	   
//	   if (nums[i] <= nums[j])//构成正序对
//	   {
//		   posPair += (right - j + 1);
//		   temp[k] = nums[i];
//		   k++;
//		   i++;
//	   }
//	   else
//	   {
//		   //不构造正序对 右元素进入temp
//		   temp[k] = nums[j];
//		   k++;
//		   j++;
//	   }
//   }
//   //上面一圈遍历完后 要么左边剩 要么右边剩 处理
//   while (i <= mid)
//   {
//	   temp[k++] = nums[i++];
//   }
//
//   while (j <= right)
//   {
//	   temp[k++] = nums[j++];
//   }
//
//   //将临时数组结果复制到原数组 使left~right区间有序
//   for (int q = 0; q < temp.size(); q++)
//   {
//	   nums[left + q] = temp[q];
//   }
//   return posPair;
//}
//
//
//
////阶段1 拆分 
//int mergeSort_countPosPair(vector<int>& nums, int left, int right)
//{
//	//统计本阶段的正序对个数
//	
//	int mid = 0;
//	int posPair = 0;
//	if (left < right)
//	{
//		mid = left + (right - left) / 2;//==>(r-l)/2 避免溢出
//		//拆分左边
//		posPair += mergeSort_countPosPair(nums, left, mid);
//		//拆分右边
//		posPair += mergeSort_countPosPair(nums, mid + 1, right);
//		//合并
//		posPair += merge_count(nums, left, mid, right);
//	}
//	return posPair;
//}
//
//int countNegPairs(vector<int>& nums)
//{
//	int n = nums.size();
//	int posPairs = mergeSort_countPosPair(nums, 0, n - 1);
//	int allPairs = n * (n - 1) / 2;
//	return allPairs - posPairs;
//}
//
//int main()
//{
//	vector<int> nums = { 5, 2, 6, 1, 3, 4 };
//	cout << countNegPairs(nums) << endl;
//	return 0;
//}



//vector<int> twoNums(vector<int>& nums, int target)
//{
//	//key:数组中的数值 value:对应的下标
//	unordered_map<int, int> hashMap;
//	int ans = 0;
//
//	for (int i = 0; i < nums.size(); ++i)
//	{
//		ans = target - nums[i];
//		//find函数返回的是迭代器 如果!= end() 说明哈希表中存储了对应的键和值
//		if (hashMap.find(ans) != hashMap.end())
//		{
//			return { hashMap[ans],i };
//		}
//		hashMap.insert({ nums[i],i });
//	}
//
//}
//
//
//
//int main()
//{
//	vector<int> nums = { 2,7,11,15,19,4,5 };
//	int target = 9;
//	vector<int> ans = twoNums(nums, target);
//	for (auto i : ans)
//	{
//		cout << i << endl;
//	}
//	cout << nums[ans[0]] << " " << nums[ans[1]] << endl;
//
//}

//冒泡排序


void bubbleSort(vector<int>& nums)
{
    int n = nums.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                std::swap(nums[j], nums[j + 1]);
            }
        }
    }
}





int main()
{

    std::vector<int> arr = { 64, 34, 25, 12, 22, 11, 90 };
    bubbleSort(arr);

    std::cout << "排序后数组: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    // 输出：11 12 22 25 34 64 90

}
