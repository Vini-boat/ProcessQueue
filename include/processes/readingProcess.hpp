#ifndef READINGPROCESS_H
#define READINGPROCESS_H

#include "../processqueue.hpp"

using namespace std;
class ReadingProcess : public Process
{
    public:
        ReadingProcess(int pid, ProcessQueue* queue);
        void execute() override;
        string toString() override;

        //friend ostream& operator<<(ostream& os, const ReadingProcess& process);

    private:
    ProcessQueue* queue;
};

#endif
