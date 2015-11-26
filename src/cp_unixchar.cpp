#include "cp_unixchar.h"

int CPUNIXChar::execute() {
    // get size of argv[]
    int argc;
    for (argc = 0; argv[argc] != NULL; ++argc) ;

    int i_src, i_dst;
    if (argc < 2) {
        // not enough arguments
        cout << "Error: Not enough arguments!" << endl;
        return 1;
    } else if (argc == 3) {
        // only filenames passed
        i_src = 1;
        i_dst = 2;
    } else if (argc == 4) {
        // flag passed
        i_src = 2;
        i_dst = 3;
    } else {
        // too many arguments
        cout << "Error: Too many arguments passed!" << endl;
        return 1;
    }

    // open read file
    int src = open(argv[i_src], O_RDONLY);

    // create and open dst
    mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
    int dst = open(argv[i_dst], O_WRONLY | O_CREAT | O_EXCL, mode);
    if (dst == -1) {
        perror("Open");
        return 1;
    }

    // copy the file
    unsigned char c[1];
    size_t bytes_read;
    while(1) {
        bytes_read = read(src, c, sizeof(c));
        if (bytes_read != sizeof(c))
            break;
        write(dst, c, sizeof(c));
    }

    return 0;
}
