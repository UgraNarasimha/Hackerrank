#include <iostream> 
#include <iterator> 
#include <map> 
#include <string>

using namespace std;

int main()
{
    string s = "kincenvizh";
    map<string,int> substrings;
    long int count = 0;
    long int n = s.length();

    for(int i = 0; i < n; i++)
    {
        string sub = s.substr(i,n-i);

        for(int j = 0; j < sub.length(); j++)
        {
            string subDistinct = sub.substr(0, sub.length() - j);

            if ( substrings.find(subDistinct) == substrings.end() ) {
            // not found
            substrings.insert({subDistinct, 1});
                cout << subDistinct << endl;
                count += 1;
            } else {
            // found
            continue;
            }
        }
    }
    cout << "Result" << count << endl;

    return 0;
}