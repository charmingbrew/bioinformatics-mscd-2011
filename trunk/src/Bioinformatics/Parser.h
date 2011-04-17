#ifndef _PARSER_H
#define _PARSER_H


class Parser
{
    private:
        static void FastaParse(std::string *Name, std::string *Sequence, int size_name, int size_sequence);
        static void AlignParse();
    public:
        static Sequence SeqFromFile(std::string Path);
        static Sequence SeqFromString(std::string Sequence, std::string Name);
        static Alignment AlignFromFile(std::string Path);
};

#endif // _PARSER_H
