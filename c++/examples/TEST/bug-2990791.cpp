#include<support/C/hwut_unit.h>
#include<iostream>
#include<GetPot>

using namespace std;

int
main(int argc, char** argv)
{
    GetPot  ifile0("bug-2990791.pot");

    hwut_info("Bug:  <cmouton> 2990791 Bug with section names ending with slash\n");

    cout << "Full pathname:\n";
    cout << ifile0("vehicle/B",   777.7) << endl;
    cout << ifile0("plane/C",     888.8) << endl;
    cout << ifile0("plane/a/D",   111.1) << endl;
    cout << ifile0("plane/a///E", 222.2) << endl;
    cout << ifile0("Root",        999.9) << endl;

    cout << "Prefix ending with slash:\n";
    ifile0.set_prefix("vehicle/");
    cout << ifile0("B", 777.7) << endl;
    ifile0.set_prefix("plane/");
    cout << ifile0("C", 888.8) << endl;
    ifile0.set_prefix("plane/a/");
    cout << ifile0("D", 111.1) << endl;
    cout << ifile0("E", 222.2) << endl;

    cout << "Prefix ending without slash:\n";
    ifile0.set_prefix("vehicle");
    cout << ifile0("B", 777.7) << endl;
    ifile0.set_prefix("plane");
    cout << ifile0("C", 888.8) << endl;
    ifile0.set_prefix("plane/a");
    cout << ifile0("D", 111.1) << endl;
    cout << ifile0("E", 222.2) << endl;

    cout << "--(Content)---------------------------------------\n";
    ifile0.print();
}
