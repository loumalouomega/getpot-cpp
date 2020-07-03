// -*- C++ -*-
//    FILE: flags.cpp Version 0.9
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

void something(const string User, const string User2, const string User3,
	       double Value, double Value2, double Value3,
	       int Number, int Number2, int Number3);
void print_help(const string);


int
main(int argc, char** argv)
{
    GetPot   cl(argc, argv);
    if( cl.size() == 1 || cl.search(2, "--help", "-h") ) print_help(cl[0]);

    // does first argument contain 'x', 'X', 'c', 'C', 'k', or  'K' ?
    const bool  first_f = cl.argument_contains(1, "xX");
    const bool  second_f  = cl.argument_contains(1, "cCkK");

    // is there any option starting with '-' containing 'a', 'b', or 'c' ?
    const bool  abc_f = cl.options_contain("abc");

    cout << "first flag  = " << first_f << endl;
    cout << "second flag = " << second_f << endl;
    cout << "a, b, or c found = " << (abc_f ? "yes" : "no") << endl;
}


void print_help(const string Application)
{
    cout << endl;
    cout << "Example using flags:" << endl << endl;
    cout << "USAGE:" << endl;
    cout << "--help, -h  get some help about this program." << endl;
    cout << endl;
    cout << "The first argument will be checked if it contains 'x' or 'X'." << endl;
    cout << "If so the first flag will be set. The second flag will be set if" << endl;
    cout << "the first argument contains a 'c', 'C', 'k', or a 'K'." << endl;
    cout << endl;
    cout << "The 'abc' flag is set when any argument starting with '-' contains an" << endl;
    cout << "'a', 'b' or a 'c'." << endl;
    cout << endl;
    exit(0);
}




