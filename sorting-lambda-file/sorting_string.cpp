// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
// bool compare(string s1,string s2){
//     return s1.size()<s2.size();
// }
int main() {
    vector<string> val={"AIe","aibb","python","python for ai ","pc"};
    sort(val.begin(),val.end(),[](string s1,string s2){ 
        return s1.size()<s2.size();});
    for(string x : val){cout<<x<<endl;}
    return 0;
}
// output
// pc
// AIe
// aibb
// python
// python for ai 