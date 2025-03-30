#include <stdio.h>
#include <syslog.h>

int main(int argc, char *argv[]) {
    // Open a connection to the syslog
    openlog(NULL, 0, LOG_USER);
    
    // Check for proper number of arguments
    if (argc != 3) {
        syslog(LOG_ERR, "Invalid Arguments <%d> - Expected 2 arguments", argc - 1);
        closelog();
        return 1;
    }

    // Retrieve file path and string to write from command line arguments
    const char *path = argv[1];
    const char *writestr = argv[2];
    
    // Open the file for writing
    FILE *file = fopen(path, "w");
    if (file == NULL) {
        syslog(LOG_ERR, "File not found: <%s>", path);
        closelog();
        return 1;
    }
    syslog(LOG_DEBUG, "Writing <%s> to <%s>", writestr, path);
    // Write to the file
    int wr_status = fprintf(file, "%s", writestr);
    if (wr_status < 0) {  // Negative value indicates failure
        syslog(LOG_ERR, "Write failed to file <%s> - Error code <%d>", path, wr_status);
        fclose(file);
        closelog();
        return 1;
    }

    // Log the successful write
   // syslog(LOG_DEBUG, "Writing <%s> to <%s>", writestr, path);

    // Close the file
    fclose(file);

    // Close the connection to the syslog
    closelog();

    return 0;
}
