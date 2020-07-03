// -*- C++ -*-
//    FILE: get.cpp Version 0.9
//    (C) 2001-2010  Frank R. Schaefer
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

int
main(int argc, char** argv)
{
    GetPot   cl(argc, argv);

    if( cl.search(2, "--help", "-h") )
	cerr << "call " << cl[0] << " with four arguments." << endl;

    const int    A = cl.get(4, 256);    // integer version of get()
    const double B = cl.get(1, 3.14);   // double version of get()
    const string C = cl.get(2, "You");  // const char* version of get()

    cout << "A (argument no 4) = " << A << endl;
    cout << "B (argument no 1) = " << B << endl;
    cout << "C (argument no 2) = " << C << endl;
}
