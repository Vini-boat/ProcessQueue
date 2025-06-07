#ifndef SYSTEM_C
#define SYSTEM_C
#include "system.hpp"
#include <iostream>
#include <string>
#include <limits>

using namespace std;
System::System()
{
    running = true;
    current_screen = SCREENS::MENU;
}
void System::run()
{
    while(running)
    {
        this->show();
        this->handleInput();
    }
}

void System::stop()
{
    this->running = false;
}

void System::clearScreen()
{
    system("cls");
}

string System::getLine()
{
    string line;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(cin, line);
    return line;
}

void System::show()
{
    switch (current_screen)
    {
    case SCREENS::MENU:
        clearScreen();
        cout << "---------- MENU ----------" << endl;
        cout << endl;
        cout << "   1- Criar novo processo" << endl;
        cout << "   2- Executar proximo processo" << endl;
        cout << "   3- Executar processo por PID" << endl;
        cout << "   4- Salvar fila de processos" << endl;
        cout << "   5- Carregar arquivo de fila" << endl;
        cout << "   9- Sair" << endl;
        cout << endl;
        break;
    case SCREENS::CREATE_PROCESS:
        clearScreen();
        cout << "---------- CRIAR PROCESSO ----------" << endl;
        cout << endl;
        cout << "   1- Criar processo de computacao" << endl;
        cout << "   2- Criar processo de escrita" << endl;
        cout << "   3- Criar processo de leitura" << endl;
        cout << "   4- Criar processo de impressao" << endl;
        cout << "   9- Voltar ao menu" << endl;
        cout << endl;
        break;
    case SCREENS::CREATE_COMPUTING_PROCESS:
        clearScreen();
        cout << "---------- CRIAR PROCESSO DE COMPUTACAO ----------" << endl;
        cout << endl;
        break;
    default:
        break;
    }
}

void System::handleInput()
{
    int input;
    string expression;
    switch (current_screen)
    {
    case SCREENS::MENU:
        while (true)
        {
            cout << "   > ";
            cin >> input;
            if(input == 1){
                current_screen = SCREENS::CREATE_PROCESS;
                break;
            }
            if(input == 2){
                current_screen = SCREENS::EXECUTE_NEXT;
                break;
            }
            if(input == 3){
                current_screen = SCREENS::EXECUTE_PID;
                break;
            }
            if(input == 4){
                current_screen = SCREENS::SAVE_QUEUE;
                break;
            }
            if(input == 5){
                current_screen = SCREENS::LOAD_QUEUE;
                break;
            }
            if(input == 9){
                running = false;
                break;
            }
            cout << "Opcao invalida, tente novamente. " << endl;
        }
        break;
    case SCREENS::CREATE_PROCESS:
        while (true)
        {
            cout << "   > ";
            cin >> input;
            if(input == 1){
                current_screen = SCREENS::CREATE_COMPUTING_PROCESS;
                break;
            }
            if(input == 2){
                current_screen = SCREENS::CREATE_WRITING_PROCESS;
                break;
            }
            if(input == 3){
                current_screen = SCREENS::CREATE_READING_PROCESS;
                break;
            }
            if(input == 4){
                current_screen = SCREENS::CREATE_PRINTING_PROCESS;
                break;
            }
            if(input == 9){
                current_screen = SCREENS::MENU;
                break;
            }
            cout << "Opcao invalida, tente novamente. " << endl;
        }
        break;
    case SCREENS::CREATE_COMPUTING_PROCESS:
        cout << "   Insira a expressao a ser computada: ";
        expression = getLine();
        // TODO: criar processo de computacao
        current_screen = SCREENS::CREATE_PROCESS;
        break;
    case SCREENS::CREATE_WRITING_PROCESS:
        cout << "   Insira o expressao a ser escrita: ";
        expression = getLine();
        //TODO: criar processo de escrita
        current_screen = SCREENS::CREATE_PROCESS;
        break;
    case SCREENS::CREATE_READING_PROCESS:
        //TODO: criar processo de leitura
        current_screen = SCREENS::MENU;
        break;
    case SCREENS::CREATE_PRINTING_PROCESS:
        //TODO: criar processo de impressao
        current_screen = SCREENS::MENU;
        break;
    case SCREENS::EXECUTE_NEXT:
        //TODO: executar proximo processo
        current_screen = SCREENS::MENU;
        break;
    case SCREENS::EXECUTE_PID:
        //TODO: executar processo por PID
        current_screen = SCREENS::MENU;
        break;
    case SCREENS::SAVE_QUEUE:
        //TODO: salvar fila de processos
        current_screen = SCREENS::MENU;
        break;
    case SCREENS::LOAD_QUEUE:
        //TODO: salvar fila de processos
        current_screen = SCREENS::MENU;
        break;
    default:
        break;
    }
}

#endif