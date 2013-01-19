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
"#ifndef __CONSTANTS_H_448F6882__\r\n"
"#define __CONSTANTS_H_448F6882__\r\n"
"\r\n"
"#define BUFFER_SIZE 1024\r\n"
"#define BUFFER_SIZE_BASE 10 // 2^10\r\n"
"\r\n"
"#define SAMPLE_RATE 44100.0\r\n"
"\r\n"
"// Also check this number of buckets above and below the target bucket index.\r\n"
"// So if the bucket index is 33, this would check buckets 32 & 34.\r\n"
"#define BUCKET_TOLERANCE 1\r\n"
"\r\n"
"// The minimum strength of the bucket value in order to trigger a hit\r\n"
"#define BUCKET_MINIMUM_STRENGTH 20.0f // TODO: Needs tweaking\r\n"
"\r\n"
"// TODO: Would be nice to use real frequencies instead of bucket indexes\r\n"
"// These must be recalibrated for different FFT buffer sizes\r\n"
"static const int kHowlBucketIndexes[] = { 14, 32, 526 };\r\n"
"#define BUCKET_NUM_INDEXES 3\r\n"
"\r\n"
"// If all buckets have at least this many hits, a howl has been found\r\n"
"#define HOWL_FOUND_NUM_HITS 20\r\n"
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
