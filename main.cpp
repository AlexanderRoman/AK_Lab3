#include <stdio.h>
#include <unistd.h>
#include <map>
#include <string>
#include <getopt.h>

using namespace std;

int main(int argc, char* argv[]) {    

    const struct option LongFlagList[] = {
            {"help",0,NULL,'h'},
            {"modification",0,NULL,'m'},
            {"version",0,NULL,'v'},
            {"value",2,NULL,'V'},
            {NULL,0,NULL,0},
    };

    int result = 0;
    int flagIndex = -1;
    const char* ShortFlagList = "hmvV::?";
    bool WasHelp = false;
    bool WasMod = false;
    bool WasVersion = false;
    bool WasValue = false;

    while ((result = getopt_long(argc, argv, ShortFlagList, LongFlagList, &flagIndex)) != -1) {
        switch (result) {
            case 'h': {
                if (WasHelp == false) {
                    printf("Arg: Help\n");
                    WasHelp = true;
                    break;
                }
                break;
            }
            case 'm': {
                if (WasMod == false) {
                    printf("Arg: Modification\n");
                    WasMod = true;
                    break;
                }
                break;
            }
            case 'v': {
                if (WasVersion == false) {
                    printf("Arg: Version\n");
                    WasVersion = true;
                    break;
                }
                break;
            }
            case 'V': {
                if (WasValue == false) {
                    if (optarg == NULL) {
                        printf("Arg: Value\n");
                        WasValue = true;
                    }
                    else {
                        printf("Arg: Value = %s\n", optarg);
                        WasValue = true;
                    }

                    break;
                }
                break;
            }
            case '?': default: {
                printf("%c is an invalid flag\n", result);
                break;
            }
        };
        flagIndex = -1;
    };
};
