// -*- C++ -*- 
//    FILE: filter.cpp
//    (C) 2002  Frank R. Schaefer
//    License: MIT
//
///////////////////////////////////////////////////////////////////////////////////
#include<iostream>
#include<GetPot>
#include<string>

using namespace std;

#define SQR(x) ((x)*(x))

void draw_circle(int Radius);
void draw_rectangle(int SizeX, int SizeY);
void draw_smiley(bool HappyF);

int 
main(int argc, char** argv) 
{
    GetPot  cl(argc, argv);
    string  input_file = cl.follow("example.pot", "--alternative");
    GetPot  ifpot(input_file.c_str());

    // (1) search for multiple options with the same meaning
    if( cl.search(4, "--help", "-h", "--hilfe", "--sos") ) {
        const string Msg = "Example program treating the prefix filtering.\n\n"
            "   Using the function .set_prefix(section) only arguments, options \n"
            "   variables are considered in the given 'section'\n\n"
            "--help, -h, --hilfe, --sos \n"
            "       this page.\n" 
            "--nice \n" 
            "       demonstrates how pseudo function calls can be accomplished.\n\n" 
            "please refer to the file 'example.pot' as input file.\n";
        cout << Msg << endl;
        exit(0);
    }

    //  -- note that the prefix is not considered as a flag
    //  -- the index in 'argument contains' indicates the position
    //     of the argument inside the namespace given by prefix
    cout << "Filter prefix: group/\n";
    ifpot.set_prefix("group/");

    cout << " -- flags in options / arguments" << endl;
    bool first_f  = ifpot.argument_contains(1, "xX");
    bool second_f = ifpot.argument_contains(1, "cCkK");
    bool abc_f    = ifpot.options_contain("abc");
    cout << "    Flags in first argument in [flags]\n" << endl;
    cout << "    x or X in arg 1       = " << first_f << endl;
    cout << "    c, C, k or K in arg 1 = " << second_f << endl;
    cout << "    a,b, or c in options  = " << abc_f << endl;
    cout << endl;
    cout <<  " -- search(), next() and follow()" << endl;
    cout << endl;
    cout <<  "    found \"--rudimental\" = " << ifpot.search("--rudimental") << endl;
    // Note that the '<<' operator may mix up the function call sequence !
    int Tmp1 = ifpot.next(-1);
    int Tmp2 = ifpot.next(-1);
    cout <<  "    followed by " << Tmp1 << " and " << Tmp2 << endl;
    const string Tmp3 = ifpot.follow("nothing", "--rudimental");
    int          Tmp4 = ifpot.next(-1);
    cout <<  "    rudimental = " << Tmp3 << " " << Tmp4 << endl;

    //  -- variables
    cout << endl;
    cout <<  " -- variables in section [user-variables]" << endl;
    cout << endl;

    cout << "Filter prefix: user-variables/\n";
    ifpot.set_prefix("user-variables/");
    vector<string> variable_names = ifpot.get_variable_names();
    for(vector<string>::const_iterator it = variable_names.begin();
        it != variable_names.end();
        it++) {
        cout <<  "    " << *it <<  "   \t= ";
        cout << ifpot((*it).c_str(), 0, 1e37);
        cout <<  "[" <<  ifpot((*it).c_str(), 1, "[1]") << "]" << endl;
    }
    cout << endl;	

    //  -- pseudo function calls
    if( cl.search("--nice") ) {
        cout <<  " -- pseudo function call feature" << endl;
        cout << endl;

        cout << "Filter prefix: pseudo-function-calls/\n";
        ifpot.set_prefix("pseudo-function-calls/");
        // ifpot.Cout << ()
        ifpot.init_multiple_occurrence();

        ifpot.search("LE-DEBUT");
        while( 1 + 1 == 2 ) {
            const string Next = ifpot.next("(no-func)");

            if( Next == "(no-func)" ) {
                break;
            }
            else if( Next == "rectangle") {
                unsigned size_x = ifpot.next(10);
                unsigned size_y = ifpot.next(10);
                draw_rectangle(size_x, size_y);
            }
            else if( Next == "circle") {
                unsigned radius = ifpot.next(4);
                draw_circle(radius);
            }
            else if( Next == "smiley" ) {
                const string Mood = ifpot.next("happy");
                draw_smiley(Mood == "happy" ? true : false);
            }
            else if( Next == "new-line") {
                const unsigned No = ifpot.next(1);
                for(unsigned i=0; i<No ;i++) cout << endl;
            }
        }
    }   
    else
        cout <<  "(use the --nice command line flag for graphical output)";
    cout << endl;
}


void draw_circle(int Radius)
{
    cout << endl;
    for(int y=0; y < Radius*2 + 1; y++) {
        for(int x=0; x < Radius*2 + 1; x++)			    
            if(    SQR(x-Radius) + SQR(y-Radius) <= SQR(Radius)
                   && SQR(x-Radius) + SQR(y-Radius) >= SQR(Radius)/2. )
                cout << ".";
            else 
                cout << " ";
        cout << endl;
    }
}    

void draw_rectangle(int SizeX, int SizeY)
{
    cout << endl;
    for(int y=0; y < SizeY; ++y) {
        for(int x=0; x < SizeX; ++x) {			    
            cout << ((x + y) % 2 ? "-" : "+");  
        }    
        cout << endl;
    }
}

void draw_smiley(bool HappyF)
{
    cout << (HappyF ? "[happy smiley]" : "[sad smiley]") << endl;
}    

