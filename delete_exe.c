#include <windows.h>
#include <stdio.h>
#include <string.h>

char current_exe[MAX_PATH];

void delete_exe(const char *dirpath) {
    char search_path[MAX_PATH];
    if (snprintf(search_path, sizeof(search_path), "%s\\*", dirpath) < 0) {
        fprintf(stderr, "Path too long: %s\n", dirpath);
        return;
    }

    WIN32_FIND_DATAA find_data;
    HANDLE hFind = FindFirstFileA(search_path, &find_data);
    if (hFind == INVALID_HANDLE_VALUE) {
        DWORD err = GetLastError();
        if (err != ERROR_FILE_NOT_FOUND) {
            fprintf(stderr, "FindFirstFile failed for %s (error %lu)\n", search_path, err);
        }
        return;
    }

    do {
        if (strcmp(find_data.cFileName, ".") == 0 || strcmp(find_data.cFileName, "..") == 0) {
            continue;
        }

        char full_path[MAX_PATH];
        if (snprintf(full_path, sizeof(full_path), "%s\\%s", dirpath, find_data.cFileName) < 0) {
            fprintf(stderr, "Path too long: %s\\%s\n", dirpath, find_data.cFileName);
            continue;
        }

        if (find_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
            delete_exe(full_path);
        } else {
            int len = strlen(find_data.cFileName);
            if (len >= 4) {
                const char *ext = find_data.cFileName + len - 4;
                if (_stricmp(ext, ".exe") == 0) {
                    char abs_path[MAX_PATH];
                    DWORD ret = GetFullPathNameA(full_path, sizeof(abs_path), abs_path, NULL);
                    if (ret == 0 || ret >= MAX_PATH) {
                        fprintf(stderr, "Path error for %s\n", full_path);
                        continue;
                    }

                    if (_stricmp(current_exe, abs_path) == 0) {
                        continue;
                    }

                    if (!DeleteFileA(full_path)) {
                        DWORD err = GetLastError();
                        if (err != ERROR_FILE_NOT_FOUND) {
                            fprintf(stderr, "Failed to delete %s (error %lu)\n", full_path, err);
                        }
                    }
                }
            }
        }
    } while (FindNextFileA(hFind, &find_data));

    FindClose(hFind);
}

int main() {
    if (GetModuleFileNameA(NULL, current_exe, sizeof(current_exe)) == 0) {
        fprintf(stderr, "GetModuleFileName failed (error %lu)\n", GetLastError());
        return 1;
    }

    delete_exe(".");

    return 0;
}