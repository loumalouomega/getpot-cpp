// -*- C++ -*-
//    (C) 2001-2003  Frank R. Schaefer
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
        // (*) Unidentified flying arguments ---------------------------------------------
        cl.search("yes");
        cl.search("no");   // request arguments, so they get tagged

        ufos = cl.unidentified_arguments();
        cout << "Unidentified Arguments\n(other than '--arguments', '-h', '--help', 'yes', 'no'):\n";
    }
    else if( cl.search("--options") ) {
        // (*) unidentified flying options (starting with '-' or '--') -------------------
        ufos = cl.unidentified_options();
        cout << "Unidentified Options (different from '--options',  '-h', '--help'):\n";
    }
    else if( cl.search("--variables") ) {
        // (*) unidentified flying variables ---------------------------------------------
        cl("x", 0.0); cl("y", 0.0); cl("z", 0.0); cl("length", 0.0); cl("height", 0.0);
        ufos = cl.unidentified_variables();
        cout << "Unidentified Variables (other than 'x', 'y', 'z', 'length', 'height'):\n";
    }
    else if( cl.search("--sections") ) {
        // (*) unidentified flying sections ----------------------------------------------
        GetPot  ifile("example.pot");
        ifile.set_prefix("vehicle/");
        ufos = ifile.unidentified_sections();

        cout << "Unidentified subsections of 'vehicle/' in file 'example.pot':\n";
        if( ufos.size() == 0 )
            cout << "    (none) add [..] section labels in file 'example.pot'.\n";
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
        "USAGE:  ez-ufo [--help] [--arguments] [--options] [--sections] \n"
        "               [--variables] [--nominuses [-i file] [-o filename]]\n"
        "               ... any arguments\n"
        "\n"
        "PURPOSE: \n"
        "\n"
        "Testing   the  GetPot's   ability   to  detect   unknown  flying   objects\n"
        "(i.e. un-recognized command line arguments.  The type of flying object you\n"
        "want to check for is specified through one of the following options).\n"
        "\n"
        "ez-ufo  tests the easy  way to  do ufo  detection. Where  'ufo' explicitly\n"
        "stated requested arguments, variables,  options, etc., ez-ufo uses the new\n"
        "feature of  GetPot, where requested objects are  tagged automatically when\n"
        "request functions such as 'follow' and 'get' are called.\n"
        "\n\n"
        "        --arguments\n"
        "             test all arguments against an internal list of possible arguments.\n"
        "\n"
        "        --options\n"
        "             test all options (arguments starting with at least one '-') against\n"
        "             an internal list of options.\n"
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
        "        > ./ez-ufo yes no -i source.cpp --arguments\n" 
        "\n" 
        "        > ./ez-ufo -i source.cpp --force n=13 -xzt --options\n" 
        "\n" 
        "        > ./ez-ufo zfd x=12 y=234 loength=21 height=21 n=2 --variables\n" 
        "\n" 
        "        > ./ez-ufo --sections # (edit file section labels in example.pot)\n" 
        "\n" 
        "        > ./ez-ufo n=21 -i in.dat -o out.dat /etc/fstab force --nominuses \n" 
        "\n" 
        "AUTHOR: (C) 2003 Frank R. Schaefer\n";

    cout << msg;
}
