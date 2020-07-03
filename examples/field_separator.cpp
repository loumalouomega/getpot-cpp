// -*- C++ -*-
//    FILE: field_separator.cpp 
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

    const string fs = cl("fs", " \t\n");
    // create another GetPot to see the effect of using a different field separator
    GetPot  look_and_see(argc, argv, fs.c_str());

    string field = "";
    for( int i = 0; field != "empty"; i++) {
	field = look_and_see("test", i, "empty");
	cout << "field " << i << ": \"" << field << "\"\n";
    }

    
}

void
print_help(const string Application)
{
    cout << endl;
    cout << "    This application allows you to specify a field separator by which a given\n";
    cout << "    string is separated into elements, so that it becomes a vector. There are\n";
    cout << "    two command line variables to play: 'fs' and 'test'.\n";
    cout << "\n";
    cout << "USAGE:" << endl;
    cout << "    --help, -h, --hilfe, --sos" << endl;
    cout << "        get some help about this program." << endl << endl;
    cout << "    --internal-information, -i" << endl;
    cout << "        show contents of database that was created by parser." << endl;
    cout << endl;       
    cout << "    fs=FIELD_SEPARATOR\n";
    cout << "        You may specify any field separator you can think of, such as '.' or ':'\n";
    cout << "        (Be careful, though, not to use comment delimiters\n";
    cout << "\n";
    cout << "    test=STRING\n";
    cout << "        Give any string you want to see being split into parts, such as 'June/14/1879'\n";
    cout << "        '130.127.11.8' or '/usr/include/g++/bits'. Make sure that the field separator\n";
    cout << "        is chosen appropriately, so that the vector is split nicely\n";
    cout << "\n";
    cout << "EXAMPLES\n";
    cout << "\n";
    cout << "        ./field_separator fs=.  test=10.23.232.16\n";
    cout << "        ./field_separator fs=:  test=af:4e:c2:72:24:0f:0f:ff\n";

    cout << "\n";
    cout << "        Try and see the difference between\n";
    cout << "\n";
    cout << "                ./field_separator fs=. test='129. 11. 32.  5'\n";
    cout << "        and\n";
    cout << "                ./field_separator fs='. ' test='129. 11. 32.  5'\n";
    cout << "\n";
}
