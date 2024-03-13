#include "Command.h"
#include "RunCommand.h"

int main(int argc, char **argv){

    Command c;

    c.args = {"ls", "-l", "0"};
    
    run_command(c);
    return 0;
}
