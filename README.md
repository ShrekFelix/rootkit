# rootkit

The sneaky kernel module will implement the following subversive actions: 

1. It will hide the “sneaky_process” executable file from both the ‘ls’ and ‘find’ UNIX commands. 

2. In a UNIX environment, every executing process will have a directory under /proc that is named with its process ID (e.g /proc/1480). This directory contains many details about the process. The sneaky kernel module will hide the /proc/<sneaky_process_id> directory (note hiding a directory with a particular name is equivalent to hiding a file!). For example, if the sneaky_process is assigned process ID of 500, then: 

   1. “ls /proc” should not show a sub-directory with the name “500” 

   2. “ps -a -u <your_user_id>” should not show an entry for process 500 

      named “sneaky_process” (since the ‘ps’ command looks at the /proc directory to examine all executing processes). 

3. It will hide the modifications to the /etc/passwd file that the sneaky_process made. It will do this by opening the saved “/tmp/passwd” when a request to open the “/etc/passwd” is seen.  For example: “cat /etc/passwd” should return contents of the original password file without the modifications the sneaky process made to /etc/passwd. 

4. It will hide the fact that the sneaky_module itself is an installed kernel module. The list of active kernel modules is stored in the /proc/modules file. Thus, when the contents of that file are read, the sneaky_module will remove the contents of the line for “sneaky_mod” from the buffer of read data being returned. For example: “lsmod” should return a listing of all modules except for the “sneaky_mod” 