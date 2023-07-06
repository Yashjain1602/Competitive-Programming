//{ Driver Code Starts
//Initial Template for C++

#include "iostream"
#include <vector>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    string concat(string s1,string s2){
        return s1+s2;
    }
    vector<int> freq(string s){
        vector<int> f(3,0);
        for(int i=0;i<s.length();i++){
            if(s.at(i) == 'a'){
                f.at(0)=f.at(0)+1;;
            }
            if(s.at(i) == 'b'){
                f.at(1)=f.at(1)+1;;
            }
            if(s.at(i) == 'c'){
                f.at(2)=f.at(2)+1;;
            }
        }
        return f;
    }
    // long long pairs(vector<string> s){
    //     long long count=0;
    //     for(int i=0;i<s.size()-1;i++){
    //         for(int j=i+1;j<s.size();j++){
    //             string s1 = concat(s.at(i),s.at(j));
    //             vector<int> f = freq(s1);
    //             if((f.at(0)%2==0 && f.at(1)%2==0 && f.at(2)%2!=0)||
    //             (f.at(0)%2!=0 && f.at(1)%2==0 && f.at(2)%2==0)||
    //             (f.at(0)%2==0 && f.at(1)%2!=0 && f.at(2)%2==0))
    //             {
    //                 ++count;
    //             }
    //         }
    //     }
    //     return count;
    // }
    int noOfPairs(vector<string> &box)
    {
        int ans=0;
        for(int i=0;i<box.size()-1;i++){
            for(int j=i+1;j<box.size();j++){
                string s1 = concat(box.at(i),box.at(j));
                vector<int> f = freq(s1);
                if((f.at(0)%2==0 && f.at(1)%2==0 && f.at(2)%2!=0)||
                (f.at(0)%2!=0 && f.at(1)%2==0 && f.at(2)%2==0)||
                (f.at(0)%2==0 && f.at(1)%2!=0 && f.at(2)%2==0))
                {

                    cout<<s1<<" ";
                    ++ans;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
        int n;
        cin>>n;
        vector<string>box(n);
        for(int i=0;i<n;i++)
            cin>>box[i];
        Solution ob;
        int ans=ob.noOfPairs(box);
        cout<<ans<<endl;
}