/*
 *
 * Operating System Design / Diseño de Sistemas Operativos
 * (c) ARCOS.INF.UC3M.ES
 *
 * @file 	metadata.h
 * @brief 	Definition of the structures and data types of the file system.
 * @date	Last revision 01/04/2020
 *
 */

#define bitmap_getbit(bitmap_, i_) (bitmap_[i_ >> 3] & (1 << (i_ & 0x07)))

static inline void bitmap_setbit(char *bitmap_, int i_, int val_) {
  if (val_)
    bitmap_[(i_ >> 3)] |= (1 << (i_ & 0x07));
  else
    bitmap_[(i_ >> 3)] &= ~(1 << (i_ & 0x07));
}

#define MAX_FILES 48
#define MAX_LENGHT 32 //Máxima longitud para el nombre de un fichero y enlace simbólico
#define MAX_FILE_SIZE 10240
#define BLOCK_SIZE 2048
#define OPEN 1
#define CLOSE 0

struct INode;
struct Superblock;

#define NUMINODO 48 //Habrá tantos inodos como archivos sea capaz de soportar el sistema
#define NUMBLOQUESDATO 20

typedef struct TipoSuperbloque{
    unsigned int numMagico;	                   /* Número mágico del superbloque: 0x000D5500 */
    unsigned int numBloquesMapaInodos;         /* Número de bloques del mapa inodos */
    unsigned int numBloquesMapaDatos;          /* Número de bloques del mapa  datos */
    unsigned int numInodos; 	                 /* Número de inodos en el dispositivo */
    unsigned int primerInodo;	                 /* Número del bloque del 1º inodo del disp. (inodo raíz) */
    unsigned int numBloquesDatos;              /* Número de bloques de datos en el disp. */
    unsigned int primerBloqueDatos;            /* Número de bloque del 1º bloque de datos */
    unsigned int tamDispositivo;	             /* Tamaño total del disp. (en bytes) */
    char relleno[BLOCK_SIZE-8*sizeof(int)];    /* Campo de relleno (para completar un bloque entero en el superbloque) */
} TipoSuperbloque;


typedef struct TipoInodoDisco{
    /*  En el sistema considerado solo se tendrá soporte para ficheros y no directórios, tal y 
        como se especifica en los requisitos */
    
    char nombre[MAX_LENGHT];	                  /* Nombre del fichero/ directorio asociado */ 
    unsigned int size;	                        /* Tamaño actual del fichero en bytes */

    /*  Cada inodo apunta a un fichero y como el tamaño máximo de un fichero es 10240 Bytes
        y cada bloque tiene 2048 Bytes  entonces se apunta a 5 bloques como máximo */
    unsigned int bloqueDirecto[5];	            /* Número del bloque directo */

    unsigned int integrididad;                           /* Booleano de integridad 0: No tiene integridad, 1: Tiene integridad*/
    unsigned int integridad ;                   /* cada vez que se hgace close se sincroniza */

} TipoInodoDisco;


typedef struct TipoInodosBloque{ 

  /* Cada inodo ocupa 64 Bytes, hay 48 luego son 3072B asi que no caben en un solo bloque */
  TipoInodoDisco inodos [24];                           /* 1536 B */
  char relleno[BLOCK_SIZE-24*sizeof(TipoInodoDisco)];   /* Campo relleno */

} TipoInodosBloque;


/*
typedef struct INode {
  char *name; //Name of the inodo
  int pointer; //The pointer to the block
  int directBlock; //Block associated with the inode
  int integrity; //Integrity verification
  int bytesFilled; //Number of bytes filled in the block
  int open; // 1 = Open, 0 = Close
} INode;

typedef struct Superblock {
  long diskSize; //Disk Size
  int INodeMap; //Map of the inodes availables
  struct INode iNodes[MAX_FILES]; //Array
  int checksum; //Utilizado para comprobar la integridad
} Superblock;
*/