//ceaser cipher
#include<bits/stdc++.h>
using namespace std;
string E(string x,int k)
{
	string c;
    int n=x.length();
	for(int i=0;i<n;i++)
	{
		if('A'<=x[i] && x[i]<='Z')
			c += (char)((x[i]-'A'+k)%26 + 'A');
		else if('a'<=x[i] && x[i]<='z')
			c += (char)((x[i]-'a'+k)%26 + 'a');
		else
			c += x[i];
	}
	return c;
}

string D(string x,int k)
{
	string c;
    int n=x.length();
	for(int i=0;i<n;i++)
	{
		if('A'<=x[i] && x[i]<='Z')
			c += (char)((x[i]-'A'-k+26)%26 + 'A');
		else if('a'<=x[i] && x[i]<='z')
			c += (char)((x[i]-'a'-k+26)%26 + 'a');
		else
			c += x[i];
	}
	return c;
}

int main()
{
	string msg,cipher;
	int key;
	cout<<"enter the key: ";
	cin>>key;
	cout<<"enter message(pt): ";
    cin>>msg;
	// cin.ignore();
	// getline(cin, msg);
	cout<<"Cipher text: ";
	cipher = E(msg,key);
	cout<<cipher<<endl;
	cout<<"Plain text: ";
	cout<<D(cipher,key);
}