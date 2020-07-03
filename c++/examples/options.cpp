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

void print_help();

int
main(int argc, char** argv)
{
    GetPot   cl(argc, argv);

    // (1) search for a single option
    // -------------------------------
    //     check if the '--do-nothing' flag is set and exit if yes
    if( cl.search("--do-nothing") ) exit(0);

    //     does the user want us to be nice ... ?
    const bool  be_nice_f = cl.search("--nice");

    // (2) search for multiple options with the same meaning
    if( cl.size() == 1 || cl.search(4, "--help", "-h", "--hilfe", "--sos") )
    { print_help(); exit(0); }

    if( cl.search(5, "--beep", "--piepse", "--bip", "--senal-acustica", "-b") )
        cerr << "BEEP\n";

    cout << "Program terminated." << endl;
    if( be_nice_f == true )
	cout << "Have a nice day." << endl;
}


void
print_help()
{
    cerr << endl;
    cout << "Example to use search()-functions:\n\n";
    cerr << endl; 
    cerr << "USAGE:" << endl;
    cerr << "--do-nothing   quit without doing anything." << endl;
    cerr << "--nice         write a nice phrase on the terminal." << endl;
    cerr << "--help, -h, --hilfe, --sos" << endl;
    cerr << "               get some help about this program." << endl;
    cerr << "--beep, -b, --piepse, --bip, --senal-acustica" << endl;
    cerr << "               get your system to make a beep." << endl;
    cerr << endl;
}


