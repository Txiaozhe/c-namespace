#include <stdio.h>
#include <ifaddrs.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdlib.h>
#include <net/if_dl.h>
#include <stdbool.h>
#include <string.h>

void getNameInfo(struct sockaddr *addr, int size_of_saddr_in, char *host) {
    int no = getnameinfo(addr, size_of_saddr_in, host, NI_MAXHOST, NULL, 0, NI_NUMERICHOST);
    if (no < 0) 
    {
        
    }
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

    for (ifa = ifList, i = 0; ifa != NULL; ifa = ifa->ifa_next, ++i)
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
            getNameInfo(ifa->ifa_addr, sizeof(struct sockaddr_in), host);
            printf(">>> address: %s\n", host);
            getNameInfo(ifa->ifa_dstaddr, sizeof(struct sockaddr_in), host);
            printf(">>> broadcast: %s\n", host);
            getNameInfo(ifa->ifa_netmask, sizeof(struct sockaddr_in), host);
            printf(">>> netmask: %s\n", host);
            printf("ipv4 ---------------------------------------------------------ipv4 \n\n");
        } else if (family == AF_INET6) {
            printf("net: %s, %d\n", ifa->ifa_name, i);
            printf(">>> family: %s\n", "IPv6");
            getNameInfo(ifa->ifa_addr, sizeof(struct sockaddr_in6), host);
            printf(">>> address: %s\n", host);
            getNameInfo(ifa->ifa_dstaddr, sizeof(struct sockaddr_in6), host);
            printf(">>> broadcast: %s\n", host);
            getNameInfo(ifa->ifa_netmask, sizeof(struct sockaddr_in6), host);
            printf(">>> netmask: %s\n", host);
            printf("ipv6 ---------------------------------------------------------ipv6 \n\n");
        } else if (family == AF_LINK) {
            struct sockaddr_dl* sdl = (struct sockaddr_dl *)ifa->ifa_addr;
            unsigned char mac[6];
            if (6 == sdl->sdl_alen)
            {
                memcpy(mac, LLADDR(sdl), sdl->sdl_alen);
                printf("mac: %s, %d\n", ifa->ifa_name, i);
                printf(">>> mac: %02x:%02x:%02x:%02x:%02x:%02x\n", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
                printf("mac ---------------------------------------------------------mac \n\n");
            }
        } else {
            printf("other: %d\n", family);
            printf("other ---------------------------------------------------------other \n\n");
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