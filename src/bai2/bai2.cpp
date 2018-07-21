#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
using namespace std;
int TimKiem(char path[],char key[]){
	char *b;
	char a[250];
	int xuathien=0;
	int dong=1;
	b=a;
	fstream f(path,ios::in);
	while(!f.eof()){
			f.getline(a,250);
			b=a;
			while((b=strstr(b,key))!=NULL){
				xuathien++;
				cout<<"ln "<<dong<<", col "<<b-a<<endl;
				b++;
			}
			dong++;
		}
	cout<<key<<" xuat hien: "<<xuathien<<" lan"<<endl;
	f.close();

	
}
int ThayThe(char path[]){
	fstream f(path,ios::in);
	fstream f2("replace.txt",ios::out);
	string a,b;
	while(!f.eof()){
		
		getline(f,a);
		b.insert(b.size(),a);
		b.append("\n");
		
		
	}
	cout<<b<<endl;
	string key;
	cout<<"find key: "<<endl;
	cin>>key;
	if(b.find(key)==-1){
		cout<<"not found"<<endl;
	}
	else{
		string key2;
		cout<<"new key: "<<endl;
		cin>>key2;
		int i = b.find(key);
		while(i!=-1){
			
			b.replace(i ,key.size(),key2);
			i = b.find(key, i + key.size());
		}
		f2<<b;
		f2<<"replace "<<key<<" by "<<key2<<endl;
		cout<<"replace successfully"<<endl;
	}
	f2.close();
	return 0;
}
	
	

int main(){
	char path[100];
	char key[20];


	cout<<"nhap duong dan file"<<endl;
	cin>>path;
	fstream f(path,ios::in);
	if(f.fail()){
		cout<<"file khong hop le, vui long nhap lai"<<endl;
	}
	else{
		while(true){
			cout<<"====== MENU ======"<<endl;
		cout<<"1. Tim Kiem"<<endl;
		cout<<"2. Thay the"<<endl;
		cout<<"3. thoat"<<endl;
		int luachon;
		cout<<"nhap lua chon: "<<endl;
		cin>>luachon;
		if(luachon<1 || luachon>3){
			cout<<"vui long nhap lai"<<endl;
		}
		switch(luachon){
			case 1: 
				cout<<"nhap tu khoa: "<<endl;
				cin>>key;
				TimKiem(path,key);
				break;
			case 2:
				ThayThe(path);
				break;
			case 3: 
				exit(0);
		}
		}
	
	}
	f.close();


}
