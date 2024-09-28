
#include "string.h"


using std::string;
using std::variant;

#include <exception>
using std::exception;


namespace cmn {


variant<Equal, size_t> compare( string sA, string sB ) {
    size_t      pos = 0;
    bool        continueLoop = true;
    bool        equal;
    while ( continueLoop ) {
        try {
            char    chA;
            char    chB;
            chA = sA.at( pos );
            chB = sB.at( pos );
            equal = chA == chB;
            continueLoop = equal;
            if ( continueLoop ) {
                pos++;
            }
        } catch ( exception const& ) {
            equal = sA.length() == sB.length();
            continueLoop = false;
        }
    }
    variant<Equal, size_t>  result;
    if ( equal ) {
        result = Equal{};
    } else {
        result = pos;
    }
    return result;
}


} // namespace cmn
