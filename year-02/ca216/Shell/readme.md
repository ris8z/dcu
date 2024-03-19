<---------------------------( USER MANUAL )--------------------------->



<------( Description of operation and commands )

The internal command, with an direct implementiation are ["cd","clr","dir","environ", "echo", "pause", "quit"]
a biref description of them below.

`cd`
    NAME:
        cd - change current directory  

    SYNOPSIS:
        cd [directory name]
        cd

    DESCRIPTION:
        the cd utility, change the current working directory,
        It try to change direcotry the the one specificated [directory name]
        if there is no direcotry name specificed it leads to to you HOME directory.


`clr`
    NAME:
        clr - clear the terminal screen

    SYNOPSIS:
        clr

    DESCRIPTION:
        it clears the terminal screen


`dir`
    NAME:
        dir - list all the file and direcotry

    SYNOPSIS:
            dir [file name]
            dir [directroy name]

    DESCRIPTION:

`environ`
    NAME:
        environ - display all the environment variables

    SYNOPSIS:
        environ

    DESCRIPTION:
        it display all the environment vars one by one

`echo`
    NAME:
        echo - display a string of text

    SYNOPSIS:
        echo [string]

    DESCRIPTION:
        it display the string to the terminal

`help`
    NAME:
        help - diplay the shell manual (this one)

    SYNOPSIS:
        help

    DESCRIPTION:
        show the manual page

`pause`
    NAME:
        pause - stop shell operation until 'enter' is pressed

    SYNOPSIS:
        pause

    DESCRIPTION:
        stop the shell until a keyboard character is pressed

`quit`
    NAME:
        quit - quit the shell

    SYNOPSIS:
        quit

    DESCRIPTION:
        quit the shell

All the other command are redirect to bash shell using the function
'execvp' type man execvp for more info




<------(Description of environment concepts)

The environment is a set of dinamic variable accessible from the terminal and it's sub procces
containg usufel information.
For example there is a variabele called PWD that stores the cucrent working directory.



<------(Description of i/o redirection)

You can change the input and output of a pragram by using this chars: "<", ">", ">>":

`<`: it is for the input, after this char you need to put the name of the input file
    ex:
        grep a < myinputfile.txt

`>`: it is for the output, after this char you need to put the name of the outputfile (this char erease the file if already exist and then add the output of your program)
    ex:
        dir > myoutputfile.txt

`>>`: it is similar to ">" but insent but it append the output of your porgram to the file
    ex:
        pwd >> myoutputfile.txt

<------(Description of the process concept, and the differences between background and foreground execution)


<------(References)

Giuseppe Esposito
22702705
<--------------------------------------------------------------------->
