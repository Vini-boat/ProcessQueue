#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>

using namespace std;
class System
{
    public:
    System();
    void run();
    void stop();

    private:
    bool running;
    int current_screen;
    void show();
    void handleInput();
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
};

#endif