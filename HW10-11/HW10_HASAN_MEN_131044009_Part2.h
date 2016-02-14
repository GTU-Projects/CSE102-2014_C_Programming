/*##############################################################*/
/*																*/
/*	HW10_HASAN_MEN_131044009_Part2.h							*/
/* 	HW10_HASAN_MEN_131044009_Test2.c ve part2.c icin yapilmistir*/
/*##############################################################*/



#define MAX_HISTORY 9999
#define MAX_ID_LEN 100

/* appoinment ve uygun calisma saatlerindeki kisileri listeye ekler
 ve listeyi return eder */
node_t* build_ll(Appointment_t appointmens[], int size, const Working_hours_t*
hours);

/* Aldigi listenin tum elemanlarini basar */
void print_node(node_t *node);

/* doldurulan listeyi csv dosyasina istenilen bicimde basar */
void write_accepted_app(node_t* head, const Files_t* files);

/* records dosyasinda taglar arasindaki bilgileri okur.
    id si ayni olan kisilere o bilgileri assign eder */
void add_personal_data(node_t* head, const Files_t* files);

/* delete dosyasindan algidi id ler listede var iþe onlari listeden siler */
int delete_appointments(node_t** head, const Files_t* files);

/* link list in tum icerigini serbest birakir*/
void free_list(node_t* head);

/* add_personalda kullanilmak icin yari recursive */
/* taglar arasindaki okumayi yapar */
void read_p_data(node_t* head,FILE *pdata);

/* gonderilen elemanin liste icinde olma durumunu return eder */
int is_duble(int hourr,node_t *list);


