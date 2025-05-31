#ifndef SYSTEM_H
#define SYSTEM_H

class System
{
    public:
    System();
    void run();
    void stop();

    private:
    bool running;
    void show();
    void handleInput();
};

#endif