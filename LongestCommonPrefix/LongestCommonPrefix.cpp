/*
* Write a function to find the longest common prefix string amongst an array of strings.
* If there is no common prefix, return an empty string "".
* 
* Example 1: 
* Input: strs = ["flower","flow","flight"]
* Output: "fl"
* 
* Example 2:
* Input: strs = ["dog","racecar","car"]
* Output: ""
* Explanation: There is no common prefix among the input strings.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class LongestCommonPrefix
{
	public:
		string findPrefix(vector<string>& strs)
		{
			if (strs.size() == 0)
				return "";

			string prefix = strs[0];

			for (int i = 1; i < strs.size(); i++)
			{
				if (strs[i][0] != prefix[0])
				{
					return "";
				}

				// while str[i] does not contain prefix
				while (strs[i].find(prefix) == string::npos)
				{
					prefix = prefix.substr(0, prefix.length() - 1);
				}
			}

			return prefix;
		}
};

int main(void)
{
	LongestCommonPrefix lCP;
	vector<string> vectorString;

	vector<string> prefixA = { "flower", "flow", "flight" };
	vector<string> prefixB = { "dog", "racecar", "car" };
	vector<string> prefixC = { "reflower", "flow", "flight" };
	vector<string> prefixD = { "napkin", "nap", "naptime" };
	vector<string> prefixE = { "c","acc","ccc" };

	cout << lCP.findPrefix(prefixA) << endl;
	cout << lCP.findPrefix(prefixB) << endl;
	cout << lCP.findPrefix(prefixC) << endl;
	cout << lCP.findPrefix(prefixD) << endl;
	cout << lCP.findPrefix(prefixE) << endl;

	return 0;
}