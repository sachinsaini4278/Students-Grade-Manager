#include<sstream>//string stream associated a object with a stream like isstringstream used for read word by word in a line (string)
#include<iostream>
#include<fstream>//file stream
#include<string>//like string.h in C
using namespace std;
int countword(string str);// used for counting the words in a line
void printtop10incse(int n);
void printtop10(int n); //for printing top 10 students
void sortstructure(int n); //sort whole structure
void printstructure(int n);  // print structure
void sortaccordingtocse(int n);
void sortaccordingtoece(int n);
void printtop10inece(int n);
struct status
{
  string line;
  float cgpa;
  int cse;
  int ece;
  int cv;
  int mec;

}student[70];

struct csestu
{
    string line;
    float cgpa;
}studentcse[70];
struct ecestu
{
    string line;
    float cgpa;
}studentece[70];
struct mestu
{
    string line;
    float cgpa;
}studentme[70];
struct cestu
{
    string line;
    float cgpa;
}studentce[70];
int main()
{

    ifstream in("result.txt");
    if(!in)
    {
        cout<<"does't exist";
        return 1;
    }
    string temp; //temporary string which will be used to take a line or other things
    int i=0;
    while(!in.eof())
    {
        getline(in,temp);
        student[i].line=temp;
        //cout<<student[i].line;
        i++;
    }

    int counttotalline=i,j;
    int cs=0,ec=0,m=0,cv=0,k=0,l=0,q=0,r=0;
    for(i=0;i<counttotalline;i++)
    {
        istringstream iss;   // input string stream istringstream is used to read line word by word
        temp=student[i].line;
        int word=countword(temp);  //total words in a line
        //cout<<word;
        iss.str(temp);//temp is line which
        for(j=0;j<=word;j++)
        {
            string A;
            iss>>A; //one byy one word will be filled into a distracted by iss..
            if(A=="CSE")
            {
                cs=1;
            }
            else if(A=="ECE")
            {
                ec=1;
            }
            else if(A=="ME")
            {
                m=1;
            }
            else if(A=="CE")
            {
                cv=1;
            }
            if(j==word) //when we reached in last mean on CGPA
            {
                stringstream convert(A); //convert string to int
                float x=0;
                convert>>x;  //storing string a in x by converted into float
             //cout<<"A="<<x<<endl;
               if(cs==1)  // means it is a cse student
                 {
                     studentcse[k].line=student[i].line;  // k is a variable used to indicate the index of csestudent
                    // cout<<studentcse[k].line<<endl;
                     studentcse[k].cgpa=x;
                     k++;
                 }
              else if(ec==1)
                 {
                     studentece[l].line=student[i].line;
                    // cout<<studentece[l].line<<endl;
                     studentece[l].cgpa=x;
                     l++;
                 }
              else if(m==1)
                 {
                     studentme[q].line=student[i].line;
                     studentme[q].cgpa=x;
                     q++;
                 }
              else if(cv==1)
                 {
                     studentce[r].line=student[i].line;
                     studentce[r].cgpa=x;
                     r++;
                 }
                 student[i].cgpa=x;
            }
         }//end of loop j
         cs=0;ec=0;m=0;cv=0;
    }//end of loop i
    sortstructure(counttotalline);
    //cout<<"...................structure......................\n";
    //printstructure(counttotalline);
    //printtop10();
    sortaccordingtocse(k);
    sortaccordingtoece(l);
    cout<<">>>>>>>>>>>>>>>>>>>>>>>Project Created by Sachin Saini<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n";
    cout<<"\t\tON WHAT CRITERIA YOU WANT TO SELECT STUDENT\n";
    cout<<"\t\t1 : OVERALL TOP 10 STUDENTS \n";
    cout<<"\t\t2 :  TOP 10 ECE STUDENTS\n";
    cout<<"\t\t3 :  TOP 10 CSE STUDENTS\n";
    cout<<"\t\t4 :  OVERALL SORTED ECE STUDENT\n";
    cout<<"\t\t5 :  OVERALL SORTED CSE STUDENT\n";
    cout<<"\t\t ENTER YOUR CHOICE\t";
    int choice=0;
    cin>>choice;
    switch(choice)
    {
    case 1 :
        cout<<"OVERALL TOP 10 STUDENT ARE AS FOLLOW \n";
        printstructure(10);
        break;
    case 2 :
        cout<<"TOP 10 ECE STUDENTS ARE AS FOLLOW \n";
        printtop10inece(10);
        break;
    case 3 :
        cout<<"TOP 10 CSE STUDENTS ARE AS FOLLOW \n";
        printtop10incse(10);
        break;
    case 4 :
         cout<<"OVERALL SORTED ECE STUDENT \n";
         printtop10inece(l);
         break;
    case 5 :
        cout<<"OVERALL SORTED CSE STUDENT \n";
        printtop10incse(k);
        break;
    }
}
int countword(string temp)
{
    int counter=0,i=0;
    while(1)  // while condition true
    {
        if(temp[i]==' ')
        {
            counter++;
        }
        else if(temp[i]=='\0')
        {
            break;
        }
        i++;
    }
    return counter;
}
void sortstructure(int n)
{
    cout<<"running ";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            if(student[j].cgpa<student[j+1].cgpa)
            {
                swap(student[j],student[j+1]);
            }
        }
    }
    printstructure(n);
}
void printstructure(int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<student[i].line<<endl;
    }
}
void printtop10incse(int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<studentcse[i].line<<endl;
    }
}
void printtop10inece(int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<studentece[i].line<<endl;
    }
}
void sortaccordingtocse(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            if(studentcse[j].cgpa<studentcse[j+1].cgpa)
            {
                swap(studentcse[j],studentcse[j+1]);
            }
        }
    }
}
void sortaccordingtoece(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            if(studentece[j].cgpa<studentece[j+1].cgpa)
            {
                swap(studentece[j],studentece[j+1]);
            }
        }
    }
}
