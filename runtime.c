#include <fcntl.h>
#include <linux/kernel.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#define FIB_DEV "/dev/fibonacci"

int main(int argc, char **argv)
{
    char write_buf[] = "testing writing";
    int offset = 92; /* TODO: try test something bigger than the limit */

    int fd = open(FIB_DEV, O_RDWR);
    if (fd < 0) {
        perror("Failed to open character device");
        exit(1);
    }

    /* Output the runtime */
    for (int i = 0; i <= offset; i++) {
        lseek(fd, i, SEEK_SET);
        long long sz1 = write(fd, write_buf, 0);
        long long sz2 = write(fd, write_buf, 1);
        printf("%d %lld %lld\n", i, sz1, sz2);
    }

    close(fd);
    return 0;
}
