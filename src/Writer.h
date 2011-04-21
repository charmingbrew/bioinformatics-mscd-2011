#ifndef _WRITER_H
#define _WRITER_H

#include <string>
#include "Alignment.h"
#include "Sequence.h"
#include <cstdio>


class Writer
{
    private:

       /**
        *  a private static method that takes in a pointer to the alignment object
        *  and writes the alignment to a file.
        *  @param File A pointer to the deisired file name
        *  @param alignment A pointer to the aligned genotypes
        */
        static void AlignWrite(string *File, Alignment *alignment)
        {
            FILE *pFile;
            FILE *aFile;
            pFile = fopen("something.fasta", "wb");
            aFile = fopen("alignment.txt", "wb");
            fwrite(alignment, 1, sizeof(alignment), aFile);
            fclose(pFile);
            fclose(aFile);
        }

         /**
         *  a private static method that takes in a pointer to the sequence object
         *  and writes the sequence to a file.
         *  @param File A pointer to the desired file name
         *  @param sequence A pointer to the sequence of the genotypes
         */
        static void SeqWrite(string *File, Sequence *sequence)
        {
            FILE *pFile;
            FILE *sFile;
            pFile = fopen("something.fasta", "wb");
            sFile = fopen("sequence.txt", "wb");
            fwrite(sequence, 1, sizeof(sequence), sFile);
            fclose(pFile);
            fclose(sFile);
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
    public:
        /**
         *  a public static method that calls the private method AlignWrite
         *  @param Path
         *  @param alignment A pointer to the aligned genotypes
         */
        static void Write(string *Path, Alignment *alignment)
        {
            AlignWrite(Path, alignment);
        }

        /**
         *  a public static method that calls the private method SeqWrite
         *  @param Path
         *  @param sequence A pointer to the sequence of the genotypes
         */
        static void Write(string *Path, Sequence *sequence)
        {
            SeqWrite(Path, sequence);
        }

        /**
         *  a public static method that calls the private method AlignWrite that writes the results
         *  @param Path
         *  @param result A pointer to the result of the aligned genotypes
         */
         /**
        static void Writer::Write(string Path, Result *result)
        {
            cout<<"Import Skynett" << endl;
        }
*/
};

#endif // _WRITER_H
