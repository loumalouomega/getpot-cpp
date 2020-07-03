// -*- C++ -*-
//    FILE: direct_follow
//    (C) 2005  Frank R. Schaefer
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

void print_help(const string);


int
main(int argc, char** argv)
{
    GetPot   cl(argc, argv);
    if( cl.size() == 1 || cl.search(2, "--help", "-h") ) {
	print_help(cl[0]);
	exit(0);
    }
    
    cout << "Strings following -U:\n";
    vector<string> tmp0 = cl.string_tails("-U");
    for(vector<string>::const_iterator it = tmp0.begin(); it != tmp0.end(); it++)
	cout << "   '" << *it << "'\n";

    cout << "Integers following -V:\n";
    vector<int> tmp1 = cl.int_tails("-V");
    for(vector<int>::const_iterator it = tmp1.begin(); it != tmp1.end(); it++) {	
	cout << "   '" << *it << "'\n";
    }

    cout << "Doubles following -NUM:\n";
    vector<double> tmp2 = cl.double_tails("-NUM");
    for(vector<double>::const_iterator it = tmp2.begin(); it != tmp2.end(); it++)
	cout << "   '" << *it << "'\n";
}



void print_help(const string Application)
{
    cout << endl;
    cout << "Example to use string_tails(), integer_tails() and double_tails() -functions:" << endl << endl;
    cout << "USAGE:" << endl;
    cout << "--help, -h  get some help about this program." << endl;
    cout << endl;
    cout << "Write one, none or more of the following arguments:\n\n";
    cout << "   -Ustring    specify user name as string" << endl;
    cout << "   -Vx         specify a value given as x" << endl;
    cout << "   -NUMx       specify number given as x" << endl;
    cout << endl;
    cout << "You can use as many argument of any type as you want." << endl;
    cout << endl;
    exit(0);
}




