// -*- C++ -*-
//    FILE: get.cpp Version 0.9
//    (C) 2001-2002  Frank R. Schaefer
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

void print_help();
using namespace std;

#define striterate(string_list, it) \
	for(vector<string>::const_iterator (it) = (string_list).begin(); \
	    (it) != (string_list).end(); (it)++)

#define iterate(CString, p) \
           for(const char* (p) = (CString).c_str(); *p ; p++)

int
main(int argc, char** argv)
{
    GetPot       cl(argc, argv);

    vector<string> ufos;
    if( cl.search(2, "-h", "--help") ) {
        print_help();
        exit(0);
    }
    else if( cl.search("--arguments") ) {
        // (*) unidentified flying arguments ---------------------------------------------
        ufos = cl.unidentified_arguments(5, "--arguments", "-h", "--help", "yes", "no");
        cout << "Unidentified Arguments (other than '--arguments', '-h', '--help', 'yes', 'no'):\n";
    }
    else if( cl.search("--options") ) {
        // (*) unidentified flying options (starting with '-' or '--') -------------------
        ufos = cl.unidentified_options(5, "--options",  "-h", "--help",
                                       "yes(ignored anyway)", "no(ignored anyway)");
        cout << "Unidentified Options (different from '--options',  '-h', '--help'):\n";
    }
    else if( cl.search("--flags") ) {
        // (*) unidentified flying flags -------------------------------------------------

        // -- flags in the first argument
        string ufos = cl.unidentified_flags("xzfjct", 1);
        cout << "-- Unaccepted flags in argument 1:\n";
        iterate(ufos, flag) {
            cout << "      '" << ((char)*flag) << "'\n";
        }
        cout << "\n   Accepted flags: 'x' 'z' 'f' 'j' 'c' 't'\n\n";

        // -- flags in arguments starting with a single '-'
        ufos = cl.unidentified_flags("ltrm");
        cout << "-- Unaccepted flags in options (argument with one '-'):\n";
        iterate(ufos, flag) {
            cout << "      '" << ((char)*flag) << "'\n";
        }
        cout << "\n   Accepted flags in options: 'l' 't' 'r' 'm'\n";
        return 0;
    }			
    else if( cl.search("--variables") ) {
        // (*) unidentified flying variables ---------------------------------------------
        ufos = cl.unidentified_variables(5, "x", "y", "z", "length", "height");

        cout << "Unidentified Variables (other than 'x', 'y', 'z', 'length', 'height'):\n";
    }
    else if( cl.search("--sections") ) {
        // (*) unidentified flying sections ----------------------------------------------
        GetPot  ifile(cl.follow("example.pot", "--input-file"));
        ifile.set_prefix("vehicle/");

        cout << "Known sections:\n";
        cout << "                 '/', 'chassis/', 'chassis/doors/'\n";
        cout << "\n";
        ufos = ifile.unidentified_sections(3, "/", "chassis/", "chassis/doors/");
        cout << "Unidentified subsections of 'vehicle/' in file 'example.pot':\n";
        if( ufos.size() == 0 ) cout << "    No unknown sections.\n";
    }
    else if( cl.search("--nominuses") ) {
        // (*) unidentified flying options (starting with '-' or '--') -------------------
        vector<string>  tmp;
        // -- read two filenames for demonstration purposes
        string   infile = cl.follow("default-in.znf", "-i");
        string   outfile = cl.follow("default-out.znf", "-o");

        tmp.push_back(infile);
        tmp.push_back(outfile);

        // -- get any other nominuses not used until now
        ufos = cl.unidentified_nominuses(tmp);

        cout << "Unused Nominus Arguments (other than arguments after -i and -o):\n";
    }
    else  {
        print_help();
        exit(0);
    }

    // (*) print out unidentified flying objects
    striterate(ufos, it) {
        cout << "     " << *it << endl;
    }
}


void print_help()
{
    const char* msg = 
	"USAGE:  ufo [--help] [--arguments] [--options] [--flags] [--sections] \n"
	"            [--variables] [--nominuses [-i file] [-o filename]]\n"
	"            ... any arguments\n"
	"\n"
	"PURPOSE: \n"
	"        Testing the GetPot's ability to detect unknown flying objects\n"
	"         (i.e. un-recognized command line arguments. The type of flying\n"
	"        object you want to check for is specified through one of the\n"
	"        following options:\n"
	"\n"
	"        --arguments\n"
	"             test all arguments against an internal list of possible arguments.\n"
	"\n"
	"        --options\n"
	"             test all options (arguments starting with at least one '-') against\n"
	"             an internal list of options.\n"
	"\n"
	"        --flags\n"
	"             test first argument and all options against internal list of flags\n"
	"             (i.e. letters in arguments that act as switches)\n"
	"\n"
	"        --sections\n"
	"             reads the input file 'example.pot' for sections that are\n"
	"              unidentified. add some sections yourself to test this feature.\n"
	"\n"
	"        --variables\n"
	"             tests all variables specified on the command line against a list\n"
	"             of specified variables.\n"
	"\n"
	"        --nominuses\n"
	"             check for unrecognized nominuses. filenames after -i and -o are\n"
	"             recognized.\n"
	"\n"
	"        Once you specified your mode add any number of command line\n"
	"        arguments and watch the output.\n"
	"\n"
	"EXAMPLES:\n" 
	"        > ./ufo yes no -i source.cpp --arguments\n" 
	"\n" 
	"        > ./ufo -i source.cpp --force n=13 -xzt --options\n" 
	"\n" 
	"        > ./ufo zfd if=source.cpp force n=13 -l -zrt -olp --flags\n" 
	"\n" 
	"        > ./ufo zfd x=12 y=234 loength=21 height=21 n=2 --variables\n" 
	"\n" 
	"        > ./ufo --sections # (edit file section labels in example.pot)\n" 
	"\n" 
	"        > ./ufo n=21 -i in.dat -o out.dat /etc/fstab force --nominuses \n" 
	"\n" 
	"AUTHOR: (C) 2002 Frank R. Schaefer\n";

    cout << msg;
}
