#include <iostream>
#include <utility>
#include <algorithm>
#include <vector> 

using namespace std;
main()
{



vector <int> vec;
vector <char,int> sort_arr;
vector <string,int> string_pair;


sort(vec.begin(), vec.end(), [](const vector<int>& a, const vector<int>& b) { return a[0] < b[0]; });


sort(sort_arr.begin(), sort_arr.end(), [](pair<char,int>& a, pair<char,int> &b) { return a.second > b.second; });


sort(string_pair.begin(),string_pair.end(),

 //LAMDA FUNCTION FOR LEXOGRAPHIC SORTING
 //LAMDA FUNCTION FOR LEXOGRAPHIC SORTING
 //LAMDA FUNCTION FOR LEXOGRAPHIC SORTING
 //LAMDA FUNCTION FOR LEXOGRAPHIC SORTING

[](pair<string,int> & a, pair<string,int> & b){
    if(a.second == b.second)
    {
        int i = 0;
        while(a.first[i] == b.first[i])
        {
            //cout << a.first[i] << " " << b.first[i] <<"\n";
            i++;
        } 
        //cout << a.first[i] << " " << b.first[i] <<"\n";
        if(a.first[i] < b.first[i])
        {
            return false;
        }
        else 
        {
            return true;
        }
    }
    else
        return (a.second < b.second);
    } 
);
}