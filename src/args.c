#include "args.h"

void print_usage(){
    puts("usage: ./ray-tracer <input-file> [-p/--preview] [-f <input-file>] [--verbose]\n");
}

void parse_args( int argc, char *argv[]){
    int choice;
    static struct option long_options[] =
    {
        /* Use flags like so:
           {"verbose",	no_argument,	&verbose_flag, 'V'}*/
        /* Argument styles: no_argument, required_argument, optional_argument */
        {"file"    , required_argument , 0        , 'f' } ,
        {"version" , no_argument       , 0        , 'v' } ,
        {"preview" , no_argument       , &preview ,  1  } ,
        {"help"    , no_argument       , 0        , 'h' } ,
        {"verbose" , no_argument       , &verbose ,  1  } ,
        {0         , 0                 , 0        ,  0  }
    };

    while (1)
    {
        int option_index = 0;

        choice = getopt_long( argc, argv, "vVhpf:",
                long_options, &option_index);

        if (choice == -1)
            break;

        switch( choice ) {
            case 'v':
                printf("Ray tracer version 0.0.0\n");
                return;

            case 'h':
                print_usage();
                return;

            case 'V':
                verbose = 1;
                break;

            case 'p':
                preview = 1;
                break;

            case 'f':
                filename = optarg;
                break;

            case '?':
                /* getopt_long will have already printed an error */
                break;

            default:
                break;
        }
    }
    if (optind < argc) {
        if(filename == NULL){
            filename = argv[optind];
        }
    }

    if(verbose){
        printf( "verbose output:\n"
                "preview: %d\n"
                "filename: %s\n",
                preview, filename
        );
    }
}

