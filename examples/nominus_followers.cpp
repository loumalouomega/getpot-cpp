// -*- C++ -*-
// MIT License; Project getpot.sourceforge.net
//
// (C) 2006  Frank R. Schaefer
//
//////////////////////////////////////////////////////////////////////////////////////
#include<iostream>
#include<GetPot>

using namespace std;

void something(const std::vector<std::string>& inputs,
	       const std::vector<std::string>& outputs);
void print_help(const string);


int
main(int argc, char** argv)
{
    using namespace std;

    GetPot   cl(argc, argv);
    if( cl.size() == 1 || cl.search(2, "--help", "-h") ) print_help(cl[0]);

    // read arguments one by one on the command line
    //  (lazy command line parsing)
    const vector<string> inputs  = cl.nominus_followers("-i"); 
    const vector<string> outputs = cl.nominus_followers(3, "-o", "--output");

    something(inputs, outputs);
}


void something(const std::vector<std::string>& inputs,
	       const std::vector<std::string>& outputs)
{
    using namespace std;

    cout << endl;
    cout << "inputs = ";
    for(vector<string>::const_iterator it = inputs.begin();
	it != inputs.end(); ++it) 
	cout << *it << ", ";
    cout << endl;
    cout << "outputs = ";
    for(vector<string>::const_iterator it = outputs.begin();
	it != outputs.end(); ++it) 
	cout << *it << ", ";

    cout << endl;
}

void print_help(const string Application)
{
    using namespace std;

    cout << endl;
    cout << "Example to use nominus_follower()-functions:" << endl << endl;
    cout << "USAGE:" << endl;
    cout << "--help, -h" << endl;
    cout << "       get some help about this program." << endl;
    cout << "-i [nominus arguments]+" << endl;
    cout << "       any number of arguments that do not start with '-'." << endl;
    cout << "       These arguments are going to be listed under 'inputs.'" << endl;
    cout << "-o        [nominus arguments]+" << endl;
    cout << "--output  [nominus arguments]+" << endl;
    cout << "--ausgabe [nominus arguments]+" << endl;
    cout << "       any number of arguments that do not start with '-'." << endl;
    cout << "       These arguments are going to be listed under 'output.'" << endl;
    cout << "\n";
    cout << "Add any number of command line arguments starting with or without '-'" << endl;
    cout << endl;
    exit(0);
}




