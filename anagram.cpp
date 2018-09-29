#include <bits/stdc++.h>

using namespace std;
vector<vector<int> >anagrams(const vector<string> &A) {
    //take each string from vector and convert each char to integer and store it in a vector
    // and sort that vector
    unordered_map<string, vector<int> > m;
    vector<vector<int>> v;

    for(int i = 0; i < A.size(); i++){
        int len = A[i].length();
        vector<int> ascii;
        for(int j = 0; j < len; j++){
            ascii.push_back(int(A[i][j]));
        }
        sort(ascii.begin(), ascii.end());
        //put together sorted string again
        string sorted="";
        for(int j = 0; j < len; j++){
            sorted += (char)ascii[j];
        }

        m[sorted].push_back(i+1);
    }
    
    for(auto it=m.begin(); it!= m.end(); it++){
        v.push_back(it->second);
    }
    return v;

}


int main()
{
    vector<string> A= {"cat","dog","god","tca"};
    vector<vector<int>> ans = anagrams(A);
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout<<ans[i][j]<< " ";
        }
        cout<<endl;
    }
    return 0;
}
