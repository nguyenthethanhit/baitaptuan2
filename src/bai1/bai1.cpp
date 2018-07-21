#include<iostream>
#include<string>
#include<stack>
#include<fstream>
using namespace std;

int SuaLoi(string s){
	stack<char> a; // chua dau (,[,{
	stack<char> b; // chua dau ),],}
	stack<int> locationB; // chua vi tri cua dau ),],}
	fstream f("BRACKET.OUT.txt",ios::out);
	f.clear();
	
    for(int i=0;i<s.size();i++){		// neu gap dau (,[,{ -> push vao stack
        if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
            a.push(s[i]);
        }
        
        // neu s[i]==')' & a.top=='(' -> lay ( ra khoi stack. tuong tu voi nhung dau ngoac khac. 
        else if(!a.empty()){			
        	if(s[i]==')'){
        		if(a.top()=='('){
        			a.pop();
				}
				// s[i] != a.top -> push s[i] vao stack b. push vi tri cua s[i] vao stack locationB
				else{
					b.push(s[i]);
					locationB.push(i);
				}
			}
			
			if(s[i]==']'){
        		if(a.top()=='['){
        			a.pop();
				}
				else{
					b.push(s[i]);
					locationB.push(i);
				}
			}
			
			if(s[i]=='}'){
        		if(a.top()=='{'){
        			a.pop();
				}
				else{
					b.push(s[i]);
					locationB.push(i);
				}
			}	
		}
		// neu stack a = empty. push s[i] vao stack b, push vi tri cua s[i] vao stack locationB
		else if(a.empty()){
			if(s[i]==')' || s[i]==']' || s[i]=='}'){
				b.push(s[i]);
				locationB.push(i);
			}
		}
     
    }
    // ghi so ngoac can them vao file
    f<<b.size()+a.size()<<endl;
    
    // neu stack chua dau ),],} != empty
    	if(!b.empty()){
		while(!b.empty()){
			if(b.top()==')'){
				//ghi vi tri dau ) va "(" vao file. tuong tu voi nhung dau khac
				f<<locationB.top()<<" ("<<endl;
				b.pop();
				locationB.pop();
			}
			
			else if(b.top()==']'){
				f<<locationB.top()<<" ["<<endl;
				b.pop();
				locationB.pop();
			}
			
			else if(b.top()=='}'){
				f<<locationB.top()<<" {"<<endl;
				b.pop();
				locationB.pop();
			}
		}
	}
    // neu stack chua cac dau (,[,{ !=empty
    if(!a.empty()){
    	int j=s.size();
    	while(!a.empty()){
    		if(a.top()=='('){
    			// ghi vi tri cuoi cua chuoi cac dau ngoac
    			f<<j<<" )"<<endl;
    			j++;
    			a.pop();
			}
			
			else if(a.top()=='['){
    			f<<j<<" ]"<<endl;
    			j++;
    			a.pop();
			}
			
			else if(a.top()=='{'){
    			f<<j<<" }"<<endl;
    			j++;
    			a.pop();
			}
		}
	}
	f.close();
	

    
}

int main(){
	string s;
	fstream f("ngoac.txt",ios::in);
	while(!f.eof()){
		f>>s;
	}
	if(s.size()>200){
		cout<<"file khong duoc nhieu hon 200 ki tu"<<endl;
		cout<<"vui long thu lai"<<endl;
		exit(0);
	}
	else{
		SuaLoi(s);
	}
	f.close();
	return 0;
}
