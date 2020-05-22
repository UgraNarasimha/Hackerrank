//ddabcdbca
//ddabc 
//abcd dbca etc all have length 4 return that integer 


// C++ program to print fewest coins substring problem 
// substrings of a given string 

#include<bits/stdc++.h> 
#include<string>
#include<map>
#include<vector>
using namespace std; 

int countDistinct(string s) 
{
	unordered_map<char, int> m; 

    for (int i = 0; i < s.length(); i++) { 
        m[s[i]]++; 
    } 

    return m.size(); 
} 

int subString(string str, int uniq) 
{ 
	int n = str.length();
	int m;
	map <string,int> hmap;
	vector <int> v;
	string temp;
	
	for (int len = 0; len < n; len++) 
	{	 
		for (int i = len+1; i <= n; i++) 
		{ 
			cout << str.substr(len,i);
			temp = str.substr(len,i);

			// call a function that checks if all unique characters are present in this substring
			m = countDistinct(str.substr(len,i));
			cout << "  : m=" << m;
			cout << endl; 

			if(m>=uniq)
			{
				hmap.insert({ temp, temp.length() });
			}
			
		} 
	}

	cout << "------------------------------------" << endl;

	for (auto itr = hmap.begin(); itr != hmap.end(); ++itr) { 
        cout << itr->first 
             << '\t' << itr->second << '\n'; 

		v.push_back(itr->second);
	}

	int min = *min_element(v.begin(), v.end());
	return min; 
} 

// Driver program to test above function 
int main() 
{ 
	string str = "ddabcdbbcae";

	cout << "Unique number of Char: " << countDistinct(str) << endl;

	int uniq = countDistinct(str);
 
	int m = subString(str, uniq);

	cout << "FewestCoins : " << m << endl; 
	return 0; 
}