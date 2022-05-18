// Sterling Gerard
// Date: April 2, 2022
// Convert  Lab 1 (Student Record ) to implement class & Object .  You will need to change functions to recive parameter of object type. 
// You also need to sort only once(any type or algorithm), and do not need to do any searching algorithm .
			

#include <iostream> // preprocessor directive for cout object 
#include <string>   // preprocessor directive for reading string of characters 
#include <fstream>  // Preprocessor directive for file
#include <iomanip>  // Preprocessor directive to manage format of output

using namespace std;

//++++++Global variables 
ifstream inname, ingrade;
int const row = 5; // number of rows
int const col = 5; // number of columns

//++++++++++++Class Definition++++++++++++++++++++++++++++++++++++++++++++++
class student
{
private:
	string name[row]; // data members
	int grade[row][col] = { {0}, {0} }, sumGrades[row] = { 0 };
	double averageGrades[row] = { 0.0 };
	char letter[row];
public:
	void read_data()
	{
		inname.open("Names1.txt");
		ingrade.open("Grades1.txt");

		int r; // loop control variable for rows
		int c; // loop control variable for col
			   // loop to read all 5 or as many names and grades in the array in your files

		for (r = 0; r < row; r++)
		{
			getline(inname, name[r]); // Read name and stores them in array of studentsName array
			for (c = 0; c < col; c++)
			{
				ingrade >> grade[r][c]; // Read grades and stores them in array of your flies
			}
		}
	}
	
	//================================Definition of Display function =========== 
	void display_data()
	{
		int r;  // Loop control variable
		int c;  // Loop control variable
				// loop to read all 5 or as many names and grades in the array of your files

		cout << "   Name						Total	Average	    Grades	" << endl;
		cout << " +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;

		for (r = 0; r < row; r++)
		{

			cout << fixed << showpoint << setprecision(2);
			cout << left << setw(20) << name[r];
			for (c = 0; c < col; c++)
			{
				cout << right << setw(7) << grade[r][c] << setw(8) << sumGrades[r] << setw(8) << averageGrades[r] << setw(8) << letter[r] << endl;
			}
		}
	}
	void sum()
	{
		int r;
		int c;

		for (r = 0; r < row; r++)
			for (c = 0; c < col; c++)
				sumGrades[r] = grade[r][c] + sumGrades[r];
	}

	void average() {
		int r;
		for (r = 0; r < row; r++)
			averageGrades[r] = (sumGrades[r]) / static_cast <double> (col);
	}

	void createletter()
	{
		int r;

		for (r = 0; r < row; r++)
		{
			if (averageGrades[r] >= 90)
				letter[r] = 'A';
			else if (averageGrades[r] >= 80)
				letter[r] = 'B';
			else if (averageGrades[r] >= 70)
				letter[r] = 'C';
			else if (averageGrades[r] >= 60)
				letter[r] = 'D';
			else
				letter[r] = 'F';
		}
	}
	void swapname(string& xp, string& yp)
	{
		string temp = xp;
		xp = yp;
		yp = temp;

	}
	void swapsum(int& xp, int& yp)
	{
		int temp = xp;
		xp = yp;
		yp = temp;
	}
	void swapaverage(double& xp, double& yp)
	{
		double temp = xp;
		xp = yp;
		yp = temp;
	}
	void swapletter(char& xp, char& yp)
	{
		char temp = xp;
		xp = yp;
		yp = temp;
	}
	void swapgrade(int& xp, int& yp)
	{
		int temp = xp;
		xp = yp;
		yp = temp;
	}
	void bubblesort()
	{

		int c;			//loop control variable to control 
		int fp, np;

		for (fp = 0; fp < row; fp++)
		{
			for (np = 0; np < (row - 1); np++)
			{
				if (letter[np] >= letter[np + 1])
				{
					swapname(name[np], name[np + 1]);
					swapsum(sumGrades[np], sumGrades[np + 1]);
					swapaverage(averageGrades[np], averageGrades[np + 1]);
					swapletter(letter[np], letter[np + 1]);

					for (c = 0; c < col; c++) 
					{
						swapgrade(grade[np][c], grade[np + 1][c]);

					}

				}
			}

		}
	}
};

int main() 
{
	student s;
	s.read_data();
	s.sum();
	s.average();
	s.createletter();
	s.bubblesort();
	s.display_data();

	inname.close();
	ingrade.close();
	system("pause");
	return 0;
}