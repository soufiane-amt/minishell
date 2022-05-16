--Check if the commands exist;
--if they are executable;
--if all the symbols given by the user are acceptable;
--check the position of the pipe strchr\\
--handle () ; they should be sum % 2 == 0
--check the position of << >> < > not last
--check the existence of env and PATH
--you should handle absolue paths of files
--heredoc input should be passed from "" and $ function to_handle by function
--status could be a string message and could be passed tp print_error
--free status
--unlink;

--check if all commands are serrounded by the prenthesis
he problem was that when the exec_cmd function tries to execute command an fails the child process is keeping going reading next instructions without any exit function or 
return to kill it , at while this takes place the first created child  process continues executing the first command and printing its output in the stdin , 
at the same time the failed child process exits the exec_cmd_ln function and loops around with new prompt that takes input from the stdin occupied in the mean time by the 
first child process and here the first child process becomes the input of the new prompt created by child second process and not only that the second child process is 
creating more child processes which will take control over the program .


in herdoc you should change all the user input into its real values
//
check if input data is surrounded by valid printhesis 
what if you cd to an other directory but you lose temp file path

𝖒𝖎𝖓𝖎𝖘𝖍𝖊𝖑𝖑➜cat
dlfk
dlfk
dlfkf
dlfkf




𝖒𝖎𝖓𝖎𝖘𝖍𝖊𝖑𝖑➜cat
𝖒𝖎𝖓𝖎𝖘𝖍𝖊𝖑𝖑➜𝖒𝖎𝖓𝖎𝖘𝖍𝖊𝖑𝖑➜
handle the lst_new type
//test syntax pipe
// ()
// test wrong CMD_NOT_F
// multipipes