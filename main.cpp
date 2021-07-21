#include<iostream>
#include<string.h>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

int countofindex=0;

class details {
public :
    char ind[10];
    char date[10];
    char day[10];
    char mno[5];
    char mname[20];
    char fname[20];
    char calo[5];

};


bool searchfordelte(string index){

    fstream f2;
    char sdind[15];
    char sddate[15];
    char sdday[20];
    char sdmno[15];
    char sdmname[20];
    char sdfname[20];
    char sdcalo[50];
    f2.open("recordsfornutrition1.txt", ios::in);
    cout<<"1"<<endl;

    if(f2.is_open()){
        while(!f2.eof()){
            f2.getline(sdind, 50, '|');
            f2.getline(sddate, 50, '|');
            f2.getline(sdday, 50, '|');
            f2.getline(sdmno, 20, '|');
            f2.getline(sdmname, 50, '|');
            f2.getline(sdfname, 60, '|');
            f2.getline(sdcalo, 50, '\n');
            if ((string) sdind == index) {
                return true;
            }
        }
        cout<<"2"<<endl;
        f2.close();
        return false;
    }
    else{
        cout<<"File didnt open inside searchfordelete"<<endl;
        return false;
    }

}


void dothesamethingforindex(string index){

    fstream f2,f4;
    char ind[50];
    char indexstring[50];
    f2.open("indexfornutrition1.txt", ios::in);
    f4.open("deletionforindex1.txt",ios::out);
    cout<<"reaching here 1"<<endl;

    if(f2.is_open() and f4.is_open()){
        cout<<"reaching here 2"<<endl;
        while(!f2.eof()){
            f2.getline(ind, 15, '|');
            f2.getline(indexstring, 15, '\n');
            if((string)indexstring!=index){
                if((string)indexstring!="") {
                    f4 << ind << "|" << indexstring << "\n";
                }
            }
        }
        f2.close();
        f4.close();
    }
    else{
        cout<<"No optnting in dosomething"<<endl;
    }

    f2.open("indexfornutrition1.txt", ios::out);
    f4.open("deletionforindex1.txt",ios::in);

    if(f2.is_open() and f4.is_open()){
        string str;
        while (getline(f4, str))
        {
            f2 << str<<"\n" ;
        }
        f2.close();
        f4.close();
    }
    else{
        cout<<"Not opening inside dosamething"<<endl;
        return;
    }
}



void delet(string index){

    bool ans= searchfordelte(index);
    cout<<"ans:"<<ans<<endl;
    if(ans)
    {
        fstream  f1,f3;
        char dind[50];
        char ddate[50];
        char dday[50];
        char dmno[50];
        char dmname[100];
        char dfname[100];
        char dcalo[5];
        f1.open("recordsfornutrition1.txt",ios::in);
        f3.open("filefordeletion.txt",ios::out);


        if(f1.is_open() and f3.is_open()) {

            while (!f1.eof()) {
                f1.getline(dind, 20, '|');
                f1.getline(ddate, 20, '|');
                f1.getline(dday, 20, '|');
                f1.getline(dmno, 10, '|');
                f1.getline(dmname, 30, '|');
                f1.getline(dfname, 30, '|');
                f1.getline(dcalo,5,'\n');
                if ((string) dind != index) {
                    if((string) dind!=""){
                        f3 << dind <<"|" << ddate << "|" << dday << "|" << dmno << "|" << dmname <<"|" << dfname << "|" << dcalo
                           << "\n";

                    }

                }

            }

            f1.close();
            f3.close();
        }
        else{
          cout<<"Nothing:"<<endl;
            return;
        }
            f1.open("recordsfornutrition1.txt",ios::out|ios::trunc);
            f3.open("filefordeletion.txt",ios::in);
            if(f1.is_open() and f3.is_open()){
                string str;
                while (getline(f3, str))
                {
                    f1 << str<<"\n" ;
                }
                f1.close();
                f3.close();
            }
            else{
                cout<<"Not opening"<<endl;
                return;
            }

            cout<<"Deletion successfull"<<endl;
    }
    else
    {
        cout<<"Entry not found"<<endl;
        return;
    }
    dothesamethingforindex(index);
}




void read_details() {
    cout << "Enter the details";
    fstream f1,f2;
    details d;
    char temp[8];

    cout << "\ndate:";
    cin >> d.date;
    cout << "\nday:";
    cin >> d.day;
    cout << "\nmno:";
    cin >> d.mno;
    cout << "\nmname:";
    cin >> d.mname;
    cout << "\nfname:";
    cin >> d.fname;
    cout << "\ncalo:";
    cin >> d.calo;
    char makingindex[12];
    for (int i = 0; i < 8; i++) {
        makingindex[i] = d.date[i];
    }
    makingindex[8] = d.mno[0];
    makingindex[9] = d.mno[1];
    for (int i = 0; i < 10; i++) {
        d.ind[i] = makingindex[i];
    }
    f1.open("recordsfornutrition1.txt",ios::in|ios::app);

    f1 << makingindex << "|" << d.date << "|" << d.day << "|" << d.mno << "|" << d.mname << "|" << d.fname << "|" << d.calo
       << "\n";

    f1.close();

    f2.open("indexfornutrition1.txt", ios::in | ios::app);
    f2 << countofindex++ << "|" << makingindex << "\n";
    f2.close();
}


void report(string date){

    fstream f1;
    char rind[100];
    char rdate[80];
    char rday[100];
    char rmno[50];
    char rmname[200];
    char rfname[200];
    char rcalo[50];
    f1.open("recordsfornutrition1.txt",ios::in);
    if(f1.is_open()){
        while(!f1.eof()){
            f1.getline(rind, 50, '|');
            f1.getline(rdate, 50, '|');
            f1.getline(rday, 50, '|');
            f1.getline(rmno, 20, '|');
            f1.getline(rmname, 50, '|');
            f1.getline(rfname, 60, '|');
            f1.getline(rcalo, 30, '\n');
            if((string)rdate==date) {
                cout << rind << "\t" << rdate << "\t" << rday << "\t" << rmno << "\t" << rmname << "\t" << rcalo<< "\n";
            }
        }
        f1.close();
    }

}


void search(string date){
    fstream  f2;bool flag=true;
    char ind[100];char indexofnutrition[100];
    f2.open("indexfornutrition1.txt", ios::in);
      if(f2.is_open())
      {
//        cout<<"Reaching here"<<endl;
        while(!f2.eof())
        {
//            cout<<"Reaching here1"<<endl;
            f2.getline(ind, 50, '|');
            f2.getline(indexofnutrition, 50, '\n');
//            cout<<indexofnutrition<<" "<<ind<<endl;
            if(((string)indexofnutrition).substr(0,8)==date){
               report(date);
                break;
            }
            else{
                flag=false;
            }
        }
        if(!flag){
            cout<<"Not presesnt"<<endl;
        }
        f2.close();
    }
      else{
        cout<<"Not open"<<endl;
    }
}


void counttotal(string date){

    fstream f1;
    char ctind[100];
    char ctdate[80];
    char ctday[100];
    char ctmno[50];
    char ctmname[200];
    char ctfname[200];
    char ctcalo[50];
    int total=0;
    f1.open("recordsfornutrition1.txt",ios::in);
    if(f1.is_open()){
        while(!f1.eof()){

            f1.getline(ctind, 50, '|');
            f1.getline(ctdate, 50, '|');
            f1.getline(ctday, 50, '|');
            f1.getline(ctmno, 20, '|');
            f1.getline(ctmname, 50, '|');
            f1.getline(ctfname, 60, '|');
            f1.getline(ctcalo, 30, '\n');
            if(date==(string)ctdate){
                string c=(string)ctcalo;
                int sub= stoi(c);
                total=total+sub;
            }
        }
        f1.close();
        cout<<"The number of calories consumed on "<<date<<" is "<<total<<endl;
    }
    else{
        cout<<"Not opened\n";
    }
}

void write(fstream &a, fstream &b) {


}

int main() {

    fstream f1,f2;


    for(;;){


        cout<<"Enter your choice"<<endl;
        int choice;
        cout<<"1.Enter a new meal value"<<endl;
        cout<<"2.Display the report"<<endl;
        cout<<"3.Delete the report"<<endl;
        cout<<"4.Update the report"<<endl;
        cout<<"5.Exit"<<endl;
        cin>>choice;

        switch(choice){

            case 1:{
                    read_details();
                break;
            }
            case 2:
            {
                string date;
                cout<<"Enter the date"<<endl;
                cin>>date;
                search(date);
                break;
            }
            case 3:{
            cout<<"Enter index"<<endl;
            string index;
            cin>>index;
            delet(index);
            break;
            }
            case 4:{
                cout<<"Enter index"<<endl;
                string index;
                cin>>index;
                delet(index);

                read_details();
                break;
            }
            case 5:{
                exit(0);
                break;
            }
            case 6:{
                cout<<"Enter the date\n";
                string date;
                cin>>date;
                counttotal(date);
                break;
            }
            default:break;


        }

        }
    return 0;
}