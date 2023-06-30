#include<string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.length() > haystack.length()) {
            return -1;
        }


        for (unsigned int i = 0; i < haystack.length() - needle.length() + 1; i++) {
            bool isCorrect = true;
            int j = 0;
            for (unsigned int j = 0; j < needle.length(); j++) {
                if (haystack[i + j] != needle[j]) {
                    isCorrect = false;
                }
            }

            if (isCorrect) {
                return i;
            }
        }

        return -1;
    }
};