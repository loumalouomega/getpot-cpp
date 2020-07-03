// -*- C++ -*-
//    FILE: bool.cpp Version 0.9
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

// Let's assume our users are frenchmen and frenchwomen:
#define GETPOT_SETTING_DEFAULT_FALSE_STRING_LIST "faux fausse"
#define GETPOT_SETTING_DEFAULT_TRUE_STRING_LIST  "vrai vraie"
#include<GetPot>

using namespace std;

int
main(int argc, char** argv)
{
    GetPot   cl(argc, argv);

    if( cl.search(2, "--help", "-h") )
	cerr << "call " << cl[0] << " with four arguments." << endl;

    cout << "cl.get(1, true)               = "   << cl.get(1, true)               << endl;                   
    cout << "cl.get(1, false)              = "   << cl.get(1, false)              << endl; 
    cout << "cl(\"a\", true)                 = " << cl("a", true)                 << endl;    
    cout << "cl(\"a\", false)                = " << cl("a", false)                << endl;    
    try {
        cout << "cl.get<bool>(\"b\")         = " << cl.get<bool>("b")             << endl; 
    }
    catch(...) {
        cout << "<exception>" << endl;
    }
    cout << "cl.direct_follow(true, \"-C\")  = " << cl.direct_follow(true, "-C")  << endl;
    cout << "cl.direct_follow(false, \"-C\") = " << cl.direct_follow(false, "-C") << endl;
                                                                                   
    cout << "cl.follow(true,  \"-d\")        = " << cl.follow(true,  "-d") << endl;
    cout << "cl.next(true)                 = "   << cl.next(true)          << endl;
    cout << "cl.follow(false, \"-e\")        = " << cl.follow(false, "-e") << endl;
    cout << "cl.next(false)                = "   << cl.next(false)         << endl;
                                                                                   
    cout << "cl(\"f\", 1, true)              = " << cl("f", 1, true)  << endl; 
    cout << "cl(\"f\", 1, false)             = " << cl("f", 1, false) << endl; 
                                                                                   
    cl.set_variable("g", true);
    cl.set_variable("h", false);
    try {
        bool my_i;
        bool my_j;
        cl.set("i", my_i);          
        cl.set("j", my_j);         
        cout << "cl.set(\"i\", my_i)             =>  my_i = " << my_i << endl; 
        cout << "cl.set(\"j\", my_j)             =>  my_j = " << my_j << endl;                  
    }
    catch(...) {
    }
    cout << "cl.set_variable(\"g\", true)    =>  g = "    << cl.get<bool>("g") << endl;
    cout << "cl.set_variable(\"h\", false)   =>  h = "    << cl.get<bool>("h") << endl;

}

