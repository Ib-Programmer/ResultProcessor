#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Result
{
  private:
	int studentnum, coursenum;
	int creditunits[20];
	string courses[20];
	string StudentRegnum[500];
	int Scores[20][500];
	char grade[500][20];
	int gradepoint[500][20];
	double sumunits = 0.0;
	double gpa[500];
	double totalgpa[500];
     int determiner=1;
  public:
	void Print()
	{
		cout << "Welcome to  Result processor\n " << endl;
		cout<<"Develop by Ibraheem Muhammad\n  ";
		cout << "%%%%%%%%%%%%%%%%%%%%%%%%%\n";
		
		cout << "Loading..........\n";
	}

	int getsumunits()
	{
		return sumunits;
	}
	int getsnum()
	{
		return studentnum;
	}
	double *getTotalgpa()
	{
		return totalgpa;
	}
	string *getregNum()
	{
		return StudentRegnum;
	}
	int getdet(){
		return determiner;
	}
	void InputAcceptor()
	{
		determiner++;
		cout << "Please Enter the number of Courses \n";
		cin >> coursenum;
		cout << "\n";
		cout << "Please Enter the number of Students \n";
		cin >> studentnum;
		cout << "\n";
		cout << "Please Enter the Courses and Credit Units \n";
		cout << "\n";
		for (int i = 0; i < coursenum; i++)
		{
			cin >> courses[i] >> creditunits[i];
			sumunits += creditunits[i];
		}
		cout << "Enter Students Record \n";

		for (int i = 0; i < studentnum; i++)
		{
			cout << "Reg No:  ";
			cin >> StudentRegnum[i];
			for (int j = 0; j < coursenum; j++)
			{
				cout << courses[j] << "\n";
				cin >> Scores[i][j];
			}
		}
	}
	void Calculategrade()
	{
		for (int i = 0; i < studentnum; i++)
		{
			for (int j = 0; j < coursenum; j++)
			{
				if ((Scores[i][j] >= 70) && (Scores[i][j] <= 100))
				{
					grade[i][j] = 'A';
					gradepoint[i][j] = 5;
				}
				else if (Scores[i][j] >= 60)
				{
					grade[i][j] = 'B';
					gradepoint[i][j] = 4;
				}
				else if (Scores[i][j] >= 50)
				{
					grade[i][j] = 'C';
					gradepoint[i][j] = 3;
				}
				else if (
					(Scores[i][j] >= 45) && (Scores[i][j] < 50))

				{
					grade[i][j] = 'D';
					gradepoint[i][j] = 2;
				}
				else if ((Scores[i][j] >= 40) && (Scores[i][j] < 45))
				{
					grade[i][j] = 'E';
					gradepoint[i][j] = 1;
				}
				else if ((Scores[i][j] >= 0) && (Scores[i][j] < 40))
				{
					grade[i][j] = 'F';
					gradepoint[i][j] = 0;
				}
				else
				{
					grade[i][j] = 'F';
					gradepoint[i][j] = 0;
				}
			}
		}
	}

	void GPA()
	{
		for (int i = 0; i < studentnum; i++)
		{
			for (int j = 0; j < coursenum; j++)
			{
				totalgpa[i] += (gradepoint[i][j] * creditunits[j]);
			}
		}
		for (int i = 0; i < studentnum; i++)
		{
			gpa[i] = totalgpa[i] / sumunits;
		}
	}
	void processor()
	{
		cout << "Reg No:          ";
		for (int j = 0; j < coursenum; j++)
		{
			cout << courses[j] << "      ";
		}
		cout << " GPA";
		cout << "\n";
		for (int i = 0; i < studentnum; i++)
		{
			cout << i + 1 << ". " << StudentRegnum[i] << "       ";
			for (int j = 0; j < coursenum; j++)
			{
				cout << grade[i][j] << "          ";
			}
			cout <<setprecision(3)<<gpa[i];
			cout << "   ";
			for (int k = 0; k < coursenum; k++)
			{
				if (grade[i][k] == 'F')
				{
					cout << "\n"
						 << "Carry Over :   " << courses[k] << "   ";
				}
			}
			cout << "\n"
				 << "\n";
		}
	}
};

class Session : public Result
{
  private:
	double sgpa[500],  fgpa[500];
	double stotalgpa[500], ftotalgpa[500];
	int studentnum, sumunit, fsumunit;
    int det;
  public:
	double Cgpa[500];
	void incrementor()
	{
		det = getdet();
		studentnum = getsnum();
		
		double *p = getTotalgpa();
		if (det==2){
			sumunit = getsumunits();
		for (int i = 0; i < studentnum; i++)
		{
			sgpa[i] = p[i];
		}
		for (int j = 0; j < studentnum; j++)
		{
			stotalgpa[j] += sgpa[j];
		}
		}
     else if (det==3){
     	fsumunit = getsumunits();
     	for (int i = 0; i < studentnum; i++)
		{
			fgpa[i] = p[i];
		}
		for (int j = 0; j < studentnum; j++)
		{
			ftotalgpa[j] += fgpa[j];
		}
		}
		else {}
	}
	void CalculateCGPA(){
			for (int j = 0; j < studentnum; j++)
		{
			stotalgpa[j] += ftotalgpa[j];
		}
		sumunit+=fsumunit;
		
		for (int i = 0; i < studentnum; i++)
		{
			Cgpa[i] = stotalgpa[i] / sumunit;
		}
	}
	void processCgpa()
	{
		string reg[500];
		string *y = getregNum();
		cout << "Reg Number "
			 << "         "
			 << "CGPA\n";
		for (int i = 0; i < studentnum; i++)
		{
			reg[i] = y[i];
		}
		for (int i = 0; i < studentnum; i++)
		{
			cout << reg[i] << "         " << setprecision(3)<<Cgpa[i] << "\n";
		}
	}

} student;

int main()
{
	string choice;
	student.Print();
	student.InputAcceptor();
	student.Calculategrade();
	student.GPA();
	student.incrementor();
	student.processor();
	cout << " \n";
	cout << "\n Do want to compute second semester result yes/no ? ";
	cin >> choice;
	if ((choice == "Yes") || (choice == "yes"))
	{
		cout << "Loading .................. \n";
		student.InputAcceptor();
		student.Calculategrade();
		student.GPA();
		student.incrementor();
		student.CalculateCGPA();
		student.processor();
		student.processCgpa();
	}
	else if ((choice == "No") || (choice == "no"))
	{
		cout << " Exiting...............";
	}
	else
	{
		cout << "      ";
	}
}
