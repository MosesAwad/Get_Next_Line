# Get_Next_Line
This project involves designing a function that reads a line from a file (or the standard input). Calling the function again would read the next line and so on until the end of the file has been reached.
The main challenge comes from the fact that the user can set the BUFFER_SIZE to whatever value they desire, as long as it is between 0 and INT_MAX. BUFFER_SIZE is how many bytes the read function reads
at once. Thus, the user can choose a buffer size that is longer than the length of the line and the function should still NOT return anything after the '\n' instance and only return one line (even if the
read function has read more bytes than the length of the line). The user can set the BUFFER_SIZE to the value that they desire either by using the flag -D BUFFER_SIZE='value' or by changing the Macro in 
the headerfile.

The bonus part of the project works the same way except it allows us to read from mutliple files at once. The challenge being that the static variables that store whatever has been read beyond th '\n' 
instance do not get jumbled up across different files. So, if the user were to call the function like this:

char *str1 = get_next_line(fd1);
char *str 2 = get_next_line(fd2);
char *str 3 = get_next_line(fd1);

Then the static variable from fd2 (if it is not NULL) should not be joined with the static variable from fd1 once get_next_line(fd1) is called again.
