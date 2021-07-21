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
    char sdind[100];
    char sddate[80];
    char sdday[100];
    char sdmno[50];
    char sdmname[200];
    char sdfname[200];
    char sdcalo[50];
    f2.open("recordsfornutrition1.txt", ios::in);

    if(f2.is_open()){
        while(!f2.eof()){
            f2.getline(sdind, 50, '|');
            f2.getline(sddate, 50, '|');
            f2.getline(sdday, 50, '|');
            f2.getline(sdmno, 20, '|');
            f2.getline(sdmname, 50, '|');
            f2.getline(sdfname, 60, '|');
            f2.getline(sdcalo, 30, '\n');
            if ((string) sdind == index) {
                return true;
            }
        }
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
    f4.open("deletionforindex1.txt",ios::out|ios::trunc);
    cout<<"reaching here 1"<<endl;

    if(f2.is_open() and f4.is_open()){
        cout<<"reaching here 2"<<endl;
        while(!f2.eof()){
            f2.getline(ind, 50, '|');
            f2.getline(indexstring, 15, '\n');
            if((string)indexstring!=index){
                f4<<ind<<"|"<<indexstring<<"\n";
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
//    cout<<"ans:"<<ans<<endl;
    if(ans)
    {
        fstream  f1,f3;
        char dind[100];
        char ddate[80];
        char dday[100];
        char dmno[50];
        char dmname[200];
        char dfname[200];
        char dcalo[5];
        f1.open("recordsfornutrition1.txt",ios::in);
        f3.open("filefordeletion.txt",ios::out);


        if(f1.is_open() and f3.is_open()) {

            while (!f1.eof()) {
                f1.getline(dind, 50, '|');
                f1.getline(ddate, 50, '|');
                f1.getline(dday, 50, '|');
                f1.getline(dmno, 20, '|');
                f1.getline(dmname, 50, '|');
                f1.getline(dfname, 60, '|');
                f1.getline(dcalo,50,'\n');
                if ((string) dind != index) {
                    f3 << dind <<'|' << ddate << '|' << dday << '|' << dmno << '|' << dmname <<'|' << dfname << '|' << dcalo
                       << "\n";
                }

                cout<<"reached10111111111"<<endl;
            }
            cout<<"reached10"<<endl;
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
                    f1 << str ;
                }
                f1.close();
                f3.close();
            }
            else{
                cout<<"Not opening"<<endl;
                return;
            }
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
    fstream  f2;
    char ind[100];char indexofnutrition[100];
    f2.open("indexfornutrition1.txt", ios::in);
      if(f2.is_open())
      {
        cout<<"Reaching here"<<endl;
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
                cout<<"Not presest"<<endl;
            }
        }
        f2.close();
    }
      else{
        cout<<"Not open"<<endl;
    }
}

void write(fstream &a, fstream &b) {


}

//void display(fstream &f1){
//
//
//    while(!f1.eof()){
//
//        f1.getline(dind,10,'|');
//        f1.getline(ddate,8,'|');
//        f1.getline(dday,10,'|');
//        f1.getline(dmno,5,'|');
//        f1.getline(dmname,20,'|');
//        f1.getline(dfname,20,'|');
//        f1.getline(dcalo,5,'|');
//        cout<<ddate<<"\t"<<dday<<"\t"<<dmno<<"\t"<<dmname<<"\t"<<dfname<<"\t"<<dcalo<<endl;
//    }
//    f1.close();
//}


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


            case 3:break;
            case 4:break;
            case 5:{
                exit(0);
                break;

            }


            default:break;


        }

        }


//    cout << "USN\t NAME\t AGE\t SEM\t BRANCH\n";
//    char dind[100];
//    char ddate[80];
//    char dday[100];
//    char dmno[50];
//    char dmname[200];
//    char dfname[200];
//    char dcalo[50];
////    while (!f1.eof())
//    {
//    f1.open("recordsfornutrition1.txt",ios::in|ios::app);
//
//    if(f1.is_open()){
//        while(f1.eof()){
//            f1.getline(dind, 50, '|');
//            f1.getline(ddate, 50, '|');
//            f1.getline(dday, 50, '|');
//            f1.getline(dmno, 20, '|');
//            f1.getline(dmname, 50, '|');
//            f1.getline(dfname, 60, '|');
//            f1.getline(dcalo, 30, '\n');
//            cout << dind << "\t" << ddate << "\t" << dday << "\t" << dmno << "\t" << dmname <<"\t"<<dcalo<<"\n";
//        }

//        cout<<"ddate->"<<ddate<<" ";
//        f1.close();
//    }
//    else{
//        cout<<"Not open"<<endl;
//    }

//    }

//    cout<<"Enter the date"<<endl;
//    char srcdate[8];
//    for(int i=0;i<8;i++){
//        cin>>srcdate[i];
//    }
//    search(srcdate);

//cout<<"Enter index"<<endl;
//string index;
//cin>>index;
//
//    delet(index);

    return 0;
}