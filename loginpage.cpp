#include<iostream>
#include<vector>
using namespace std;

class user{
    private:
    string name,password;
    
    public:
    user(string username, string pass){
        name=username;
        password=pass;
    }
    string getusername(){
        return name;
    }
    string getuserpass(){
        return password;
    }
};

class usermanager{
    public:
    vector<user> users;
    
    void registation(){
        string name;
        string password;
        cout<<"Enter your name: ";
        cin>>name;
        cout<<"Enter your password: ";
        cin>>password;
        user newuser(name, password);
        users.push_back(newuser);
        cout<<"YOU HAVE SUCCESSFULLY REGISTER......"<<endl;
    }
    
    bool login(string name, string pass){
        for(int i=0;i<users.size();i++){
            if(users[i].getusername()==name && users[i].getuserpass()==pass){
                cout<<"LOGIN SUCCESSFULLY......"<<endl;
                return true;
            }
        }
        cout<<"INVALID NAME OR PASSWORD "<<endl;
        return false;
    }

    void showlist(){
        cout<<"-------USERLIST--------"<<endl;
        for(int i=0;i<users.size();i++){
            cout<<users[i].getusername()<<endl;
        }
    }

    void searchuser(string name){
        for(int i=0;i<users.size();i++){
            if(users[i].getusername()==name){
                cout<<"USER FOUND......"<<endl;
            }
        }
    }

    void deleteuser(string name){
        for(int i=0;i<users.size();i++){
            if(users[i].getusername()==name){
                users.erase(users.begin()+ i);
                cout<<"REMOVE USER SUCCESSFULLY......"<<endl;
            }
        }

    } 

};

int main(){
    usermanager us;
    int op;
    char choice;
    string name,password;
    
    do{
        system("cls");
        cout<<"\tSELECT ANY NUMBER FROM BELOW OPTION "<<endl;
        cout<<"\t1. Registration "<<endl;
        cout<<"\t2. Login "<<endl;
        cout<<"\t3. Show user list "<<endl;
        cout<<"\t4. Search user "<<endl;
        cout<<"\t5. Delete user "<<endl;
        cout<<"\t6. Exit"<<endl;
        cin>>op;
        switch(op){
        case 1:
            us.registation();
            break;
        case 2:
            cout<<"Enter your name: ";
            cin>>name;
            cout<<"Enter your password: ";
            cin>>password;
            us.login(name,password);
            break;
        case 3:
            us.showlist();
            break;
        case 4:
            cout<<"Enter name that you want to search: ";
            cin>>name;
            us.searchuser(name);
            break;
        case 5:
            cout<<"Enter name that you want to delete: ";
            cin>>name;
            us.deleteuser(name);
            break;
        case 6:
            exit(1);
            break;
        
        default:
        cout<<"Please choose correct option"<<endl;
            break;
        }
        cout<<"Do you want to continue [Yes(Y)/No(N)]"<<endl;
        cin>>choice;
  }
  while(choice=='y'||choice=='Y');
  
}