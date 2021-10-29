/****************************************
 *The code below is copied and modified from
 *https://gitlab.com/cpsc457/public/longest-int-my-getchar
 *Which was written by Pavol Federl (2020)
 *
 *
 *
 *
 ***************************************/


#include <unistd.h>
#include <cstdio>
#include <iostream>

using namespace std;

char buffer [1024*1024];
int buff_size = 0;
int buff_pos = 0;




char readChar(){
    if(buff_pos >= buff_size) {
        buff_size = read(STDIN_FILENO, buffer, sizeof(buffer));

        if (buff_size <= 0){
            return ios::eofbit;
        }

        buff_pos = 0;
    }



    return buffer[buff_pos++];




}

bool is_palindrome( const std::string & s){
    for( size_t i = 0 ; i < s.size() / 2 ; i ++)
        if( tolower(s[i]) != tolower(s[s.size()-i-1]))
            return false;
    return true;
}

string getLongest(){
    string longest;
    bool breaker = false;

    while(true){
        string word;


        while(true){
            char temp = readChar();
            if(temp == ios::eofbit){
                breaker = true;
            }
            if(!isspace(temp) && !breaker) {
                word.push_back(temp);
            } else {
                break;
            }

        }
        if(word.size() > longest.size()) {
            if (is_palindrome(word)) {
                longest = word;
            }
        }
        if(breaker){
            break;
        }

    }
    return longest;
}


int main(){
    string selectedPalindrome = getLongest();
    printf("Longest palindrome: %s\n", selectedPalindrome.c_str());
    return 0;
}
