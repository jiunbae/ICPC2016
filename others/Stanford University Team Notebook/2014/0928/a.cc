#include<iostream>
using namespace std;
int main()
{
    int testcasenums, casenum;
    cin>>testcasenums;
    for(casenum=1;casenum<=testcasenums;casenum++)
    {
        int n;
        cin>>n;
        int sum=0;
        for(int i=1;i<=n;i++) sum+=i*2-1;
        cout<<sum<<endl;
    }
    return 0;
}

// Save the file as [name].cc

// To compile, type the following at terminal
//   g++ [name].cc -o [executable_name]

// To run, simpley enter "./[executable_name]" at terminal

// All input/output is standard, i.e. you'll type the input
// directly to the console (terminal).

// If you want to feed the input from a file, say input.in, do
//   ./[executable_name] < input.in
// Similarly, if you want to output to a file, say output.out, do
//   ./[executable_name] > output.out
// You can do both at the same time:
//   ./[executable_name] < input.in > output.out
