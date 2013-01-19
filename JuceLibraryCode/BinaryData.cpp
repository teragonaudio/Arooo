/* ==================================== JUCER_BINARY_RESOURCE ====================================

   This is an auto-generated file: Any edits you make may be overwritten!

*/

namespace BinaryData
{

//================== Constants.h ==================
static const unsigned char temp_5e5755fc[] =
"/*\r\n"
"  ==============================================================================\r\n"
"\r\n"
"    Constants\r\n"
"    Created: 19 Jan 2013 1:55:33pm\r\n"
"    Author:  Nik Reiman\r\n"
"\r\n"
"  ==============================================================================\r\n"
"*/\r\n"
"\r\n"
"#ifndef __CONSTANTS_448F6882__\r\n"
"#define __CONSTANTS_448F6882__\r\n"
"\r\n"
"\r\n"
"\r\n"
"\r\n"
"\r\n"
"#endif  // __CONSTANTS_448F6882__\r\n";

const char* Constants_h = (const char*) temp_5e5755fc;


const char* getNamedResource (const char*, int&) throw();
const char* getNamedResource (const char* resourceNameUTF8, int& numBytes) throw()
{
    unsigned int hash = 0;
    if (resourceNameUTF8 != 0)
        while (*resourceNameUTF8 != 0)
            hash = 31 * hash + (unsigned int) *resourceNameUTF8++;

    switch (hash)
    {
        case 0xe75f2d58:  numBytes = 363; return Constants_h;
        default: break;
    }

    numBytes = 0;
    return 0;
}

}
