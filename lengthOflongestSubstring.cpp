#include <iostream>
#include <vector>
using namespace std;
int main(){
    return 0;
}
int lengthOfLongestSubstring(string s) {

        if (s.empty()) return 0;  
        int result = 0; 
	    int start = 0;  
	    vector<bool> chars_in_substring;
		chars_in_substring.resize(256);
		for (int i = 0; i < s.size(); ++i) {
		    while (chars_in_substring[s[i]]) {
			chars_in_substring[s[start++]] = false;
			}
			chars_in_substring[s[i]] = true;
			result = max(result, i-start+1);	
		}
		return result;
    }