#include<iostream>
#include<GetPot>

using namespace std;

void something(const string User, const string User2, const string User3,
	       double Value, double Value2, double Value3,
	       int Number, int Number2, int Number3);
void print_help(const string);


int
main(int argc, char** argv)
{
    GetPot   cl(argc, argv);
    if( cl.size() == 1 || cl.search(2, "--help", "-h") ) print_help(cl[0]);

    // print out all argument that do not start with a minus
    cout << "\n(1) iterating with .next_nominus():\n    ";
    string  nm = cl.next_nominus();
    while( nm != "" ) {
	cout << "[" << nm << "]" << '\t';
	nm = cl.next_nominus();     
    } 
    
    cout << endl;

    // now get the whole vector at once
    cout << "(2) extracting nominus vector, then iterating:\n    ";
    vector<string>   files = cl.nominus_vector();
    for(vector<string>::const_iterator it=files.begin();
	it != files.end();
	it++) 
	cout << "<" << *it << ">" << '\t';

    cout << "\n\n";
}


void print_help(const string Application)
{
    cout << endl;
    cout << "APPLICATION: Nominus Arguments" << endl;
    cout << endl;
    cout << "USAGE:" << endl;
    cout << "   ./follow [arguments]*" << endl << endl;
    cout << "   --help, -h  get some help about this program." << endl;
    cout << endl;
    cout << "  any option that does not start with '-'" << endl;
    cout << "  will be printed on screen twice." << endl;
    cout << endl;
    exit(0);
}




