#include <stdio.h>
#include <ifaddrs.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdlib.h>
#include <net/if_dl.h>
#include <stdbool.h>
#include <string.h>

int main() {
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
    if (ifa->ifa_addr->sa_family == AF_INET6) {
      sin6 = (struct sockaddr_in6*) ifa->ifa_addr;
    } else {
      sin = (struct sockaddr_in*) ifa->ifa_addr;
    }

    printf("test-os: %d\n", 11);
    if (ifa->ifa_netmask->sa_family == AF_INET6) {
      sin6 = (struct sockaddr_in6*) ifa->ifa_netmask;
    } else {
      sin = (struct sockaddr_in*) ifa->ifa_netmask;
    }

    if (ifa->ifa_dstaddr) {
      if (ifa->ifa_dstaddr->sa_family == AF_INET6) {
        printf("test-os: %s\n", "12-1");
        sin6 = (struct sockaddr_in6*) ifa->ifa_dstaddr;
      } else {
        printf("test-os: %s\n", "12-2");
        sin = (struct sockaddr_in*) ifa->ifa_dstaddr;
      }
    }
  }
  printf("success");

  freeifaddrs(ifList);

  return 0;
}