
#include <iostream>
#include<unistd.h>
using namespace std;
int main() {
    // insert code here...
    int i;
    int sum = 0;
    int tempSum = 0;
    int p1fd[2];
    int p2fd[2];
    int p3fd[2];
    pid_t pid;
    char buff[13] = "Example Text";
    pipe(p1fd);
    pipe(p2fd);
    pipe(p3fd);
    pid = fork();
    if(pid == 0)
    {
        //part 1
        close(p1fd[0]); //close read
        write(p1fd[1], &buff, sizeof(buff));
        close(p1fd[1]); //close write
        read(p1fd[0], &buff, sizeof(buff));
        cout << buff << endl;
        close(p1fd[0]); //close read
        
        //part 2
        close(p3fd[1]);
        for (i = 6; i <= 10; i++){
            sum += i;
        }
        while(read(p3fd[0], &tempSum, sizeof(tempSum)))
            sum += tempSum;
        close(p3fd[0]);
        cout << sum << endl;
        
    }
    else{
        //part 1
        close(p2fd[0]); //close read
        write(p2fd[1], &buff, sizeof(buff));
        close(p2fd[1]); //close write
        read(p2fd[0], &buff, sizeof(buff));
        cout << buff << endl;
        close(p2fd[0]);
        
        //part 2
        close(p3fd[0]); //close reader before reading
        for (i = 1; i <= 5; i++){
            tempSum += i;
        }
        write(p3fd[1], &tempSum, sizeof(tempSum));
        close(p3fd[1]); //after writing close writer
    }
         
    return 0;
    
}


