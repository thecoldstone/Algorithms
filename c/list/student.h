typedef enum {
    infsys,
    intsys,
    pocsys,
    grasys
} TObor;

typedef struct tdata {
    TObor obor;
    int rocnik;
    float prumer;
} TData;

typedef struct tstudent {
    char *jmeno;
    TData data;
} TStudent;

