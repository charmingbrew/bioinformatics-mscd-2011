#ifndef _WRITER_H
#define _WRITER_H


class Writer
{
    private:
        static void AlignWrite(std::string *File, Alignment alignment);
        static void SeqWrite(std::string *File, Sequence sequence);
        static void ResultWrite(std::string *File, Result result);
    public:
        static void Write(std::string Path, Alignment alignment);
        static void Write(std::string Path, Sequence sequence);
        static void Write(std::string Path, Result result);
};

#endif // _WRITER_H
