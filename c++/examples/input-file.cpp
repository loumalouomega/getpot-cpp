// -*- C++ -*-
//    FILE: input-file.cpp
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
#define __GETPOT_TRUE "vrai true"

#include<iostream>
#include<GetPot>

using namespace std;


extern "C" {
#include<math.h>
}
void print_help();

int
main(int argc, char** argv)
{
    GetPot      cl(argc, argv);      // command line args
    string      base_directory = cl.follow("./", "--directory");

    // (1) search for multiple options with the same meaning
    if( cl.search(4, "--help", "-h", "--hilfe", "--sos") ) {
        print_help();
        exit(0);
    }
    string comment_type = cl.follow("GetPot", "-c");

    string comment_start = "#"; 
    string comment_end   = "\n";
    string input_file    = "example.pot";

    if( comment_type == "BASIC" ) {
        comment_start = "REM"; 
        comment_end   = "\n";
        input_file    = "example-BASIC.pot";
    }
    else if( comment_type == "C" ) {
        comment_start = "/*"; 
        comment_end   = "*/";
        input_file    = "example-C.pot";
    }
    else if( comment_type == "Latex" ) {
        comment_start = "%"; 
        comment_end   = "\n";
        input_file    = "example-Latex.pot";
    }
    else if( comment_type == "Punk" ) {
        comment_start = "TRASH STARTS"; 
        comment_end   = "TRASH ENDS";
        input_file    = "example-Punk.pot";
    }
    else if( comment_type == "GetPot" ) {
        // default 'GetPot': everything as initialized
    }
    else {
        cerr << "error: comment type '" << comment_type << "' not implemented in this example\n";
        cerr << "       options are:\n";
        cerr << "           GetPot (default), BASIC, C, Latex, and Punk\n";
        exit(-1);
    }

    // input file:
    GetPot  ifile0(base_directory + input_file, comment_start, comment_end); 
    // test of operator =:
    GetPot ifile = ifile0;

    if( cl.search(2, "--internal-information", "-i") ) {
        ifile.print();
        exit(0);
    }


    // (2) playing with sections
    cout << "webpage       = " << ifile("webpage", "nothing.somewhere.idn") << endl;
    cout << "user          = " << ifile("user", "nobody") << endl;
    cout << "dos-file      = " << ifile("dos-file", "nobody") << endl;
    cout << "latex-formula = " << ifile("latex-formula", "nobody") << endl;

    cout << "no. clicks   = " << ifile("clicks", 0) << endl;
    // Error by purpose ...
    cout << "acceleration = " << ifile("acceleration", M_PI) << endl; 
    
    ifile.set_prefix("vehicle/");
    // Error by purpose ...
    cout << "wheel-base = " << ifile("vehicle/wheel-base",2.65) << endl;
    cout << "wheel-base = " << ifile("wheel-base",2.65) << endl; //correct
    cout << "vehicle/initial-xyz = ";
    cout << ifile("initial-xyz", 0, 0.) << '\t';  // first element of vector
    cout << ifile("initial-xyz", 1, 0.) << '\t';  // second element of vector 
    cout << ifile("initial-xyz", 2, 0.) << '\n';  // third element of vector

    // Error by purpose ...
    cout << "vehicle/tires/B = " << ifile("tires/B", 777.7) << endl;
    cout << "              C = " << ifile("tires/C", 777.7) << endl;
    cout << "              E = " << ifile("tires/E", 777.7) << endl;
    cout << "              D = " << ifile("tires/D", 777.7) << endl;

    ifile.set_prefix("");
    cout << "vehicle/chassis/Roh = " << ifile("vehicle/chassis/Roh", 777.7) << endl;
    cout << "                S   = " << ifile("vehicle/chassis/S",   777.7) << endl;
    cout << "                Cd  = " << ifile("vehicle/chassis/Cd",  777.7) << endl;

    cout << "vehicle/chassis/doors/number = " << ifile("vehicle/chassis/doors/number",2) << endl;
    cout << "                      locks  = " << ifile("vehicle/chassis/doors/locks","yes") << endl;

    // (3) playing with things we do normally only with command line arguments
    ifile.set_prefix("group/");
    cout << "x-ratio      = " << ifile.follow(3.14, "-x") << endl;
    cout << "Boolean -b   = " << ifile.follow(false, "-b") << endl;
    cout << "Next Boolean = " << ifile.next(false)         << endl;
    cout << "sound-mode   = " << ifile.next("none")        << endl;
    bool n_f = ifile.search("-x");
    cout << "-x flag in [group] = " << (n_f ? "activated" : "disabled") << endl;
}


void
print_help()
{
    cerr << endl;
    cout << "Example how to use GetPot to parse input files." << endl;
    cerr << endl; 
    cerr << "USAGE:" << endl;
    cerr << "--help, -h, --hilfe, --sos" << endl;
    cerr << "        get some help about this program." << endl << endl;
    cerr << endl << endl;       
    cerr << "--internal-information, -i" << endl;
    cerr << "        show contents of database that was created by file parser.";
    cerr << endl;
    cerr << "--comment, -c COMMENT TYPE" << endl;
    cerr << "        determine the comment type you want to specify\n";
    cerr << "        options are:\n";
    cerr << "               GetPot (default), BASIC, C, Latex, and Punk\n";
    cerr << "        correspondingly the input file will be:\n";
    cerr << "           example.pot\n";
    cerr << "           example-BASIC.pot\n";
    cerr << "           example-Latex.pot, etc.\n";
    cerr << endl;
}

