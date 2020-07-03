#include <support/C/hwut_unit.h>
#include <iostream>
#include <GetPot>

void test(const char* VariableName, GetPot&  cl);

int 
main(int argc, char** argv)
{
    using namespace std;

    GetPot   cl("bug-2992224.pot");

    hwut_info("Bug: <cmouton> Constraints with multiple parenthesis.");

    std::cout << "Constraint : (<= 5 & % 2) | (> 5 & ! % 2)" << endl;
    std::cout << "             -- less or equal five\n"; 
    std::cout << "                and divisable by two\n"; 
    std::cout << "             -- or greater than five\n";
    std::cout << "                and not divisable by two\n";
    
    test("a0", cl);
    test("a1", cl);
    test("a2", cl);
    test("a3", cl);
    test("a4", cl);
    test("a5", cl);
    test("a6", cl);
    test("a7", cl);
    test("a8", cl);
    test("a9", cl);
}

void test(const char* VariableName, GetPot&  cl)
{
    using namespace std;

    cout << VariableName << " = " << cl.get(VariableName, "((<= 5 & % 2) | (> 5 & ! % 2))", -1000) << endl;
}
