// -*- C++ -*-
//    FILE: expand.cpp
//    (C) 2002  Frank R. Schaefer
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
//////////////////////////////////////////////////////////////////////////////////

#include<GetPot>
#include<iostream>
using namespace std;

void print(string Str="")
{ cout << Str << endl; }

void print(string Str1, string Str2)
{ cout << Str1 << Str2 << endl; }

int
main(int argc, char** argv)
{
    GetPot cl(argc, argv);      // command line args
    string base_directory = cl.follow("./", "--directory");
    GetPot ifpot((base_directory + "expand.pot").c_str());
    
    if( cl.search(2, "--internal-information", "-i") ) {
	ifpot.print();
	exit(0);
    }

    // (*) help display
    if( cl.search(4, "--help", "-h", "--hilfe", "--sos") ) {
	string msg("Example how to use GetPot to parse input files.\n\n"  
		   "USAGE:\n"  
		   "--help, -h, --hilfe, --sos\n" 
		   "        get some help about this program.\n\n" 
		   "--internal-information, -i\n" 
		   "        show contents of database that was created by file parser.\n" 
		   "--infile string\n" 
		   "        input file name (default: example.pot)");
	print(msg);
	exit(0);
    }

    // (*) example usage
    print("[1.1]--------------------------------------------------------------------------");
    print("Information 0: ", ifpot("info0", "nobody")  );

    ifpot.set_prefix("1.2/");
    print("[1.2]--------------------------------------------------------------------------");
    print("Information 0: ", ifpot("info0", "(nothing)"));
    print("Information 1: ", ifpot("info1", "(nothing)"));
    
    ifpot.set_prefix("1.3/");
    print("[1.3]--------------------------------------------------------------------------");
    print("Information 0: ", ifpot("info0", "(nothing)"));
    print("Information 1: ", ifpot("info1", "(nothing)"));
    
    ifpot.set_prefix("1.4/");
    print("[1.4]--------------------------------------------------------------------------");
    print("Information 0: ", ifpot("info0", "(nothing)"));
    print("Information 1: ", ifpot("info1", "(nothing)"));
 
    ifpot.set_prefix("2.1/");
    print("[2.1]--------------------------------------------------------------------------");
    print("Information 0: ", ifpot("info0", "(nothing)"));
    print("Information 1: ", ifpot("info1", "(nothing)"));
    print("Information 2: ", ifpot("info2", "(nothing)"));

    ifpot.set_prefix("2.2/");
    print("[2.2]--------------------------------------------------------------------------");
    print("Information 0: ", ifpot("info0", "(nothing)"));
    print("Information 1: ", ifpot("info1", "(nothing)"));

    ifpot.set_prefix("2.3/");
    print("[2.3]--------------------------------------------------------------------------");
    print("Information 0: ", ifpot("info0", "(nothing)"));
    print("Information 1: ", ifpot("info1", "(nothing)"));
    print("Information 2: ", ifpot("info2", "(nothing)"));

    ifpot.set_prefix("3.1/");
    print("[3.1]--------------------------------------------------------------------------");
    print("Information 0: ", ifpot("info0", "(nothing)"));
    print("Information 1: ", ifpot("info1", "(nothing)"));
    print("Information 2: ", ifpot("info2", "(nothing)"));
    print("Information 3: ", ifpot("info3", "(nothing)"));
    print("Information 4: ", ifpot("info4", "(nothing)"));
    print("Information 5: ", ifpot("info5", "(nothing)"));
    print("Information 6: ", ifpot("info6", "(nothing)"));
    print("Information 7: ", ifpot("info7", "(nothing)"));

    ifpot.set_prefix("3.2/");
    print("[3.2]--------------------------------------------------------------------------");
    print("Information 0: ", ifpot("info0", "(nothing)"));
    print("Information 1: ", ifpot("info1", "(nothing)"));

    ifpot.set_prefix("3.3/");
    print("[3.3]--------------------------------------------------------------------------");
    print("Information 0: ", ifpot("info0", "(nothing)"));
    print("Information 1: ", ifpot("info1", "(nothing)"));
    print("Information 2: ", ifpot("info2", "(nothing)"));
    print("Information 3: ", ifpot("info3", "(nothing)"));
    print("Information 4: ", ifpot("info4", "(nothing)"));
    print("Information 5: ", ifpot("info5", "(nothing)"));
    print("Information 6: ", ifpot("info6", "(nothing)"));
    print("Information 7: ", ifpot("info7", "(nothing)"));

    ifpot.set_prefix("3.4/");
    print("[3.4]--------------------------------------------------------------------------");
    print("Information 0: ", ifpot("info0", "(nothing)"));
    print("Information 1: ", ifpot("info1", "(nothing)"));
    print("Information 2: ", ifpot("info2", "(nothing)"));

    ifpot.set_prefix("3.5/");
    print("[3.5]--------------------------------------------------------------------------");
    print("Information 0: ", ifpot("info0", "(nothing)"));
    print("Information 1: ", ifpot("info1", "(nothing)"));
    print("Information 2: ", ifpot("info2", "(nothing)"));
    print("Information 3: ", ifpot("info3", "(nothing)"));
    print("Information 4: ", ifpot("info4", "(nothing)"));
    print("Information 5: ", ifpot("info5", "(nothing)"));
    print("Information 6: ", ifpot("info6", "(nothing)"));
    print("Information 7: ", ifpot("info7", "(nothing)"));

    ifpot.set_prefix("3.6/");
    print("[3.6]--------------------------------------------------------------------------");
    print("Information 0: ", ifpot("info0", "(nothing)"));
    print("Information 1: ", ifpot("info1", "(nothing)"));
}
