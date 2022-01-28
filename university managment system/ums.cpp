#include<iostream>
using namespace std;
#include<string.h>
#include<fstream>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<time.h>
#include<conio.h>
#include<iomanip>
class ums
{
private:
    char time[20];
    int block;
    int roomno;
    char subjectname[30];
    char dayname[30];
    char date[30];
    char studentname[30];
    char fathername[30];
    char mothername[30];
    char address[100];
    int percentage;
    char branch[30];
    char name[30];
    int ISBN;
    char title[30];
    char author[30];
    int edition;
    int quantity;
    int code;
    char message1[100];
    int number;
    int age;
    int validity;
    int booked;
    int totalclass;
    int present;
    int marks=0;
    int fullmarks=100;
    char assignment[100];
public:
    ums()
    {
    ISBN=0;
    booked=0;
    strcpy(title,"No title");
    strcpy(author,"No author");
    edition=0;
    quantity=0;
    code=0;
    age=0;
    validity=0;
    strcpy(name,"No name");
    booked=0;
    strcpy(message1,"no message avalable");
    number=0;
    strcpy(subjectname,"No name");
    strcpy(dayname,"No day name");
    strcpy(date,"No date");
    strcpy(studentname,"No name");
    strcpy(fathername,"No name");
    strcpy(mothername,"No name");
    strcpy(address,"No name");
    strcpy(branch,"No name");
    strcpy(assignment,"No name");
    strcpy(name,"No name");
    present=0;
    totalclass=50;


    }


    void add_lecture_time_table();
    void add_examintion_department();
    void add_admission();
    void add_announcement();
    void add_attendance();
    void add_marks();
    void add_assignment();




    //
    void show_lecture_time_table();
    void show_lecture_time_table_title();
    void show_examintaion_department();
    void show_examintaion_department_title();
    void show_admission();
    void show_admission_title();
    void show_announcement();
    void show_attendance_title();
    void show_attendance();
    void show_marks();
    void show_marks_title();
    void show_assignment();
    void show_assignment_title();


    //
    void store_lecture_time_table();
    void store_examintaion_department();
    void store_admission();
    void store_announcement();
    void store_attendance();
    void store_marks();
    void store_assignment();




    //
    void view_all_lecture_time_table();
    void view_all_examintaion_department();
    void view_all_admission();
    void view_announcement();
    void view_all_attendance();
    void view_all_marks();
    void view_all_assignment();

    //
    void search_examintaion(char *);
    void search_addmission(char *);
    void search_lecture_time_table(char *);
    void search_marks(char *);
    //
    void update_examintion(char *);
    void update_admission(char *);
    void update_time_table(char *);
    void update_time_table_after(int);
    void search_lecture_time_table(int);
    void update_attendance(int);
    void update_marks(char *);

    //library
    void addBook();
    void addMember();
    void showData();
    void display();
    void showNameBook();
    void showNameMember();
    void showMember();
    int storeBook();
    int storeMember();
    void viewStocks();
    void viewMember();
    void searchBook(char *);
    void searchMember(char *);
    void removeBook(char *);
    void removeMember(char *);
    void UpdateBook(char *);
    void UpdateMember(char *);
    int UpdateIssueBooked(char *);
    void issueBook(char *);
    //
};
class issue
{
private:
    char name[20];
    ums obj;
public:
    void generate(char cname[],ums b)
    {
        strcpy(name,cname);
        obj=b;
    }
    void disp()
    {
       cout<<"Name of student="<<name;
        obj.display();
    }
};



//library part starts
   void ums::addBook()
{
    cout<<"\nEnter Isbn no:";
    cin>>ISBN;
    cout<<"Enter title  :";
    cin.ignore();
    cin.getline(title,29);
    cout<<"Enter author :";
    cin.getline(author,29);
    cout<<"Enter edition:";
    cin>>edition;
    cout<<"Enter quantity:";
    cin>>quantity;
}

void  ums::addMember()
{
    cout<<"\nEnter code:";
    cin>>code;
    cout<<"Enter Name:";
    cin.ignore();
    cin.getline(name,20);
    cout<<"Enter Mobile No:";
    cin>>number;
    cout<<"Enter age:";
    cin>>age;
    cout<<"Enter validity";
    cin>>validity;
    cout<<"subjectname";
    cin>>subjectname;
}
void ums::showNameBook()
{
    cout<<"ISBN"<<setw(10)<<"title"<<setw(11)<<"author"<<setw(12)<<"edition"<<setw(11)<<"booked"<<setw(13)<<"quantity"<<"\n";
    cout<<"--------------------------------------------------------------------\n";

}
void ums::showData()
{
    cout<<ISBN<<setw(10)<<title<<setw(11)<<author<<setw(12)<<edition<<setw(11)<<booked<<setw(13)<<quantity<<"\n";

}
void ums::showNameMember()
{
    cout<<"code"<<setw(9)<<"name"<<setw(11)<<"number"<<setw(8)<<"age"<<setw(13)<<"validity"<<setw(17)<<"subject name"<<"\n\n";
}
void ums::showMember()
{
    cout<<code<<setw(9)<<name<<setw(11)<<number<<setw(8)<<age<<setw(13)<<validity<<setw(17)<<subjectname<<endl;
}

void ums::display()
{
    cout<<"\nBook details ";
    cout<<"\nISBN=   ="<<ISBN;
    cout<<"\ntitle=  ="<<title;
    cout<<"\nauthor= ="<<author;
    cout<<"\nEdition ="<<edition;
    cout<<"\nBooked  ="<<booked;
    cout<<"\nQuantity="<<quantity;
    cout<<"\n----------------------------\n";
}
int ums::storeBook()
{
    ofstream fout;
    if(ISBN==0&&quantity==0)
    {
        cout<<"Data not initialized";
        return 0;
    }

    else
    {
       fout.open("lab.dat",ios::app|ios::binary);
       fout.write((char*)this,sizeof(*this));
       cout<<"\t\t\t Book added successfully";
       return 1;
    }

}

int ums::storeMember()
{
    ofstream fout;
    if(code==0&&age==0)
    {
        cout<<"Data not initialized";
        return 0;
    }

    else
    {
       fout.open("member.dat",ios::app|ios::binary);
       fout.write((char*)this,sizeof(*this));
       cout<<"\t\t\t Member added successfully";
       return 1;
    }

}


void ums::searchBook(char *t)
{
    ifstream fin;
    int flag=0;
    fin.open("lab.dat",ios::in|ios::binary);
    if(!fin)
        cout<<"File not found";
    else
    {
        fin.read((char*)this,sizeof(*this));
        while(!fin.eof())
        {
            if(!strcmp(author,t))
            {
                showData();
                flag=1;
            }
            fin.read((char*)this,sizeof(*this));

        }
        if(flag==0)
            cout<<" Book not found";
    }
}
int ums::UpdateIssueBooked(char *t)
{
   fstream file;
   int x=0;
   file.open("lab.dat",ios::in|ios::out|ios::ate|ios::binary);
   file.seekg(0);
   file.read((char*)this,sizeof(*this));
   if(!file)
    cout<<"File not found";
       while(!file.eof())
       {
           if(!strcmp(author,t))
           {
                booked++;
                quantity--;
                x++;
                file.seekp(file.tellp()-sizeof(*this));
                file.write((char*)this,sizeof(*this));


           }
           if(x==1)
           {
              file.close();
              return 0;
           }

           file.read((char*)this,sizeof(*this));
       }


}

void ums::searchMember(char *t )
{
     ifstream fin;
    int flag=0;
    fin.open("member.dat",ios::in|ios::binary);
    if(!fin)
        cout<<"File not found";
    else
    {
        fin.read((char*)this,sizeof(*this));
        while(!fin.eof())
        {
            if(!strcmp(name,t))
            {
                showMember();
                flag=1;
            }
            fin.read((char*)this,sizeof(*this));

        }
        if(flag==0)
            cout<<" Member not found";
    }
}

void ums::viewStocks()
{
    ifstream fin;
    int choice;
    char author[30];
    int totalBooks=0;
    cout<<"\t 1.All Books\n";
    cout<<"\t 2.search Book\n";
    cout<<"\t Enter your choice";
    cin>>choice;
    switch(choice)
    {
    case 1:
        fin.open("lab.dat",ios::in|ios::binary);
    if(!fin)
        cout<<"\nFile not found";
    else
      {
       fin.read((char*)this,sizeof(*this));
       showNameBook();
         while(!fin.eof())
         {
            totalBooks++;
            showData();
            fin.read((char*)this,sizeof(*this));
         }
         cout<<"total no of books "<<totalBooks;

       }
       break;
    case 2:
        cout<<"Enter author name:";
        cin.ignore();
        cin.getline(author,29);
        searchBook(author);
        break;


    }
}

void ums::viewMember()
{
    ifstream fin;
    int choice;
    char name[30];
    int totalmember=0;
    cout<<"\t\t\t\t\t\t\t\t1.All Members\n";
    cout<<"\t\t\t\t\t\t\t\t2.search Member\n";
    cout<<"\t\t\t\t\t\t\t\tEnter your choice";
    cin>>choice;
    switch(choice)
    {
    case 1:
        fin.open("member.dat",ios::in|ios::binary);
    if(!fin)
        cout<<"\nFile not found";
    else
      {
       fin.read((char*)this,sizeof(*this));
       showNameMember();
         while(!fin.eof())
         {
            totalmember++;
            showMember();
            fin.read((char*)this,sizeof(*this));
         }
         cout<<"total no of Members "<<totalmember;

       }
       break;
    case 2:
        cout<<"Enter member name:";
        cin.ignore();
        cin.getline(name,29);
        searchMember(name);
        break;


    }
}

void ums::removeBook(char *t)
{
    ifstream fin;
    ofstream fout;
    fin.open("lab.dat",ios::in|ios::binary);
    if(!fin)
        cout<<"File not found";
    else
    {
        fout.open("temp.dat",ios::out|ios::binary);
        fin.read((char*)this,sizeof(*this));
        while(!fin.eof())
        {
            if(strcmp(t,author))
            {

                fout.write((char*)this,sizeof(*this));
            }
            fin.read((char*)this,sizeof(*this));
        }
        fin.close();
        fout.close();
        remove("lab.dat");
        rename("temp.dat","lab.dat");
        cout<<"\n Book removed successfully";
    }
}

void ums::removeMember(char *t)
{
    ifstream fin;
    ofstream fout;
    fin.open("member.dat",ios::in|ios::binary);
    if(!fin)
        cout<<"File not found";
    else
    {
        fout.open("tempMember.dat",ios::out|ios::binary);
        fin.read((char*)this,sizeof(*this));
        while(!fin.eof())
        {
            if(strcmp(t,name))
            {

                fout.write((char*)this,sizeof(*this));
            }
            fin.read((char*)this,sizeof(*this));
        }
        fin.close();
        fout.close();
        remove("member.dat");
        rename("tempMember.dat","member.dat");
        cout<<"\n Member removed successfully";
    }
}

void ums::UpdateBook(char *t)
{
    fstream file;
    file.open("lab.dat",ios::in|ios::out|ios::ate|ios::binary);
    file.seekg(0);
    file.read((char*)this,sizeof(*this));
    while(!file.eof())
    {
        if(!strcmp(t,author))
        {
            addBook();
            file.seekp(file.tellp()-sizeof(*this));
            file.write((char*)this,sizeof(*this));
        }
        file.read((char*)this,sizeof(*this));
    }
    file.close();
    cout<<"Data updated successfully";
}
void ums::UpdateMember(char *t)
{
     fstream file;
    file.open("member.dat",ios::in|ios::out|ios::ate|ios::binary);
    file.seekg(0);
    file.read((char*)this,sizeof(*this));
    while(!file.eof())
    {
        if(!strcmp(t,name))
        {
            addMember();
            file.seekp(file.tellp()-sizeof(*this));
            file.write((char*)this,sizeof(*this));
        }
        file.read((char*)this,sizeof(*this));
    }
    file.close();
    cout<<"Data updated successfully";
}
//library managment part end

//add part
void ums::add_marks()
{
    cout<<"enter code of subject";
    cin>>code;
    cout<<"enter subject name";
    cin.ignore();
    cin>>subjectname;
    cout<<"Eneter marks";
    cin>>marks;


}
void ums::add_attendance()
{
    present++;
    cout<<"Enter subject code";
    cin>>code;
    cout<<"Enter subject name";
    cin.ignore();
    cin.getline(subjectname,29);
    percentage=50*(present/100);
}
void ums::add_lecture_time_table()
{
    cout<<"\nEnter Time::";
    cin.ignore();
    cin.getline(time,29);
    cout<<"\nEnter Block::";
    cin>>block;
    cout<<"\nEtner room no::";
    cin>>roomno;
    cout<<"\nEnter subject name::";
    cin.ignore();
    cin.getline(subjectname,29);
    cout<<"\nEnter day name::";
    cin.ignore();
    cin.getline(dayname,29);
    cout<<"\nEnter Branch::";
    cin.ignore();
    cin.getline(branch,29);

}

void ums::add_examintion_department()
{
    cout<<"\nEnter date";
    cin.ignore();
    cin>>date;
    cout<<"\nEnter Time::";
    cin.ignore();
    cin.getline(time,29);
    cout<<"\nEnter Block::";
    cin>>block;
    cout<<"\nEtner room no::";
    cin>>roomno;
    cout<<"\nEnter subject name::";
    cin.ignore();
    cin.getline(subjectname,29);
    cout<<"\nEnter day name::";
    cin.ignore();
    cin.getline(dayname,29);

}
void ums::add_assignment()
{
    cout<<"Enter subject code";
    cin>>code;
    cout<<"Enter subject name";
    cin.ignore();
    cin.getline(subjectname,20);
    cout<<"Assignment name";
    cin.ignore();
    cin.getline(assignment,90);


}
void ums::add_admission()
{
    cout<<"\nEnter student name::";
      cin.ignore();
    cin.getline(name,29);
    cout<<"\nEnter Father name::";
      cin.ignore();
    cin.getline(fathername,29);
      cin.ignore();
    cout<<"\nEnter mother name::";
      cin.ignore();
    cin.getline(mothername,29);
      cin.ignore();
    cout<<"\nEnter Address";
      cin.ignore();
    cin.getline(address,99);
    cout<<"\nEnter percentage in 12th";
    cin>>percentage;


}
void ums::add_announcement()
{
    cout<<"Enter Branch name";
    cin.ignore();
    cin.getline(branch,20);
    cout<<"Write message for student";
      cin.ignore();
    cin.getline(message1,100);
}
// add part end
//show part
void ums::show_assignment()
{
    cout<<"\ncode="<<code;
    cout<<"\nsubjcet name"<<subjectname;
    cout<<"\nAssignment name"<<assignment;
}
void ums::show_marks()
{
    cout<<code<<setw(20)<<subjectname<<setw(19)<<fullmarks<<setw(15)<<marks<<endl;

}
void ums::show_marks_title()
{

    cout<<"code"<<setw(20)<<"subjectname"<<setw(19)<<"fullmarks"<<setw(15)<<"marks"<<endl;
    cout<<"---------------------------------------------------------------------------\n\n";
}
void ums::show_lecture_time_table()
{
    cout<<subjectname<<setw(15)<<block<<setw(16)<<roomno<<setw(14)<<time<<setw(17)<<dayname<<endl;
}

void ums::show_examintaion_department()
{
    cout<<date<<setw(21)<<subjectname<<setw(15)<<block<<setw(16)<<roomno<<setw(14)<<time<<setw(17)<<dayname<<endl;
}
void ums::show_examintaion_department_title()
{
    cout<<"Date"<<setw(11)<<"subjectname"<<setw(15)<<"block"<<setw(16)<<"roomno"<<setw(14)<<"time"<<setw(17)<<"dayname"<<endl;
    cout<<"----------------------------------------------------------------------------\n";
}

void ums::show_lecture_time_table_title()
{
    cout<<"subjectname"<<setw(15)<<"block"<<setw(16)<<"roomno"<<setw(14)<<"time"<<setw(17)<<"dayname"<<endl;
    cout<<"----------------------------------------------------------------------------\n";
}
void ums::show_admission()
{
    cout<<studentname<<setw(20)<<fathername<<setw(18)<<mothername<<setw(20)<<percentage<<setw(16)<<branch<<endl;
}
void ums::show_admission_title()
{
    cout<<"studentname"<<setw(20)<<"fathername"<<setw(18)<<"mothername"<<setw(20)<<"percentage"<<setw(16)<<"branch"<<endl;
    cout<<"----------------------------------------------------------------------------\n";
}
void ums::show_announcement()
{
    cout<<"\n\nToday Annoucement";
    cout<<"branch="<<branch;
    cout<<"\n\n";
    cout<<message1;
}
void ums::show_attendance_title()
{
    cout<<"\t\t Your attendance\n\n";
    cout<<"code"<<setw(21)<<"subjectname"<<setw(16)<<"present"<<setw(20)<<"totalclass"<<setw(20)<<"percentage %\n";
    cout<<"-----------------------------------------------------------------------------------------------------\n\n";
}
void ums::show_attendance()
{
    cout<<code<<setw(21)<<subjectname<<setw(16)<<present<<setw(20)<<totalclass<<setw(20)<<percentage;
}


//show part end;
//store part starts
void ums::store_assignment()
{
    ofstream fout;
    fout.open("assignment.dat",ios::out|ios::binary);
    fout.write((char*)this,sizeof(*this));
    fout.close();
}
void ums::store_marks()
{
    ofstream fout;
    fout.open("marks.dat",ios::out|ios::binary);
    fout.write((char*)this,sizeof(*this));
    fout.close();
}
void ums::store_attendance()
{
    ofstream fout;
    fout.open("attendance.dat",ios::out|ios::binary);
    fout.write((char*)this,sizeof(*this));
    fout.close();
}
void ums::store_announcement()
{
    ofstream fout;
    fout.open("annoucement.dat",ios::out|ios::binary);
    fout.write((char*)this,sizeof(*this));
    fout.close();
}
void ums::store_lecture_time_table()
{


    ofstream fout;
    fout.open("timetable.dat",ios::app|ios::binary);
    fout.write((char*)this,sizeof(*this));
    fout.close();
    cout<<"\nTime table added successfully in Database";


}
void ums::store_examintaion_department()
{


    ofstream fout;
    fout.open("examintion.dat",ios::app|ios::binary);
    fout.write((char*)this,sizeof(*this));
    fout.close();
    cout<<"\nExamintion table added successfully in Database";


}

void ums::store_admission()
{
     ofstream fout;
    fout.open("admission.dat",ios::app|ios::binary);
    fout.write((char*)this,sizeof(*this));
    fout.close();
    cout<<"\nstudent details added successfully in Database";
}
// store data code end;
//view all database
void ums::view_all_assignment()
{
    int x=0;
    ifstream fin;
    fin.open("assignment.dat",ios::in|ios::binary);
    fin.read((char*)this,sizeof(*this));
    if(!fin)
        cout<<"Data not avalable";
        else
        {
            while(!fin.eof())
    {
        show_assignment();
        fin.read((char*)this,sizeof(*this));
        x++;

    }
        }

    fin.close();
    cout<<"\n\n total assignment ="<<x;
}
void ums::view_all_marks()
{
    int x=0;
    ifstream fin;
    fin.open("marks.dat",ios::in|ios::binary);
    fin.read((char*)this,sizeof(*this));
    if(!fin)
        cout<<"Data not avalable";
    else

    {
         show_marks_title();
        while(!fin.eof())
    {
        show_marks();
        fin.read((char*)this,sizeof(*this));
        x++;

    }
    }

    fin.close();
    cout<<"\n\n total subject ="<<x;
}
void ums::view_all_attendance()
{
    int x=0;
    ifstream fin;
    fin.open("attendance.dat",ios::in|ios::binary);
    fin.read((char*)this,sizeof(*this));
    if(!fin)
        cout<<"Data not avalable";
        else
    {


    show_attendance_title();

    while(!fin.eof())
    {
        show_attendance();
        fin.read((char*)this,sizeof(*this));
        x++;

    }
    }
    fin.close();
    cout<<"\n\n total annoucemnt="<<x;
}
void ums::view_announcement()
{
    int x=0;
    ifstream fin;
    fin.open("annoucement.dat",ios::in|ios::binary);
    fin.read((char*)this,sizeof(*this));
    if(!fin)
        cout<<"Data not avalable";
        else
        {
             while(!fin.eof())
    {
        show_announcement();
        fin.read((char*)this,sizeof(*this));
        x++;

    }
    fin.close();
        }

    cout<<"\n\n total annoucemnt="<<x;
}
void ums::view_all_lecture_time_table()
{
    ifstream fin;
    int x=0;
    fin.open("timetable.dat",ios::in|ios::binary);
    fin.read((char*)this,sizeof(*this));
    if(!fin)
        cout<<"Data not avalable\n";
    else
    {
        show_lecture_time_table_title();
        while(!fin.eof())
        {
          show_lecture_time_table();
          fin.read((char*)this,sizeof(*this));
          x++;
        }
        fin.close();
    }
    cout<<"Total Number of time table"<<x;
}

void ums::view_all_examintaion_department()
{
    ifstream fin;
    int x=0;
    fin.open("examintion.dat",ios::in|ios::binary);
    fin.read((char*)this,sizeof(*this));
    if(!fin)
        cout<<"Data not avalable\n";
    else
    {
        show_examintaion_department_title();
        while(!fin.eof())
        {
          show_examintaion_department();
          fin.read((char*)this,sizeof(*this));
          x++;
        }
        fin.close();
    }
    cout<<"Total Number of time table"<<x;
}

void ums::view_all_admission()
{
    ifstream fin;
    int x=0;
    fin.open("admission.dat",ios::in|ios::binary);
    fin.read((char*)this,sizeof(*this));
    if(!fin)
        cout<<"Data not avalable\n";
    else
    {
        show_admission_title();
        while(!fin.eof())
        {
          show_admission();
          fin.read((char*)this,sizeof(*this));
          x++;
        }
        fin.close();
    }
    cout<<"Total Number of student "<<x;
}


//view all database code end;
// search code begin
void ums::search_marks(char *t)
{
    ifstream fin;
    fin.open("marks.dat",ios::in|ios::binary);
    fin.read((char*)this,sizeof(*this));
    if(!fin)
        cout<<"Data not avalable";
    else
    {
        while(!fin.eof())
        {
           if(!strcmp(t,subjectname))
          {
            show_marks_title();
            show_marks();
          }
          fin.read((char*)this,sizeof(*this));
        }
        fin.close();
    }
}
void ums::search_examintaion(char *t)
{
    ifstream fin;
    fin.open("examination.dat",ios::in|ios::binary);
    fin.read((char*)this,sizeof(*this));
    if(!fin)
        cout<<"Data not avalable";
    else
    {
        while(!fin.eof())
        {
           if(!strcmp(t,subjectname))
          {
            show_examintaion_department_title();
            show_examintaion_department();
          }
          fin.read((char*)this,sizeof(*this));
        }
        fin.close();
    }
}
void ums::search_addmission(char *t)
{
    ifstream fin;
    fin.open("admission.dat",ios::in|ios::binary);
    fin.read((char*)this,sizeof(*this));
    if(!fin)
        cout<<"Data not avalable";
    else
    {
        while(!fin.eof())
        {
           if(!strcmp(t,subjectname))
          {
            show_admission_title();
            show_examintaion_department_title();
          }
          fin.read((char*)this,sizeof(*this));
        }
        fin.close();
    }
}
void ums::search_lecture_time_table(char *t)
{
    ifstream fin;
    fin.open("timetable.dat",ios::in|ios::binary);
    fin.read((char*)this,sizeof(*this));
    if(!fin)
        cout<<"Data not avalable";
    else
    {
        while(!fin.eof())
        {
           if(!strcmp(t,dayname))
          {
            show_lecture_time_table_title();
            show_lecture_time_table();
          }
          fin.read((char*)this,sizeof(*this));
        }
        fin.close();
    }
}
//search code end
// Update code
void ums::update_marks(char *t)
{
    fstream file;
    file.open("marks.dat",ios::in|ios::out|ios::ate|ios::binary);
    file.seekg(0);
    file.read((char*)this,sizeof(*this));
    while(!file.eof())
    {
        if(!strcmp(t,subjectname))
        {
            search_marks(t);
            add_marks();
            file.seekp(file.tellp()-sizeof(*this));
            file.write((char*)this,sizeof(*this));
        }
        file.read((char*)this,sizeof(*this));
    }
    file.close();
    cout<<"Data updated successfully";
}
void ums::update_examintion(char *t)
{
    fstream file;
    file.open("examintion.dat",ios::in|ios::out|ios::ate|ios::binary);
    file.seekg(0);
    file.read((char*)this,sizeof(*this));
    while(!file.eof())
    {
        if(!strcmp(t,subjectname))
        {
            search_examintaion(t);
            add_examintion_department();
            file.seekp(file.tellp()-sizeof(*this));
            file.write((char*)this,sizeof(*this));
        }
        file.read((char*)this,sizeof(*this));
    }
    file.close();
    cout<<"Data updated successfully";
}
void ums::update_admission(char *t)
{
    fstream file;
    file.open("admission.dat",ios::in|ios::out|ios::ate|ios::binary);
    file.seekg(0);
    file.read((char*)this,sizeof(*this));
    while(!file.eof())
    {
        if(!strcmp(t,studentname))
        {
            search_addmission(t);
            add_admission();
            file.seekp(file.tellp()-sizeof(*this));
            file.write((char*)this,sizeof(*this));
        }
        file.read((char*)this,sizeof(*this));
    }
    file.close();
    cout<<"Data updated successfully";
}

void ums::update_time_table(char *t)
{
    fstream file;
    file.open("timetable.dat",ios::in|ios::out|ios::ate|ios::binary);
    file.seekg(0);
    file.read((char*)this,sizeof(*this));
    while(!file.eof())
    {
        if(!strcmp(t,dayname))
        {
            search_lecture_time_table(t);
            add_lecture_time_table();
            file.seekp(file.tellp()-sizeof(*this));
            file.write((char*)this,sizeof(*this));
        }
        file.read((char*)this,sizeof(*this));
    }
    file.close();
    cout<<"Data updated successfully";
}
void ums::update_time_table_after(int t)
{
    fstream file;
    file.open("attendance.dat",ios::in|ios::out|ios::ate|ios::binary);
    file.seekg(0);
    file.read((char*)this,sizeof(*this));
    while(!file.eof())
    {
        if(t==code)
        {
            present++;
            percentage=percentage*(present/100);
            file.seekp(file.tellp()-sizeof(*this));
            file.write((char*)this,sizeof(*this));
        }
        file.read((char*)this,sizeof(*this));
    }
    file.close();
    cout<<"Data updated successfully";
}
//update code end
//  menu code
int student_menu()
{
    int choice;
    cout<<"\n\n\n\t\t\t\t\t\t********STUDENT PORTAL********\n\n";
    cout<<"\n\t\t\t\t\t\t\t1.today lecture";
    cout<<"\n\t\t\t\t\t\t\t2.Attendance";
    cout<<"\n\t\t\t\t\t\t\t3.Announcemnet";
    cout<<"\n\t\t\t\t\t\t\t4.Assignment";
    cout<<"\n\t\t\t\t\t\t\t5.view marks";
    cout<<"\n\t\t\t\t\t\t\t6.Exam Avalable";
    cout<<"\n\t\t\t\t\t\t\t7.My profile";
    cout<<"\n\t\t\t\t\t\t\t8.Library department";
    cout<<"\n\t\t\t\t\t\t\tEnter your choice";
    cin>>choice;
    return choice;


}
int parents_menu()
{
    int choice;
    cout<<"\n\n\n\t\t\t\t\t\t********PARENTS PORTAL********\n\n";
    cout<<"\n\t\t\t\t\t\t\t1.today lecture";
    cout<<"\n\t\t\t\t\t\t\t2.Attendance";
    cout<<"\n\t\t\t\t\t\t\t3.Announcemnet";
    cout<<"\n\t\t\t\t\t\t\t4.Assignment";
    cout<<"\n\t\t\t\t\t\t\t5.view marks";
    cout<<"\n\t\t\t\t\t\t\t6.Exam Avalable";
    cout<<"\n\t\t\t\t\t\t\t7.My profile";
    cout<<"\n\t\t\t\t\t\t\t8.Library department";
    cout<<"\n\t\t\t\t\t\t\tEnter your choice";
    cin>>choice;
    return choice;


}


int library()
{
    int choice;
    cout<<"\n\t\t\t\t\t\t\t1.view stock";
    cout<<"\n\t\t\t\t\t\t\t2.issue book";
    cout<<"\n\t\t\t\t\t\t\tEnter your choice";
    cin>>choice;
    return choice;
}
int view_marks()
{
    int choice;
    cout<<"\n\t\t\t\t\t\t\t1.All Terms";
    cout<<"\n\t\t\t\t\t\t\t2.Search Terms";
    cout<<"\n\t\t\t\t\t\t\tEnter choice";
    cin>>choice;
    return choice;
}

int teacher_menu()
{
    int choice;
    cout<<"\n\n\n\t\t\t\t\t\t********TEACHER PORTAL********\n\n";
    cout<<"\n\t\t\t\t\t\t\t1.Mark attendance";
    cout<<"\n\t\t\t\t\t\t\t2.Upload Assignment";
    cout<<"\n\t\t\t\t\t\t\t3.Upload marks";
    cout<<"\n\t\t\t\t\t\t\tEnter choice";
    cin>>choice;
    return choice;
}
int managment_menu()
{
    int choice;
    cout<<"\n\n\n\t\t\t\t\t\t\t********MANAGMENT PORTAL********\n\n";
    cout<<"\n\t\t\t\t\t\t\t1.Examintion department";
    cout<<"\n\t\t\t\t\t\t\t2.Admission department";
    cout<<"\n\t\t\t\t\t\t\t3.Library department";
    cout<<"\n\t\t\t\t\t\t\t4.Teacher";
    cout<<"\n\t\t\t\t\t\t\t5.Put Announcement";
    cout<<"\n\t\t\t\t\t\t\t6. class Time table";
    cout<<"\n\t\t\t\t\t\t\tEnter choice";
    cin.ignore();
    cin>>choice;
    return choice;
}
int examintion_department()
{
    int choice;
    cout<<"\n\t\t\t\t\t\t\t1.Add examintion";
    cout<<"\n\t\t\t\t\t\t\t2.Avalable exam";
    cout<<"\n\t\t\t\t\t\t\t3.Search Exam";
    cout<<"\n\t\t\t\t\t\t\t4.update Exam";
    cout<<"\n\t\t\t\t\t\t\t5.Exit";
    cout<<"\n\t\t\t\t\t\t\tEnter  your choice";
    cin>>choice;
     return choice;
}
int admission_department()
{
    int choice;
    cout<<"\n\t\t\t\t\t\t\t1.Take admission";
    cout<<"\n\t\t\t\t\t\t\t2.All student";
    cout<<"\n\t\t\t\t\t\t\t3.Search student";
    cout<<"\n\t\t\t\t\t\t\t4.Upadate student data";
    cout<<"\n\t\t\t\t\t\t\t5.Exit";
    cout<<"\n\t\t\t\t\t\t\tenter your choice";
    cin>>choice;
     return choice;
}
int  library_department()
{
    int choice;
    cout<<"\n\n\n\t\t\t\t\t\t\t1.Add New Books\n";
    cout<<"\t\t\t\t\t\t\t2.Remove books\n";
    cout<<"\t\t\t\t\t\t\t3.Issue a book\n";
    cout<<"\t\t\t\t\t\t\t4.List of book issued\n";
    cout<<"\t\t\t\t\t\t\t5.View Stock\n";
    cout<<"\t\t\t\t\t\t\t6.Update Book Data\n";
    cout<<"\t\t\t\t\t\t\t7.Exit\n";
    cout<<"\n\t\t\t\t\t\tEnter your choice:";
    cin>>choice;
    return choice;
}
int teacher()
{
     int choice;
    cout<<"\n\t\t\t\t\t\t\t1.Add Teacher";
    cout<<"\n\t\t\t\t\t\t\t2.view All Teacher";
    cout<<"\n\t\t\t\t\t\t\t3.Search Teacher";
    cout<<"\n\t\t\t\t\t\t\t4.Upadate Teacher data";
    cout<<"\n\t\t\t\t\t\t\t5.Exit";
    cout<<"\n\t\t\t\t\t\t\tenter your choice";
    cin>>choice;
    return choice;
}
int annoucement()
{
    int choice;
    cout<<"\n\t\t\t\t\t\t\t1.Add annoucement";
    cout<<"\n\t\t\t\t\t\t\t2.view annoucement";
    cout<<"\n\t\t\t\t\t\t\t3.exit";
    cout<<"\n\t\t\t\t\t\t\tenter choice";
    cin>>choice;
    return choice;
}
int menu()
{
   time_t t;
   time(&t);
   SYSTEMTIME stime;
   GetSystemTime(&stime);

    cout<<ctime(&t)<<stime.wDay<<"/"<<stime.wMonth<<"/"<<stime.wYear;
    cout<<"\n\n\n\t\t\t\t\tLOVELY PROFFESSIONAL UNIVERSITY  MANAGMENT SYSTEM\n\n";
    cout<<"\n\t\t\t\t\t\t\t1.MANAGMENT PORTAL";
    cout<<"\n\t\t\t\t\t\t\t2.STUDENT   PORTAL";
    cout<<"\n\t\t\t\t\t\t\t3.TEACHER   PORTAL";
    cout<<"\n\t\t\t\t\t\t\t4.PARENTS   PORTAL";
    int choice;
    cout<<"\n\n\t\t\t\t\t Enter choice :";
    cin.ignore();
    cin>>choice;
    return choice;
}
int time_table()
{
    int choice;
    cout<<"\n1.Add time table";
    cout<<"\n2.view time table";
    cout<<"\n3.update time table";
    cout<<"\n4.exit";
    cout<<"\n enter choice";
    cin>>choice;
    return choice;
}
// menu code end
int main()
{
    ums u;
    issue i1;
    fstream G;
    char subjectname[30];
    char studentname[30];
    char name1[20];
    char name[30];
    char author[30];
    char dayname[30];
    char h;
    int x=0;
    char ch;
    while(1)
    {
        m:
            system("cls");
        switch(menu())
  {
       case 1:
           h:
                    switch(managment_menu())
                 {

                     case 1:
                           switch(examintion_department())
                         {
                               case 1:
                                     u.add_examintion_department();
                                     u.store_examintaion_department();

                                     break;
                               case 2:
                                     u.view_all_examintaion_department();
                                     break;
                               case 3:
                                     cout<<"Enter subject name";
                                     cin.getline(subjectname,29);
                                     u.search_examintaion(subjectname);
                                     break;
                              case 4:
                                     cout<<"Enterr stduent name to update exam data";
                                     cin.getline(subjectname,29);
                                     u.update_examintion(subjectname);
                                     break;
                        }

                    break;

                   case 2:
                           switch(admission_department())
                       {

                            case 1:
                                    u.add_admission();
                                    u.store_admission();
                                    break;
                            case 2:
                                    u.view_all_admission();
                                     break;
                            case 3:
                                   cout<<"Enter student name";
                                   cin.getline(studentname,29);
                                   u.search_addmission(studentname);
                                   break;
                            case 4:
                                   cout<<"Enterr subject name to update student data";
                                   cin.getline(subjectname,29);
                                   u.update_admission(subjectname);
                                   break;
                        }
                    break;

                    case 3:
                            switch( library_department())
                            {
                            case 1:
                                u.addBook();
                                u.storeBook();
                                break;
                            case 2:
                                cout<<"Enter book author name to remove";
                                cin.getline(author,29);
                                u.searchBook(author);
                                u.removeBook(author);
                                break;
                            case 3:
                                cout<<"Enter author of book to issue a book   ::";
                                cin.ignore();
                                cin.getline(author,29);
                                u.searchBook(author);
                                u.UpdateIssueBooked(author);
                                cout<<"Enter your name";
                                cin.ignore();
                                cin.getline(name1,20);
                                i1.generate(name1,u);
                                G.open("issue.dat",ios::app|ios::binary);
                                G.write((char*)&i1,sizeof(i1));
                                G.close();
                                cout<<"Book issued successfully";
                                break;
                            case 4:
                               G.open("issue.dat",ios::in|ios::binary);
                               G.read((char*)&i1,sizeof(i1));
                               if(!G)
                               cout<<"Data is not avalable";
                               else
                               {
                               while(!G.eof())
                                 {
                                   i1.disp();
                                   G.read((char*)&i1,sizeof(i1));
                                    x++;

                                  }
                               }
                               G.close();
                               cout<<"\n\n Total Number of Booked book :"<<x;
                               break;
                            case 5:
                                u.viewStocks();
                                break;
                            case 6:
                                 cout<<"Enter author of book to Update data : ";
                                 cin.ignore();
                                 cin.getline(author,29);
                                 u.UpdateBook(author);
                                 break;

                            }
                            break;
                    case 4:
                              switch(teacher())
                              {
                              case 1:
                                u.addMember();
                                u.storeMember();
                              case 2:
                                u.viewMember();
                                break;
                              case 3:
                                cout<<"Enter Teacher name to remove";
                                cin.getline(name,29);
                                u.searchMember(name);
                                u.removeMember(name);
                                break;
                              case 4:
                                cout<<"Enter name of Teacher to update Data";
                                cin.get(name,20);
                                u.searchMember(name);
                                u.UpdateMember(name);
                                break;

                              }
                             break;
                    case 5:
                             switch(annoucement())
                             {
                             case 1:
                                u.add_announcement();
                                u.store_announcement();
                                break;
                             case 2:
                                u.view_announcement();
                                break;
                             }
                             break;
                    case 6:
                            switch(time_table())
                            {
                            case 1:
                                u.add_lecture_time_table();
                                u.store_lecture_time_table();
                                break;
                            case 2:
                                u.view_all_lecture_time_table();
                                break;
                            case 3:
                                cout<<"Enter day name to update time table";
                                cin.getline(dayname,20);
                                u.search_lecture_time_table(dayname);
                                u.update_time_table(dayname);
                                break;
                            }
                            break;






                    }

                    cout<<"\n\n press y for continue M for main menu Q for quit";
                        cin>>ch;
                        if(ch=='y'||ch=='Y')
                            goto h;
                        else if(ch=='M'||ch=='m')
                            goto m;
                            else
                                exit(1);
         break;



    case 2:
            a:
             switch(student_menu())
             {
                       case 1:
                           u.view_all_lecture_time_table();
                           break;
                       case 2:
                           u.view_all_attendance();
                           break;
                        case 3:
                           u.view_announcement();
                           break;
                        case 4:
                            u.view_all_assignment();
                            break;
                        case 5:
                                switch(view_marks())
                                       {
                                          case 1:
                                               u.view_all_marks();
                                               break;
                                          case 2:
                                               cout<<"Enter name of subject ";
                                               cin.getline(subjectname,29);
                                               u.search_marks(subjectname);
                                               break;

                                       }
                        case 6:
                                u.view_all_examintaion_department();
                                break;
                        case 7:
                               cout<<"enter your name";
                               cin.getline(name1,20);
                               u.search_addmission(name1);
                               break;
                        case 8:
                                   switch(library())
                                   {
                                      case 1:
                                            u.viewStocks();
                                            break;
                                      case 2:
                                           cout<<"Enter author of book to issue a book   ::";
                                           cin.ignore();
                                           cin.getline(author,29);
                                           u.searchBook(author);
                                           u.UpdateIssueBooked(author);
                                           cout<<"Enter your name";
                                           cin.ignore();
                                           cin>>name;
                                           i1.generate(name1,u);
                                           G.open("issue.dat",ios::app|ios::binary);
                                           G.write((char*)&i1,sizeof(i1));
                                           G.close();
                                           cout<<"Book issued successfully";
                                           break;

                                   }


             }
              cout<<"\n\n press y for continue M for main menu Q for quit";
                        cin>>ch;
                        if(ch=='y'||ch=='Y')
                            goto a;
                        else if(ch=='M'||ch=='m')
                            goto m;
                            else
                                exit(1);

       break;
    case 3:
        c:
              switch(teacher_menu())
              {
                    case 1:
                        u.add_attendance();
                        u.store_attendance();
                        break;
                    case 2:
                        u.add_assignment();
                        u.store_assignment();
                        break;
                    case 3:
                        u.add_marks();
                        u.store_marks();
                        break;


              }
               cout<<"\n\n press y for continue M for main menu Q for quit";
                        cin>>ch;
                        if(ch=='y'||ch=='Y')
                            goto c;
                        else if(ch=='M'||ch=='m')
                            goto m;
                            else
                                exit(1);

       break;
                    case 4:
                        d:
             switch(parents_menu())
             {
                       case 1:
                           u.view_all_lecture_time_table();
                           break;
                       case 2:
                           u.view_all_attendance();
                           break;
                        case 3:
                           u.view_announcement();
                           break;
                        case 4:
                            u.view_all_assignment();
                            break;
                        case 5:
                                switch(view_marks())
                                       {
                                          case 1:
                                               u.view_all_marks();
                                               break;
                                          case 2:
                                               cout<<"Enter name of subject ";
                                               cin.getline(subjectname,29);
                                               u.search_marks(subjectname);
                                               break;

                                       }
                        case 6:
                                u.view_all_examintaion_department();
                                break;
                        case 7:
                               cout<<"enter your name";
                               cin.getline(name1,20);
                               u.search_addmission(name1);
                               break;
                        case 8:
                                   switch(library())
                                   {
                                      case 1:
                                            u.viewStocks();
                                            break;
                                      case 2:
                                           cout<<"Enter author of book to issue a book   ::";
                                           cin.ignore();
                                           cin.getline(author,29);
                                           u.searchBook(author);
                                           u.UpdateIssueBooked(author);
                                           cout<<"Enter your name";
                                           cin.ignore();
                                           cin>>name;
                                           i1.generate(name1,u);
                                           G.open("issue.dat",ios::app|ios::binary);
                                           G.write((char*)&i1,sizeof(i1));
                                           G.close();
                                           cout<<"Book issued successfully";
                                           break;

                                   }


             }
              cout<<"\n\n\n\t\tpress y for continue M for main menu Q for quit";
                        cin>>ch;
                        if(ch=='y'||ch=='Y')
                            goto d;
                        else if(ch=='M'||ch=='m')
                            goto m;
                            else
                                exit(1);

       break;

       }




    }




}

