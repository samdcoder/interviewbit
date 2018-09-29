#include <bits/stdc++.h>

using namespace std;

int braces(string A){
    //pass 1 for redundant, 0 for no redundant braces
    int len = A.length();
    stack<char> s;
    for(int i = 0; i < len; i++){
        if(A[i] == ')'){
            char top_element = s.top();
            s.pop();
            int flag = 0;
            while(top_element != '('){
                if(top_element == '+' || top_element == '-' || top_element == '/' || top_element == '*' || top_element == ' ')
                    flag = 1;

                top_element = s.top();
                s.pop();
            }
            if(flag == 0){
                return 1;
            }
        }
        else{
            s.push(A[i]);
        }
    }
    return 0;
}
int main()
{
    int ans = braces("(a + (a + b))");
    cout<<ans<<endl;
    return 0;
}
