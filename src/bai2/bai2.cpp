#include<iostream>
#include<string>
#include<fstream>
#include<queue>
using namespace std;
//sử dụng hàm find() để tìm từ khóa và hàm replace() để thay thế từ khóa
void TimKiem(string key,char path[]){
    fstream f(path,ios::in);
    fstream f2("output.txt",ios::out);
    string a;
    queue<int> ln;      //queue chứa các dòng
    queue<int> col;     // chứa các vị trí của keyword
    int dong=1;
    while(!f.eof()){
        getline(f,a);   // đọc từng dòng trong file
        int i = a.find(key);
        while(i!=-1){
            ln.push(dong);  //push dòng vào ln
            col.push(i);    // push vị trí xuất hiện của từ vào col
            i = a.find(key,i+key.size()-1);
        }
        dong++;
    }
    // số lần xuất hiện của key = số lượng phần tử trong queue
    cout<<key<<" xuat hien: "<<col.size()<<" lan"<<endl;
    f2<<key<<" xuat hien: "<<col.size()<<" lan"<<endl;
    while(!col.empty()){
        cout<<"ln "<<ln.front()<<" ,col: "<<col.front()<<endl;
        f2<<"ln "<<ln.front()<<" ,col: "<<col.front()<<endl;
        ln.pop();
        col.pop();

    }
    f.close();
    f2.close();
}
void ThayThe(char path[],string b){
    
    string key, newkey;
    cout<<"find key: "<<endl;
    cin>>key;
    key.append(" ");    //thêm khoảng trắng vào sau key để không tìm đến từ có chứa key bên trong vd: abcKEYcba
    cout<<"new key"<<endl;
    cin>>newkey;
    newkey.append(" ");
    fstream f(path,ios::out);
    
    fstream f2("output.txt",ios::out);
   // đưa tất cả nội dung của file vào string b. sau đó thực hiện tìm kiếm
    if(b.find(key)==-1){
        cout<<"not found "<<key<<endl;

    }else{
        int i = b.find(key);    // vị trí đầu tiên của key trong b
        while(i!=-1){
            b.replace(i,key.size(),newkey); // thay thế key bằng newkey
            i = b.find(key,i+key.size());   // vị trí tiếp theo của key trong string b
        }
        cout<<"replace "<<key<<" by "<<newkey<<" successfully"<<endl;
        f<<b;   // ghi string b đã thay thế vào file input.txt
        f2<<"replace "<<key<<" by "<<newkey<<" successfully"<<endl; //ghi lịch sử vào file output.txt
    }
    f.close();
    f2.close();


}

int main(){
    string key;
    string a,b;
    char path[20];
    nhapfile:cout<<"nhap file: "<<endl;
    cin>>path;
    fstream f(path,ios::in);
    // kiểm tra file có hợp lệ hay không
    if(f.fail()){
        cout<<"file khong hop le, vui long nhap lai"<<endl;
        goto nhapfile;
    }
    else{
        while(true){
            cout<<"================ MENU ================"<<endl;
            cout<<"1. Tim Kiem"<<endl;
            cout<<"2. Thay The"<<endl;
            cout<<"3. Thoat"<<endl;
            int luachon;
            nhaplai:cout<<"================ nhap lua chon ================"<<endl;
            cin>>luachon;
            if(luachon<1 || luachon>3){
                cout<<"lua chon khong hop le, vui long nhap lai"<<endl;
                goto nhaplai;
            }
            else{
                switch(luachon){
                    case 1: 
                        cout<<"nhap key: "<<endl;
                        cin>>key;
                        key.append(" ");    //thêm khoảng trắng vào key để hàm find() chỉ tìm đúng từ key, không tìm từ xxxKEYxxx
                        TimKiem(key,path);  // truyền key và đường dẫn file vào hàm TimKiem()
                        break;
                    case 2:
                     while(!f.eof()){
                        getline(f,a);
                        b.append(a);
                        b.append("\n");
                    }
                    // chuyển toàn bộ nội dung từ file sang string b, sau đó truyền vào hàm ThayThe()
                        ThayThe(path,b);
                        break;
                    case 3:
                        exit(0);

                }
            }
        }
    }
    return 0;
}