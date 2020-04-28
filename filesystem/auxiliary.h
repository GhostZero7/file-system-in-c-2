
/*
 *
 * Operating System Design / Diseño de Sistemas Operativos
 * (c) ARCOS.INF.UC3M.ES
 *
 * @file 	auxiliary.h
 * @brief 	Headers for the auxiliary functions required by filesystem.c.
 * @date	Last revision 01/04/2020
 *
 */


/*
 * @brief 	Synchronises disk and memory
 * @return 	0 if success, -1 otherwise.
 */

int my_sync(void);

/*
 * @brief 	Allocates an inode
 * @return 	array of position of the inode if success, [-1, -1] otherwise.
 */
int * ialloc(void);

/*
 * @brief 	computes the position of the inode map
 * @return 	array of position of the inode exists [block, position in the block], [-1, -1] otherwise.
 */
int * computePositionInodeMap(int positionMap);

/*
 * @brief 	Allocates a block
 * @return 	block if success, -1 otherwise.
 */
int alloc(void);

/*
 * @brief 	Liberates an inode
 * @return  -1 if it fails
 */
int ifree(int * arrayPosicion);


