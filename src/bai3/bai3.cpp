#include<iostream>
#include<fstream>
#include<queue>
using namespace std;
int a[100][100];
int back[100];
int BFS(int dinh,int canh,int start,int finish){
	int chuaxet[100];
	queue<int> q;
	q.push(start);
	
	for(int i=1;i<=dinh;i++){
		chuaxet[i]=0;
		back[i]=0;
	}
	while(!q.empty()){
		int u = q.front();
		q.pop();
		if(u==finish){
			break;
		}
		else {
			for(int i=1;i<=dinh;i++){
				if(a[u][i]==1 && chuaxet[i]==0){
					chuaxet[i]=1;
					q.push(i);
					back[i]=u;
				}
			}
		}
	}
	
}

void duongdimin(int start,int finish,int back[]){
	int duongdi[100];
	int i=0;
	if(back[finish]==0){
		cout<<"khong tim thay duong di"<<endl;
	}
	else{
		while(finish != start){
			duongdi[i]=finish;
			finish= back[finish];
			i++;
		}
	}
	cout<<start<<" ";
	for(int j=i-1;j>=0;j--){
		cout<<duongdi[j]<<" ";
	}
}
int main(){
	int dinh,canh,start,finish;
	
	fstream f("INPUT.TXT",ios::in);
	f>>dinh;
	f>>canh;
	f>>start;
	f>>finish;
	int dau,cuoi;
	for(int i=1;i<=canh;i++){
		f>>dau;
		f>>cuoi;
		a[dau][cuoi]=1;
		a[cuoi][dau]=1;
	}
	BFS(dinh,canh,start,finish);
	duongdimin(start,finish,back);
}
