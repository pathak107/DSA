#include <iostream>
#include <set>

using namespace std;

bool isPalin(string str){
    int n=str.size();
    for(int i=0;i<= n/2 ;i++){
        if(str[i]!= str[n-1-i]){
            return false;
        }
    }

    return true;
}


void remPalin(string substr, string str)
{
   cout<<str.find(substr)<<endl;
}

void subString(string substr,string str,int i){
    if(i==str.size()){

        if(isPalin(substr)){
            remPalin(substr,str);
        }
        cout<<substr<<endl;
        return;
    }

    subString(substr+str[i],str,i+1);
    subString(substr,str,i+1);

    
}





int main()
{
    int t;
    string str[100];
    cin>>t;
    for (int i = 0; i < t; i++)
    {
        cin>>str[i];
        subString("",str[i],0);
    }

    return 0;
}