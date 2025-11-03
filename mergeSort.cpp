//合并
int merge(vector<int>& nums, int left, int mid, int right)
{
	vector<int> temp(right - left + 1);
	int posPairs = 0;
	int i = left;
	int j = mid + 1;
	int k = 0;
	while (i <= mid && j <= right)
	{
		if (nums[i] < nums[j])
		{
			posPairs += (right - j + 1);//这里要posPairs要累计 不然会出bug
			temp[k] = nums[i];
			i++;
			k++;
		}
		else
		{
			temp[k] = nums[j];
			j++;
			k++;
		}
	}

	//当左边有剩余
	while (i <= mid)
	{
		temp[k++] = nums[i++];
	}

	//当右边有剩余
	while (j <= right)
	{
		temp[k++] = nums[j++];
	}

	//把temp复制给nums 确保left~right区间有序
	for (int p = 0; p < temp.size(); p++)
	{
		nums[left + p] = temp[p];
	}
	return posPairs;
}





//拆分
int mergeSort_countPosPair(vector<int>& nums, int left, int right)
{
	int mid = left + (right - left) / 2;
	int posPairs = 0;
	//递归出口
	if (left < right)
	{
		//拆分左边
		posPairs += mergeSort_countPosPair(nums, left, mid);

		//拆分右边
		posPairs += mergeSort_countPosPair(nums, mid + 1, right);

		//合并
		posPairs += merge(nums, left, mid, right);

	}

	return posPairs;
}

int count_negPairs(vector<int>& nums)
{
	int n = nums.size();
	int posPairs = mergeSort_countPosPair(nums, 0, n - 1);
	int allPairs = n * (n - 1) / 2;
	return allPairs - posPairs;
}

int main()
{
	vector<int> nums = { 5, 2, 6, 1, 3, 4 };
	int ans = count_negPairs(nums);
	cout << ans << endl;

	vector<int> nums2 = { 4, 3, 2, 1 };
	cout << count_negPairs(nums2) << endl;

	return 0;
}





//合并
void merge(vector<int>& nums, int left, int mid, int right)
{
	vector<int> temp(right - left + 1);
	int i = left;
	int j = mid + 1;
	int k = 0;
	while (i <= mid && j <= right)
	{
		if (nums[i] < nums[j])
		{
			temp[k] = nums[i];
			i++;
			k++;
		}
		else
		{
			temp[k] = nums[j];
			j++;
			k++;
		}
	}

	//当左边有剩余
	while (i <= mid)
	{
		temp[k++] = nums[i++];
	}

	//当右边有剩余
	while (j <= right)
	{
		temp[k++] = nums[j++];
	}

	//把temp复制给nums 确保left~right区间有序
	for (int p = 0; p < temp.size(); p++)
	{
		nums[left + p] = temp[p];
	}
}





//拆分
void mergeSort(vector<int>& nums, int left, int right)
{
	int mid = left + (right - left) / 2;
	//递归出口
	if (left < right)
	{
		//拆分左边
		mergeSort(nums, left, mid);

		//拆分右边
		mergeSort(nums, mid + 1, right);

		//合并
		merge(nums, left, mid, right);

	}

}


int main()
{
	vector<int> nums = { 5, 2, 6, 1, 3, 4 };
	mergeSort(nums, 0, nums.size() - 1);
	for (auto single : nums)
	{
		cout << single << endl;
	}

	return 0;
}