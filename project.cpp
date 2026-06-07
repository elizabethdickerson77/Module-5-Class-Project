#include <iostream>
#include <fstream>
#include <string>
using namespace std;

double getFederalTax(double annualSalary) {
if (annualSalary < 5000)
return 0.0;
else if (annualSalary < 10000)
return 0.06;
else if (annualSalary < 20000)
return 0.15;
else if (annualSalary < 40000)
return 0.20;
else if (annualSalary < 60000)
return 0.25;
else
return 0.30;
}

int main() {
ifstream inData;
inData.open("employees.dat");

int ssn;
string firstName, middleInitial, lastName;
double annualSalary;
int numCovered;
char retirementFlag;

cout.setf(ios::fixed);
cout.precision(2);

while (inData >> ssn >> firstName >> middleInitial >> lastName
>> annualSalary >> numCovered >> retirementFlag) {

double monthlyGross = annualSalary / 12.0;

// Deductions
double federalTax = monthlyGross * getFederalTax(annualSalary);
double stateTax = monthlyGross * 0.06;
double healthDeduction = numCovered * 100.0;
double retirementDeduction = 0.0;
if (retirementFlag == 'Y')
retirementDeduction = monthlyGross * 0.06;

double monthlyNet = monthlyGross - federalTax - stateTax
- healthDeduction - retirementDeduction;

// Output
cout << "SSN: " << ssn << endl;
cout << "Name: " << lastName << ", " << firstName
<< " " << middleInitial << endl;
cout << "Monthly Gross: $" << monthlyGross << endl;
cout << "Federal Tax: $" << federalTax << endl;
cout << "State Tax: $" << stateTax << endl;
cout << "Health Insurance: $" << healthDeduction << endl;
cout << "Retirement: $" << retirementDeduction << endl;
cout << "Monthly Net Pay: $" << monthlyNet << endl;
cout << "----------------------------" << endl;
}

inData.close();
return 0;
}
