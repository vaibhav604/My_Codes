#include<iostream>
#include<string>
using namespace std;
int keypad(int n,string output[],string keys[])
{
	if(n==0){
        output[0]="";
        return 1;
    }
    
    int lastDigit=n%10;
    string smallOutput[10000];
    
    int k = keypad(n/10, smallOutput,keys);
    string s = keys[lastDigit];
    int m=0;
    for(int i=0;i<s.size();i++){
        for(int j=0;j<k;j++){
            output[m++]=smallOutput[j]+s[i];
        }
    }
    return m;
}

int keypad(int n, string output[]) {
	string keys[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    
    return keypad(n, output,keys);
}
int main()
{
	int n;
    cin >> n;

    string* output=new string[10000];
    int count = keypad(n, output);
    for(int i = 0; i < count; i++){
        cout << output[i] << endl;
    }
    cout<<count<<endl;
    return 0;

}
