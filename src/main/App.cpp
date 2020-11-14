#include <iostream>
#include <string>

#define MAX 1000

using namespace std;

struct Person{
    string m_Name;
    int m_Sex;
    int m_Age;
    string m_Phone;
    string m_Addr;
};

struct Addressbooks{
    struct Person personArray[MAX];
    int m_Size;
};

void addPerson(Addressbooks *abs){
    if(abs -> m_Size ==MAX){
        cout << "通讯录已满 ，无法添加" << endl;
        return;
    }else{
        string name;
        cout << "请输入姓名: " << endl;
        cin >> name;
        abs->personArray[abs->m_Size].m_Name = name;
        cout << "请输入性别：" << endl;
        cout << "1 -- 男"<< endl;
        cout << "2 -- 女"<< endl;

        int sex = 0;
        while(true){
            cin >> sex;
            if(sex == 1 || sex == 2){
                abs ->personArray[abs->m_Size].m_Sex = sex;
                break;
            }
            cout << "输入有错，请重新输入";
        }

        cout << "请输入年龄： "<< endl;
        int age  =0;
        cin >> age;
        abs->personArray[abs->m_Size].m_Age = age;

        cout << "请输入联系电话：  "<< endl;
        string phone = "";
        cin >> phone;
        abs->personArray[abs->m_Size].m_Phone = phone;

        cout << "请输入家庭地址:  " <<endl;
        string address;
        cin >> address;
        abs->personArray[abs->m_Size].m_Addr = address;
        
        abs->m_Size++;
        cout << "添加成功" << endl;
        
        // cin.get();
        // system("reset");
    }

}

void showAllPersion(Addressbooks *abs){
    if(abs->m_Size == 0){
        cout << "当前记录为空 " << endl;
    }else{
        int size = abs->m_Size;

        for(int i = 0; i < size; i++){
            cout <<"姓名： " << abs->personArray[i].m_Name <<"\t"
                <<"性别：" << (abs->personArray[i].m_Sex == 1 ? "男":"女" )<< "\t"
                <<"年龄：" << abs->personArray[i].m_Age << "\t"
                <<"电话：" << abs->personArray[i].m_Phone << "\t"
                << "住址：" << abs->personArray[i].m_Addr << endl;
        }        
    }

    // cin.get();
    // system("reset");
}

int isExist(Addressbooks *abs,string name){
    for(int i = 0; i < abs->m_Size; i++){
        if(abs->personArray[i].m_Name == name){
            return i;
        }
    }
    return -1;
}



void deletePersion(Addressbooks *abs){

    cout << "请输入要删除的联系人"<< endl;
    string name ;
    cin >> name;

    int ret = isExist(abs,name);
    if(ret != -1){
        for(int i = ret; i< abs->m_Size; i++){
            abs->personArray[i] = abs->personArray[i + 1];
        }
        abs->m_Size--;
        cout << "删除成功" << endl;
    }else{
        cout << "查无此人" << endl;
    }
    // cin.get();
    // system("reset");
}

void searchPersion(Addressbooks *abs){
    cout << "请输入要查找的人姓名" << endl;
    string name;
    cin >> name;

    int ret = isExist(abs,name);
    if(ret != -1){
            cout <<"姓名： " << abs->personArray[ret].m_Name <<"\t"
                <<"性别" << (abs->personArray[ret].m_Sex == 1 ? "男":"女" )<< "\t"
                <<"年龄：" << abs->personArray[ret].m_Age << "\t"
                <<"电话：" << abs->personArray[ret].m_Phone << "\t"
                << "住址：" << abs->personArray[ret].m_Addr << endl;
    }else{
        cout << "查无此人"<< endl;
    }
    // cin.get();
    // system("reset");
}

void modifyPerson(Addressbooks *abs){
    cout << "请输入你要修改的联系人" << endl;
    string name;
    cin >> name;

    int ret = isExist(abs,name);
    if(ret != -1){
        string name;
        cout << "不支持修改" << endl;
    }else{
        cout << "查无此人" << endl;
    }
}

void cleanPersion(Addressbooks *abs){
    abs->m_Size = 0;
    cout << "通讯录已清空" << endl;
    // system("reset");
}

void showMenu(){
	cout << "***************************" << endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  0、退出通讯录  *****" << endl;
	cout << "***************************" << endl;
}

int main(){

    Addressbooks abs;
    abs.m_Size = 0;

    int select  = 0;
    
    while(true){
        showMenu();
        cin >> select;

        switch(select){
            case 1:
                addPerson(&abs);
                // system("reset");
                break;
            case 2:
                showAllPersion(&abs);
                // system("reset");
                break;
            case 3:
                deletePersion(&abs);
                // system("reset");
                break;
            case 4:
                searchPersion(&abs);
                // system("reset");
                break;
            case 5:
                modifyPerson(&abs);
                break;
            case 6:
                cleanPersion(&abs);
                break;
            case 0:
                cout << "欢迎下次使用" << endl;
                // system("reset");
                return 0;
                break;
            default:
                break;
        }
    }
    // cin.get();
    // system("reset");
    return 0;
}    
