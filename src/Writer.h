#ifndef _WRITER_H
#define _WRITER_H

#include <string>
#include <fstream>
#include <iostream>
#include "Alignment.h"
#include "Sequence.h"

class Writer
{
    public:

       /**
        *  a private static method that takes in a pointer to the alignment object
        *  and writes the alignment to a file.
        *  @param File A pointer to the deisired file name
        *  @param alignment A pointer to the aligned genotypes
        */
        static void FileWrite(Alignment alignment)
        {

        }

         /**
         *  a private static method that takes in a pointer to the sequence object
         *  and writes the sequence to a file.
         *  @param File A pointer to the desired file name
         *  @param sequence A pointer to the sequence of the genotypes
         */
        static void FileWrite(Sequence sequence)
        {
            ofstream toaster;
            toaster.open ("m9848_OUTPUT.txt");
            toaster << sequence.GetSequence();
            toaster.close();
        }

        /**
         *  a private static method that takes in a pointer to the result object
         *  and writes the result to a file.
         *  @param File A pointer to the desired file name
         *  @param result A pointer to the result from the aligned genotypes
         */

        /**
        static void Writer::AlignWrite(string *File, Result *result)
        {
            FILE *pFile;
            FILE *rFile;
            pFile = fopen("something.fasta", "wb");
            rFile = fopen("result.txt", "wb");
            fwrite(result, 1, sizeof(result), rFile);
            fclose(pFile);
            fclose(rFile);
        }
        */
};

#endif // _WRITER_H
