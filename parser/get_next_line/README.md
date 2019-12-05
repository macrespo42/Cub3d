# Get next line (gnl)

get next line its used to read line by line in a file descriptor.
The prototype is : `int get_next_line(int fd, char **line);`

## How to use ?

You can use gnl in your project, when you compile you need to define a
BUFFER_SIZE like : `clang -W files.c get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=42`

you can find the subject at ft.subject.pdf in this repo.
