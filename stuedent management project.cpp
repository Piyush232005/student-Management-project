#include<iostream>
#include<conio.h>
#include<vector>
using namespace std;

class student
{
    private:
        int rollno, age;
        string name;
    public:
         student(int stdRollno,string stdName,int stdAge)
	    {
        	rollno = stdRollno;
        	name = stdName;
        	age = stdAge;
		}
		void setRollno(int stdRollno)
		{
			rollno =stdRollno;
		}
		int getRollno()
		{
			return rollno;
		}
		void setName(string stdName)
		{
			name =stdName;
		}
		string getName()
		{
			return name;
		}
		void setAge(int stdAge)
		{
			age =stdAge;
		}
		int getAge()
		{
			return age;
		}
		void displayStudent()
		{
		    cout<<"Roll No : "<<rollno<<endl;
		    cout<<"Name    : "<<name<<endl;
		    cout<<"Age    : "<<age<<endl;
		}


};
//create function to add new student
void addNewStudent(vector<student>&students)
{
	int rollno,age;
	string name;
	cout<<"Enter Rollno :";
	cin>>rollno;
	//check if student already exist

	for(int i=0;i<students.size();i++)
    {
        if(students[i].getRollno()==rollno)
        {
            cout<<"\t\tStudent already exist"<<endl;
            cout<<"\t\t......................"<<endl;
            return;
        }
    }
	cout<<"Enter Name :";
	cin>>name;
	cout<<"Enter Age :";
	cin>>age;

	student newStudent(rollno,name,age);
	students.push_back(newStudent);

	cout<<"\t\tStudent added successfully......."<<endl;
}
//display of all student
void DisplayAllStudent(vector<student>& students)
{
    if(students.empty())
    {
        cout<<"\t\t No Student Found"<<endl;
        return;
    }
    for(int i=0;i<students.size();i++)
    {
        students[i].displayStudent();
        cout<<endl;
    }

}
//searching of students
void SearchStudent(vector<student>& students)
{
    int rollno;
    cout<<"\t\tEnter Rollno :";
    cin>>rollno;

    for(int i=0;i<students.size();i++)
    {
        if(students[i].getRollno()==rollno)
        {
            cout<<"\t\t------Student Found-------"<<endl;
            students[i].displayStudent();
            return;
        }
    }

}
// update the student
void updateStudent(vector<student>& students)
{
    string sname;
    bool found = false;
    int choice;

    cout<<"\t\tEnter Name to update Record :";
    cin.ignore();
    getline(cin,sname);

    for(int i=0;i<students.size();i++)
    {
        if(students[i].getName()==sname)
        {
            found = true;

            cout<<"\t\t----Student found ----"<<endl;
            cout<<"\t\t 1.update Rollno"<<endl;
            cout<<"\t\t 2.update name"<<endl;
            cout<<"\t\t 3.update age"<<endl;
            cout<<"\t\tEnter Your choice"<<endl;
            cin>>choice;

            switch(choice)
            {
                case 1:
                    {
                        int rno;
                        cout<<"\t\tEnter New roll no :"<<endl;
                        cin>>rno;
                        students[i].setRollno(rno);

                        break;
                    }
                case 2:
                    {
                        string name;
                        cout<<"\t\tEnter New Name :"<<endl;
                        cin.ignore();
                        getline(cin,name);
                        students[i].setName(name);

                        break;
                    }
                case 3:
                    {
                       int age;
                       cout<<"\t\tEnter New Age :"<<endl;
                       cin>>age;
                       students[i].setAge(age);
                       break;
                    }
                default:
                    cout<<"\t\t Invalid Name "<<endl;

            }

        }
        if(!found)
        {
            cout<<"\t\tRecord Not Found "<<endl;
            return;
        }
    }

}
// create function to delete student in list
void deleteStudent(vector<student>& students)
{
    string name;
    cout<<"Enter Name to delete :";
    cin.ignore();
    getline(cin,name);
    for(int i=0;i<students.size();i++)
    {
        if(students[i].getName()==name)
        {
            students.erase((students.begin()+i));
            cout<<"\t\t Student Data remove successfully......"<<endl;
        }

    }
}
main()
{
	vector<student> students;
	students.push_back(student(1,"Piyush",20));

	char choice;

	do
    {
        system("cls");
        int op;
	   cout<<"\t\t......................"<<endl;
	   cout<<"\t\tStudent Management System "<<endl;
	   cout<<"\t\t......................"<<endl;
	   cout<<"\t\t1.Add new student"<<endl;
	   cout<<"\t\t2.Display All students"<<endl;
	   cout<<"\t\t3.Search Student"<<endl;
	   cout<<"\t\t4.Update Student"<<endl;
	   cout<<"\t\t5.Delete Student"<<endl;
	   cout<<"\t\t6.Exit "<<endl;

	   cout<<"\t\tEnter your choice :";
	   cin>>op;
	   switch(op)
	  {
		case 1:
			addNewStudent(students);
			break;
        case 2:
            DisplayAllStudent(students);
            break;
        case 3:
            SearchStudent(students);
            break;
        case 4:
            updateStudent(students);
            break;
        case 5:
            deleteStudent(students);
            break;
		case 6:
		    exit(1);
		default:
            cout<<"\t\tInvalid Number ......."<<endl;
	  }
	  cout<<"\t\tDo you Want to continue [Yes/ No] ? :";
	  cin>>choice;
    }while(choice=='y'||choice=='Y');

    getch();
}
