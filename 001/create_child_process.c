#include <stdio.h>
#include <windows.h>
int main() {
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
/*allocate memory*/
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    // Create a child process
    if (!CreateProcess(NULL,   // No module name (use command line)
        "notepad.exe",        // Command line
        NULL,                 // Process handle not inheritable
        NULL,                 // Thread handle not inheritable
        FALSE,                // Set handle inheritance to FALSE
        0,                    // No creation flags
        NULL,                 // Use parent's environment block
        NULL,                 // Use parent's starting directory 
        &si,                  // Pointer to STARTUPINFO structure
        &pi)                  // Pointer to PROCESS_INFORMATION structure
    ) {
        fprintf(stderr, "CreateProcess failed");
        return -1;
    }

/*parent will wait for the child to complete*/
    WaitForSingleObject(pi.hProcess, INFINITE);
    printf("Child process completed.\n");

    // Close process and thread handles. 
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0;
}