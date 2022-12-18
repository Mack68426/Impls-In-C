/*
HTTP-message =  起始行(start-line)
                *( header-field CRLF )
                CRLF
                [ message-body ]
*/

/*
##起始行##

###請求行 request-line:

|#####################################|
|                                     |
|[方法] [請求目標] [HTTP版本]\r\n       |
|                                     |
|#####################################|

###狀態行 status-line:

|#####################################|
|                                     |
|[HTTP版本] [狀態碼] [原因短語]\r\n     |
|                                     |
|#####################################|

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

void errmsg(const char *message){ perror(message); exit(0);}

int main()
{
    const char *host = "https://www.mirrormedia.mg/";
    const char *port = "80";

    char request[0xfff], response[0xfff]; // 請求與回應訊息
    char *requestLine = "GET / HTTP/1.1\r\n"; // 請求行
    char *headerFmt = "Host: %s\r\n"; // Host表頭欄位
    char *CRLF = "\r\n";  // 表頭後的CRLF

    
    struct addrinfo *result;
}
