// -*- C++ -*-
//    FILE: follow
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

void something(const double&  Alpha, const int Beta, 
	       const string Name, const int No, 
	       const string Name2, const int No2, 
	       const double XSz, const double YSz);
void print_help(const string);


int
main(int argc, char** argv)
{
    GetPot   cl(argc, argv);
    if( cl.size() == 1 || cl.search(2, "--help", "-h") ) print_help(cl[0]);

    // read arguments one by one on the command line
    //  (lazy command line parsing)
    const double Alpha = cl.follow(0.,    "--alpha");   // [rad]
    const int    Beta  = cl.follow(256,   "--beta"); // [1/s]
    cl.init_multiple_occurrence();
    const string  User  = cl.follow("You", "--user");      
    const int     No    = cl.next(0x42); 
    const string  User2 = cl.follow("me too", "--user"); // second user specified ?
    const int     No2   = cl.next(0x43); 
    cl.enable_loop();
    const double  XSz   = cl.follow(0., 3, "--size", "--sz", "-s"); // [cm]
    const double  YSz   = cl.next(0.);                              // [cm]

    something(Alpha, Beta, User, No, User2, No2, XSz, YSz);
}


void something(const double&  Alpha, const int Beta, 
	       const string Name, const int No, 
	       const string Name2, const int No2, 
	       const double XSz, const double YSz)
{
    cout << endl;
    cout << "Alpha (float)   = " << Alpha << endl;
    cout << "Beta  (integer) = " << Beta  << endl;
    cout << "Names           = " << Name << ", " << Name2 << endl << endl;
    cout << "Special numbers = " << No << " and " << No2 << endl << endl;
    cout << "x-size, y-size  = " << XSz << ", " << YSz << endl;
    cout << endl;
}

void print_help(const string Application)
{
    cout << endl;
    cout << "Example to use follow()-functions:" << endl << endl;
    cout << "USAGE:" << endl;
    cout << "--help, -h" << endl;
    cout << "       get some help about this program." << endl;
    cout << "--alpha number" << endl;
    cout << "       specify the value of alpha given as number." << endl;
    cout << "--beta number" << endl;
    cout << "       specify the value of beta given as number." << endl;
    cout << "--user string number" << endl;
    cout << "       specify user name as string and id as number" << endl;
    cout << "       (default = 'You' and '0x42')." << endl;
    cout << "       multiple users possible. " << endl;
    cout << "--size, --sz, -s number1 number2" << endl;
    cout << "       specify x and y sizes" << endl;
    cout << endl;
    exit(0);
}




