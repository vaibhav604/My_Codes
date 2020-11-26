#include<iostream>
#include<string>
using namespace std;
void keypad(int n,string output,string keys[])
{
	if(n==0){
        cout<<output<<endl;
        return;
    }
    int lastDigit=n%10;
    string s = keys[lastDigit];
    for(int i=0;i<s.size();i++){
        keypad(n/10, output+s[i],keys);
    }
}

void keypad(int n, string output) {
	string keys[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    
    keypad(n, output,keys);
}
int main()
{
	int n;
    cin >> n;
    //string* output=new string[10000];
    keypad(n, "");
    return 0;

}
