#include<string>
#include<iostream>
using namespace std;
string addBinary(string a, string b) {
     	int tag=0;
        int len_a=a.size();
        int len_b=b.size();
        if(len_a==0)
            return b;
        if(len_b==0)
            return a;
        int len=len_a<len_b?len_a:len_b;
        int size=len_a>len_b?len_a:len_b;
        string result(size+1,'0');
        if(len_a>len_b)
        {
            string tmp=a;
            a=b;
            b=tmp;
        }
		len_a=a.size();
		len_b=b.size();
        int i=0;
        for(i=len-1;i>=0;i--)
        {
		len_b--;
            if(a[i]=='0'&&b[len_b]=='0')
            {   
                if(tag==1)
                {
                    result[size--]='1';
                    tag=0;
                }else
                {
                    result[size--]='0';
                    tag=0;
                }
                
            }
            else if(b[len_b]=='1'&&a[i]=='1')
            {
                if(tag==1)
                {
                    result[size--]='1';
                    tag=1;
                }else
                {
                    result[size--]='0';
                    tag=1;
                }
            }else
            {
                if(tag==1)
                {
                   result[size--]='0';
                    tag=1;
                }else
                {
                   result[size--]='1';
                    tag=0;
                }
                
            }       
        }
        {
            for(i=len_b-1;i>=0;i--)
            {
                if(tag==1&&b[i]=='1')
                {
                    result[size--]='0';
                    tag=1;
                }else if(tag==1&&b[i]=='0')
                {
                    result[size--]='1';
                    tag=0;
                }
                else if(tag==0)
                {
                    result[size--]=b[i];
                    tag=0;
                }
            }
        }
         if(tag==1)
            result[0]='1';
        if(result[0]=='0')
            result.erase(0,1);
        return result;
        
        
    }


int main()
{
	string b="1010";
	string a="1011";
	cout<<addBinary(a,b);
}
