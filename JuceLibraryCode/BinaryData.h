/* =========================================================================================

   This is an auto-generated file: Any edits you make may be overwritten!

*/

#ifndef BINARYDATA_H_1109256_INCLUDED
#define BINARYDATA_H_1109256_INCLUDED

namespace BinaryData
{
    extern const char*   icon_png;
    const int            icon_pngSize = 373630;

    extern const char*   Constants_h;
    const int            Constants_hSize = 1900;

    // Points to the start of a list of resource names.
    extern const char* namedResourceList[];

    // Number of elements in the namedResourceList array.
    extern const int namedResourceListSize;

    // If you provide the name of one of the binary resource variables above, this function will
    // return the corresponding data and its size (or a null pointer if the name isn't found).
    const char* getNamedResource (const char* resourceNameUTF8, int& dataSizeInBytes) throw();
}

#endif
