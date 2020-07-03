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

    if( cl.search(4, "--help", "-h", "--hilfe", "--sos") ) {
        print_help();
        exit(0);
    }

    // input file:
    GetPot  ifile(base_directory + "constraints.pot");

    if( cl.search(2, "--internal-information", "-i") ) {
        ifile.print();
        exit(0);
    }

    // Define our own understanding of true and false ...
    // ifile.set_true_string_list(2,  "possible",   "conceivable");
    //ifile.set_false_string_list(2, "impossible", "inconceivable");

    ifile.set_prefix("");
    cout << "boolean test  = " << ifile("booly_0", false) << endl;
    cout << "boolean test  = " << ifile("booly_1", false) << endl;
    cout << "boolean test  = " << ifile("booly_2", true)  << endl;

    {
      cout << "Tests with set method and default values." << endl;
      int n;
      ifile.set("number", n, "< 10", 4) ;
      cout  << "  n " << n << endl;

      float d;
      ifile.set("real", d, "!= 5", 4.) ;
      cout << "  d "  << d << endl;
 
      bool b;
      ifile.set("boolean", b, "", false) ;
      cout  << "  b " << b << endl;
 
      string s;
      ifile.set("string", s, "'tests'|'t'", "error");
      cout << "  s "  << s << endl;
    }
     
    {
      const char* Constraint = "'fritz' | 'otto'";
        const char* Default    = "nonsense";

        cout << "Constraints on String:\n";
        cout << "   " << ifile.get("string/good1", Constraint, Default) << endl;
        cout << "   " << ifile.get("string/good2", Constraint, Default) << endl;
        cout << "   " << ifile.get("string/bad1",  Constraint, Default) << endl;
        cout << "   " << ifile.get("string/bad2",  Constraint, Default) << endl;
        cout << "   " << ifile.get("string/bad3",  Constraint, Default) << endl;
        cout << "   " << ifile.get("string/bad4",  Constraint, Default) << endl;
        cout << "   " << ifile.get("string/bad5",  Constraint, Default) << endl;

        cout << "Constraints on String (without default value):\n";
        cout << "   "          << ifile.get<string>("string/good1", Constraint) << endl;
        cout << "   "          << ifile.get<string>("string/good2", Constraint) << endl;
        try    { cout << "   " << ifile.get<string>("string/bad1",  Constraint) << endl; }
        catch(std::runtime_error){}
        try    { cout << "   " << ifile.get<string>("string/bad2",  Constraint) << endl; }
        catch(std::runtime_error){}
        try    { cout << "   " << ifile.get<string>("string/bad3",  Constraint) << endl; }
        catch(std::runtime_error){}
        try    { cout << "   " << ifile.get<string>("string/bad4",  Constraint) << endl; }
        catch(std::runtime_error){}
        try    { cout << "   " << ifile.get<string>("string/bad5",  Constraint) << endl; }
        catch(std::runtime_error){}
    }

    {
        // Constraint: if less or equal 16, it must be even, i.e. divisable by 2.
        //             if not,              it must be odd,  i.e. not divisable by 2.
        const char*  Constraint = "<= 16 & % 2 | > 16 & ! % 2";
        const double Default = -1;

        cout << "Constraints on Number:\n";
        cout << "   " << ifile.get("number/good1", Constraint, -1.0)    << endl;
        cout << "   " << ifile.get("number/good2", Constraint, Default) << endl;
        cout << "   " << ifile.get("number/good3", Constraint, Default) << endl;
        cout << "   " << ifile.get("number/bad1",  Constraint, Default) << endl;
        cout << "   " << ifile.get("number/bad2",  Constraint, Default) << endl;
        cout << "   " << ifile.get("number/bad3",  Constraint, Default) << endl;

        cout << "Constraints on String (without default value):\n";
        cout << "   "          << ifile.get<double>("number/good1", Constraint) << endl;
        cout << "   "          << ifile.get<double>("number/good2", Constraint) << endl;
        try    { cout << "   " << ifile.get<double>("number/bad1",  Constraint) << endl; }
        catch(std::runtime_error){}
        try    { cout << "   " << ifile.get<double>("number/bad2",  Constraint) << endl; }
        catch(std::runtime_error){}
        try    { cout << "   " << ifile.get<double>("number/bad3",  Constraint) << endl; }
        catch(std::runtime_error){}
    }

    {
        const char*  NConstraint = "! == 4711";
        const char*  SConstraint = "! 'rotten'";
        const double NDefault = -1;
        const char*  SDefault = "nonsense";

        cout << "Negation:\n";
        cout << ifile.get("negation/good_number", NConstraint, NDefault) << endl;
        cout << ifile.get("negation/bad_number",  NConstraint, NDefault) << endl;
        cout << ifile.get("negation/good_string", SConstraint, SDefault) << endl;
        cout << ifile.get("negation/bad_string",  SConstraint, SDefault) << endl;
    }

}


void
print_help()
{
    cerr << endl;
    cout << "Example how to use GetPot to apply constraints on input values." << endl;
    cerr << endl; 
    cerr << "USAGE:" << endl;
    cerr << "--help, -h, --hilfe, --sos" << endl;
    cerr << "        get some help about this program." << endl << endl;
    cerr << endl << endl;       
    cerr << "--internal-information, -i" << endl;
    cerr << "        show contents of database that was created by file parser.";
    cerr << endl;
}

