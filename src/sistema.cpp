#ifndef Sistema_C
#define Sistema_C
#include "../include/sistema.hpp"
#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include "../include/processqueue.hpp"

using namespace std;

Sistema::Sistema()
{
    running = true;
    current_screen = SCREENS::MENU;
    queue = ProcessQueue();
}

void Sistema::run()
{
    while(running)
    {
        this->show();
    }
}

void Sistema::stop()
{
    this->running = false;
}

void Sistema::clearScreen()
{
    system("cls");
}

string Sistema::getLine()
{
    string line;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(cin, line);
    return line;
}

void Sistema::show()
{
    int input;
    int n1, n2;
    char operation;
    string line;
    MathExpression expression;
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
        cout << "   > ";
        cin >> input;
        switch (input) {
            case 1: current_screen = SCREENS::CREATE_PROCESS; break;
            case 2: current_screen = SCREENS::EXECUTE_NEXT; break;
            case 3: current_screen = SCREENS::EXECUTE_PID; break;
            case 4: current_screen = SCREENS::SAVE_QUEUE; break;
            case 5: current_screen = SCREENS::LOAD_QUEUE; break;
            case 9: running = false; break;
            default: cout << "Opcao invalida, tente novamente." << endl; break;
        }
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
        cout << "   > ";
        cin >> input;
        switch (input) {
            case 1: current_screen = SCREENS::CREATE_COMPUTING_PROCESS; break;
            case 2: current_screen = SCREENS::CREATE_WRITING_PROCESS; break;
            case 3: current_screen = SCREENS::CREATE_READING_PROCESS; break;
            case 4: current_screen = SCREENS::CREATE_PRINTING_PROCESS; break;
            case 9: current_screen = SCREENS::MENU; break;
            default: cout << "Opcao invalida, tente novamente." << endl; break;
        }
        break;

    case SCREENS::CREATE_COMPUTING_PROCESS:
        clearScreen();
        cout << "---------- CRIAR PROCESSO DE COMPUTACAO ----------" << endl;
        cout << endl;
        cout << "   Insira o primeiro numero: ";
        cin >> n1;
        cout << "   Insira a operacao (+, -, *, /): ";
        cin >> operation;
        while (!expression.isValidOperation(operation)) {
            cout << "Operacao invalida. Tente novamente: ";
            cin >> operation;
        }
        cout << "   Insira o segundo numero: ";
        cin >> n2;
        expression.setA(n1);
        expression.setB(n2);
        expression.setOperation(expression.toOperation(operation));

        queue.addComputingProcess(expression);
        current_screen = SCREENS::CREATE_PROCESS;
        break;

    case SCREENS::CREATE_WRITING_PROCESS:
        clearScreen();
        cout << "---------- CRIAR PROCESSO DE ESCRITA ----------" << endl;
        cout << endl;
        cout << "   Insira o primeiro numero: ";
        cin >> n1;
        cout << "   Insira a operacao (+, -, *, /): ";
        cin >> operation;
        while (!expression.isValidOperation(operation)) {
            cout << "Operacao invalida. Tente novamente: ";
            cin >> operation;
        }
        cout << "   Insira o segundo numero: ";
        cin >> n2;
        expression.setA(n1);
        expression.setB(n2);
        expression.setOperation(expression.toOperation(operation));

        queue.addWritingProcess(expression);
        current_screen = SCREENS::CREATE_PROCESS;
        break;

    case SCREENS::CREATE_READING_PROCESS:
        queue.addReadingProcess();
        current_screen = SCREENS::CREATE_PROCESS;
        break;

    case SCREENS::CREATE_PRINTING_PROCESS:
        queue.addPrintingProcess();
        current_screen = SCREENS::CREATE_PROCESS;
        break;

    case SCREENS::EXECUTE_NEXT:
        queue.executeNext();
        current_screen = SCREENS::MENU;
        break;

    case SCREENS::EXECUTE_PID:
        clearScreen();
        cout << "---------- EXECUTAR PROCESSO POR PID ----------" << endl;
        cout << endl;
        cout << "   Insira o PID do processo: ";
        cin >> input;
        queue.executeByPID(input);
        current_screen = SCREENS::MENU;
        break;

    case SCREENS::SAVE_QUEUE:
        clearScreen();
        cout << "---------- SALVAR FILA EM ARQUIVO ----------" << endl;
        cout << endl;
        cout << "   Insira o nome do arquivo (sem .txt): ";
        cin >> line;
        queue.saveToFile(line);
        current_screen = SCREENS::MENU;
        break;

    case SCREENS::LOAD_QUEUE:
        clearScreen();
        cout << "---------- SALVAR FILA EM ARQUIVO ----------" << endl;
        cout << endl;
        cout << "   Insira o nome do arquivo (sem .txt): ";
        cin >> line;
        queue.loadFromFile(line);
        current_screen = SCREENS::MENU;
        break;

    default:
        break;
    }
}

#endif
