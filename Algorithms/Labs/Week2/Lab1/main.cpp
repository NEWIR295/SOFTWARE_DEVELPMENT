/*
sliding window technique:
    longest substring with no repeating characters
*/
#include <iostream>
#include <string>
std::pair<std::string,int> findLongestSubstring(std::string string){

    std::pair<std::string,int> longestSubstring;
    std::string longString;
    for(int i = 0;i<string.size();i++){
        for(int j = i+1;j<string.size();i++){
            if(string.at(i) == string.at(j) ){

            }
            else{
                continue;
            }
        }
    }

    return longestSubstring;
}