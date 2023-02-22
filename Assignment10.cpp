//# pragma once
# include<iostream>
#include <fstream>
#include <iomanip>

using namespace std;

class student{
    int roll_no;
    char name[20];
    int division_no;
    char address[20];

    public :
        void getdata();
        void showdata();
        int getrollno();
}S;

void student ::getdata(){
    cout<< "\n-----------ENTER STUDENT DETAILS------------\n";
    cout<<"ENTER ROLL NUMBER :";
    cin>> roll_no;
    cout<<"ENTER NAME :";
    cin.ignore();
    cin.getline(name,20);
    cout<<"ENTER DIVISION NUMBER :";
    cin>>division_no;
    cout<<"ENTER ADDRESS :";
    cin.ignore();
    cin.getline(address,20); 
}

void student ::showdata(){
    cout<<"\n-----------STUDENT DETAILS-----------\n";
    cout<<"ROLL NUMBER :"<<roll_no<<endl;
    cout<<"NAME :"<<name<<endl;
    cout<<"DIVISION NUMBER :"<<division_no<<endl;
    cout<<"ADDRESS :"<<address<<endl;
    cout<<endl;
}

int student ::getrollno(){
    return roll_no;
}

void addData(){
    ofstream fout;
    fout.open("students.txt", ios::binary|ios::out|ios::app);
    S.getdata();
    fout.write((char*)&S,sizeof(S));
    fout.close();
    cout<<"\n\n-----------DATA SUCCESSFULLY SAVED TO FILE--------------\n";

}

void displayDATA(){
    ifstream fin;
    fin.open("students.txt",ios::in|ios::binary);
    while(fin.read((char*)&S, sizeof(S))){
        S.showdata();
    }
}
void searchData(){
    int n, flag =0;
    ifstream fin;

    fin.open("students.txt", ios::in|ios::binary);
    cout<<"ENTER ROLL NUMBER YOU WANT TO SEARCH :";
    cin>>n;
    while(fin.read((char*)&S, sizeof(S))){
        if(n == S.getrollno()){
            cout<< "THE DETAILS OF ROLL NUMBER "<<n<<" SHOWN HERE : \n";
            S.showdata();
            flag++;
        }

    }
    fin.close();
    if(flag ==0){
        cout<<" -----------THE STUDENT ROLL NUMBER"<<n<< "NOT FOUND---------\n\n";
        cout<<"\n\n---------DATA READING FROM FILE SUCCESFULLY DONE----------\n";
    }
}

void deleteDATA(){
    int n,flag=0;
    ifstream fin;
    ofstream fout, tout;

    fin.open("students.txt", ios::in|ios::binary);
    fout.open("tempstud.txt", ios::out|ios::app|ios::binary);
    tout.open("Trashstud.txt", ios::out|ios::app|ios::binary);
    cout<<"ENTER ROLL NUMBER YOU WANT TO MOVE TO TRASH :";
    cin>>n;
    while(fin.read((char*)&S, sizeof(S)));{
        if(n == S.getrollno()){
            cout<<"THE FOLLOWING ROLL NUMBER "<< n << " HAS BEEN MOVED TO TRASH :\n";
            S.showdata();
            tout.write((char*)&S, sizeof(S));
            flag++;
        }
        else{
            fout.write((char*)&S, sizeof(S));
        }
    }
    fout.close();
    tout.close();
    fin.close();
    if(flag==0){
        cout<<" -------THE STUDENT ROLL NUMBER "<< n << " NOT FOUND ------\n\n";
        remove("students.txt");
        rename("tempstud.txt", "students.txt");
    }
}

void modifyDATA(){
    int n,flag=0,pos;
    fstream fio;

    fio.open("students.txt", ios::in|ios::out|ios::binary);
    cout<<"ENTER THE ROLL NUMBER YOU WANT TO MODIFY :";
    cin>>n;
    while(fio.read((char*)&S, sizeof(S))){
        pos = fio.tellg();
        if(n == S.getrollno()){
            cout<<" THE FOLLOWING ROLL NUMBER "<< n << " WILL BE MODIFIED WITH NEW DATA :\n";
            S.showdata();
            cout<<"\n\n------NOW ENTER THE NEW DETAILS------";
            S.getdata();
            fio.seekg(pos-sizeof(S));
            fio.write((char*)&S, sizeof(S));
            flag++;
        }
    }
    if(flag == 0){
        cout<<" ----------THE ROLL NUMBER "<< n << " NOT FOUND--------\n\n"; 
    }
}

int main()
{
	    int ch;
    do{
        cout<<"--------------STUDENT DATABASE SYSTEM----------------\n";
        cout<<"=======================================================\n";
        cout<<"1. WRITE DATA TO FILE\n";
        cout<<"2. READ DATA FROM FILE\n";
        cout<<"3. SEARCH DATA FROM FILE\n";
        cout<<"4. DELETE DATA FROM FILE\n";
        cout<<"5. MODIFY DATA FROM FILE\n";
        cout<<"6. EXIT FROM THE PROGRAM\n";
        cout<<"ENTER YOUR CHOICE :";
        cin>>ch;

        switch(ch){
            case 1:
            addData();
            break;

            case 2:
            displayDATA();
            break;

            case 3:
            searchData();
            break;

            case 4:
            deleteDATA();
            break;

            case 5:
            modifyDATA();
            break;

            case 6:
            cout<<"--------THANK YOU----------";
            exit(0);
        }
    }while(ch);
    return 0;

}
