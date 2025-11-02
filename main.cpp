#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>

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


int main()
{
	int i;
	string str;
	for (i = 1; i <= 2020; i++)
	{
		str.append(to_string(i));
	}
	int count = 0;

	count = std::count(str.begin(), str.end(), '2');

	cout << count << endl;
	return 0;
}