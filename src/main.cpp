
#include "./lib/common/string.h"


#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;


int test() {
    auto compareResult = cmn::compare( 
        "Sodium-ion batteries (NIBs, SIBs, or Na-ion batteries) are several types of rechargeable batteries, which use sodium ions (Na+) as their charge carriers.", 
        "Sodium-ion batteries (NIBs, SIBs, or Na-ion batteries) are several types of rechargeable batteries, which use sodìum ions (Na+) as their charge carrìers." );
    //                                                                                                                    ^                                  ^
    //   0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000111111111111111111111111111111111111111111111111111111111111
    //   0000000000111111111122222222223333333333444444444455555555556666666666777777777788888888889999999999000000000011111111112222222222333333333344444444445555555555
    //   0123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789
    if ( holds_alternative< size_t >( compareResult ) ) {
        cout << "String differs at position " << std::get< size_t  >( compareResult ) << endl;
    } else {
        cout << "String are equal." << endl;
    }
    return 0;
}

int main( [[maybe_unused]] int argc, [[maybe_unused]] char* argv[] )
{
    int     nArgIndex = 1;
    while ( nArgIndex < argc ) {
        string  sArg{ argv[ nArgIndex ] };
        if ( sArg == "-t" ) {
            nArgIndex++;
            return test() ? 0 : -1;
        } else {
            cout << "Unused: sArg = " << sArg << '\n';
            nArgIndex++;
        }
    }
    return 0;
}
