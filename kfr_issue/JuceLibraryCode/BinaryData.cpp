/* ==================================== JUCER_BINARY_RESOURCE ====================================

   This is an auto-generated file: Any edits you make may be overwritten!

*/

#include <cstring>

namespace BinaryData
{

//================== README.txt ==================
static const unsigned char temp_binary_data_0[] =
"Code for reading/writing wav and reading flac and mp3 files.\n"
"\n"
"These 3 files are released to public domain by the author:\n"
"dr_flac.h\n"
"dr_wav.h\n"
"dr_mp3.h\n"
"\n"
"See also information in these files.\n"
"\n"
"https://github.com/mackron/dr_libs\n";

const char* README_txt = (const char*) temp_binary_data_0;


const char* getNamedResource (const char* resourceNameUTF8, int& numBytes);
const char* getNamedResource (const char* resourceNameUTF8, int& numBytes)
{
    unsigned int hash = 0;

    if (resourceNameUTF8 != nullptr)
        while (*resourceNameUTF8 != 0)
            hash = 31 * hash + (unsigned int) *resourceNameUTF8++;

    switch (hash)
    {
        case 0x2aaab85f:  numBytes = 223; return README_txt;
        default: break;
    }

    numBytes = 0;
    return nullptr;
}

const char* namedResourceList[] =
{
    "README_txt"
};

const char* originalFilenames[] =
{
    "README.txt"
};

const char* getNamedResourceOriginalFilename (const char* resourceNameUTF8);
const char* getNamedResourceOriginalFilename (const char* resourceNameUTF8)
{
    for (unsigned int i = 0; i < (sizeof (namedResourceList) / sizeof (namedResourceList[0])); ++i)
        if (strcmp (namedResourceList[i], resourceNameUTF8) == 0)
            return originalFilenames[i];

    return nullptr;
}

}
