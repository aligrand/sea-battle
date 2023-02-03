#include "sb_globdef.h"

extern void call_upload(char *);

void call_sendServer(){
    FILE *serverfile;
    char path[50] = "onlineconfig\\me.bin";

#ifdef __linux__
#if __linux__
    path[9] = '/';
#endif
#endif

    serverfile = fopen(path, "wb");

    if (!serverfile) {
        printf(">> file can't be opened");
        sleep(1);
        exit(0);
    }

    fwrite(&p1, sizeof(struct player_info), 1, serverfile);
    fwrite(&p2, sizeof(struct player_info), 1, serverfile);
    fwrite(&is_ended, sizeof(int), 1, serverfile);
    fwrite(&board_size, sizeof(int), 1, serverfile);
    fwrite(&player, sizeof(int), 1, serverfile);
    fwrite(&last_player, sizeof(int), 1, serverfile);
    fwrite(&repair_num, sizeof(int), 1, serverfile);
    fwrite(&max_part, sizeof(int), 1, serverfile);
    fwrite(board_cpy, sizeof(char[2][52][52]), 1, serverfile);

    fclose(serverfile);

    call_upload(path);
}