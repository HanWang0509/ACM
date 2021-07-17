#include "bits/stdc++.h"
using namespace std;
const int maxn=25;
int n,a,b,c,T;
string s;
int check(char ch,int x,int y,int z){
   // cout<<ch<<endl;
    if(ch=='0') return min(x,y+z);
    if(ch=='1') return min(y,x+z);
}
int main()
{
    cin>>T;
    while(T--){
        s="";
        cin>>n>>a>>b>>c;
        cin>>s;
        //cout<<n<<" "<<a<<" "<<b<<" "<<c<<" "<<endl; 
        int sum =0;
        for(int i=0;i<n;i++){
            sum+=check(s[i],a,b,c);
        }
        cout<<sum<<endl;
    }
    return 0;
}