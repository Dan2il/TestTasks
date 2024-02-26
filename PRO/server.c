#include <fcgi_stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int count = 0;

  // while (FCGI_Accept() >= 0) {
  //   printf(
  //       "Content-type: text/html\r\n"
  //       "\r\n"
  //       "<title>FastCGI Hello World!</title>"
  //       "<h1>FastCGI Hello World!</h1>"
  //       "Request number %d running on host <i>%s</i>\n",
  //       ++count, "nginx");
  // }

  while (FCGI_Accept() >= 0) {
    printf(
        "Content-type: text/html\r\n"
        "\r\n"
        "<title>FastCGI Hello World!</title>"
        "<h1>FastCGI Hello World!</h1>"
        "Request number %d running on host <i>%s</i>\n",
        ++count, "nginx");

    char *method = getenv("REQUEST_METHOD");
    if (!strcmp(method, "POST")) {
      int ilen = atoi(getenv("CONTENT_LENGTH"));
      char *bufp = malloc(ilen);
      fread(bufp, ilen, 1, stdin);
      printf("The POST data is<P>%s\n", bufp);
      free(bufp);
    }
  }

  // "Content-type: text/html\r\n"
  // "\r\n"
  // "<title>FastCGI Hello World!</title>"
  // "<h1>FastCGI Hello World!</h1>"
  // "Request number %d running on host <i>%s</i>\n",
  // ++count, "nginx"

  // <form action="upload" method="POST" enctype="multipart/form-data">
  //     <input type="file" name="myfile">
  //     <br/>
  //     <input type="submit" name="Submit">
  // </form>
}
