// -*- C++ -*-
//    FILE: direct_follow
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
	       int Number, int Number2, int Number3,
               bool Boolean, bool Boolean2, bool Boolean3);
void print_help(const string);


int
main(int argc, char** argv)
{
    GetPot   cl(argc, argv);
    if( cl.size() == 1 || cl.search(2, "--help", "-h") ) print_help(cl[0]);

    // Specify, that in case the cursor reaches the end of argument list,
    // it is not automatically reset to the start. This way the search
    // functions do not wrap around. Instead, they notify an 'not fount'
    // in case the option was not in between 'cursor' and the argv.end().
    cl.reset_cursor();
    cl.disable_loop();

    // check out 'const string' versions
    const string  User  = cl.direct_follow("You",   "-U");  
    const string  User2 = cl.direct_follow("Karl",  "-U"); 
    const string  User3 = cl.direct_follow("Heinz", "-U");

    // check out 'double' versions
    cl.reset_cursor(); 
    double  Value  = cl.direct_follow(3.14, "-V"); 
    double  Value2 = cl.direct_follow(9.81, "-V"); 
    double  Value3 = cl.direct_follow(1.62, "-V"); 

    // check out 'integer' versions
    cl.reset_cursor(); 
    int  Number  = cl.direct_follow(12, "-NUM");
    int  Number2 = cl.direct_follow(43, "-NUM");
    int  Number3 = cl.direct_follow(64, "-NUM");

    // check out 'Boolean' versions
    cl.reset_cursor(); 
    int  Boolean  = cl.direct_follow(false, "-BOOL");
    int  Boolean2 = cl.direct_follow(false, "-BOOL");
    int  Boolean3 = cl.direct_follow(true, "-BOOL");

    something(User, User2, User3, Value, Value2, Value3, Number, Number2, Number3, Boolean, Boolean2, Boolean3);
}


void something(const string User, const string User2, const string User3,
	       double Value, double Value2, double Value3,
	       int Number, int Number2, int Number3,
               bool Boolean, bool Boolean2, bool Boolean3)
{
    cout << "Users   = " << User  << ", " << User2 << ", " << User3 << endl;
    cout << "Values  = " << Value << ", " << Value2 << ", " << Value3 << endl;
    cout << "Numbers = " << Number << ", " << Number2 << ", " << Number3 << endl;
    cout << "Booleans = " << Boolean << ", " << Boolean2 << ", " << Boolean3 << endl;
}

void print_help(const string Application)
{
    cout << endl;
    cout << "Example to use direct_follow()-functions:" << endl << endl;
    cout << "USAGE:" << endl;
    cout << "--help, -h  get some help about this program." << endl;
    cout << endl;
    cout << "-Ustring    specify user name as string" << endl;
    cout << "-Vx         specify a value given as x" << endl;
    cout << "-NUMx       specify number given as x" << endl;
    cout << "-BOOLx      specify Boolean given as x" << endl;
    cout << endl;
    cout << "a total amount of three of each is expected." << endl;
    cout << "try 'tails.cpp' for indefinite number of arguments." << endl;
    cout << endl;
    exit(0);
}




