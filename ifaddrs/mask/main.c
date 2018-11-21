#include <stdio.h>
#include <ifaddrs.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdlib.h>
#include <stdbool.h>

struct net_info {
    char *address;
    char *netmask;
    char *family;
    char *mac;
    int *scopeid;
    bool *internal;
    char *cidr;
};

int getNameInfo(struct sockaddr *addr, int size_of_saddr_in, char *host) {
    return getnameinfo(addr, size_of_saddr_in, host, NI_MAXHOST, NULL, 0, NI_NUMERICHOST);
}

int getSubnetMask()
{
    struct sockaddr_in *sin = NULL;
    struct sockaddr_in6 *sin6 = NULL;
    struct ifaddrs *ifa = NULL, *ifList;
    int i;

    if (getifaddrs(&ifList) < 0)
    {
        return -1;
    }

    for (ifa = ifList, i = 0; ifa != NULL; ifa = ifa->ifa_next, i++)
    {
        int family = ifa->ifa_addr->sa_family, s;
        char host[NI_MAXHOST];

        if (s != 0) {
          printf("getnameinfo() failed: %s\n", gai_strerror(s));
          exit(EXIT_FAILURE);
        }

        if(family == AF_INET)
        {
            printf("net: %s, %d\n", ifa->ifa_name, i);
            printf(">>> family: %s\n", "IPv4");
            s = getNameInfo(ifa->ifa_addr, sizeof(struct sockaddr_in), host);
            printf(">>> address: %s\n", host);
            s = getNameInfo(ifa->ifa_dstaddr, sizeof(struct sockaddr_in), host);
            printf(">>> broadcast: %s\n", host);
            s = getNameInfo(ifa->ifa_netmask, sizeof(struct sockaddr_in), host);
            printf(">>> netmask: %s\n", host);
            printf("---------------------------------------------------------\n\n");
        } else if (family == AF_INET6) {
            printf("net: %s, %d\n", ifa->ifa_name, i);
            printf(">>> family: %s\n", "IPv6");
            s = getNameInfo(ifa->ifa_addr, sizeof(struct sockaddr_in6), host);
            printf(">>> address: %s\n", host);
            s = getNameInfo(ifa->ifa_dstaddr, sizeof(struct sockaddr_in6), host);
            printf(">>> broadcast: %s\n", host);
            s = getNameInfo(ifa->ifa_netmask, sizeof(struct sockaddr_in6), host);
            printf(">>> netmask: %s\n", host);
            printf("---------------------------------------------------------\n\n");
        } else {
            // printf("n>>>: %d\n", ifa->ifa_addr->sa_family);
        }
    }

    freeifaddrs(ifList);

    return 0;
}

int main(void)
{
    getSubnetMask();

    return 0;
}