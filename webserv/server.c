/*
1. Initialize server's sequence number to 0 or random number : https://stackoverflow.com/questions/10452855/tcp-sequence-number
2. Ignore SIGPIPE signal : Makes sure writing to a closed peer socket fails at write with EPIPE
3. Get set of socket address structs for TCP sock that uses PORT_NUM(service name)
    with getaddrinfo()
4. AI_PASSIVE is specified to bind the socket to wildcard address (node needs to be NULL)
    to enable multi host servers to accept connections requests sent to ant of host's network addresses
5. Iterate through the socket addr structs receivde. Exit loop when a socket addr struct capable of
    a socket and bind successfully
6. Set SO_REUSEADDR for the socket : Because it's the listening socket
7. mark it as listening socket
8. Service clients iteratively : each client request served before next client's request is accepted
LOOP
    1. Accept a new connection : pass non-NULL pointers to accept() : obtain the address of the client
        display client address on stdout
    2. Read client message : '\n' terminated string specifys how many sequence numbers the client wants
        convert string to int store in reqLen
    3. Send current seqNum to client, encoding it as a '\n' terminated string
        seqNum - (seqNum + reqLen - 1) are assumed to be allocated by server
    4. Update the server sequence number 
        new seqNum = seqNum + reqlen

*/
#define _DEFAULT_SOURCE//_BSD_SOURCE
#include <stdint.h>
#include <sys/types.h>
#include <sys/socket.h> 
#include <netdb.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <errno.h>
#include <readline/readline.h>
#define INT_LEN 30
# define BACKLOG 50
#define PORT_NUM "50000"
#define ADDRSTRLEN (NI_MAXHOST + NI_MAXSERV + 10)

int main(int argc, char **argv)
{
    uint32_t                seqNum;
    char                    rewLenStr[INT_LEN];
    char                    seqNumStr[INT_LEN];
    struct sockaddr_storage claddr; // https://manpages.ubuntu.com/manpages/lunar/man3/sockaddr.3type.html#:~:text=sockaddr_storage%20A%20structure%20at%20least,of%20at%20least%2032%20bits.
    int                     lfd;
    int                     cfd;
    int                     optval;
    int                     reqLen;
    socklen_t               addrlen;
    struct addrinfo         hints; // https://stackoverflow.com/questions/78198959/incomplete-type-is-not-allowed-in-a-c-program
    struct addrinfo         *result;
    struct addrinfo         *rp;
    char                    addrStr[ADDRSTRLEN];
    char                    host[NI_MAXHOST];
    char                    service[NI_MAXSERV];

    if (argc > 1)
        printf("Whatever\n");
    seqNum = 0;
    if (signal(SIGPIPE, SIG_IGN) == SIG_ERR)
    {
        perror("SIGPIPE signal");
        perror(strerror(errno));
        return (1);
    }
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_canonname = NULL;
    hints.ai_addr = NULL;
    hints.ai_next = NULL;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_family = AF_UNSPEC;
    hints.ai_flags = AI_PASSIVE | AI_NUMERICSERV;
    if (getaddrinfo(NULL, PORT_NUM, &hints, &result) != 0)
    {
        perror("getaddrinfo");
        perror(strerror(errno));
        return (1);
    }
    optval = 1;
    for (rp = result; rp != NULL; rp = rp->ai_next)
    {
        lfd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
        if (lfd == -1)
            continue;
        if (setsockopt(lfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) == -1)
        {
            perror("setsocket");
            perror(strerror(errno));
            return (1);
        }
        if (bind(lfd, rp->ai_addr, rp->ai_addrlen) == 0)
            break;
        close(lfd);
    }
    if (rp == NULL)
    {
        perror("Could not bind socket to any address");
        perror(strerror(errno));
        return (1);
    }
    if (listen(lfd, BACKLOG) == -1)
    {
        perror("listen");
        perror(strerror(errno));
        return (1);
    }
    freeaddrinfo(result);
    for (;;)
    {
        addrlen = sizeof(struct sockaddr_storage);
        cfd = accept(lfd, (struct sockaddr *) &claddr, &addrlen);
        if (cfd == -1)
        {
            perror("accept");
            continue;
        }
        if (getnameinfo((struct sockaddr *) &claddr,
                            addrlen, host, NI_MAXHOST,
                            service, NI_MAXSERV, 0) == 0
            )
            snprintf(addrStr, ADDRSTRLEN, "(%s, %s)", host, service);
        else
            snprintf(addrStr, ADDRSTRLEN, "(?UNKNOWN?)");
        printf("Connection from %s\n", addrStr);
        // if ()
    }
    return (0);
    
}