#ifndef _SEQUENCE_H
#define _SEQUENCE_H

class Sequence
{
    private:
        std::string Name;
        std::string Sequence;

    public:
        Sequence();
        ~Sequence();

        std::string GetName();
        void SetName(std::string Name);

        std::string GetSequence();
        void SetSequence(std::string Sequence);

        std::string GetFormattedSequence();
}

#endif // _SEQUENCE_H
