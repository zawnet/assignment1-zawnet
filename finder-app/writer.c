#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>

int main(int argc, char *argv[]) {

    if (argc != 3) {
        fprintf(stderr, "Error: Two arguments required - <directory_path> <search_string>\n");
        syslog(LOG_ERR, "Usage: %s <file_path> <string_to_write>", argv[0]);
        return 1;
    }
    char *filesdir = argv[1];
    char *searchstr = argv[2];

    //Otworz polaczenie z syslogiem z facility LOG USER
    openlog("writer", LOG_PID, LOG_USER);

    printf("%s", filesdir);

    FILE *fp = fopen(filesdir, "w");
    if(fp == NULL) {
        syslog(LOG_ERR, "Error opening file: %s", filesdir);
        closelog();
        return 1;
    }
    if(fputs(searchstr, fp) == EOF){
        syslog(LOG_ERR, "Error writing to file: %s", filesdir);
        fclose(fp);
        closelog();
        return 1;

    }
    syslog(LOG_DEBUG, "Writing <%s> to <%s>", searchstr ,filesdir);
    fclose(fp);


// Zaloguj pomyślne zapisanie danych
    syslog(LOG_DEBUG, "Writing \"%s\" to %s", searchstr, filesdir);

    closelog();


    return 0;
}