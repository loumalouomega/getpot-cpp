// -*- C++ -*-
//    FILE: options.cpp 
//    (C) 2001  Frank R. Schaefer
//
//    This library is free software; you can redistribute it and/or
//    modify it under the terms of the GNU Lesser General Public
//    License as published by the Free Software Foundation; either
//    version 2.1 of the License, or (at your option) any later version.
//
//    This library is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//    Lesser General Public License for more details.
//
//    You should have received a copy of the GNU Lesser General Public
//    License along with this library; if not, write to the Free Software
//    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//////////////////////////////////////////////////////////////////////////////////////
#include<iostream>
#include<GetPot>


using namespace std;

extern "C" {
#include<math.h>
}
void print_help(const string);

int
main(int argc, char** argv)
{
    GetPot      cl(argc, argv);      // command line args

    // (1) search for multiple options with the same meaning
    if( cl.search(4, "--help", "-h", "--hilfe", "--sos") || cl.size() == 1) {
	print_help(argv[0]);
	exit(0);
    }

    if( cl.search(2, "--internal-information", "-i") ) {
        cl.print();
        exit(0);
    }
    // (2) some variables of each type
    const double A_Number   = cl("float", 0.);
    const double An_Integer = cl("integer", 0);
    const string  A_String   = cl("string", "default");

    const double Element1 = cl("vector", 0, 0.0);
    const string Element2 = cl("vector", 1, "default");
    const int    Element3 = cl("vector", 2, 0);

    cout << "Specified Parameters:" << endl;
    cout << "float   = " << A_Number << endl;
    cout << "integer = " << An_Integer << endl;
    cout << "string  = " << A_String << endl;
    cout << endl;
    cout << "Vector elements:" << endl;
    cout << "Element 0 (double) = " << Element1 << endl;
    cout << "Element 1 (string) = " << Element2 << endl;
    cout << "Element 2 (int)    = " << Element3 << endl;
    
}

void
print_help(const string Application)
{
    cout << endl;
    cout << "Example how to use GetPot to parse variables on the command line." << endl;
    cout << endl; 
    cout << "USAGE:" << endl;
    cout << "--help, -h, --hilfe, --sos" << endl;
    cout << "        get some help about this program." << endl << endl;
    cout << "--internal-information, -i" << endl;
    cout << "        show contents of database that was created by parser." << endl;
    cout << endl;       
    cout << "type a command line like the following:" << endl;
    cout << Application << " string=otto.von.bismarck float=3.14 \\" << endl;
    cout << "        integer=41 vector='1.26 something 0x40'" << endl;
    cout << endl;
    cout << "the variables that can be specified are:" << endl;
    cout << "       float    a double variable" << endl;
    cout << "       integer  an integer variable" << endl;
    cout << "       string   a string variable" << endl;
    cout << "       vector   a mixed type vector:" << endl;
    cout << "                element 0 => double " << endl;
    cout << "                element 1 => string" << endl;
    cout << "                element 2 => int" << endl;
    cout << endl;
}
