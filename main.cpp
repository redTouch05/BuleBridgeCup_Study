#include<iostream>
#include<string>
#include<algorithm>
using namespace std;


bool is_Answer(int s3,int s4)
{
	string s = to_string(s3) + to_string(s4);
	sort(s.begin(), s.end());
	for (int i = 0; i < 10; i++)
	{
		if (s[i] != '0' + i)
		{
			return false;
		}
	}
	return true;
}

bool is_Answer2(int s3, int s4)//MY
{
	 int ans[10] = { 0 };
	int i = 0;
	while (s3 >= 1)
	{
		ans[i] = s3 % 10;
		s3 /= 10;
		i++;
	}
	
	while (s4 >= 1)
	{
		ans[i] = s4 % 10;
		s4 /= 10;
		i++;
	}

	sort(ans, ans + 10);
	for (int i = 0; i < 10; i++)
	{
		if (ans[i] != i)
		{
			return false;
		}
	}
	return true;
}





int main()
{
	for (int i = 10; i < 22; i++)
	{
		int s3 = i * i * i;
		int s4 = i * i * i * i;
		if (s3 >= 1000 && s3 < 10000 && s4 >= 100000 && s4 < 1000000)
		{
			if (is_Answer2(s3,s4))
			{

				cout << "Answer is: " << i << endl;

			}


		}

	}
	return 0;
}