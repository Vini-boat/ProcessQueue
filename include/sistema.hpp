#ifndef Sistema_H
#define Sistema_H

#include <string>
#include "processqueue.hpp"

using namespace std;
class Sistema
{
    public:
    Sistema();
    void run();
    void stop();

    private:
    bool running;
    int current_screen;
    void show();
    void clearScreen();
    string getLine();
    enum SCREENS {
        MENU,
        CREATE_PROCESS,
        CREATE_COMPUTING_PROCESS,
        CREATE_WRITING_PROCESS,
        CREATE_READING_PROCESS,
        CREATE_PRINTING_PROCESS,
        EXECUTE_NEXT,
        EXECUTE_PID,
        SAVE_QUEUE,
        LOAD_QUEUE,
    };

    ProcessQueue queue;
};

#endif
