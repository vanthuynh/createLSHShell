#define LSH_RL_BUFSIZE 1024
char *lsh_read_line(void)
{
    char *line = NULL;
    ssize_t bufsize = 0; // have getline allocate a buffer for us

    if (getline(&line, &bufsize, stdin) == -1){
        if (feof(stdin)) {
            exit(EXIT_SUCCESS);  // We recieved an EOF
        } else  {
            perror("readline");
            exit(EXIT_FAILURE);
        }
    }
    return line;
}

void lsh_loop(void)
{
    char *line;
    char **args;
    int status;

    // checking the status variable
    do {
        printf("> ");
        line = lsh_read_line(); // call function to read a line
        args = lsh_split_line(line); // split the line into args
        status = lsh_execute(args);  // execute the args

        free(line);
        free(args);
    } while (status);
}

int main(int argc, char **argv)
{
    // Load config files, if any.

    // Run command loop.
    lsh_loop();

    // Perform any shutdown/cleanup.
    return EXIT_SUCCESS;
}