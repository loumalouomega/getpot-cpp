// -*- C++ -*-
//    FILE: next.cpp
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

void something(const double& A, const int SmpNo, 
	       const string Name, const int No);
void print_help(const string);


int
main(int argc, char** argv)
{
    GetPot   cl(argc, argv);
    if( cl.size() == 1 || cl.search(2, "--help", "-h") ) print_help(cl[0]);

    // read arguments one by one on the command line
    //  (lazy command line parsing)
    cl.reset_cursor();
    const double   A = cl.next(0.);    // [rad]
    const int      B = cl.next(256);   // [1/s]
    const string   User = cl.next((const char*)"You");
    const int      No   = cl.next(0x42); 

    something(A, B, User, No);
}


void something(const double&  A, const int B, const string Name, const int No)
{
    cout << endl;
    cout << "A = " << A << endl;
    cout << "B = " << B << endl;
    cout << "Name           = " << Name << endl;
    cout << "Special number = " << No << endl;
    cout << endl;
}

void print_help(const std::string Application)
{
    cout << endl;
    cout << endl;
    cout << "Example to use next()-functions:" << endl << endl;
    cout << "USAGE:" << endl;
    cout << "    $1  (double) Value of A" << endl;
    cout << "    $2  (integer) Value of B" << endl;
    cout << "    $3  (string) Name to be printed" << endl;
    cout << "    $4  (integer) Some number to be printed" << endl;
    cout << endl;
    exit(0);
}





